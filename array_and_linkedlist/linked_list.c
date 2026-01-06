#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
  int val;
  struct LinkNode *next;
} LinkNode;

static LinkNode *createNode(int val)
{
  LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
  node->val = val;
  node->next = NULL;
  return node;
}

static void printLinkedList(LinkNode *head)
{
  if (head == NULL)
  {
    printf("null");
    return;
  }

  LinkNode *current = head;
  while (current->next)
  {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("%d\n", current->val);
}

// 插入节点
static void insert(LinkNode *head, int index, LinkNode *insert_node)
{
  LinkNode *current = head;
  for (int i = 0; i < index - 1; i++)
  {
    current = current->next;
  }
  insert_node->next = current->next;
  current->next = insert_node;
}

// 通过值查找节点的序号(第一个匹配的)
static int find(LinkNode *head, int target)
{
  int index = 0;
  LinkNode *current = head;
  while (current)
  {
    if (current->val == target)
      return index;
    current = current->next;
    index++;
  }
  return -1;
}

// 通过index查找节点的值
static int findValByIndex(LinkNode *head, int index)
{
  LinkNode *current = head;
  for (int i = 0; i < index; i++)
  {
    current = current->next;
  }
  return current->val;
}

// 通过index删除节点
static void deleteNodeByIndex(LinkNode *head, int index)
{
  LinkNode *current = head;
  for (int i = 0; i < index - 1; i++)
  {
    current = current->next;
  }
  LinkNode *delete_node = current->next;
  current->next = delete_node->next;
  free(delete_node);
}

int main()
{
  LinkNode *n0 = createNode(0);
  LinkNode *n1 = createNode(1);
  LinkNode *n2 = createNode(2);
  LinkNode *n3 = createNode(3);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  printLinkedList(n0);

  // 插入节点
  insert(n0, 2, createNode(12));
  printLinkedList(n0);

  // 查找节点
  int index = find(n0, 12);
  printf("index: %d\n", index);

  // 查找节点的值
  int val = findValByIndex(n0, index);
  printf("val: %d\n", val);

  // 删除节点
  deleteNodeByIndex(n0, 3);
  printLinkedList(n0);

  return 0;
}