#include <stdio.h>

void swap(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// standard quicksort partition
void partition(int * A, int left, int right, int *i, int *j) {
  *i = left;
  *j = right;

  int pivoPos = (*i + *j) /2; 
  int pivo = A[pivoPos];
  printf("Pivo: %d\n", pivo);
  printf("Pivo Pos: %d\n", pivoPos);

  do{
    while (pivo > A[*i]) (*i)++;
    while (pivo < A[*j]) (*j)--;
    
    if(*i <= *j){
      swap(&A[*i], &A[*j]);
      (*i)++;
      (*j)--;
    }
    
  }while(*i <= *j);


  for(int x = 0; x < 9; x++){
    printf("%d ", A[x]);
  }
  printf("\n");
  printf("I: %d J: %d\n", *i, *j);

}


// standard quicksort
void quickSort(int * A, int left, int right) {
  int i, j;

  printf("Particao I: %d J:%d\n", left, right);
  partition(A, left, right, &i, &j);
  printf("Particao I: %d J:%d\n", left, right);

  while(left < j) {
    printf("Chamou left\n");
    printf("left: %d j: %d\n", left, j);
    quickSort(A, left, j);
  }
  while(i < right){
    printf("Chamou rigth\n");
    printf("i: %d right: %d\n", i, right);
    quickSort(A, i, right);
  }

}

int main(){
  int t[] = {
    3, 4, 6, 2, 1, 11, 34, 12, 98, 56
  };
  // int t[] = {
  //   3, 4, 6, 2, 1, 11, 34, 12, 98, 56, 
  //   23, 45, 67, 89, 90, 12, 34, 56, 78, 91,
  //   14, 25, 36, 47, 58, 69, 70, 81, 92, 103,
  //   17, 28, 39, 40, 51, 62, 73, 84, 95, 106,
  //   19, 30, 41, 52, 63, 74, 85, 96, 107, 118,
  //   21, 32, 43, 54, 65, 76, 87, 98, 109, 120,
  //   22, 33, 44, 55, 66, 77, 88, 99, 110, 121,
  //   24, 35, 46, 57, 68, 79, 90, 101, 112, 123,
  //   26, 37, 48, 59, 70, 81, 92, 103, 114, 125,
  //   27, 38, 49, 60, 71, 82, 93, 104, 115, 126
  // };


  quickSort(t, 0, 9);

  for(int i = 0; i < 9; i++){
    printf("%d ", t[i]);
  }

  return 0;

}