#include <stdio.h>

//find min
//delete min
//decrease key
//merge


//Bottom Up to build a Heap!
int AdjustHeap(int A[], int i, int n){ //Adjust Root i, Tree[0]~Tree[n]
  int temp, j;
  temp = A[i];
  int j = i*2;
  while(j<=n){ //Still have children
    if(j<n){ //Still have right sibling????
      if(A[j]<A[j+1]) //
        j++;
    }
  }

}

int main(){
  int count, i;
  scanf(" %d", &count);
  int heap[count];
  for(i = 0; i < count; i++){
    scanf(" %d", &heap[i]);
  }
  for(i = 0; i < count; i++){
    AdjustHeap(heap, i);
  }
  for(i = 0; i < count; i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
  return 0;
}

/*
Paret: (i-1)/2
Current: i
Left: i*2+1
Right: i*2+2
*/

//Insert to build a Heap!
int InsertHeap(int A[], int i){
  int temp = A[i];
  while( temp > A[(i-1)/2] ){
    A[i] = A[(i-1)/2]; //Parent move down
    i = (i-1)/2;
    if(i==0)
      break;
  }
  A[i] = temp;
}

int main(){
  int count, i;
  scanf(" %d", &count);
  int heap[count];
  for(i = 0; i < count; i++){
    scanf(" %d", &heap[i]);
  }
  for(i = 0; i < count; i++){
    InsertHeap(heap, i);
  }
  for(i = 0; i < count; i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
  return 0;
}
