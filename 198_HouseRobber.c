#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// previous version mistakenly think there is only 2 combination of items

// Meaning: item in index i represent
// "what's the maximum possible robbery value if I start considering houses from
// position i onwards?
int memo[100];

int dp(int i, int *nums, int numsSize) {
  // Base case
  if (i >= numsSize) {
    return 0;
  }

  // Check if already computed
  if (memo[i] != -1) {
    return memo[i];
  }

  // Two choices: rob current house or skip it
  int rob_current = nums[i] + dp(i + 2, nums, numsSize);
  int skip_current = dp(i + 1, nums, numsSize);

  // Save result in memo table
  memo[i] = (rob_current > skip_current) ? rob_current : skip_current;

  return memo[i];
}

int rob(int *nums, int numsSize) {
  // Initialize memo table with -1
  for (int i = 0; i < numsSize; i++) {
    memo[i] = -1;
  }

  return dp(0, nums, numsSize);
}