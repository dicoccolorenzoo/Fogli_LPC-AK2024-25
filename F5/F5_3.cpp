//

#include <stdio.h>

int main(){
  int n=0,x,sum=0,prod;
  while (n<=0||n>37){
    printf("\n Inserisci il numero di cifre del numero binario: ");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
      x=-1;
      while (x<0||x>1){
        printf("\n Inserisci la %d° cifra da destra: ",i+1);
        scanf("%d",&x);
      }
      prod=1;
      for (int k=1;k<=i;k++){
        prod *= 2;
      }
      sum += prod*x;
    }
  }
  printf("\n Il valore in decimale è %d",sum);
  return 0;
}
