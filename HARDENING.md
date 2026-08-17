<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.18.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.18.0** was hardened automatically. 35 finding(s) were identified and resolved across 2 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple `${{ ... }}` expressions are interpolated directly inside `run:` shell command strings (Nu shell), violating rule (a). This allows an attacker who controls input values to inject arbitrary shell commands.

**Install Linux clang dependencies** step: `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` and `^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}` / `^bash $"($action_path)/llvm_install.sh" ${{ inputs.version }}` — `inputs.version` interpolated directly into the Nu shell run block.

**Install MacOS clang dependencies** step: `let brew_install_arg = 'llvm@${{ inputs.version }}'` and `"/usr/local/bin/clang-format-${{ inputs.version }}"` — `inputs.version` interpolated directly.

**Setup cpp-linter dependencies** step: `'${{ inputs.verbosity }}' == 'debug'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"` — multiple inputs interpolated directly.

**Run cpp-linter** step: All inputs (`inputs.style`, `inputs.extensions`, `inputs.tidy-checks`, `inputs.repo-root`, `inputs.version`, `inputs.verbosity`, `inputs.lines-changed-only`, `inputs.files-changed-only`, `inputs.thread-comments`, `inputs.no-lgtm`, `inputs.step-summary`, `inputs.ignore`, `inputs.ignore-tidy`, `inputs.ignore-format`, `inputs.database`, `inputs.file-annotations`, `inputs.extra-args`, `inputs.tidy-review`, `inputs.format-review`, `inputs.passive-reviews`, `inputs.jobs`) and `runner.os` are interpolated directly into the Nu shell run block as string literals.

Locations:

- `action.yml:247`
- `action.yml:263`
- `action.yml:284`
- `action.yml:286`
- `action.yml:325`
- `action.yml:332`
- `action.yml:376`

### unsafe-shell (severity: high)

In the **Setup cpp-linter dependencies** step, the uv installer script is fetched from a remote URL (`https://astral.sh/uv/<version>/install.sh`) using `http get` and then piped directly to `^sh` via `$installer | ^sh`. This executes remotely-fetched content in a shell without first saving it to a file and verifying its integrity, matching the unsafe-shell pattern of piping remote content to a shell interpreter.

Locations:

- `action.yml:322`

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

Fixed all security findings in hardened/action/action.yml:

1. **script-injection / static-inline-injection**: Moved all ${{ inputs.* }} and ${{ runner.os }} expressions out of Nu shell run: blocks into env: blocks. The Nu shell scripts now reference these values via $env.VAR_NAME:
   - 'Install Linux clang dependencies': INPUT_VERSION env var replaces ${{ inputs.version }} in run block
   - 'Install MacOS clang dependencies': INPUT_VERSION env var replaces ${{ inputs.version }} in run block
   - 'Setup cpp-linter dependencies': Added INPUT_VERBOSITY, INPUT_VERSION, INPUT_TIDY_CHECKS, INPUT_STYLE env vars
   - 'Run cpp-linter': Added 22 env vars (all inputs + RUNNER_OS_NAME) replacing all ${{ }} expressions in run block

2. **unsafe-shell**: Fixed the uv installer pipe-to-shell pattern. Instead of `let installer = http get ... | ^sh`, the script now saves the installer to a file first (`http get ... | save --force $installer_path`) and then executes it with `^sh $installer_path`. For Windows, the content is read from the saved file before passing to PowerShell.

### Iteration 2

**Fixes applied:** script-injection, unpinned-uses, missing-permissions

**Notes:**

Fixed all 5 findings across 11 workflow files:

1. script-injection (release.yml line 34): Moved inputs.tag into env var INPUT_TAG, used ${INPUT_TAG:-$MAJOR_VERSION} in shell.
2. script-injection (cpp-linter.yml line 24): Moved steps.linter.outputs.checks-failed into env var CHECKS_FAILED.
3. script-injection (self-test.yml line 57): Moved all three linter output expressions into env vars (CHECKS_FAILED, CLANG_TIDY_CHECKS_FAILED, CLANG_FORMAT_CHECKS_FAILED).
4. unpinned-uses: Pinned cpp-linter/cpp-linter-action@main→SHA, actions/cache@v5→SHA, actions/checkout@v5→SHA (examples), cpp-linter/cpp-linter-action@v2→SHA (examples), and all cpp-linter/.github reusable workflows @main→SHA.
5. missing-permissions: Added permissions: {} at top level to cpp-linter.yml, mkdocs-deploy.yml, pre-commit.yml, examples/only-clang-format.yml, and examples/only-clang-tidy.yml; added minimal job-level permissions where needed.

