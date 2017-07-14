#include <stdio.h>

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
};

int quick_sort(int A[], int left, int right) //排序A[left]~A[riht]
{
  int pivot;
  int i, j;
  if(left < right){
    pivot = A[left];
    i = left;
    j = right+1;
    while(i<j){
      while(pivot>A[i])
        i++;
      while(pivot<A[j])
        j--;
      if(i<j) //直到i ,j兩軍交會
        swap(&A[i], &A[j]);
    }
    while(i<j) //要不要加這個while??
      swap(&A[left], &A[j]);
    quick_sort(A, left, j-1);
    quick_sort(A, j+1, right);
  }
};

int main(){
  int count, i;
  scanf("%d", &count);
  int list[count];
  printf("Numbers to be sorted: ");
  for(i = 0; i<count; i++){
    scanf("%d", &list[i]);
    printf("%d ", list[i]);
  }
  printf("\n");
  quick_sort(list, 0, count-1);
  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}
