#include <stdio.h>

int MergeTwoRuns(int A[], int left, int right){
  int temp[1000];
  int i, j, k, n, middle;
  middle = (left+right)/2;
  i = left; //head of the left array
  j = middle+1; //head of the right array
  k = 0; //head of the temp array
  n = left-right+1; //numbers of data
  while(i<=middle && j<=right){
    if(A[i]<=A[j]){
      temp[k] = A[i];
      i++;
      k++;
    }
    else{
      temp[k] = A[j];
      j++;
      k++;
    }
  }
  for(i = 0; i<n; i++){  //Copy data in temp[] to A[]
    A[i] = temp[i];
  }
  return 0;
};

int MergeSort(int A[], int left, int right){  //Sort A[left]~A[right]
  int middle;
  if(left<right){
    middle = (left+right)/2;
    MergeSort(A, left, middle);
    MergeSort(A, middle+1, right);
    MergeTwoRuns(A, left, right);
  }
  return 0;
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
  MergeSort(list, 0, count-1);
  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}
