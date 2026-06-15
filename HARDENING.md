<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.17.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `1`

Action **cpp-linter--cpp-linter-action/v2.17.1** was hardened automatically. 34 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Sub-rule (a): Multiple ${{ ... }} expressions are directly interpolated inside run: shell command strings in action.yml. In the 'Install Linux clang dependencies' step, ${{ inputs.version }} is embedded directly in the nu shell script (e.g., `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}`). In the 'Install MacOS clang dependencies' step, ${{ inputs.version }} is used in `let brew_install_arg = 'llvm@${{ inputs.version }}'` and in ln commands. In the 'Setup cpp-linter dependencies' step, ${{ inputs.version }} and ${{ inputs.verbosity }} are interpolated directly. In the 'Run cpp-linter' step, all inputs (style, extensions, tidy-checks, repo-root, version, verbosity, lines-changed-only, files-changed-only, thread-comments, no-lgtm, step-summary, ignore, ignore-tidy, ignore-format, database, file-annotations, extra-args, tidy-review, format-review, passive-reviews, jobs) are directly interpolated into the args list, and ${{ runner.os }} is also interpolated. Any of these inputs could contain shell metacharacters that execute arbitrary commands.

Locations:

- `action.yml:232`
- `action.yml:261`
- `action.yml:278`
- `action.yml:302`
- `action.yml:330`

### unsafe-shell (severity: high)

In the 'Setup cpp-linter dependencies' step, the uv installer script is fetched from a remote URL (https://astral.sh/uv/.../install.sh) using `http get` and the response content is piped directly to `^sh` for execution (`$installer | ^sh`). This matches the unsafe-shell pattern of downloading and immediately executing remote content without first saving it to a file and verifying it.

Locations:

- `action.yml:302`

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

Fixed all script-injection and static-inline-injection findings by moving every ${{ inputs.* }} and ${{ runner.os }} expression from run: blocks into env: blocks, then referencing them via $env.INPUT_* variables in nu shell syntax. Fixed the unsafe-shell finding in 'Setup cpp-linter dependencies' by saving the downloaded uv installer to a temp file ($env.RUNNER_TEMP/uv_installer) before executing it with ^sh, instead of piping directly with $installer | ^sh. All four affected steps were updated: 'Install Linux clang dependencies', 'Install MacOS clang dependencies', 'Setup cpp-linter dependencies', and 'Run cpp-linter'.

