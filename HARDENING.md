<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.21.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.21.0** was hardened automatically. 39 finding(s) were identified and resolved across 2 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a) violation: Multiple ${{ inputs.* }} and ${{ runner.* }} expressions are interpolated directly inside run: blocks in action.yml (Nushell shell scripts). This allows an attacker-controlled input to inject arbitrary shell commands. Affected steps include 'Install Linux clang dependencies' (e.g. `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}`, `^sudo $"($action_path)/llvm_install.sh" ${{ inputs.version }}`), 'Install MacOS clang dependencies' (e.g. `let brew_install_arg = 'llvm@${{ inputs.version }}'`), 'Setup cpp-linter dependencies' (e.g. `let version_str = '${{ inputs.version }}'`, `if ("${{ inputs.tidy-checks }}" != "-*")`, `if ("${{ inputs.style }}" | is-not-empty)`), and 'Run cpp-linter' (e.g. `'--style=${{ inputs.style }}'`, `'--extensions=${{ inputs.extensions }}'`, `'${{ runner.os }}' == 'Linux'`, and all other --flag=${{ inputs.* }} lines).

Locations:

- `action.yml:249`
- `action.yml:250`
- `action.yml:271`
- `action.yml:274`
- `action.yml:285`
- `action.yml:288`
- `action.yml:291`
- `action.yml:316`
- `action.yml:330`
- `action.yml:349`
- `action.yml:353`
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
- `action.yml:394`
- `action.yml:395`
- `action.yml:396`
- `action.yml:414`

### script-injection (severity: high)

Rule (a) violation in .github/workflows/release.yml: ${{ inputs.tag }} and ${{ inputs.ref }} are interpolated directly inside run: shell commands. Specifically: `git tag --force --annotate ${{ inputs.tag || '$MAJOR_VERSION' }} --message 'Retag ${{ inputs.tag || '$MAJOR_VERSION' }}'` and `git push origin ${{ inputs.tag || '$MAJOR_VERSION' }} --force`. An attacker with workflow_dispatch access can inject arbitrary git commands.

Locations:

- `.github/workflows/release.yml:34`
- `.github/workflows/release.yml:35`
- `.github/workflows/release.yml:36`

### script-injection (severity: high)

Rule (a) violation in .github/workflows/self-test.yml: ${{ steps.linter.outputs.checks-failed }}, ${{ steps.linter.outputs.clang-tidy-checks-failed }}, and ${{ steps.linter.outputs.clang-format-checks-failed }} are interpolated directly inside a run: shell command (echo statements). Step outputs can contain attacker-controlled content from PR events.

Locations:

- `.github/workflows/self-test.yml:62`
- `.github/workflows/self-test.yml:63`
- `.github/workflows/self-test.yml:64`

### unpinned-uses (severity: high)

Multiple workflow files reference actions/reusable workflows using mutable tag or branch refs instead of full 40-character SHA commit hashes, making them vulnerable to supply-chain attacks:
- .github/workflows/cpp-linter.yml: `cpp-linter/cpp-linter-action@main`
- .github/workflows/labeler.yml: `cpp-linter/.github/.github/workflows/pr-labeler.yml@main`
- .github/workflows/mkdocs-deploy.yml: `cpp-linter/.github/.github/workflows/mkdocs.yml@main`
- .github/workflows/pre-commit.yml: `cpp-linter/.github/.github/workflows/pre-commit.yml@main`
- .github/workflows/release-drafter.yml: `cpp-linter/.github/.github/workflows/release-drafter.yml@main`
- .github/workflows/stale.yml: `cpp-linter/.github/.github/workflows/stale.yml@main`
- .github/workflows/examples/only-PR-comments.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`
- .github/workflows/examples/only-clang-format.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`
- .github/workflows/examples/only-clang-tidy.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`

Locations:

- `.github/workflows/cpp-linter.yml:18`
- `.github/workflows/labeler.yml:13`
- `.github/workflows/mkdocs-deploy.yml:11`
- `.github/workflows/pre-commit.yml:10`
- `.github/workflows/release-drafter.yml:13`
- `.github/workflows/stale.yml:11`
- `.github/workflows/examples/only-PR-comments.yml:14`
- `.github/workflows/examples/only-PR-comments.yml:17`
- `.github/workflows/examples/only-clang-format.yml:13`
- `.github/workflows/examples/only-clang-format.yml:16`
- `.github/workflows/examples/only-clang-tidy.yml:13`
- `.github/workflows/examples/only-clang-tidy.yml:16`

### missing-permissions (severity: medium)

Several workflow files have no top-level `permissions:` key and no job-level `permissions:` key on any job, meaning they run with the default (potentially broad) token permissions:
- .github/workflows/cpp-linter.yml: no top-level permissions, no job-level permissions on the `cpp-linter` job.
- .github/workflows/mkdocs-deploy.yml: no top-level permissions, no job-level permissions on the `build-docs` job.
- .github/workflows/pre-commit.yml: no top-level permissions, no job-level permissions on the `pre-commit` job.
- .github/workflows/examples/only-clang-format.yml: no top-level permissions, no job-level permissions on the `cpp-linter` job.
- .github/workflows/examples/only-clang-tidy.yml: no top-level permissions, no job-level permissions on the `cpp-linter` job.

Locations:

- `.github/workflows/cpp-linter.yml:1`
- `.github/workflows/mkdocs-deploy.yml:1`
- `.github/workflows/pre-commit.yml:1`
- `.github/workflows/examples/only-clang-format.yml:1`
- `.github/workflows/examples/only-clang-tidy.yml:1`

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

**Fixes applied:** script-injection, static-inline-injection, unpinned-uses, missing-permissions

**Notes:**

Fixed all findings:

1. **script-injection / static-inline-injection in action.yml**: Moved all ${{ inputs.* }} and ${{ runner.* }} expressions from run: blocks into env: blocks for all four affected steps ('Install Linux clang dependencies', 'Install MacOS clang dependencies', 'Setup cpp-linter dependencies', 'Run cpp-linter'). Nushell scripts now reference $env.INPUT_VERSION, $env.INPUT_VERBOSITY, $env.RUNNER_OS_NAME, etc.

2. **script-injection in release.yml**: Moved ${{ inputs.tag }} to env: block as INPUT_TAG; replaced backtick command substitution with $() and properly quoted all variables.

3. **script-injection in self-test.yml**: Moved ${{ steps.linter.outputs.* }} expressions to env: block (CHECKS_FAILED, TIDY_CHECKS_FAILED, FORMAT_CHECKS_FAILED) and referenced them as plain env vars in the run: block.

4. **unpinned-uses**: Pinned all mutable refs to full SHA commits:
   - cpp-linter/cpp-linter-action@main and @v2 → @cab1143a2c149bc41e85b070a9de81716974c18f
   - actions/checkout@v5 → @fbc6f3992d24b796d5a048ff273f7fcc4a7b6c09
   - All cpp-linter/.github reusable workflows @main → @f3f3c766170cc625ccc900fcec546bff75d2e0f0

5. **missing-permissions**: Added `permissions: {}` top-level block to cpp-linter.yml, mkdocs-deploy.yml, pre-commit.yml, only-clang-format.yml, and only-clang-tidy.yml.

### Iteration 2

**Fixes applied:** script-injection, unsafe-shell

**Notes:**

1. script-injection (.github/workflows/cpp-linter.yml line 33): Moved `${{ steps.linter.outputs.checks-failed }}` out of the run: block into an env: block as CHECKS_FAILED, and updated the echo command to reference $CHECKS_FAILED instead.
2. unsafe-shell (action.yml ~line 360): Replaced the pattern of fetching the uv installer and piping it directly to ^sh (`$installer | ^sh`) with a safe two-step approach: save the downloaded content to a file (`$env.RUNNER_TEMP | path join 'uv_installer'`) using `http get ... | save --force $installer_path`, then execute it with `^sh $installer_path`. The Windows PowerShell path was similarly updated to read from the saved file.

