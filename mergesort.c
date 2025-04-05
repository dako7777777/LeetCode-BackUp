#include <stdio.h>
#include <stdlib.h>

void merge(int left, int right, int *arr) {
  int size = (right - left + 1);
  int *temp = malloc(sizeof(int) * size);
  int mid = (left + right) / 2;

  int i = left;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }

  while (j <= right) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  for (int i = 0; i < size; i++) {
    arr[left + i] = temp[i];
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
  int right = numsSize - 1;
  mergeSort(left, right, nums);
}

int main() {
  int nums[] = {53, 1, 7, 9};
  int size = 4;
  sortArray(nums, size);
  for (int i = 0; i < size; i++) {
    printf("%d\n", nums[i]);
  }
}