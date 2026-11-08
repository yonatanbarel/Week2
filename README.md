
# GitLab CI Pipeline for Social Network Exercise 2

This README provides an overview of the GitLab CI pipeline defined in `gitlab-ci.yml` for building, testing, and deploying the social network exercise.

## Overview

The pipeline has the following stages:

-   `build-pipeline-tools`: Clones and builds utility scripts and programs needed for the pipeline
-   `part1Answers`: Checks for PDF with part 1 answers
-   `build1`  : Compiles part 1 code
-   `test1`: Runs part 1 test
-   `build2/test2`: Build and test part 2
-   `build3/test3`: Build and test part 3
-   `build4/test4`: Build and test part 4
-   `build-bonus/test-bonus`: Build and test bonus part
-   `submission-verifier`: Checks submission date
-   `zip-and-send`: Sends zip to ING server


## Job Details

**Build Pipeline Tools** - Builds helper scripts like filesverifier, valgrindverifier etc.

**Verify Submission** - Runs filesverifier to check for required files.

**Verify Exercise Files** - Checks for files needed for the exercise.

**Part 1 Answers** - Checks for PDF with part 1 answers.

**Build Part 1** - Compiles part 1 code with test file.

**Test Part 1** - Runs test cases on part 1 code.

**Build & Test Part 2 to Part 4** - Builds and tests remainder of parts.

**Memory Check** - Runs part 4 code on valgrind to check for mem leaks.

**ZIP and Send** - Sends zip of pipeline run to ING server.

## Conclusion

This pipeline automates build, test, verification of this social network exercise using modular stages and reusable utils.
