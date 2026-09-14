<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.22.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.22.0** was hardened automatically. 36 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple ${{ inputs.* }} expressions are interpolated directly into Nushell run: blocks. YAML template substitution occurs before the shell parses the script, so attacker-controlled input values containing Nushell metacharacters (e.g., `)`, `|`, `;`, string delimiters) can break out of their intended string context and execute arbitrary commands.

Affected steps and representative offending lines:
- 'Install Linux clang dependencies': `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}`
- 'Install MacOS clang dependencies': `let brew_install_arg = 'llvm@${{ inputs.version }}'` and `clang-format-${{ inputs.version }}`
- 'Setup cpp-linter dependencies': `'${{ inputs.verbosity }}' == 'debug'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"`
- 'Run cpp-linter': all `inputs.*` interpolated into Nushell string literals (e.g., `'--style=${{ inputs.style }}'`), plus `'${{ runner.os }}' == 'Linux'`

Locations:

- `action.yml:248`
- `action.yml:263`
- `action.yml:264`
- `action.yml:278`
- `action.yml:279`
- `action.yml:291`
- `action.yml:295`
- `action.yml:296`
- `action.yml:320`
- `action.yml:330`
- `action.yml:349`
- `action.yml:356`
- `action.yml:370`
- `action.yml:371`
- `action.yml:372`
- `action.yml:373`
- `action.yml:374`
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
- `action.yml:399`

### unsafe-shell (severity: high)

In the 'Setup cpp-linter dependencies' step, a remote installer script is fetched via HTTP and piped directly to a shell interpreter without saving to a file first: `let installer = http get --raw --redirect-mode follow $uv_installer_url` followed by `$installer | ^sh`. This allows a compromised or malicious remote server to execute arbitrary code on the runner. The script should be saved to a file, verified (e.g., checksum), and then executed separately.

Locations:

- `action.yml:336`

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

Fixed all script-injection and static-inline-injection findings by moving every ${{ inputs.* }} and ${{ runner.os }} expression out of Nushell run: blocks and into env: blocks. The Nushell scripts now reference these values via $env.INPUT_* and $env.RUNNER_OS_NAME variables. Fixed the unsafe-shell finding in 'Setup cpp-linter dependencies' by saving the remote installer script to a file ($env.RUNNER_TEMP/uv_installer) before executing it with ^sh, instead of piping the HTTP response directly to ^sh.

