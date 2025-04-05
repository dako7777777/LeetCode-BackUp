#include <stdio.h>
#include <stdlib.h>

void merge(int left, int right, int *arr) {
  int size = (right - left + 1);
  int *temp = malloc(sizeof(int) * size);
  int mid = (left + right) / 2;

  int i = left;
  int j = mid + 1;
  int k = 0;

  while (i <= left &&
         j <= right) { // (1)compare without = (2)left should compare with mid
    if (arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  if (i < left) { // use wrong comparison rather than while loop
    temp[k] = arr[i];
    i++;
    k++;
  }

  if (j < right) { // use wrong comparison rather than while loop
    temp[k] = arr[j];
    j++;
    k++;
  }

  for (int i = 0; i < size; i++) {
    arr[left + i] = temp[i]; // miss the left
  }

  free(temp);
}

void mergeSort(int left, int right, int *arr) {
  if (left < right) { // miss base case
    int mid = (left + right) / 2;
    mergeSort(left, mid, arr);
    mergeSort(mid + 1, right, arr);
    merge(left, right, arr);
  }
}

void sortArray(int *nums, int numsSize) {
  int left = 0;
  int right = numsSize - 1; // without -1
  mergeSort(left, right, nums);
}

int main() {
  int nums[] = {53, 1};
  sortArray(nums, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d\n", nums[i]);
  }
}