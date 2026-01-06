#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int val;
  struct Node *next;
} Node;

typedef struct List
{
  int *arr;
  int capacity;
  int size;
  int extendRatio;
} List;

Node *createNode(int val)
{

  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  return node;
}

List *createList()
{
  List *list = malloc(sizeof(List));
  list->capacity = 10;
  list->arr = malloc(sizeof(int *) * list->capacity);
  list->size = 0;
  list->extendRatio = 2;
  return list;
}

void destroyList(List *list)
{
  if (list == NULL)
    return;
  if (list->arr != NULL)
    free(list->arr);
  free(list);
}

int get(List *list, int index)
{
  if (list == NULL || index < 0 || index >= list->size)
    return -1;
  return list->arr[index];
}

void set(List *list, int index, int val)
{
  if (list == NULL || index < 0 || index >= list->size)
    return;
  list->arr[index] = val;
}

void printList(List *list)
{
  if (list == NULL || list->size <= 0)
  {
    printf("null");
    return;
  }

  for (int i = 0; i < list->size - 1; i++)
    printf("%d -> ", list->arr[i]);
  printf("%d\n", list->arr[list->size - 1]);
}

void extend(List *list)
{
  int newCapacity = list->capacity * list->extendRatio;
  int *extend = (int *)malloc(sizeof(int) * newCapacity);
  int *temp = list->arr;

  for (int i = 0; i < list->size; i++)
    extend[i] = list->arr[i];

  list->arr = extend;
  list->capacity = newCapacity;
  free(temp);
}

void push(List *list, int val)
{
  if (list == NULL)
    return;
  if (list->size >= list->capacity)
    extend(list);
  list->arr[list->size] = val;
  list->size++;
}

void insert(List *list, int index, int val)
{
  if (list == NULL || index < 0 || index > list->size)
    return;
  if (list->size >= list->capacity)
    extend(list);

  for (int i = list->size; i > index; i--)
    list->arr[i] = list->arr[i - 1];
  list->arr[index] = val;
  list->size++;
}

void delete(List *list, int index)
{
  if (list == NULL || index < 0 || index >= list->size)
    return;

  int delVal = list->arr[index];
  for (int i = index; i < list->size - 1; i++)
    list->arr[i] = list->arr[i + 1];
  list->size--;
}

int main()
{
  List *list = createList();
  push(list, 1);
  push(list, 2);
  push(list, 3);
  push(list, 4);
  push(list, 5);
  push(list, 6);
  push(list, 7);
  push(list, 8);
  push(list, 9);
  push(list, 10);
  push(list, 11);
  push(list, 12);
  push(list, 13);
  push(list, 14);
  push(list, 15);
  push(list, 16);
  push(list, 17);
  printList(list);

  // 插入
  insert(list, 5, 100);
  printList(list);

  // 删除
  delete(list, 5);
  delete(list, 5);
  printList(list);

  // 访问元素
  int val = get(list, 5);
  printf("val: %d\n", val);

  // 修改元素
  set(list, 5, 200);
  printList(list);

  destroyList(list);

  return 0;
}