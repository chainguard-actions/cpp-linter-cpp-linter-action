<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.24.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `374911c4be584df24e6da57af2d990570ef0f859`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.24.0** was hardened automatically. 2 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step downloads the uv installer from https://astral.sh/uv/<version>/install.sh (or install.ps1 on Windows) with `let installer = http get --raw --redirect-mode follow $uv_installer_url`. It then runs it straight away: `$installer | ^sh`, or `^powershell -ExecutionPolicy ByPass $installer` on Windows. This works the same way as `curl ... | sh`. Remote content goes directly to a shell without being saved to a file and checked (for example against a pinned checksum) first. Fix: save the installer to a file, check its sha256 against a pinned value, then run it. Or install uv from a release archive that has a pinned checksum.

Locations:

- `action.yml:420`

### prior-fix (severity: high)

Carried forward from this version's previous harden, which fixed it; fix it again unless the code no longer has the problem. The previous harden changed action.yml without recording a finding for it, and this analysis reported nothing there. Re-apply its security changes unless the code no longer needs them. The previous patch:
```diff
diff --git a/action.yml b/action.yml
index 40be257..e6804a8 100644
--- a/action.yml
+++ b/action.yml
@@ -280,10 +280,27 @@ outputs:
 runs:
   using: "composite"
   steps:
     - name: Setup nu shell
       # I'm done writing everything twice (in bash and powershell)
       # With nu shell, we use the same shell/script for all platforms
       uses: hustcer/setup-nu@95cd3bfe252450ef7d35dd9a7ddecf3484341134 # v3.28
       with:
         version: '0.106.1'
 
@@ -306,7 +323,7 @@ runs:
 
     - name: Enable cache
       if: inputs.cache-enable == 'true' || inputs.cache-enable == true
       uses: actions/cache@55cc8345863c7cc4c66a329aec7e433d2d1c52a9 # v6.1.0
       with:
         path: ${{ runner.temp }}/cpp-linter-action-cache
         key: cpp-linter-action_${{ runner.os }}_${{ steps.compute-cache-key.outputs.key }}
@@ -432,12 +449,27 @@ runs:
         } else {
           $"https://astral.sh/uv/($env.UV_VERSION)/install.sh"
         }
-        let installer = http get --raw --redirect-mode follow $uv_installer_url
+        # Download the installer to a file first, check it, then run it separately
+        let installer_path = if $is_windows {
+          $env.RUNNER_TEMP | path join 'uv-installer.ps1'
+        } else {
+          $env.RUNNER_TEMP | path join 'uv-installer.sh'
+        }
+        (
+          http get --raw --redirect-mode follow $uv_installer_url
+          | save --raw --force $installer_path
+        )
+        let installer_text = open --raw $installer_path | decode utf-8
+        if ($installer_text | is-empty) or (not ($installer_text | str contains $env.UV_VERSION)) {
+          print $"::error title=uv installer verification failed::Downloaded installer from ($uv_installer_url) is empty or does not reference uv ($env.UV_VERSION)"
+          exit 1
+        }
         if $is_windows {
-          ^powershell -ExecutionPolicy ByPass $installer
+          ^powershell -NoProfile -ExecutionPolicy ByPass -File $installer_path
         } else {
-          $installer | ^sh
+          ^sh $installer_path
         }
+        rm --force $installer_path
 
         let gh_action_debug = $env | get --optional 'ACTIONS_STEP_DEBUG'
         let action_verbosity = $env.INPUT_VERBOSITY == 'debug'

```

Locations:

- `action.yml`

## Iteration Notes

### Iteration 1

**Fixes applied:** unsafe-shell, prior-fix

**Notes:**

In action.yml, the 'Setup cpp-linter dependencies' step now downloads the uv installer to a file in $RUNNER_TEMP instead of keeping it in memory. Before running it, the step checks that the file is not empty and that it mentions the pinned UV_VERSION. It then runs the file with 'sh <file>' (or 'powershell -NoProfile -ExecutionPolicy ByPass -File <file>' on Windows) and deletes it afterwards. This is the same change the previous harden made. I could not compute a pinned sha256 for the installer because I have no network access to fetch it. So the check is a content check, not a checksum. setup-nu and actions/cache were already pinned to SHAs.

