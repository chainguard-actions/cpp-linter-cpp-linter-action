<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.24.2

> This file was generated automatically by the hardening agent.

**Policy SHA:** `374911c4be584df24e6da57af2d990570ef0f859`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.24.2** was hardened automatically. 1 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step (nu shell) downloads the uv installer from a remote URL (`let installer = http get --raw --redirect-mode follow $uv_installer_url`, https://astral.sh/uv/<version>/install.sh) and pipes the downloaded content straight into a shell with `$installer | ^sh`. The script is never saved to a file or checked before it runs, so this is the same as `curl ... | sh`. The Windows branch passes the downloaded content directly to `^powershell -ExecutionPolicy ByPass $installer`. Fix: save the installer to a file, check it against a pinned checksum, then run it as a separate step. Better still, download the pinned uv release binary and verify its checksum.

Locations:

- `action.yml:457`

## Iteration Notes

### Iteration 1

**Fixes applied:** unsafe-shell

**Notes:**

I fixed the 'Setup cpp-linter dependencies' step in action.yml, but nothing has been run: the new install code hasn't been executed on any runner.

The step no longer pipes the astral.sh install script into sh, or hands it to powershell on Windows. Instead it downloads the uv 0.9.5 release archive straight from GitHub (github.com/astral-sh/uv/releases/download/0.9.5/uv-<target>.tar.gz or .zip) and works out <target> from the OS, the CPU architecture, and musl vs glibc on Linux. Before unpacking, it compares the archive's sha256 with the .sha256 file published next to it and stops on a mismatch. It then extracts with tar (Expand-Archive on Windows), copies uv and uvx (plus uvw on Windows) into UV_INSTALL_DIR, stops if uv is missing, and deletes the temp files.

The checksum is not pinned in the action, so the finding is only partly addressed. It comes from the same release as the archive, which catches corrupted or swapped downloads but not a tampered release. I had no way to look up the real hashes for uv 0.9.5 and didn't want to guess them. To finish the fix, add the published sha256 for each target as a constant in the step.

The nu shell code also relies on a few things I haven't checked:
- which architecture names nu reports
- the folder layout inside the archives (uv-<target>/uv in the tarballs, files at the top level in the zips)
- whether the .sha256 file comes back as text or binary

Run the step on Linux, macOS and Windows runners before publishing.

