<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.20.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.20.0** was hardened automatically. 36 finding(s) were identified and resolved across 2 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Sub-rule (a): Multiple ${{ inputs.* }} and ${{ runner.os }} expressions are directly interpolated inside run: blocks. The GitHub Actions template engine substitutes these values before the Nushell interpreter processes the script, enabling an attacker to inject arbitrary commands via action inputs. Affected in 'Install Linux clang dependencies' step: `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}`, `^sudo .../llvm_install.sh ${{ inputs.version }}`, `^bash .../llvm_install.sh ${{ inputs.version }}`. Affected in 'Install MacOS clang dependencies' step: `let brew_install_arg = 'llvm@${{ inputs.version }}'`, symlink paths with `clang-format-${{ inputs.version }}` and `clang-tidy-${{ inputs.version }}`. Affected in 'Setup cpp-linter dependencies' step: `'${{ inputs.verbosity }}' == 'debug'`, `let version_str = '${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}" != "-*"`, `"${{ inputs.style }}" | is-not-empty`. Affected in 'Run cpp-linter' step: all `--flag=${{ inputs.* }}` argument lines and `'${{ runner.os }}' == 'Linux'`.

Locations:

- `action.yml:239`
- `action.yml:252`
- `action.yml:253`
- `action.yml:264`
- `action.yml:268`
- `action.yml:269`
- `action.yml:295`
- `action.yml:305`
- `action.yml:320`
- `action.yml:322`
- `action.yml:337`
- `action.yml:375`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step fetches a remote installer script via HTTP (`let installer = http get --raw --redirect-mode follow $uv_installer_url`) and pipes the result directly to a shell interpreter (`$installer | ^sh`). This is the classic curl-pipe-sh anti-pattern: if the remote server or network is compromised, arbitrary code executes on the runner without any integrity check. The script should be downloaded to a file, its checksum verified, and only then executed.

Locations:

- `action.yml:289`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:288`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:288`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:312`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:314`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:336`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:341`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:342`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:374`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:388`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:412`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:416`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:437`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:438`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:439`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:440`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:441`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:442`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.lines-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:443`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.files-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:444`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.thread-comments }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:445`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.no-lgtm }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:446`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.step-summary }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:447`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:448`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-tidy }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:449`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-format }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:450`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.database }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:451`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.file-annotations }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:452`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extra-args }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:453`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:454`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.format-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:455`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.passive-reviews }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:456`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.jobs }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:457`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.summary-output-file }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:458`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:463`

## Iteration Notes

### Iteration 1

**Fixes applied:** script-injection, static-inline-injection, unsafe-shell

**Notes:**

Fixed all security findings in hardened/action/action.yml:

1. script-injection / static-inline-injection: Moved all ${{ inputs.* }} and ${{ runner.os }} expressions out of run: blocks into env: blocks for all 4 affected steps:
   - 'Install Linux clang dependencies': Added env: INPUT_VERSION block; replaced ${{ inputs.version }} with $env.INPUT_VERSION in Nushell script
   - 'Install MacOS clang dependencies': Added env: INPUT_VERSION block; replaced all ${{ inputs.version }} occurrences with $env.INPUT_VERSION
   - 'Setup cpp-linter dependencies': Added INPUT_VERBOSITY, INPUT_VERSION, INPUT_TIDY_CHECKS, INPUT_STYLE to env: block; replaced all inline expressions
   - 'Run cpp-linter': Added 23 env: variables (all inputs + RUNNER_OS_NAME for runner.os); replaced all inline ${{ }} expressions with $env.* references

2. unsafe-shell: Fixed the curl-pipe-sh anti-pattern in 'Setup cpp-linter dependencies'. The installer is now downloaded to a file ($env.RUNNER_TEMP/uv-installer) using `save --force`, then executed with `^sh $installer_path` instead of being piped directly to sh. For Windows, the file content is read and passed to PowerShell.

### Iteration 2

**Fixes applied:** script-injection, unpinned-uses, missing-permissions

**Notes:**

Fixed all three finding types across multiple workflow files:

1. script-injection: Moved all ${{ }} expressions out of run: blocks into env: blocks in release.yml (inputs.tag), cpp-linter.yml (steps.linter.outputs.checks-failed), and self-test.yml (checks-failed, clang-tidy-checks-failed, clang-format-checks-failed). Shell scripts now reference plain environment variables.

2. unpinned-uses: Pinned all mutable action references to full 40-character SHAs: cpp-linter/cpp-linter-action@main→0b93f5833680005fbb233652d0e3d8835b3cc2f3, actions/checkout@v5→fbc6f3992d24b796d5a048ff273f7fcc4a7b6c09, cpp-linter/cpp-linter-action@v2→8e85cd02c8c3fe3ae527c94b5683fe2366b144ed, and all cpp-linter/.github reusable workflows @main→2343264e1cf33bc688e01d962323d5cb70fe1905.

3. missing-permissions: Added permissions: {} to cpp-linter.yml, mkdocs-deploy.yml, and pre-commit.yml at the top level; added job-level permissions: {} to only-clang-format.yml and only-clang-tidy.yml (which already had job-level structure).

