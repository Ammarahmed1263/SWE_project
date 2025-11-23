# 🛠️ Team Rules & Workflow

## 1. Commit Message Format
We use a strict format to keep history clean:
**Format:** `type(feature_name): short description`

**Allowed Types:**
* `feat`: A new feature
* `fix`: A bug fix
* `docs`: Documentation changes
* `style`: Formatting (no code change)
* `refactor`: Code cleanup (no behavior change)

**Example:**
> `feat(login): add google sign-in button`
> `fix(navbar): correct alignment issue`

---

## 2. How to Create a Branch
Never work on `main`. Always create a new branch for your task.

1.  **Get latest code:**
    ```bash
    git checkout main
    git pull origin main
    ```
2.  **Create branch:**
    ```bash
    # Format: type/feature-name
    git checkout -b feat/login-page
    ```

---

## 3. How to Create a Pull Request (PR)
1.  **Push your branch:**
    ```bash
    git push origin feat/login-page
    ```
2.  Go to the GitHub repository page.
3.  Click the yellow **"Compare & pull request"** button.
4.  **Title:** Use the commit format (e.g., `feat(login): Add Google Sign-in`).
5.  **Reviewers:** Assign at least one team member.
6.  **Create:** Click "Create Pull Request" and wait for approval.
