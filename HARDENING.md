<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.20.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.20.0** was hardened automatically. 35 finding(s) were identified and resolved across 2 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a) violation: Multiple ${{ inputs.* }} expressions are directly interpolated inside run: blocks (Nu shell scripts) in action.yml. Before the Nu shell ever executes, GitHub Actions substitutes these template expressions into the script text verbatim, allowing an attacker who controls input values to inject arbitrary shell commands. Affected expressions include ${{ inputs.version }}, ${{ inputs.style }}, ${{ inputs.tidy-checks }}, ${{ inputs.verbosity }}, ${{ inputs.extensions }}, ${{ inputs.repo-root }}, ${{ inputs.lines-changed-only }}, ${{ inputs.files-changed-only }}, ${{ inputs.thread-comments }}, ${{ inputs.no-lgtm }}, ${{ inputs.step-summary }}, ${{ inputs.ignore }}, ${{ inputs.ignore-tidy }}, ${{ inputs.ignore-format }}, ${{ inputs.database }}, ${{ inputs.file-annotations }}, ${{ inputs.extra-args }}, ${{ inputs.tidy-review }}, ${{ inputs.format-review }}, ${{ inputs.passive-reviews }}, ${{ inputs.jobs }}, ${{ inputs.summary-output-file }}, and ${{ runner.os }}. These must be moved to env: variables and referenced as $env.VAR_NAME inside the Nu shell scripts.

Locations:

- `action.yml:246`
- `action.yml:247`
- `action.yml:263`
- `action.yml:271`
- `action.yml:285`
- `action.yml:291`
- `action.yml:294`
- `action.yml:316`
- `action.yml:330`
- `action.yml:349`
- `action.yml:353`
- `action.yml:381`
- `action.yml:382`
- `action.yml:383`
- `action.yml:384`
- `action.yml:385`
- `action.yml:386`
- `action.yml:387`
- `action.yml:388`
- `action.yml:389`
- `action.yml:390`
- `action.yml:391`
- `action.yml:392`
- `action.yml:393`
- `action.yml:394`
- `action.yml:395`
- `action.yml:396`
- `action.yml:397`
- `action.yml:398`
- `action.yml:399`
- `action.yml:400`
- `action.yml:401`
- `action.yml:402`
- `action.yml:416`

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

**Fixes applied:** script-injection, static-inline-injection

**Notes:**

Fixed all script injection findings by moving ${{ inputs.* }} and ${{ runner.os }} expressions from run: blocks to env: blocks in all four affected steps. Nu shell scripts now reference these values via $env.INPUT_* syntax (e.g., $env.INPUT_VERSION, $env.INPUT_VERBOSITY, etc.) instead of directly interpolating GitHub Actions expressions. Changes made to: (1) 'Install Linux clang dependencies' - added env: INPUT_VERSION, updated apt_install_args and llvm_install.sh invocations; (2) 'Install MacOS clang dependencies' - added env: INPUT_VERSION, updated brew_install_arg and ln -s commands; (3) 'Setup cpp-linter dependencies' - added INPUT_VERBOSITY, INPUT_VERSION, INPUT_TIDY_CHECKS, INPUT_STYLE to existing env: block, updated all references; (4) 'Run cpp-linter' - added full env: block with all 23 inputs plus RUNNER_OS_NAME, updated all args list entries and verbosity/PATH checks to use $env.* references.

### Iteration 2

**Fixes applied:** unsafe-shell

**Notes:**

Fixed the unsafe shell pattern in the 'Setup cpp-linter dependencies' step (action.yml ~line 295). The uv installer script was previously fetched via `http get` and piped directly to `^sh` (or passed as content to `^powershell`). The fix saves the downloaded script to a temporary file (`$env.RUNNER_TEMP | path join 'uv_installer'`) using `save --force`, then executes it with `^sh $installer_path` (or `^powershell -ExecutionPolicy ByPass $installer_path` on Windows). This ensures the script is written to disk before execution, eliminating the unsafe pipe-from-internet-to-shell pattern.

