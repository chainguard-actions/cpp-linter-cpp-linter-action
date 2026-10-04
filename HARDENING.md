<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.17.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.17.1** was hardened automatically. 33 finding(s) were identified and resolved across 2 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple `${{ inputs.* }}` and `${{ runner.os }}` expressions are directly interpolated inside `run:` shell command strings (sub-rule a). YAML template substitution occurs before the nushell interpreter sees the value, allowing an attacker who controls these inputs to inject arbitrary shell commands.

Affected occurrences:
- 'Install Linux clang dependencies' step: `clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` in apt_install_args list; `${{ inputs.version }}` passed directly to `llvm_install.sh`.
- 'Install MacOS clang dependencies' step: `'llvm@${{ inputs.version }}'` in brew_install_arg; `clang-format-${{ inputs.version }}` and `clang-tidy-${{ inputs.version }}` in ln -s commands.
- 'Setup cpp-linter dependencies' step: `'${{ inputs.verbosity }}' == 'debug'` comparison; `${{ inputs.version }}` in clang-tools command list.
- 'Run cpp-linter' step: all inputs (`style`, `extensions`, `tidy-checks`, `repo-root`, `version`, `verbosity`, `lines-changed-only`, `files-changed-only`, `thread-comments`, `no-lgtm`, `step-summary`, `ignore`, `ignore-tidy`, `ignore-format`, `database`, `file-annotations`, `extra-args`, `tidy-review`, `format-review`, `passive-reviews`, `jobs`) interpolated directly into the args array; `'${{ inputs.verbosity }}' == 'debug'`; `'${{ runner.os }}' == 'Linux'`.

Locations:

- `action.yml:248`
- `action.yml:249`
- `action.yml:263`
- `action.yml:267`
- `action.yml:280`
- `action.yml:285`
- `action.yml:286`
- `action.yml:313`
- `action.yml:323`
- `action.yml:325`
- `action.yml:340`
- `action.yml:341`
- `action.yml:342`
- `action.yml:343`
- `action.yml:344`
- `action.yml:345`
- `action.yml:346`
- `action.yml:347`
- `action.yml:348`
- `action.yml:349`
- `action.yml:350`
- `action.yml:351`
- `action.yml:352`
- `action.yml:353`
- `action.yml:354`
- `action.yml:355`
- `action.yml:356`
- `action.yml:357`
- `action.yml:358`
- `action.yml:359`
- `action.yml:360`
- `action.yml:369`
- `action.yml:376`

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

**Fixes applied:** script-injection, static-inline-injection

**Notes:**

Fixed all script injection vulnerabilities in action.yml by moving ${{ inputs.* }} and ${{ runner.os }} expressions from run: shell script bodies into env: blocks, then referencing them as $env.INPUT_* nushell environment variables.

1. 'Install Linux clang dependencies': Added env: { INPUT_VERSION } block; replaced ${{ inputs.version }} in apt_install_args list and llvm_install.sh invocations with nushell variable $version (assigned from $env.INPUT_VERSION).

2. 'Install MacOS clang dependencies': Added env: { INPUT_VERSION } block; replaced ${{ inputs.version }} in brew_install_arg and ln -s path strings with nushell interpolation using $version.

3. 'Setup cpp-linter dependencies': Added INPUT_VERBOSITY and INPUT_VERSION to existing env: block; replaced '${{ inputs.verbosity }}' == 'debug' with $env.INPUT_VERBOSITY == 'debug'; replaced ${{ inputs.version }} in clang-tools command with $version from $env.INPUT_VERSION.

4. 'Run cpp-linter': Added full env: block with all 21 inputs plus RUNNER_OS_NAME=${{ runner.os }}; replaced all ${{ inputs.* }} in args array with $"--flag=($env.INPUT_*)" nushell string interpolation; replaced '${{ inputs.verbosity }}' == 'debug' with $env.INPUT_VERBOSITY == 'debug'; replaced '${{ runner.os }}' == 'Linux' with $env.RUNNER_OS_NAME == 'Linux'.

### Iteration 2

**Fixes applied:** unsafe-shell

**Notes:**

Fixed the 'Setup cpp-linter dependencies' step in action.yml. The original code used Nu shell's `http get` to fetch the uv installer script into a variable and then piped it directly to `^sh` (or passed it directly to `^powershell` on Windows). The fix saves the downloaded installer to a temporary file using `$nu.temp-path | path join "uv-installer.(ext)"` and `save --force`, then executes the saved file with `^sh $installer_path` or `^powershell -ExecutionPolicy ByPass -File $installer_path` respectively. This eliminates the pipe-remote-content-to-shell anti-pattern.

