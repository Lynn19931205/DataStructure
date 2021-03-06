#include <stdio.h>

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
}

int bubble_sort(int A[], int n){
  int i, j, flag;
  for(i = 0; i<n-1; i++){ //n個數字排序，只用 n-1 回
    int flag = 0; //表示有無發生交換
    for(j = 0; j < n-i; j++){ //從第一個數字開始比較，直到最後一個數字
      if(A[j]>A[j+1]){
        swap(&A[j], &A[j+1]);
        flag = 1;
      }
    }
    if(flag == 0) break; //此回合沒有發生交換
  }
}

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
  bubble_sort(list, count);
  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}
