#include <stdio.h>
#include <stdlib.h>

// 打印
static void printArray(int arr[], int size)
{
  if (arr == NULL || size <= 0)
  {
    printf("[]");
    return;
  }

  printf("[");
  for (int i = 0; i < size - 1; i++)
    printf("%d, ", arr[i]);
  printf("%d]\n", arr[size - 1]);
}

// 扩展
static int *extend(int *arr, int size, int enlarge)
{
  int *res = (int *)malloc(sizeof(int) * (size + enlarge));
  for (int i = 0; i < size; i++)
  {
    res[i] = arr[i];
  }
  for (int i = size; i < size + enlarge; i++)
  {
    res[i] = 0;
  }
  return res;
}

// 查找指定元素
static int find(int *arr, int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  // 初始化数组
  int arr[5] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);

  // 扩展数组
  int enlarge = 3;
  int *newArr = extend(arr, size, enlarge);
  size += enlarge;
  printArray(newArr, size);
  free(newArr);

  // 查找元素
  int index = find(arr, size, 5);
  printf("index: %d\n", index);

  return 0;
}