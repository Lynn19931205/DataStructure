#include <stdio.h>

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
}

int selection_sort(int list[], int n){
  int i, j, min_id;
  for(i = 0; i<n-1; i++){
    min_id = i;
    for(j=i+1; j<n; j++){
      if (list[j] < list[min_id])
        min_id = j;
    }
    swap(&list[i], &list[min_id]); //送地址過去swap function
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
  selection_sort(list, count);
  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}
