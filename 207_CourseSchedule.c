#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex {
  int courseNum;
  struct vertex *next;
} vertex_t;

// since the numVertices is known, we can skip using this data struct

// typedef struct adj_list {
//   int numVertices;
//   vertex_t **adjList;
// } adj_list_t;

void add_edge(vertex_t **adjList, int course, int prereq) {
  vertex_t *newNode = malloc(sizeof(vertex_t));
  newNode->courseNum = prereq; // Mistaken: store wrongly with course

  // prepend: the code for first node and the rest is the same
  newNode->next = adjList[course];
  adjList[course] = newNode;
}

bool cycle(int courseNum, vertex_t **adjList, int *visited) {
  // Mistaken(important): the first node in the item of adjacency list is the
  // pre instead of course itself the course is the index number!
  // this function will return true to represent there is a cycle
  // -1 represent there is a cycle; 1 represent visited

  // base case 1: there is a cycle
  if (visited[courseNum] == -1) {
    return true;
  }

  // base case 2: there is no cycle
  if (visited[courseNum] == 1) {
    return false;
  }

  // recursion part: handle not visited case
  visited[courseNum] = -1;

  vertex_t *current = adjList[courseNum];
  while (current) {
    if (cycle(current, visited)) {
      return true;
    }
    current = current->next;
  }

  visited[courseNum] = 1;
  return false;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize,
               int *prerequisitesColSize) {

  // # 1 initialize data
  // ## 1.1 add prereq to adjacency list
  vertex_t **adjList = calloc(numCourses, sizeof(vertex_t *));

  // Build graph
  for (int i = 0; i < prerequisitesSize; i++) {
    int course = prerequisites[i][0];
    int prereq = prerequisites[i][1];
    add_edge(adjList, course, prereq);
  }

  // ## 1.2 create an array to store the status of each course
  int *visited =
      calloc(numCourses, sizeof(int)); // set parameter wrongly, in opposite

  // # 2: check whether there is a cycle in each class
  for (int i = 0; i < numCourses; i++) {
    // Mistaken: didn't check whether the vertex has been visited
    if (visited[i] == 0) {
      // if there is a cycle, then return false
      if (cycle(i, adjList, visited)) {
        free(visited);
        // Free adjList here
        return false;
      }
    }
  }

  free(visited);
  // Free adjList here
  return true;
}