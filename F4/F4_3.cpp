/* Programma che eleva a potenza un numero reale per un esponente intero*/

#import <stdio.h>
#import <math.h>

int main(){
  int n;
  float x,prod=1;
  printf("Inserisci due numeri il primo (reale) la base, il secondo (intero) l'esponente: \n");
  scanf("%f %d",&x,&n);
  float pow = pow(x,n);
  if (n>0){
    for (int i=0;i<n;i++){
      prod*=x;
    }
    printf("Il valore di %f^%d dato dal nostro algirtmo è %f mentre quello di math.h è %f /n", x,n,prod,pow);
  } else if (x<0) {
    for (int i=0;i<n;i++){
      prod*=1./x;
    }
    printf("Il valore di %f^%d dato dal nostro algirtmo è %f mentre quello di math.h è %f /n", x,n,prod,pow);
  } else {
    printf("Inf");
    return 1;
  }
  return 0;
}
