/* Programma che attraverso un ciclo WHILE fornisce il binomiale di due numeri n e k LDC*/

#import <stdio.h>

int main(){
  int n,k,i=1;
  double prod=1;
  printf("Inserisci due numeri interi maggiori di 0 di cui calcolare il binomiale (ricorda che il primo deve essere più grande del secondo) \n:");
  scanf("%d %d", &n, &k);
  while ((k<0|| k>n)&&i>6){
    printf("Inserire dei valori consentiti: ");
    scanf("%d %d", &n, &k);
    i++;
  }
  if (k<0 || k>n){
    return 1;
  }
  for (int j=1; j<=n-k; j++){
      prod *= float(k+j)/j;
  }
  printf("Il binomiale tra %d e %d vale %d",n,k,int(prod));
  return 0;
}
