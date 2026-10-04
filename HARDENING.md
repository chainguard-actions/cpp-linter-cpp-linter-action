<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.18.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.18.0** was hardened automatically. 35 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Sub-rule (a): Multiple ${{ inputs.* }} expressions are directly interpolated into run: shell scripts across four steps in action.yml. GitHub Actions performs template substitution before the Nushell interpreter ever sees the script, so an attacker-controlled input value can inject arbitrary shell commands.

• 'Install Linux clang dependencies' step: `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `${{ inputs.version }}` passed directly to the LLVM installer.
• 'Install MacOS clang dependencies' step: `'llvm@${{ inputs.version }}'` and `/usr/local/bin/clang-format-${{ inputs.version }}`.
• 'Setup cpp-linter dependencies' step: `'${{ inputs.verbosity }}' == 'debug'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"`.
• 'Run cpp-linter' step: all CLI args built from `${{ inputs.style }}`, `${{ inputs.extensions }}`, `${{ inputs.tidy-checks }}`, `${{ inputs.repo-root }}`, `${{ inputs.version }}`, `${{ inputs.verbosity }}`, `${{ inputs.lines-changed-only }}`, `${{ inputs.files-changed-only }}`, `${{ inputs.thread-comments }}`, `${{ inputs.no-lgtm }}`, `${{ inputs.step-summary }}`, `${{ inputs.ignore }}`, `${{ inputs.ignore-tidy }}`, `${{ inputs.ignore-format }}`, `${{ inputs.database }}`, `${{ inputs.file-annotations }}`, `${{ inputs.extra-args }}`, `${{ inputs.tidy-review }}`, `${{ inputs.format-review }}`, `${{ inputs.passive-reviews }}`, `${{ inputs.jobs }}`, and `${{ runner.os }}`.

Fix: move all inputs into env: variables and reference them as Nushell env vars (e.g., `$env.INPUT_VERSION`) so that template substitution never touches the run: script body.

Locations:

- `action.yml:248`
- `action.yml:265`
- `action.yml:266`
- `action.yml:278`
- `action.yml:282`
- `action.yml:283`
- `action.yml:310`
- `action.yml:319`
- `action.yml:330`
- `action.yml:334`
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
- `action.yml:375`
- `action.yml:376`
- `action.yml:377`
- `action.yml:378`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step fetches a remote installer script via HTTP and pipes its content directly to a shell interpreter. In Nushell syntax: `let installer = http get --raw --redirect-mode follow $uv_installer_url` followed by `$installer | ^sh`. This is functionally equivalent to `curl https://astral.sh/uv/.../install.sh | sh` — a classic unsafe-shell pattern. If the remote server is compromised or the request is intercepted (MITM), arbitrary code executes on the runner. The script should be downloaded to a file first, its integrity verified (e.g., checksum), and then executed separately.

Locations:

- `action.yml:315`

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

Fixed all script-injection and static-inline-injection findings by moving all ${{ inputs.* }} and ${{ runner.os }} expressions from run: blocks into env: blocks in all four affected steps (Install Linux clang dependencies, Install MacOS clang dependencies, Setup cpp-linter dependencies, Run cpp-linter). In each step, Nushell scripts now reference values via $env.VAR_NAME instead of inline template substitution. Fixed the unsafe-shell finding in the Setup cpp-linter dependencies step by downloading the uv installer script to a file first (using `save --force`) and then executing it with `^sh $uv_installer_path`, rather than piping the downloaded content directly to `^sh`.

