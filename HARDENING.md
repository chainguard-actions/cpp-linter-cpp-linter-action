<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.24.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.24.0** was hardened automatically. 1 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### unsafe-shell (severity: high)

In the 'Setup cpp-linter dependencies' step, the uv installer is fetched with `let installer = http get --raw --redirect-mode follow $uv_installer_url` (https://astral.sh/uv/<version>/install.sh or install.ps1). It then runs straight away with `$installer | ^sh` on Linux/macOS and `^powershell -ExecutionPolicy ByPass $installer` on Windows. This is the same as `curl ... | sh`: the remote script is never saved to a file or checked before it runs. Fix: save it to a file, check its integrity (for example a pinned checksum), then run it as a separate step, as the step already does for llvm.sh.

Locations:

- `action.yml:439`
- `action.yml:437`

## Iteration Notes

### Iteration 1

**Fixes applied:** unsafe-shell

**Notes:**

In the 'Setup cpp-linter dependencies' step (action.yml), the uv installer (install.sh or install.ps1) is now saved to $RUNNER_TEMP with `save --raw`. Before running, the step checks that the file is not empty and that it mentions the pinned UV_VERSION; if either check fails, the step stops with an error. The file is then run on its own with `sh <file>` or `powershell -NoProfile -ExecutionPolicy ByPass -File <file>`, and deleted afterwards. This is the same download-then-run pattern the step already uses for llvm.sh.

I did not add a pinned SHA256 for the installer script. Its hash can't be looked up with the tools I have, and I wasn't going to make one up. The version check confirms which installer was downloaded, but it doesn't prove the file hasn't been tampered with. The uv installer itself checks the checksum of the uv archive it downloads. If maintainers want the installer pinned too, they can add its SHA256 to the step and compare against it before running.

