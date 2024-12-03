#include <stdio.h>
#define N 100

int main(){
  int n, arr[N], cont=0;
  printf("Inserisci il valore del numero intero: ");
  scanf("%d", &n);
  while(n){
    if (n%2) arr[cont]=1;
    else arr[cont]=0;
    n/=2;
    ++cont;
  }
  printf("\n Il valore in binario è: ");
  for (int i=cont-1; i>=0; i--)
    printf("%d",arr[i]);
  return 0;
}
