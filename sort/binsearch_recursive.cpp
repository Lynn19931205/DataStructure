#include <stdio.h>

int binary_search(int A[], int left, int right, int key){
  int mid;
  while(left<=right)
  {
    mid = (left+right)/2;
    if(key == A[mid]){
      printf("Found! Position: %d", mid+1);
      printf("\n");
      break;
    }
    else if(key<A[mid]){
      binary_search(A, left, mid-1, key);
    }
    else if(key>A[mid]){
      binary_search(A, mid+1, right, key);
    }
    else{
      printf("Not Found!");
      printf("\n");
      break;
    }
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
  binary_search(list, 0, n-1, key);
  return 0;
}
