//Progrmma che esegue una serie limitata k=0,...,n di r^k: r(reale) e n(intero)

#include <stdio.h>
#include <math.h>
int main(){
  int n;
  float sum=1,r,prod, power=1;
  printf("Inserisci un numero reale (diverso da 1) e un numero intero:\n");
  scanf("%f %d",&r,&n);
  for (int i=1;i<=n;i++){
    prod=1;
    for (int k=0;k<i;k++){
      prod*=r;
    }
    sum+=prod;
  }
  for (int j=0; j<n+1; j++)
    power = r;
  printf("\n Il valore fornito dal nostro algoritmo è %f mentre il valore ottenuto tramite l'elevazione a potenza è %f",sum, float(1-power)/(1-r));
}
