<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.23.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `374911c4be584df24e6da57af2d990570ef0f859`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.23.1** was hardened automatically. 55 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a): the 'Install Linux clang dependencies' step puts ${{ inputs.version }} directly into the nu run script, e.g. `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}`. A crafted version value can inject nu code. Fix: pass it through env: and read it as $env.VAR.

Locations:

- `action.yml:322`
- `action.yml:346`
- `action.yml:348`

### script-injection (severity: high)

Rule (a): the 'Install MacOS clang dependencies' step puts ${{ inputs.version }} directly into the script: `let brew_install_arg = 'llvm@${{ inputs.version }}'` and in the `^ln -s ... "/usr/local/bin/clang-format-${{ inputs.version }}"` lines.

Locations:

- `action.yml:370`

### script-injection (severity: high)

Rule (a): the 'Setup cpp-linter dependencies' step puts several inputs directly into the script: `let action_verbosity = '${{ inputs.verbosity }}' == 'debug'`, `let version_str = '${{ inputs.version }}'`, `if ("${{ inputs.tidy-checks }}" != "-*")` and `if ("${{ inputs.style }}" | is-not-empty)`.

Locations:

- `action.yml:408`

### script-injection (severity: high)

Rule (a): the 'Check out the pull request head for auto-fix' step puts expressions directly into the script: `cd '${{ inputs.repo-root }}'` and `let head_sha = '${{ github.event.pull_request.head.sha }}'`.

Locations:

- `action.yml:474`

### script-injection (severity: high)

Rule (a): the 'Run cpp-linter' step builds its argument list by putting about 22 inputs directly into single-quoted strings in the script, e.g. `'--style=${{ inputs.style }}'`, `'--extra-arg=${{ inputs.extra-args }}'` and `'--ignore=${{ inputs.ignore }}'`. It also uses `if '${{ inputs.auto-fix }}' == 'true'`, `let action_verbosity = '${{ inputs.verbosity }}'` and `('${{ runner.os }}' == 'Linux')`. A value containing a single quote can break out of the string and inject nu code.

Locations:

- `action.yml:501`

### script-injection (severity: high)

Rule (a): the 'Auto-commit clang-format fixes' step puts expressions directly into the script: `let head_sha = '${{ github.event.pull_request.head.sha }}'`, `let head_repo = '${{ github.event.pull_request.head.repo.full_name }}'`, `'${{ github.repository }}'`, `cd '${{ inputs.repo-root }}'`, `'${{ inputs.extensions }}'`, `'${{ inputs.auto-fix-git-user }}'`, `'${{ inputs.auto-fix-git-email }}'` and `'${{ inputs.auto-fix-commit-msg }}'`.

Locations:

- `action.yml:561`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step downloads the uv installer with `let installer = http get --raw --redirect-mode follow $uv_installer_url` (https://astral.sh/uv/<ver>/install.sh) and pipes it straight into the shell with `$installer | ^sh`. On Windows it runs the downloaded content with `^powershell -ExecutionPolicy ByPass $installer`. Remote content runs without being saved to a file or verified first.

Locations:

- `action.yml:400`
- `action.yml:404`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:323`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:323`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:347`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:349`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:371`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:376`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:377`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:409`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:423`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:447`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:451`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Check out the pull request head for auto-fix"; move to env: map

Locations:

- `action.yml:475`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.sha }}" appears directly in run: block of step "Check out the pull request head for auto-fix"; move to env: map

Locations:

- `action.yml:479`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:502`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:503`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:504`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:505`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:506`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:507`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.lines-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:508`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.files-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:509`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.thread-comments }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:510`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.no-lgtm }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:511`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.step-summary }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:512`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:513`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-tidy }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:514`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-format }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:515`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.database }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:516`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.file-annotations }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:517`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extra-args }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:518`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:519`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.format-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:520`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.passive-reviews }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:521`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.jobs }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:522`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.summary-output-file }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:523`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:525`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:531`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.sha }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:562`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.repo.full_name }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:563`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:585`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:599`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-user }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:614`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-user }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:617`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-email }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:619`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-email }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:622`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-commit-msg }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:626`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-commit-msg }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:629`

### prior-fix (severity: high)

Carried forward from this version's previous harden, which fixed it; fix it again unless the code no longer has the problem. The previous harden changed action.yml without recording a finding for it, and this analysis reported nothing there. Re-apply its security changes unless the code no longer needs them. The previous patch:
```diff
diff --git a/action.yml b/action.yml
index 7ef4560..f6437b5 100644
--- a/action.yml
+++ b/action.yml
@@ -32,8 +32,8 @@ inputs:
     default: "boost-*,bugprone-*,performance-*,readability-*,portability-*,modernize-*,clang-analyzer-*,cppcoreguidelines-*"
   repo-root:
     description: >
-      The relative path to the repository root directory.
-      This path is relative to the path designated as the runner's `GITHUB_WORKSPACE` environment variable.
+      The relative path to the repository root directory. This path is relative to the path designated as the runner's `GITHUB_WORKSPACE` environment variable.
+
     required: false
     default: '.'
   version:
@@ -283,13 +283,29 @@ outputs:
 runs:
   using: "composite"
   steps:
     - name: Setup nu shell
       # I'm done writing everything twice (in bash and powershell)
       # With nu shell, we use the same shell/script for all platforms
       uses: hustcer/setup-nu@9215c80adb545a85c419d5085b76eb6d082f49e7 # v3.27
       with:
         version: '0.106.1'
-
     - name: Compute cache key
       if: inputs.cache-enable == 'true' || inputs.cache-enable == true
       id: compute-cache-key
@@ -306,21 +322,22 @@ runs:
             }
         )
         $'key=($key)\n' | save --append $env.GITHUB_OUTPUT
-
     - name: Enable cache
       if: inputs.cache-enable == 'true' || inputs.cache-enable == true
       uses: actions/cache@55cc8345863c7cc4c66a329aec7e433d2d1c52a9 # v6.1.0
       with:
         path: ${{ runner.temp }}/cpp-linter-action-cache
         key: cpp-linter-action_${{ runner.os }}_${{ steps.compute-cache-key.outputs.key }}
-
     - name: Install Linux clang dependencies
       if: runner.os == 'Linux'
       shell: nu {0}
+      env:
+        INPUT_VERSION: ${{ inputs.version }}
       run: |
         let action_path = $env.GITHUB_ACTION_PATH | path expand
+        let version = $env.INPUT_VERSION
         let apt_install_args = [
-            install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}
+            install -y $"clang-format-($version)" $"clang-tidy-($version)"
         ]
         let has_sudo = not ((which 'sudo') | is-empty)
 
@@ -344,9 +361,9 @@ runs:
 
           let llvm_installer_result = (
             if $has_sudo {
-                ^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}
+                ^sudo $"($action_path)/llvm_install.sh" $version
             } else {
-                ^bash $"($action_path)/llvm_install.sh" ${{ inputs.version }}
+                ^bash $"($action_path)/llvm_install.sh" $version
             }
           ) | complete
           print $llvm_installer_result
@@ -362,26 +379,31 @@ runs:
             print $result
           }
         }
-
     - name: Install MacOS clang dependencies
       if: runner.os == 'macOS'
       shell: nu {0}
+      env:
+        INPUT_VERSION: ${{ inputs.version }}
       run: |-
+        let version = $env.INPUT_VERSION
         ^brew update
-        let brew_install_arg = 'llvm@${{ inputs.version }}'
+        let brew_install_arg = $"llvm@($version)"
         let result = (^brew install $brew_install_arg) | complete
         print $result
         if ($result.exit_code == 0) {
           let brew_prefix = ^brew --prefix $brew_install_arg
-          ^ln -s $"($brew_prefix)/bin/clang-format" "/usr/local/bin/clang-format-${{ inputs.version }}"
-          ^ln -s $"($brew_prefix)/bin/clang-tidy" "/usr/local/bin/clang-tidy-${{ inputs.version }}"
+          ^ln -s $"($brew_prefix)/bin/clang-format" $"/usr/local/bin/clang-format-($version)"
+          ^ln -s $"($brew_prefix)/bin/clang-tidy" $"/usr/local/bin/clang-tidy-($version)"
         }
-
     - name: Setup cpp-linter dependencies
       shell: nu {0}
       env:
         UV_NO_MODIFY_PATH: 1
         UV_VERSION: '0.9.5'
+        INPUT_VERBOSITY: ${{ inputs.verbosity }}
+        INPUT_VERSION: ${{ inputs.version }}
+        INPUT_TIDY_CHECKS: ${{ inputs.tidy-checks }}
+        INPUT_STYLE: ${{ inputs.style }}
       run: |-
         let action_path = $env.GITHUB_ACTION_PATH | path expand
         $e
... (truncated)
```

Locations:

- `action.yml`

## Iteration Notes

### Iteration 1

**Fixes applied:** script-injection, static-inline-injection, unsafe-shell, prior-fix

**Notes:**

All edits are in action.yml; nothing was run or tested.

**Script injection:** In all six nu steps (Linux install, macOS install, Setup deps, PR-head checkout, Run cpp-linter, Auto-commit), the `inputs.*` and `github.event.pull_request.*` values now come in through each step's `env:` block. Scripts read them with `$env | get --optional NAME | default ''`. The `default ''` matters on Windows, where an empty environment variable doesn't exist and `$env.NAME` would fail. In the two longest steps this lookup is wrapped in a small helper, `get-input`. I didn't name it `input` because that is a built-in nu command.

**Other replacements:** `runner.os` became `$env.RUNNER_OS` and `github.repository` became `$env.GITHUB_REPOSITORY`. cpp-linter's arguments are now built as nu string interpolations, so each value is still passed as one argument and nothing in it gets evaluated.

**Unsafe shell:** The uv installer is downloaded to a file in `$RUNNER_TEMP`, checked to be non-empty, run with `sh <file>` (or `powershell -ExecutionPolicy ByPass -File <file>` on Windows) and then deleted. No arguments are passed, same as upstream. On Windows this is a small change in how the script runs: upstream passed the downloaded text to PowerShell as a command, and it now runs as a script file.

**Prior fix:** This re-applies the security changes from the previous harden; I didn't reapply its rewording of the `repo-root` description. The hustcer/setup-nu and actions/cache references were already pinned to commit SHAs.

