#include <stdio.h>
#include <stdlib.h>

// Your solution
int compare(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int minSetSize(int *arr, int arrSize) {
  // find the frequency of each number
  int setSize = arrSize;
  int *freSet = calloc(setSize, sizeof(int));

  for (int i = 0; i < setSize; i++) {
    if (arr[i] >= setSize) {
      int newSize = arr[i] + 1;
      freSet = realloc(freSet, newSize * sizeof(int));

      // Initialize the new elements to zero
      for (int j = setSize; j < newSize; j++) {
        freSet[j] = 0;
      }
      setSize = newSize;
    }

    freSet[arr[i]] += 1;
  }

  // sort the frequency set in descending
  qsort(freSet, setSize, sizeof(int), compare);
  //   for (int i = 0; i < arrSize; i++) {
  //     printf("%d\n", freSet[i]);
  //   }

  // begin to remove the item in higher frequency until reach the threshold
  int size = arrSize; // * make error in how to initialize
  int i = 0;
  while (size > (arrSize / 2)) { // make mistake about how to compare
    // printf("i: %d\n", i);
    // printf("size: %d\n", size);
    // printf("freSet[i]: %d\n\n", freSet[i]);
    size -= freSet[i];
    i++;
  }

  free(freSet);
  return i;
};

int main() {

  // Test Case 1: Basic example from LeetCode
  {
    int arr[] = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int expected = 2; // Remove all 3's and 5's
    int result = minSetSize(arr, size);
    printf("Test Case 1: ");
    printf("Expected: %d, Got: %d - %s\n", expected, result,
           (expected == result) ? "PASSED" : "FAILED");
  }

  // Test Case 2: Single number repeated
  {
    int arr[] = {7, 7, 7, 7, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int expected = 1; // Remove all 7's
    int result = minSetSize(arr, size);

    printf("Test Case 2: ");
    printf("Expected: %d, Got: %d - %s\n", expected, result,
           (expected == result) ? "PASSED" : "FAILED");
  }

  // Test Case 3: All numbers are unique
  {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int expected = 5; // Remove any 5 numbers
    int result = minSetSize(arr, size);

    printf("Test Case 3: ");
    printf("Expected: %d, Got: %d - %s\n", expected, result,
           (expected == result) ? "PASSED" : "FAILED");
  }

  // Test Case 4: Another LeetCode example
  {
    int arr[] = {1000, 1000, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int expected = 1; // Remove all 1000's
    int result = minSetSize(arr, size);

    printf("Test Case 4: ");
    printf("Expected: %d, Got: %d - %s\n", expected, result,
           (expected == result) ? "PASSED" : "FAILED");
  }

  // Test Case 5: Edge case - minimum array size
  {
    int arr[] = {1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int expected = 1; // Remove all 1's
    int result = minSetSize(arr, size);

    printf("Test Case 5: ");
    printf("Expected: %d, Got: %d - %s\n", expected, result,
           (expected == result) ? "PASSED" : "FAILED");
  }

  return 0;
}