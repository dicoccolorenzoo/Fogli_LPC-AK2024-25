/* Programma che attraverso un ciclo WHILE fornisce l'MCD e l'mcm LDC*/

#import <stdio.h>

int main(){
  int a,b,pr;
  printf("Inserisci due numeri interi di cui calcolare MCD e mcm (separlai da uno spazio) \n:");
  scanf("%d %d",&a,&b);
  pr = a*b; //Mi salvo il valore effettivo di a e b;
  if (a<0||b<0){
    printf("Alcuni dati inseriti non sono corretti");
    return 1;
  }
  while (a-b!=0){
    if (a<b){
      a = a + b;
      b = a - b;
      a = a - b;
    }
    a = a - b;
  }
  printf("Il massimo comun divisore è: %d \n",b);
  printf("Il minimo comune multiplo è: %d",pr/b);
  return 0;
}
