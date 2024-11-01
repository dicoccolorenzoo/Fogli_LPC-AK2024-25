/* Programma che attraverso un ciclo FOR fornisce
una volta che l'utente ne inserisce il numero (che viene cambiato per evitare overflow o errori)
n valori appartenti alla successione di fibonacci */

#import <stdio.h>

int main(){
  int a=0,b=1,n;
  printf("Inseire il numero di valori della serie di Fibonacci da voler visualizzare:");
  scanf("%d",&n);
  if (n<0)n*=-1;
  if (n==0)n=1; else if (n>47)n=n-n/47*47;
  if (n==1){
    printf("\n %d",a);
  } else {
    printf("\n %d \t %d",a,b);
    for (int i=0;i<n-2;i++){
      b = a + b;
      printf("\t %d",b);
      a = b - a;
    }
  }
  return 0;
}
