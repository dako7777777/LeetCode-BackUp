#include <stdio.h>
#include <stdlib.h>

// Your solution
int compare(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int minSetSize(int *arr, int arrSize) {
  // find the frequency of each number
  int freqSize = arrSize;
  int *freq = calloc(freqSize, sizeof(int));

  for (int i = 0; i < arrSize; i++) { // make mistake, change it into freqSize
    if (arr[i] >= freqSize) {
      int newSize = arr[i] + 1;
      freq = realloc(freq, newSize * sizeof(int)); // need to familiar

      // Initialize the new elements to zero
      for (int j = freqSize; j < newSize; j++) {
        freq[j] = 0;
      }
      freqSize = newSize;
    }

    freq[arr[i]]++;
  }

  // sort the frequency set in descending
  qsort(freq, freqSize, sizeof(int), compare);

  // begin to remove the item in higher frequency until reach the threshold
  int size = 0; // * make error in how to initialize
  int count = 0;
  while (size < (arrSize / 2)) { // make mistake about how to compare
    size += freq[count++];
    // count++;
  }

  free(freq);
  return count;
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