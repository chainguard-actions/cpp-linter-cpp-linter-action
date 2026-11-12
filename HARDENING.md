<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.24.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.24.1** was hardened automatically. 2 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step downloads the uv installer from the network and pipes it straight into a shell without saving it to a file first: `let installer = http get --raw --redirect-mode follow $uv_installer_url` followed by `$installer | ^sh` (fetched from https://astral.sh/uv/($env.UV_VERSION)/install.sh). This is the same pattern as curl | sh. Save the script to a file, verify its checksum, and run it as a separate step.

Locations:

- `action.yml:453`

### unsafe-shell (severity: high)

On Windows, the same step passes the downloaded installer content (from https://astral.sh/uv/($env.UV_VERSION)/install.ps1) straight to PowerShell as the command to run: `^powershell -ExecutionPolicy ByPass $installer`. This runs remote content without saving or verifying it first, the PowerShell version of curl | sh.

Locations:

- `action.yml:451`

## Iteration Notes

### Iteration 1

**Fixes applied:** unsafe-shell

**Notes:**

In the 'Setup cpp-linter dependencies' step (nu shell), the uv installer (install.sh / install.ps1, version-pinned URL) is now saved to a file in $RUNNER_TEMP, checked to be non-empty, and executed as a file (`sh <file>` / `powershell -ExecutionPolicy ByPass -File <file>`) instead of piping content into sh or passing it as a PowerShell command; the file is removed afterwards. No upstream checksum is published for these installer scripts, so no hash verification was added.

