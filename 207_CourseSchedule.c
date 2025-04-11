#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex {
  int courseNum;
  struct vertex *next;
} vertex_t;

typedef struct adj_list {
  int numVertices;
  vertex_t **adjList;
} adj_list_t;

void add_node(vertex_t *head, int nextCourseNum) {
  vertex_t *newNode = malloc(sizeof(vertex_t));
  newNode->courseNum = nextCourseNum;
  newNode->next = NULL;
  head->next = newNode;
}

bool cycle(vertex_t *course, int *checkStatus) {
  // this function will return true to represent there is a cycle
  // -1 represent there is a cycle; 1 represent visited

  // base case 1: there is a cycle
  if (checkStatus[course->courseNum] == -1) {
    return true;
  }

  // base case 2: there is no cycle
  if (checkStatus[course->courseNum] == 1) {
    return false;
  }

  // recursion part: handle not visited case
  checkStatus[course->courseNum] = -1;

  vertex_t *current = course->next;
  while (current) {
    if (cycle(current, checkStatus)) {
      return true;
    }
    current = current->next;
  }

  checkStatus[course->courseNum] = 1;
  return false;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize,
               int *prerequisitesColSize) {

  // # 1 initialize data
  // ## 1.1 add prereq to adjacency list
  adj_list_t *courseAdj = malloc(sizeof(adj_list_t));
  courseAdj->adjList = malloc(sizeof(vertex_t *));
  courseAdj->numVertices = 0; // need check

  for (int i = 0; i < numCourses; i++) {
    vertex_t *newCourse = malloc(sizeof(vertex_t));
    newCourse->courseNum = i;
    newCourse->next = NULL;

    for (int j = 0; j < prerequisitesSize; j++) {
      // find the array store the prereq for the current course

      if (i == prerequisites[j][0]) {
        vertex_t *current = newCourse;
        for (int k = 1; k < *prerequisitesColSize; k++) {
          vertex_t *temp = current->next;
          add_node(current, prerequisites[j][k]);
          current = temp;
        }
      }
    }
  }

  // ## 1.2 create an array to store the status of each course
  int *checkStatus = calloc(sizeof(int), 100);

  // # 2: check whether there is a cycle in each class
  for (int i = 0; i < courseAdj->numVertices; i++) {
    // if there is a cycle, then return false
    if (cycle(courseAdj->adjList[i], checkStatus)) {
      return false;
    }
  }

  return true;
}