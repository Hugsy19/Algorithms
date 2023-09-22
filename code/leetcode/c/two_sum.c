// leetcode 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100
#define HASHSIZE 107

typedef struct Node {
  int val;
  int index;
  struct Node *next;
} Node;

int *twoSum_1(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] + nums[j] == target) {
        int *ret = (int *)malloc(sizeof(int) * 2);
        ret[0] = i, ret[1] = j;
        *returnSize = 2;
        return ret;
      }
    }
  }
  *returnSize = 0;
  return NULL;
}

int *twoSum_2(int *nums, int numsSize, int target, int *returnSize) {
  Node *hash[HASHSIZE];                // hash table
  for (int i = 0; i < HASHSIZE; ++i) { // init
    hash[i] = (Node *)malloc(sizeof(Node));
    hash[i]->val = hash[i]->index = -1;
    hash[i]->next = NULL;
  }
  for (int i = 0; i < numsSize; ++i) {
    int tmp = target - nums[i];
    int pos = abs(tmp) % HASHSIZE;
    Node *head = hash[pos];
    while (head->next && head->next->val != tmp)
      head = head->next;
    if (head->next) {
      int *ret = (int *)malloc(sizeof(int) * 2);
      ret[0] = i, ret[1] = head->next->index;
      for (int i = 0; i < HASHSIZE; ++i)
        free(hash[i]);
      *returnSize = 2;
      return ret;
    }
    pos = abs(nums[i]) % HASHSIZE;
    head = hash[pos];
    while (head->next)
      head = head->next;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->val = nums[i];
    head->next->index = i;
    head->next->next = NULL;
  }
  for (int i = 0; i < HASHSIZE; ++i)
    free(hash[i]);
  *returnSize = 0;
  return NULL;
}

int main(int argc, char *argv[]) {
  int *ret;
  int *nums;
  int numsSize;
  int target;
  int returnSize;
  char input_line[BUFSIZE];

  while (fgets(input_line, sizeof(input_line), stdin) != NULL) {
    numsSize = atoi(input_line);
    nums = (int *)malloc(numsSize * sizeof(int));

    if (fgets(input_line, sizeof(input_line), stdin) != NULL) {
      char *token = strtok(input_line, " ");
      for (int i = 0; i < numsSize; ++i) {
        nums[i] = atoi(token);
        token = strtok(NULL, " ");
      }
    }

    if (fgets(input_line, sizeof(input_line), stdin) != NULL) {
      target = atoi(input_line);
    }

    ret = twoSum_1(nums, numsSize, target, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; ++i) {
      printf("%d", ret[i]);
      if (i < returnSize - 1)
        printf(", ");
    }
    printf("]\n");

    ret = twoSum_2(nums, numsSize, target, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; ++i) {
      printf("%d", ret[i]);
      if (i < returnSize - 1)
        printf(", ");
    }
    printf("]\n");

    free(nums);
  }
  return 0;
}