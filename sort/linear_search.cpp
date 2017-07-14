#include <stdio.h>

int linear_search(int A[], int n, int key){
  int i;
  for(i = 0; i<n; i++)
    if(key == A[i]){
      printf("Found! Position: %d\n", i+1);
    }
    else{
      printf("Not Found!\n");
    }
}

int main(){
  int n, i, key;
  printf("Enter array length: ");
  scanf("%d", &n);
  printf("\n");
  int list[n];
  printf("Enter sorted numbers: ");
  for(i = 0; i<n; i++){
    scanf("%d", &list[i]);
  }
  printf("\n");
  printf("Current numbers: ");
  for(i = 0; i<n; i++){
    printf("%d ", list[i]);
  }
  printf("\n");
  printf("Enter key: ");
  scanf("%d", &key);
  linear_search(list, n-1, key);
  return 0;
}
