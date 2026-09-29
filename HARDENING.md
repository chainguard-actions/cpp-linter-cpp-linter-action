<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.21.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.21.0** was hardened automatically. 36 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Sub-rule (a): Multiple run: blocks in action.yml directly interpolate ${{ inputs.* }} and ${{ runner.* }} expressions inside Nu shell scripts. GitHub Actions performs template substitution before the shell sees the script, so a caller-controlled input value containing Nu shell metacharacters (e.g. quotes, parentheses, pipe characters) can break out of the intended string context and execute arbitrary commands.

Affected occurrences:
- 'Install Linux clang dependencies' step: `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `${{ inputs.version }}` passed as arguments to llvm_install.sh
- 'Install MacOS clang dependencies' step: `'llvm@${{ inputs.version }}'`, `"/usr/local/bin/clang-format-${{ inputs.version }}"`, `"/usr/local/bin/clang-tidy-${{ inputs.version }}"`
- 'Setup cpp-linter dependencies' step: `'${{ inputs.verbosity }}'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"`
- 'Run cpp-linter' step: all `${{ inputs.* }}` values interpolated into the args list (style, extensions, tidy-checks, repo-root, version, verbosity, lines-changed-only, files-changed-only, thread-comments, no-lgtm, step-summary, ignore, ignore-tidy, ignore-format, database, file-annotations, extra-args, tidy-review, format-review, passive-reviews, jobs, summary-output-file) and `'${{ runner.os }}'`

Fix: move all inputs into env: variables and reference them via $env.VAR_NAME inside the Nu shell scripts, never interpolating ${{ }} directly into run: script text.

Locations:

- `action.yml:219`
- `action.yml:235`
- `action.yml:237`
- `action.yml:252`
- `action.yml:256`
- `action.yml:257`
- `action.yml:285`
- `action.yml:291`
- `action.yml:307`
- `action.yml:310`
- `action.yml:328`
- `action.yml:362`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' run: block fetches a remote installer script (from astral.sh) using `http get` and pipes the response body directly to `^sh` without first saving it to disk for inspection: `$installer | ^sh`. This is the classic 'curl | sh' anti-pattern — if the remote server is compromised or the URL is intercepted (e.g. via MITM or DNS hijacking), arbitrary code will execute on the runner. The fix is to save the installer to a temporary file, verify its integrity (e.g. checksum), and then execute it separately.

Locations:

- `action.yml:281`

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

**Fixes applied:** script-injection, unsafe-shell, static-inline-injection

**Notes:**

Fixed all script-injection and static-inline-injection findings by moving every ${{ inputs.* }} and ${{ runner.* }} expression out of run: blocks into env: blocks, then referencing them via $env.VAR_NAME in the Nu shell scripts. Fixed the unsafe-shell finding in 'Setup cpp-linter dependencies' by saving the downloaded installer script to a temp file (RUNNER_TEMP/uv_installer) and executing it with ^sh $installer_path instead of piping directly to ^sh. All four affected steps (Install Linux clang dependencies, Install MacOS clang dependencies, Setup cpp-linter dependencies, Run cpp-linter) have been updated.

