//Programma che dati tre numeri forniti dall'utente, ne trova il valore assoluto e dopodiché ne trova il più grande
#import <stdio.h>

int main(){
  int a,b,er; //Definiamo 2 numeri;

  printf("Scrivi due numeri interi, metti lo spazio tra ogni numero '1 2'");
  scanf("%d %d", &a, &b);
  if (a<0&&b<0){
    printf("L'area del rettangolo è %d mentre il perimentro è %d",a*b+2*(a+b));
  } else if (a==0||b==0){
    er = 1;
    printf("Il rettangolo è degenere");
  } else {
    er = 1;
    printf("Inserisci un valore valido");
  }
  if (errore != 1){
    printf("\n Il maggiore dei numeri è %d",max);
    return 0;
  } else {
    printf("\n Uno dei numeri è non accettabile, riprova inserendo altri valori");
    return 1;
  }
}
//2147483647
