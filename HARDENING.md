<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.21.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.21.0** was hardened automatically. 36 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple `${{ inputs.* }}` expressions are directly interpolated inside `run:` shell script blocks (rule a). GitHub Actions performs template substitution before the Nu shell processes the script, so attacker-controlled input values can inject arbitrary shell commands.

**"Install Linux clang dependencies" step**: `clang-format-${{ inputs.version }}` and `clang-tidy-${{ inputs.version }}` in a Nu list literal, and `${{ inputs.version }}` passed as argument to `llvm_install.sh`.

**"Install MacOS clang dependencies" step**: `'llvm@${{ inputs.version }}'`, `"/usr/local/bin/clang-format-${{ inputs.version }}"`, `"/usr/local/bin/clang-tidy-${{ inputs.version }}"`.

**"Setup cpp-linter dependencies" step**: `'${{ inputs.verbosity }}'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"`.

**"Run cpp-linter" step**: All action inputs are interpolated directly into Nu string literals for CLI args: `${{ inputs.style }}`, `${{ inputs.extensions }}`, `${{ inputs.tidy-checks }}`, `${{ inputs.repo-root }}`, `${{ inputs.version }}`, `${{ inputs.verbosity }}`, `${{ inputs.lines-changed-only }}`, `${{ inputs.files-changed-only }}`, `${{ inputs.thread-comments }}`, `${{ inputs.no-lgtm }}`, `${{ inputs.step-summary }}`, `${{ inputs.ignore }}`, `${{ inputs.ignore-tidy }}`, `${{ inputs.ignore-format }}`, `${{ inputs.database }}`, `${{ inputs.file-annotations }}`, `${{ inputs.extra-args }}`, `${{ inputs.tidy-review }}`, `${{ inputs.format-review }}`, `${{ inputs.passive-reviews }}`, `${{ inputs.jobs }}`, `${{ inputs.summary-output-file }}`, and `${{ runner.os }}` and `${{ inputs.verbosity }}` in conditional expressions.

Locations:

- `action.yml:237`
- `action.yml:255`
- `action.yml:256`
- `action.yml:274`
- `action.yml:278`
- `action.yml:279`
- `action.yml:305`
- `action.yml:316`
- `action.yml:325`
- `action.yml:327`
- `action.yml:353`
- `action.yml:354`
- `action.yml:355`
- `action.yml:356`
- `action.yml:357`
- `action.yml:358`
- `action.yml:359`
- `action.yml:360`
- `action.yml:361`
- `action.yml:362`
- `action.yml:363`
- `action.yml:364`
- `action.yml:365`
- `action.yml:366`
- `action.yml:367`
- `action.yml:368`
- `action.yml:369`
- `action.yml:370`
- `action.yml:371`
- `action.yml:372`
- `action.yml:373`
- `action.yml:374`
- `action.yml:385`
- `action.yml:386`

### unsafe-shell (severity: high)

The "Setup cpp-linter dependencies" step fetches a remote installer script from `https://astral.sh/uv/<version>/install.sh` via HTTP and pipes the response body directly to `sh` using `$installer | ^sh`. This is the classic unsafe shell pattern: remote content is executed without first being saved to disk and inspected. A compromised or MITM'd response could execute arbitrary code on the runner.

Locations:

- `action.yml:310`

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

Fixed all script-injection findings by moving every ${{ inputs.* }} and ${{ runner.os }} expression from run: blocks into env: blocks, then referencing them via $env.VAR_NAME in Nu shell scripts. Fixed the unsafe-shell finding in the 'Setup cpp-linter dependencies' step by saving the uv installer script to a temp file first (using Nu's 'save --force') before executing it with '^sh $installer_path', instead of piping directly to sh. All 35+ injection points across 4 steps (Install Linux clang dependencies, Install MacOS clang dependencies, Setup cpp-linter dependencies, Run cpp-linter) have been remediated.

