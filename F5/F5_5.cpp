#include <stdio.h>
#define N 100

int main(){
  int n, cont=0;
  float arr[N];
  printf("Inserisci il valore del numero intero tra 0 e 10: ");
  scanf("%d", &n);
  if (n<0||n>10) return 1;
  for (int i=0; i<n; i++){
    printf("\n Inserire il valore del coeficente di x^%d: ",i);
    scanf("%f", &arr[i]);
  }
  double result = arr[n - 1],x;
  printf("\n Scrivi il valore della x di cui vuoi calcolare il polinomio: ");
  scanf("%lf", &x);
    for (int i=n-2; i>=0; i--){
      result = result*x+arr[i]; //Attento a non mettere *= altrimenti fai danni con la somma
    }
  printf("\n Il valore calcolato è: %f", result);
  return 0;
}
