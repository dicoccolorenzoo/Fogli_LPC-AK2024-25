/* Programma che attraverso un ciclo WHILE fornisce la sommatoria per k=0,...,n del binomiale tra n e k LDC*/

#import <stdio.h>

int main(){
  int n, sum=0;
  double prod=1;
  printf("Inserisci un numero compreso tra 0 e 30 di cui calcolare l'algoritmo");
  scanf("%d", &n);
  if (n<0||n>=30){
    printf("Il valore inserito non è consentito");
    return 1;
  }
  for (int k=0; k<=n;k++){
    prod=1;
    for (int j=1; j<=n-k; j++){
        prod *= float(k+j)/j;
    }
      sum += int(prod);
  }
  printf("La sommatoria per k=0,...,n del binomiale tra %d e k è %d",n,sum);
  return 0;
}
