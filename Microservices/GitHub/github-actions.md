# In-depth Overview of GitHub Actions

- [In-depth Overview of GitHub Actions](#in-depth-overview-of-github-actions)
  - [Introduction](#introduction)
    - [Key Features](#key-features)
    - [Structure of a Workflow File](#structure-of-a-workflow-file)
    - [Example 1: Basic CI Workflow](#example-1-basic-ci-workflow)
    - [Example 2: Deploying to AWS](#example-2-deploying-to-aws)
    - [Example 3: Scheduled Workflows](#example-3-scheduled-workflows)
    - [Key Concepts](#key-concepts)
    - [Debugging Tips](#debugging-tips)
    - [Advanced Features](#advanced-features)

## Introduction

GitHub Actions is a CI/CD (Continuous Integration/Continuous Deployment) and automation tool integrated directly into GitHub. It enables you to automate workflows for building, testing, and deploying your code, as well as perform other tasks like managing issues, sending notifications, and more.

### Key Features

1. **Integration with GitHub**: Direct integration with GitHub repositories for seamless workflow automation.
2. **Event-driven Workflows**: Trigger workflows on GitHub events like `push`, `pull_request`, or `schedule`.
3. **YAML-based Configurations**: Workflows are defined in `.github/workflows/*.yml`.
4. **Reusable Workflows**: Centralized workflows can be reused across multiple repositories.
5. **Marketplace**: Thousands of pre-built actions available in the [GitHub Marketplace](https://github.com/marketplace).
6. **Secrets Management**: Store sensitive data like API keys securely.
7. **Cross-platform Runners**: Support for Linux, macOS, and Windows.

---

### Structure of a Workflow File

A GitHub Actions workflow file is structured as follows:

```yaml
name: <Workflow Name>
on: <Trigger Events>
jobs:
  <job_id>:
    runs-on: <Runner Type>
    steps:
      - name: <Step Name>
        uses: <GitHub Action or Command>
        with: <Inputs>
        env:
          <Environment Variables>
```

---

### Example 1: Basic CI Workflow

This workflow runs on every `push` or `pull_request` event to a `main` branch.

```yaml
name: CI

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Set up Node.js
        uses: actions/setup-node@v3
        with:
          node-version: 16

      - name: Install dependencies
        run: npm install

      - name: Run tests
        run: npm test
```

---

### Example 2: Deploying to AWS

This workflow deploys a static website to AWS S3 when changes are pushed to the `main` branch.

```yaml
name: Deploy to AWS S3

on:
  push:
    branches:
      - main

jobs:
  deploy:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Install AWS CLI
        run: |
          curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"
          unzip awscliv2.zip
          sudo ./aws/install

      - name: Deploy to S3
        env:
          AWS_ACCESS_KEY_ID: ${{ secrets.AWS_ACCESS_KEY_ID }}
          AWS_SECRET_ACCESS_KEY: ${{ secrets.AWS_SECRET_ACCESS_KEY }}
          AWS_REGION: us-east-1
        run: |
          aws s3 sync ./website s3://your-s3-bucket-name --delete
```

---

### Example 3: Scheduled Workflows

Run a script every day at midnight using cron syntax.

```yaml
name: Daily Data Sync

on:
  schedule:
    - cron: '0 0 * * *' # Runs every day at midnight UTC

jobs:
  data-sync:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Run sync script
        run: python scripts/sync.py
```

---

### Key Concepts

1. **Triggers (`on`)**:
   - Define when a workflow is triggered.
   - Examples: `push`, `pull_request`, `schedule`, `workflow_dispatch`.

2. **Jobs**:
   - Define what needs to be done. Jobs run in isolated environments (containers or VMs).
   - Can depend on other jobs using `needs`.

3. **Steps**:
   - Actions or commands executed in a job. These can:
     - Use pre-defined actions (e.g., `actions/checkout`).
     - Run custom shell commands (`run`).

4. **Runners**:
   - The environment where jobs are executed.
   - GitHub-hosted runners: `ubuntu-latest`, `macos-latest`, `windows-latest`.
   - Self-hosted runners for custom environments.

5. **Secrets**:
   - Securely store sensitive information (e.g., tokens, API keys).
   - Accessed via `secrets.<key>`.

---

### Debugging Tips

1. **Log Outputs**:
   Use `echo` to log custom messages during the workflow.

   ```yaml
   - name: Log message
     run: echo "Debugging step"
   ```

2. **Enable Debug Logs**:
   Add a secret `ACTIONS_STEP_DEBUG` with the value `true` to see debug logs.

3. **Rerun Workflows**:
   Use the GitHub UI to rerun failed workflows for testing fixes.

---

### Advanced Features

1. **Matrix Builds**:
   Run jobs with multiple configurations, such as testing on different Node.js versions.

   ```yaml
   jobs:
     build:
       runs-on: ubuntu-latest
       strategy:
         matrix:
           node-version: [14, 16, 18]
       steps:
         - name: Setup Node.js
           uses: actions/setup-node@v3
           with:
             node-version: ${{ matrix.node-version }}
   ```

2. **Reusable Workflows**:
   Define a workflow in one repository and call it from another.

3. **Artifacts**:
   Share files between jobs or workflows.

   ```yaml
   - name: Upload artifact
     uses: actions/upload-artifact@v3
     with:
       name: test-results
       path: ./results/
   ```

4. **Concurrency**:
   Prevent duplicate runs of workflows.

   ```yaml
   concurrency:
     group: ${{ github.ref }}
     cancel-in-progress: true
   ```

---

GitHub Actions is a versatile and powerful tool for automating tasks and improving your development workflow. The above examples can serve as a foundation to tailor workflows for your specific needs.
