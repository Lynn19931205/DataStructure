#include <stdio.h>

int binary_search(int A[], int key, int n){
  int left, right, mid;
  left = 0;
  right = n-1;
  while(left<=right){
    mid = (left+right)/2;
    switch((key==A[mid])?1:(key<A[mid])?2:(key>A[mid])?3:4){
      case 1:
        printf("Found! Position: %d", mid+1);
        printf("\n");
        break;
      case 2:
        right = mid-1;
      case 3:
        left = mid+1;
      case 4:
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
  binary_search(list, key, n);
  return 0;
}
