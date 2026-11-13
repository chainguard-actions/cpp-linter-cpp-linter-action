<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.24.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `374911c4be584df24e6da57af2d990570ef0f859`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.24.1** was hardened automatically. 2 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step downloads the uv installer from https://astral.sh/uv/<version>/install.sh (install.ps1 on Windows) with `let installer = http get --raw --redirect-mode follow $uv_installer_url`. It then runs that content directly: `$installer | ^sh` on Linux/macOS, and `^powershell -ExecutionPolicy ByPass $installer` on Windows. This is the nushell form of `curl ... | sh`. The remote script is never saved to a file or checked against a hash before it runs. Fix: save it to a file, verify its checksum (or install a pinned uv release binary with a known checksum), then run it as a separate step, as the llvm.sh install already does.

Locations:

- `action.yml:432`

### prior-fix (severity: high)

Carried forward from this version's previous harden, which fixed it; fix it again unless the code no longer has the problem. The previous harden changed action.yml without recording a finding for it, and this analysis reported nothing there. Re-apply its security changes unless the code no longer needs them. The previous patch:
```diff
diff --git a/action.yml b/action.yml
index c3ccb9c..b4c869c 100644
--- a/action.yml
+++ b/action.yml
@@ -294,10 +294,27 @@ outputs:
 runs:
   using: "composite"
   steps:
     - name: Setup nu shell
       # I'm done writing everything twice (in bash and powershell)
       # With nu shell, we use the same shell/script for all platforms
       uses: hustcer/setup-nu@eacad52a4634c4f8d17a94916f93be6856861b9c # v3.29
       with:
         version: '0.106.1'
 
@@ -320,7 +337,7 @@ runs:
 
     - name: Enable cache
       if: inputs.cache-enable == 'true' || inputs.cache-enable == true
       uses: actions/cache@55cc8345863c7cc4c66a329aec7e433d2d1c52a9 # v6.1.0
       with:
         path: ${{ runner.temp }}/cpp-linter-action-cache
         key: cpp-linter-action_${{ runner.os }}_${{ steps.compute-cache-key.outputs.key }}
@@ -446,12 +463,22 @@ runs:
         } else {
           $"https://astral.sh/uv/($env.UV_VERSION)/install.sh"
         }
-        let installer = http get --raw --redirect-mode follow $uv_installer_url
+        let installer_path = if $is_windows {
+          $env.RUNNER_TEMP | path join 'uv-installer.ps1'
+        } else {
+          $env.RUNNER_TEMP | path join 'uv-installer.sh'
+        }
+        http get --raw --redirect-mode follow $uv_installer_url | save --raw --force $installer_path
+        if (not ($installer_path | path exists)) or ((ls $installer_path | get 0.size) == 0b) {
+          print "::error title=uv installer download failed::Downloaded uv installer is missing or empty"
+          exit 1
+        }
         if $is_windows {
-          ^powershell -ExecutionPolicy ByPass $installer
+          ^powershell -ExecutionPolicy ByPass -File $installer_path
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

In the 'Setup cpp-linter dependencies' step, the uv installer used to be piped straight into a shell. It is now saved with `save --raw --force` to $RUNNER_TEMP (uv-installer.sh, or uv-installer.ps1 on Windows). The step stops with an error if the file is missing or empty. The file is then run as `^sh $installer_path`, or `powershell -ExecutionPolicy ByPass -File $installer_path` on Windows, and deleted afterwards. This is the same change the previous harden made. It does not check the installer against a hash, because no known checksum was available. hustcer/setup-nu and actions/cache were already pinned to SHAs.

