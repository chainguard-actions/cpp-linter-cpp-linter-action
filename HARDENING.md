<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.17.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.17.1** was hardened automatically. 39 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Sub-rule (a): Multiple ${{ inputs.* }} expressions are directly interpolated inside run: blocks in action.yml (nu shell scripts). In the 'Install Linux clang dependencies' step, `${{ inputs.version }}` is embedded directly in a nu shell array literal used as apt-get arguments. In the 'Install MacOS clang dependencies' step, `${{ inputs.version }}` is embedded in brew install arguments and symlink paths. In the 'Setup cpp-linter dependencies' step, `${{ inputs.verbosity }}` and `${{ inputs.version }}` are embedded directly. In the 'Run cpp-linter' step, all inputs (style, extensions, tidy-checks, repo-root, version, verbosity, lines-changed-only, files-changed-only, thread-comments, no-lgtm, step-summary, ignore, ignore-tidy, ignore-format, database, file-annotations, extra-args, tidy-review, format-review, passive-reviews, jobs) and `${{ runner.os }}` are interpolated directly into the run: script. Any of these inputs can contain shell metacharacters or newlines that are interpreted before the nu shell parses the script.

Locations:

- `action.yml:248`
- `action.yml:271`
- `action.yml:280`
- `action.yml:295`
- `action.yml:300`
- `action.yml:310`
- `action.yml:316`
- `action.yml:330`
- `action.yml:340`
- `action.yml:348`
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
- `action.yml:379`
- `action.yml:380`
- `action.yml:395`

### script-injection (severity: high)

Sub-rule (a): In .github/workflows/release.yml, the 'Update rolling tag' step directly interpolates `${{ inputs.tag || '$MAJOR_VERSION' }}` into git tag and git push shell commands, and the checkout step uses `${{ inputs.ref }}`. An attacker-controlled `inputs.tag` value (via workflow_dispatch) could inject arbitrary shell commands into the git tag --annotate --message argument and the git push command.

Locations:

- `.github/workflows/release.yml:30`
- `.github/workflows/release.yml:34`
- `.github/workflows/release.yml:35`
- `.github/workflows/release.yml:36`

### script-injection (severity: high)

Sub-rule (a): In .github/workflows/cpp-linter.yml, the 'Fail fast?!' step directly interpolates `${{ steps.linter.outputs.checks-failed }}` inside an echo command in a run: block. Step outputs are workflow-controllable and must not be interpolated directly into shell scripts.

Locations:

- `.github/workflows/cpp-linter.yml:24`

### script-injection (severity: high)

Sub-rule (a): In .github/workflows/self-test.yml, the 'Fail fast?!' step directly interpolates `${{ steps.linter.outputs.checks-failed }}`, `${{ steps.linter.outputs.clang-tidy-checks-failed }}`, and `${{ steps.linter.outputs.clang-format-checks-failed }}` inside echo commands in a run: block. Step outputs are workflow-controllable and must not be interpolated directly into shell scripts.

Locations:

- `.github/workflows/self-test.yml:62`
- `.github/workflows/self-test.yml:63`
- `.github/workflows/self-test.yml:64`

### unpinned-uses (severity: high)

Multiple workflow files reference actions or reusable workflows using mutable tag or branch refs instead of pinned full-length SHA commits:
- cpp-linter.yml: `cpp-linter/cpp-linter-action@main` (branch ref)
- self-test.yml: `actions/cache@v5` (tag ref)
- labeler.yml: `cpp-linter/.github/.github/workflows/pr-labeler.yml@main` (branch ref)
- mkdocs-deploy.yml: `cpp-linter/.github/.github/workflows/mkdocs.yml@main` (branch ref)
- pre-commit.yml: `cpp-linter/.github/.github/workflows/pre-commit.yml@main` (branch ref)
- release-drafter.yml: `cpp-linter/.github/.github/workflows/release-drafter.yml@main` (branch ref)
- stale.yml: `cpp-linter/.github/.github/workflows/stale.yml@main` (branch ref)
- examples/only-PR-comments.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`
- examples/only-clang-format.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`
- examples/only-clang-tidy.yml: `actions/checkout@v5`, `cpp-linter/cpp-linter-action@v2`

Locations:

- `.github/workflows/cpp-linter.yml:16`
- `.github/workflows/self-test.yml:30`
- `.github/workflows/labeler.yml:11`
- `.github/workflows/mkdocs-deploy.yml:10`
- `.github/workflows/pre-commit.yml:9`
- `.github/workflows/release-drafter.yml:12`
- `.github/workflows/stale.yml:9`
- `.github/workflows/examples/only-PR-comments.yml:13`
- `.github/workflows/examples/only-PR-comments.yml:16`
- `.github/workflows/examples/only-clang-format.yml:13`
- `.github/workflows/examples/only-clang-format.yml:16`
- `.github/workflows/examples/only-clang-tidy.yml:13`
- `.github/workflows/examples/only-clang-tidy.yml:16`

### missing-permissions (severity: medium)

Several workflow files have no top-level `permissions:` key and at least one job also has no `permissions:` key, meaning the default (broad) token permissions apply:
- cpp-linter.yml: no top-level permissions, the `cpp-linter` job has no job-level permissions block.
- mkdocs-deploy.yml: no top-level permissions, the `build-docs` job has no job-level permissions block.
- pre-commit.yml: no top-level permissions, the `pre-commit` job has no job-level permissions block.
- examples/only-clang-format.yml: no top-level permissions, the `cpp-linter` job has no job-level permissions block.
- examples/only-clang-tidy.yml: no top-level permissions, the `cpp-linter` job has no job-level permissions block.

Locations:

- `.github/workflows/cpp-linter.yml:1`
- `.github/workflows/mkdocs-deploy.yml:1`
- `.github/workflows/pre-commit.yml:1`
- `.github/workflows/examples/only-clang-format.yml:1`
- `.github/workflows/examples/only-clang-tidy.yml:1`

### unsafe-shell (severity: high)

In action.yml, the 'Setup cpp-linter dependencies' step downloads a remote installer script via `http get --raw --redirect-mode follow $uv_installer_url` and pipes the result directly to `^sh` (the shell) without first saving it to a file for inspection. This is the nushell equivalent of `curl URL | sh`, which allows a compromised or malicious remote server to execute arbitrary code on the runner. The URL is constructed from the `UV_VERSION` env var (set to a literal in the same step), but the pattern itself is unsafe.

Locations:

- `action.yml:325`

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

**Fixes applied:** script-injection, unpinned-uses, missing-permissions, unsafe-shell, static-inline-injection

**Notes:**

Fixed all findings across action.yml and multiple workflow files:

1. **script-injection / static-inline-injection (action.yml)**: Moved all ${{ inputs.* }} and ${{ runner.os }} expressions out of run: blocks into env: blocks for all four affected steps. Nu shell scripts now reference values via $env.INPUT_* variables.

2. **script-injection (release.yml)**: Moved ${{ inputs.tag }} to env: block as INPUT_TAG; shell script uses ${INPUT_TAG:-$MAJOR_VERSION} safely with proper quoting.

3. **script-injection (cpp-linter.yml)**: Moved ${{ steps.linter.outputs.checks-failed }} to env: block as CHECKS_FAILED.

4. **script-injection (self-test.yml)**: Moved all three ${{ steps.linter.outputs.* }} expressions to env: block.

5. **unpinned-uses**: Pinned all mutable tag/branch refs to full commit SHAs: cpp-linter/cpp-linter-action@main→1b0049fe, actions/cache@v5→caa29612, actions/checkout@v5→fbc6f399, cpp-linter/cpp-linter-action@v2→8e85cd02, cpp-linter/.github workflows@main→2343264e.

6. **missing-permissions**: Added top-level permissions: {} to cpp-linter.yml, mkdocs-deploy.yml, pre-commit.yml, only-clang-format.yml, only-clang-tidy.yml. Added job-level permissions blocks where needed.

7. **unsafe-shell**: Fixed curl|sh equivalent in Setup cpp-linter dependencies step - installer is now saved to a file first, then executed separately with ^sh $installer_path.

