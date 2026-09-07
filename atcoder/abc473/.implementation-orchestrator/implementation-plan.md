## Change summary

- Goal: Prevent `d.cpp` from exploring impossible branches while preserving the required lexicographic output.
- Non-goals: No changes to other contest solutions or repository-wide tooling.
- Repository and current-state evidence: Small AtCoder C++ solution repository; `d.cpp` currently performs recursive enumeration and calls the final-level loop for every candidate remainder.
- Observable behavior or data boundary affected: The output sequence set and order must remain identical; runtime must be practical for the stated constraints.

## Risk and decision analysis

- Primary risks: Incorrect pruning could omit valid solutions or change lexicographic order; DP memory/indexing errors could cause invalid access.
- Design uncertainty: One plausible design: suffix feasibility DP plus lexicographic DFS.
- Closest existing precedent and selected relationship: Adapt the existing DFS; retain its traversal order and add a local suffix-feasibility table.
- Rationale for the selected relationship (including any complexity, responsibility, dependency, testability, or risk concern): This is the smallest local fix and avoids changing the output construction logic.
- Pattern or architecture decision: No additional architecture; a suffix DP directly addresses the concrete pruning requirement.
- Compatibility and rollback considerations: Single-file source change; reverting `d.cpp` restores the original implementation.
- Active workflow state: None.
- Applicable repository instructions and precedence: No `AGENTS.md` found.

## Required route decision

```text
Primary execution: direct
Supporting skills: none
Why: Small local bug fix with a settled algorithm and sample-based validation.
Rejected options: staged -> no dependent work; comparative -> no material design uncertainty; acceptance harness -> existing sample outputs provide a sufficient oracle for this local change.
Required gates: plan evidence validation, compile, sample comparison, adversarial N=2 case, final evidence validation.
```

## Change size and staging

- Estimated changed lines (additions + deletions): under 40
- Change type: complex logic
- Applicable limit: 500
- Actual diff and affected call sites inspected: `solve()` and its local `dfs` in `d.cpp`; no external callers.
- Split required: no
- Smallest coherent first stage: Implement suffix feasibility and prune DFS.
- Branch/PR sequence and dependencies: None.

## Selected skills

| Order | Skill | Why it is needed | Expected output |
| ----- | ----- | ---------------- | --------------- |
| 1 | implementation-acceptance-contract | Define observable output and performance checks before editing. | Acceptance criteria and validation matrix below. |
| 2 | implementation-verification-gate | Verify output, compilation, and the adversarial branch-pruning case. | Final evidence with command results. |

## Acceptance and validation

| ID | Criterion | Validation command/check | Expected oracle |
| ------ | --------- | ------------------------ | --------------- |
| AC-001 | Every valid sequence is printed exactly once in lexicographic order. | Compile and compare output for all `test_d` samples. | Exact match with `test_d/sample-*.out`. |
| AC-002 | The previously pathological `N=2, K=200000` case completes without quadratic dead-branch enumeration. | Compile and run with timeout using generated input; count output lines. | Completes within a short timeout and prints `100001` lines. |
| AC-003 | The solution remains valid for edge cases `N=1` and small `K`. | Run `test_d/sample-2.in` and sample 1/3. | Exact sample output. |

## Implementation steps

1. Build a suffix feasibility DP `can[i][r]` for coefficients `i..N`.
2. Group feasible suffix remainders by the current coefficient's residue modulo `i`, so the ascending `q` traversal skips impossible candidates instead of scanning them.
3. Compile and run the validation matrix; inspect the final diff.

## Decision gates

- [x] Design is local and preserves traversal order.
- [x] Samples and adversarial case pass.
- [x] Final evidence validation passes.

## Completion evidence

- Required commands: plan evidence validator, `g++`, sample comparison, adversarial timeout/count check, final evidence validator.
- Evidence record: `.implementation-orchestrator/evidence.json`
- Files or artifacts to inspect: `d.cpp`, `.implementation-orchestrator/evidence.json`
- Residual risks: None expected after exact sample and adversarial validation; the output volume itself remains bounded by the problem guarantee.
