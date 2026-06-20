<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.18.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `1`

Action **cpp-linter--cpp-linter-action/v2.18.0** was hardened automatically. 35 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a): Multiple ${{ inputs.* }} and ${{ runner.* }} expressions are directly interpolated inside run: shell command strings across four steps in action.yml. GitHub Actions substitutes these expressions before the Nu shell interpreter sees the script, so special characters in input values can alter script behavior. Affected steps: 'Install Linux clang dependencies' uses ${{ inputs.version }} in a list literal and as a command argument (e.g. `install -y clang-format-${{ inputs.version }}`); 'Install MacOS clang dependencies' uses ${{ inputs.version }} in string literals; 'Setup cpp-linter dependencies' uses ${{ inputs.verbosity }}, ${{ inputs.version }}, ${{ inputs.tidy-checks }}, ${{ inputs.style }}; 'Run cpp-linter' interpolates all inputs into a Nu list (e.g. '--style=${{ inputs.style }}') and uses ${{ runner.os }}.

Locations:

- `action.yml:253`
- `action.yml:278`
- `action.yml:292`
- `action.yml:355`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step downloads a remote installer script from astral.sh using Nu shell's `http get` and pipes the result directly to `^sh`: `$installer | ^sh`. This is equivalent to curl | sh — executing remotely-fetched content without saving or verifying it first. A compromised or MITM response could execute arbitrary code on the runner.

Locations:

- `action.yml:320`

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

**Fixes applied:** script-injection, static-inline-injection, unsafe-shell

**Notes:**

Fixed all script-injection and static-inline-injection findings by moving all ${{ inputs.* }} and ${{ runner.* }} expressions from run: blocks to env: blocks across four steps in action.yml:

1. 'Install Linux clang dependencies': Added env: block with CLANG_VERSION=${{ inputs.version }}, replaced inline expressions with $env.CLANG_VERSION in Nu shell script.

2. 'Install MacOS clang dependencies': Added env: block with CLANG_VERSION=${{ inputs.version }}, replaced inline expressions with $env.CLANG_VERSION in Nu shell script.

3. 'Setup cpp-linter dependencies': Added INPUT_VERBOSITY, INPUT_VERSION, INPUT_TIDY_CHECKS, INPUT_STYLE to env: block, replaced all inline expressions with $env.INPUT_* references. Also fixed the unsafe-shell issue: instead of piping the downloaded installer directly to ^sh ($installer | ^sh), the script is now saved to a file first (save --force $installer_path), executed from the file (^sh $installer_path), then cleaned up (rm --force $installer_path).

4. 'Run cpp-linter': Added all 22 inputs plus runner.os to env: block (INPUT_STYLE, INPUT_EXTENSIONS, INPUT_TIDY_CHECKS, INPUT_REPO_ROOT, INPUT_VERSION, INPUT_VERBOSITY, INPUT_LINES_CHANGED_ONLY, INPUT_FILES_CHANGED_ONLY, INPUT_THREAD_COMMENTS, INPUT_NO_LGTM, INPUT_STEP_SUMMARY, INPUT_IGNORE, INPUT_IGNORE_TIDY, INPUT_IGNORE_FORMAT, INPUT_DATABASE, INPUT_FILE_ANNOTATIONS, INPUT_EXTRA_ARGS, INPUT_TIDY_REVIEW, INPUT_FORMAT_REVIEW, INPUT_PASSIVE_REVIEWS, INPUT_JOBS, RUNNER_OS_NAME), replaced all inline expressions with $env.INPUT_* and $env.RUNNER_OS_NAME references in Nu shell script.

