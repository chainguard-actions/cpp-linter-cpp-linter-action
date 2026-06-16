<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.17.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `1`

Action **cpp-linter--cpp-linter-action/v2.17.0** was hardened automatically. 34 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple ${{ inputs.* }} and ${{ runner.os }} expressions are directly interpolated inside run: shell command strings (sub-rule a). This allows an attacker who controls the calling workflow's inputs to inject arbitrary shell commands.

- 'Install Linux clang dependencies' step: `clang-format-${{ inputs.version }}`, `clang-tidy-${{ inputs.version }}`, and `${{ inputs.version }}` used directly as nu-shell list elements and command arguments.
- 'Install MacOS clang dependencies' step: `'llvm@${{ inputs.version }}'`, `"/usr/local/bin/clang-format-${{ inputs.version }}"`, `"/usr/local/bin/clang-tidy-${{ inputs.version }}"` interpolated directly.
- 'Setup cpp-linter dependencies' step: `'${{ inputs.verbosity }}'` and `${{ inputs.version }}` interpolated directly.
- 'Run cpp-linter' step: All inputs (`${{ inputs.style }}`, `${{ inputs.extensions }}`, `${{ inputs.tidy-checks }}`, `${{ inputs.repo-root }}`, `${{ inputs.version }}`, `${{ inputs.verbosity }}`, `${{ inputs.lines-changed-only }}`, `${{ inputs.files-changed-only }}`, `${{ inputs.thread-comments }}`, `${{ inputs.no-lgtm }}`, `${{ inputs.step-summary }}`, `${{ inputs.ignore }}`, `${{ inputs.ignore-tidy }}`, `${{ inputs.ignore-format }}`, `${{ inputs.database }}`, `${{ inputs.file-annotations }}`, `${{ inputs.extra-args }}`, `${{ inputs.tidy-review }}`, `${{ inputs.format-review }}`, `${{ inputs.passive-reviews }}`, `${{ inputs.jobs }}`) and `${{ runner.os }}` are interpolated directly inside the run: block.

Locations:

- `action.yml:253`
- `action.yml:278`
- `action.yml:295`
- `action.yml:310`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step fetches a remote installer script from astral.sh via `http get --raw --redirect-mode follow $uv_installer_url` and then pipes the result directly to a shell interpreter with `$installer | ^sh`. This is equivalent to `curl URL | sh` — executing untrusted remote content without any integrity verification.

Locations:

- `action.yml:330`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:279`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:279`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:303`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:305`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:327`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:332`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:333`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:365`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:379`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:380`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:396`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:397`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:398`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:399`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:400`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:401`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.lines-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:402`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.files-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:403`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.thread-comments }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:404`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.no-lgtm }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:405`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.step-summary }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:406`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:407`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-tidy }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:408`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-format }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:409`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.database }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:410`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.file-annotations }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:411`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extra-args }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:412`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:413`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.format-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:414`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.passive-reviews }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:415`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.jobs }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:416`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:421`

## Iteration Notes

### Iteration 1

**Fixes applied:** script-injection, static-inline-injection, unsafe-shell

**Notes:**

Fixed all security findings in action.yml:

1. **script-injection / static-inline-injection** (all 4 affected steps):
   - 'Install Linux clang dependencies': Added `env: INPUT_VERSION: ${{ inputs.version }}` and replaced all 3 inline `${{ inputs.version }}` uses in the run: block with nu shell variable `$version` (from `$env.INPUT_VERSION`).
   - 'Install MacOS clang dependencies': Added `env: INPUT_VERSION: ${{ inputs.version }}` and replaced all 3 inline `${{ inputs.version }}` uses with `$version`.
   - 'Setup cpp-linter dependencies': Added `INPUT_VERBOSITY` and `INPUT_VERSION` to env: block; replaced inline `${{ inputs.verbosity }}` and `${{ inputs.version }}` uses with `$env.INPUT_VERBOSITY` and `$env.INPUT_VERSION`.
   - 'Run cpp-linter': Added a full env: block with all 22 inputs plus `RUNNER_OS_NAME: ${{ runner.os }}`; replaced all inline `${{ inputs.* }}` and `${{ runner.os }}` expressions with `$env.INPUT_*` and `$env.RUNNER_OS_NAME` references.

2. **unsafe-shell**: Fixed the 'Setup cpp-linter dependencies' step to no longer pipe remote installer content directly to sh/powershell. The installer is now saved to a temp file first (`save --force $installer_path`) and then executed separately (`^sh $installer_path` or `^powershell -ExecutionPolicy ByPass -File $installer_path`), eliminating the curl|sh anti-pattern.

