#include <stdio.h>
#include <stdlib.h>

// Your solution
int compare(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int minSetSize(int *arr, int arrSize) {
  // Initially allocate freq with size arrSize
  int freqSize = arrSize;
  int *freq = calloc(freqSize, sizeof(int));

  // Count frequencies of each value, resize if needed
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] >= freqSize) {
      // Need to resize
      int newSize = arr[i] + 1; // +1 because we need indices 0 to arr[i]
      freq = realloc(freq, newSize * sizeof(int));

      // Initialize the new elements to zero
      for (int j = freqSize; j < newSize; j++) {
        freq[j] = 0;
      }

      freqSize = newSize;
    }
    freq[arr[i]]++;
  }

  // Sort frequencies in descending order
  qsort(freq, freqSize, sizeof(int), compare);

  // Remove elements until reaching half
  int removed = 0;
  int count = 0;
  while (removed < arrSize / 2) {
    removed += freq[count++];
  }

  free(freq);
  return count;
}

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