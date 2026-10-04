<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.18.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.18.0** was hardened automatically. 35 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a) violation: Multiple ${{ inputs.* }} and ${{ runner.* }} expressions are directly interpolated inside run: shell command strings across four steps in action.yml. GitHub Actions performs YAML template substitution before the shell ever sees the string, so an attacker-controlled input value can inject arbitrary shell metacharacters.

Affected lines and expressions:
- 'Install Linux clang dependencies' step: `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` (used as a Nu shell list literal), and `${{ inputs.version }}` passed as a positional argument to llvm_install.sh.
- 'Install MacOS clang dependencies' step: `let brew_install_arg = 'llvm@${{ inputs.version }}'`, and `"/usr/local/bin/clang-format-${{ inputs.version }}"` / `"/usr/local/bin/clang-tidy-${{ inputs.version }}"`.
- 'Setup cpp-linter dependencies' step: `let version_str = '${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}" != "-*"`, `"${{ inputs.style }}" | is-not-empty`, `'${{ inputs.verbosity }}' == 'debug'`.
- 'Run cpp-linter' step: All inputs interpolated directly into the args list strings (e.g. `'--style=${{ inputs.style }}'`, `'--extensions=${{ inputs.extensions }}'`, `'--tidy-checks=${{ inputs.tidy-checks }}'`, etc.) and `'${{ runner.os }}' == 'Linux'`.

Locations:

- `action.yml:248`
- `action.yml:268`
- `action.yml:269`
- `action.yml:278`
- `action.yml:281`
- `action.yml:285`
- `action.yml:286`
- `action.yml:310`
- `action.yml:330`
- `action.yml:334`
- `action.yml:338`
- `action.yml:356`
- `action.yml:358`
- `action.yml:375`
- `action.yml:376`
- `action.yml:377`
- `action.yml:378`
- `action.yml:379`
- `action.yml:380`
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
- `action.yml:404`
- `action.yml:407`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step fetches a remote installer script from https://astral.sh/uv/{version}/install.sh using `http get` and pipes the result directly to `^sh` without first saving it to a file and verifying its integrity. Pattern: `$installer | ^sh`. This allows a compromised or MITM'd remote server to execute arbitrary code on the runner.

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

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:403`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:407`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:439`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:440`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:441`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:442`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:443`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:444`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.lines-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:445`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.files-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:446`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.thread-comments }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:447`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.no-lgtm }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:448`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.step-summary }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:449`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:450`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-tidy }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:451`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-format }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:452`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.database }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:453`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.file-annotations }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:454`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extra-args }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:455`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:456`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.format-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:457`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.passive-reviews }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:458`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.jobs }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:459`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:464`

## Iteration Notes

### Iteration 1

**Fixes applied:** script-injection, unsafe-shell, static-inline-injection

**Notes:**

Fixed all script-injection and static-inline-injection findings by moving every ${{ inputs.* }} and ${{ runner.* }} expression from run: shell strings into env: blocks for all four affected steps (Install Linux clang dependencies, Install MacOS clang dependencies, Setup cpp-linter dependencies, Run cpp-linter). In Nu shell, these are referenced as $env.VAR_NAME. Fixed the unsafe-shell finding by replacing the `$installer | ^sh` pipe pattern with saving the installer to a file first (http get ... | save --force $installer_path) and then executing it as a file (^sh $installer_path), preventing MITM attacks from executing arbitrary code via piped shell execution.

