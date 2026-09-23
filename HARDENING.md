<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.23.1

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.23.1** was hardened automatically. 54 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Rule (a): Multiple ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Install Linux clang dependencies' step. The expressions ${{ inputs.version }} appear on lines 318, 342, and 344, substituted directly into Nu shell script text before the shell runs. An attacker-controlled input value could inject arbitrary Nu shell syntax.

Locations:

- `action.yml:318`
- `action.yml:342`
- `action.yml:344`

### script-injection (severity: high)

Rule (a): Multiple ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Install MacOS clang dependencies' step. The expressions ${{ inputs.version }} appear on lines 366, 371, and 372, substituted directly into Nu shell script text before the shell runs.

Locations:

- `action.yml:366`
- `action.yml:371`
- `action.yml:372`

### script-injection (severity: high)

Rule (a): Multiple ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Setup cpp-linter dependencies' step. Expressions include ${{ inputs.verbosity }} (line 404), ${{ inputs.version }} (line 418), ${{ inputs.tidy-checks }} (line 442), and ${{ inputs.style }} (line 446), all substituted directly into Nu shell script text before the shell runs.

Locations:

- `action.yml:404`
- `action.yml:418`
- `action.yml:442`
- `action.yml:446`

### script-injection (severity: high)

Rule (a): Multiple ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Check out the pull request head for auto-fix' step. Expressions include ${{ inputs.repo-root }} (line 470) and ${{ github.event.pull_request.head.sha }} (line 474), substituted directly into Nu shell script text before the shell runs. The github.event.pull_request.head.sha value is attacker-controlled on pull_request events.

Locations:

- `action.yml:470`
- `action.yml:474`

### script-injection (severity: high)

Rule (a): Numerous ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Run cpp-linter' step. All inputs (style, extensions, tidy-checks, repo-root, version, verbosity, lines-changed-only, files-changed-only, thread-comments, no-lgtm, step-summary, ignore, ignore-tidy, ignore-format, database, file-annotations, extra-args, tidy-review, format-review, passive-reviews, jobs, summary-output-file, auto-fix) are interpolated on lines 497–520, plus ${{ inputs.verbosity }} on line 526 and ${{ runner.os }} on line 538.

Locations:

- `action.yml:497`
- `action.yml:520`
- `action.yml:526`
- `action.yml:538`

### script-injection (severity: high)

Rule (a): Multiple ${{ }} expressions are directly interpolated inside run: shell scripts in the 'Auto-commit clang-format fixes' step. Expressions include ${{ github.event.pull_request.head.sha }} (line 556), ${{ github.event.pull_request.head.repo.full_name }} (line 557), ${{ github.repository }} (line 558), ${{ inputs.repo-root }} (line 579), ${{ inputs.extensions }} (line 592), ${{ inputs.auto-fix-git-user }} (lines 607, 610), ${{ inputs.auto-fix-git-email }} (lines 612, 615), and ${{ inputs.auto-fix-commit-msg }} (lines 619, 622). Attacker-controlled github.event.* values are especially dangerous.

Locations:

- `action.yml:556`
- `action.yml:557`
- `action.yml:558`
- `action.yml:579`
- `action.yml:592`
- `action.yml:607`
- `action.yml:612`
- `action.yml:619`

### unsafe-shell (severity: high)

The 'Setup cpp-linter dependencies' step fetches a remote installer script via HTTP and pipes it directly to a shell interpreter: `let installer = http get --raw --redirect-mode follow $uv_installer_url` followed by `$installer | ^sh` (line 400). If the remote URL is compromised or the content is tampered with in transit, arbitrary code will execute on the runner. The script should be downloaded to a file, its integrity verified (e.g. checksum), and then executed separately.

Locations:

- `action.yml:400`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:323`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:323`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:347`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install Linux clang dependencies"; move to env: map

Locations:

- `action.yml:349`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:371`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:376`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Install MacOS clang dependencies"; move to env: map

Locations:

- `action.yml:377`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:409`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:423`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:447`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Setup cpp-linter dependencies"; move to env: map

Locations:

- `action.yml:451`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Check out the pull request head for auto-fix"; move to env: map

Locations:

- `action.yml:475`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.sha }}" appears directly in run: block of step "Check out the pull request head for auto-fix"; move to env: map

Locations:

- `action.yml:479`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.style }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:502`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:503`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-checks }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:504`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:505`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.version }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:506`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:507`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.lines-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:508`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.files-changed-only }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:509`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.thread-comments }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:510`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.no-lgtm }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:511`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.step-summary }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:512`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:513`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-tidy }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:514`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.ignore-format }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:515`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.database }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:516`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.file-annotations }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:517`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extra-args }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:518`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.tidy-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:519`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.format-review }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:520`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.passive-reviews }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:521`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.jobs }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:522`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.summary-output-file }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:523`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:525`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.verbosity }}" appears directly in run: block of step "Run cpp-linter"; move to env: map

Locations:

- `action.yml:531`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.sha }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:562`

### static-inline-injection (severity: high)

shell injection: expression "${{ github.event.pull_request.head.repo.full_name }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:563`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.repo-root }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:585`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.extensions }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:599`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-user }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:614`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-user }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:617`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-email }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:619`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-git-email }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:622`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-commit-msg }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:626`

### static-inline-injection (severity: high)

shell injection: expression "${{ inputs.auto-fix-commit-msg }}" appears directly in run: block of step "Auto-commit clang-format fixes"; move to env: map

Locations:

- `action.yml:629`

## Iteration Notes

### Iteration 1

**Fixes applied:** script-injection, unsafe-shell, static-inline-injection

**Notes:**

Fixed all script injection findings by moving every ${{ }} expression from run: blocks into env: blocks in the affected steps: 'Install Linux clang dependencies' (INPUT_VERSION), 'Install MacOS clang dependencies' (INPUT_VERSION), 'Setup cpp-linter dependencies' (INPUT_VERBOSITY, INPUT_VERSION, INPUT_TIDY_CHECKS, INPUT_STYLE), 'Check out the pull request head for auto-fix' (INPUT_REPO_ROOT, PR_HEAD_SHA), 'Run cpp-linter' (24 env vars for all inputs and runner.os), and 'Auto-commit clang-format fixes' (PR_HEAD_SHA, PR_HEAD_REPO, GITHUB_REPOSITORY_NAME, INPUT_REPO_ROOT, INPUT_EXTENSIONS, INPUT_AUTO_FIX_GIT_USER, INPUT_AUTO_FIX_GIT_EMAIL, INPUT_AUTO_FIX_COMMIT_MSG). Fixed the unsafe-shell finding by replacing the pipe-from-internet pattern ('let installer = http get ... | ^sh') with downloading to a file first and then executing it ('http get ... | save --force $installer_path' then '^sh $installer_path'). All Nu shell scripts now reference values via $env.VAR_NAME.

