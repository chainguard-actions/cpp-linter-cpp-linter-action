<!-- markdownlint-disable -->

# Hardening Report: cpp-linter--cpp-linter-action/v2.23.0

> This file was generated automatically by the hardening agent.

**Policy SHA:** `d636be7e43ef829af6e853da6b3c7566db9f72fe`

**Test Policy SHA:** `843adf9e4b8f85d0c08b27b9d0b09dd094b54702`

**Harden Agent Version:** `2`

Action **cpp-linter--cpp-linter-action/v2.23.0** was hardened automatically. 49 finding(s) were identified and resolved across 1 iteration(s).

## Findings Fixed

### script-injection (severity: high)

Multiple `run:` blocks in action.yml directly interpolate `${{ inputs.* }}` and `${{ github.* }}` expressions inside Nushell scripts. The GitHub Actions template engine substitutes these values before the shell sees them, allowing an attacker who controls input values to inject arbitrary Nushell commands.

**Install Linux clang dependencies step** (sub-rule a): `install -y clang-format-${{ inputs.version }} clang-tidy-${{ inputs.version }}` — `inputs.version` is interpolated directly into a list that is passed to apt-get.

**Install MacOS clang dependencies step** (sub-rule a): `let brew_install_arg = 'llvm@${{ inputs.version }}'` — `inputs.version` is interpolated directly into a Nushell string literal.

**Setup cpp-linter dependencies step** (sub-rule a): `'${{ inputs.verbosity }}' == 'debug'`, `'${{ inputs.version }}'`, `"${{ inputs.tidy-checks }}"`, `"${{ inputs.style }}"` — multiple inputs interpolated directly into Nushell script.

**Check out the pull request head for auto-fix step** (sub-rule a): `cd '${{ inputs.repo-root }}'` and `let head_sha = '${{ github.event.pull_request.head.sha }}'` — attacker-controlled `inputs.repo-root` and `github.event.pull_request.head.sha` interpolated directly.

**Run cpp-linter step** (sub-rule a): All inputs are interpolated directly into argument strings, e.g. `'--style=${{ inputs.style }}'`, `'--extensions=${{ inputs.extensions }}'`, `'--tidy-checks=${{ inputs.tidy-checks }}'`, `'--ignore=${{ inputs.ignore }}'`, etc., plus `'${{ runner.os }}'`.

**Auto-commit clang-format fixes step** (sub-rule a): `'${{ github.event.pull_request.head.sha }}'`, `'${{ github.event.pull_request.head.repo.full_name }}'`, `'${{ github.repository }}'`, `cd '${{ inputs.repo-root }}'`, `'${{ inputs.extensions }}'`, `'${{ inputs.auto-fix-git-user }}'`, `'${{ inputs.auto-fix-git-email }}'`, `'${{ inputs.auto-fix-commit-msg }}'` — all interpolated directly into Nushell script.

Locations:

- `action.yml:270`
- `action.yml:310`
- `action.yml:338`
- `action.yml:395`
- `action.yml:425`
- `action.yml:475`

### unsafe-shell (severity: high)

In the 'Setup cpp-linter dependencies' step, the action fetches a remote installer script from `https://astral.sh/uv/{version}/install.sh` via HTTP and pipes its content directly to `sh` without saving it to a file first: `$installer | ^sh`. This is the classic unsafe curl-to-shell pattern. If the remote server is compromised or the connection is intercepted, arbitrary code will execute on the runner. The LLVM installer in the same action correctly saves to a file first before executing, but the uv installer does not.

Locations:

- `action.yml:338`

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

Fixed all security findings in hardened/action/action.yml:

1. **script-injection / static-inline-injection**: Moved all ${{ inputs.* }} and ${{ github.* }} expressions from run: blocks into env: blocks for all 6 affected steps. Nushell scripts now reference values via $env.VAR_NAME instead of inline template substitution, preventing attacker-controlled values from being interpreted as shell commands.

2. **unsafe-shell**: Fixed the uv installer download in the 'Setup cpp-linter dependencies' step. Instead of piping the downloaded script directly to sh ($installer | ^sh), the script is now saved to a file first (http get ... | save --force $installer_path) and then executed (^sh $installer_path). The Windows PowerShell path was also updated to read from the saved file.

