#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helper(int *i, int size, int *sum, int *arr) {
  // base case
  if (*i >= size - 1) {
    return;
  }

  // recursion part
  *i += 2;
  *sum += arr[*i];
  helper(i, size, sum, arr);
}

int rob(int *nums, int numsSize) {
  int sum1 = 0;
  int sum2 = 0;
  int index1 = -2;
  int index2 = -1;

  helper(&index1, numsSize, &sum1, nums);
  helper(&index2, numsSize, &sum2, nums);

  return (sum1 > sum2) ? sum1 : sum2;
}