#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *members;
  int length;
} Set;

Set* init();
bool is_empty(Set *set);
void insert(Set *set, int member);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);
Set *set_intersection(Set *setA, Set *setB);
Set *set_difference(Set *setA, Set *setB);
bool is_subset(Set *setA, Set *setB);
bool set_equality(Set *setA, Set *setB);
bool is_member(Set *set, int value);

int main() {
  // Example usage
  Set *setA = init();
  insert(setA, 5);
  insert(setA, 6);
  insert(setA, 7);

  Set *setB = init();
  insert(setB, 7);
  insert(setB, 8);
  insert(setB, 9);

  Set *setC = set_union(setA, setB);
  printf("Union of A and B: ");
  print_set(setC);

  Set *setD = set_intersection(setA, setB);
  printf("Intersection of A and B: ");
  print_set(setD);

  Set *setE = set_difference(setA, setB);
  printf("Difference of A and B: ");
  print_set(setE);

  bool subsetCheck = is_subset(setA, setB);
  if (subsetCheck)
    printf("A is a subset of B.\n");
  else
    printf("A is not a subset of B.\n");

  return 0;
}

Set* init() {
  Set *new_set = malloc(sizeof(Set));
  new_set->length = 0;
  new_set->members = malloc(sizeof(int));
  return new_set;
}

bool is_empty(Set *set) {
  return (set->length == 0);
}

bool is_member(Set *set, int value) {
  for (int i = 0; i < set->length; i++) {
    if (set->members[i] == value) {
      return true;
    }
  }
  return false;
}

void insert(Set *set, int member) {
  if (!is_member(set, member)) {
    set->members = realloc(set->members, sizeof(int) * (set->length + 1));
    set->members[set->length] = member;
    set->length = set->length + 1;
  }
}

void print_set(Set *set) {
  for (int i = 0; i < set->length; i++) {
    if (i == (set->length - 1)) {
      printf("%d\n", set->members[i]);
    } else {
      printf("%d, ", set->members[i]);
    }
  }
}

Set *set_union(Set *setA, Set *setB) {
  Set *newSet = init();
  for (int i = 0; i < setA->length; i++) {
    insert(newSet, setA->members[i]);
  }
  for (int i = 0; i < setB->length; i++) {
    insert(newSet, setB->members[i]);
  }
  return newSet;
}

Set *set_intersection(Set *setA, Set *setB) {
  Set *newSet = init();
  for (int i = 0; i < setA->length; i++) {
    if (is_member(setB, setA->members[i])) {
      insert(newSet, setA->members[i]);
    }
  }
  return newSet;
}

Set *set_difference(Set *setA, Set *setB) {
  Set *newSet = init();
  for (int i = 0; i < setA->length; i++) {
    if (!is_member(setB, setA->members[i])) {
      insert(newSet, setA->members[i]);
    }
  }
  return newSet;
}

bool is_subset(Set *setA, Set *setB) {
  for (int i = 0; i < setA->length; i++) {
    if (!is_member(setB, setA->members[i])) {
      return false;
    }
  }
  return true;
}

bool set_equality(Set *setA, Set *setB) {
  if (setA->length != setB->length) {
    return false;
  }
  return is_subset(setA, setB);
}
