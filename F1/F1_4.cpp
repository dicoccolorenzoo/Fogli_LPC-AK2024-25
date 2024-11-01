//Programma che dati tre numeri forniti dall'utente, ne trova il valore assoluto e dopodiché ne trova il più grande
#import <stdio.h>

int main(){
  int a,b,c,max; //Definiamo 3 numeri
  int errore=0;

  printf("Scrivi tre numeri interi, metti lo spazio tra ogni numero '1 2 -3'");
  scanf("%d %d %d", &a, &b, &c);
  if (a<0){ //Ottenuti i valori, se questi sono negativi le rendiamo positivi, se uno dei valori è uguale a 0 diamo un messaggio di errore
    a = -a;
  }
  if (b<0){
    b = -b;
  }
  if (c<0){
    c = -c;
  }
  if (a==0||b==0||c==0){
    errore = 1;
  }

  max = a; //Cerchiamo il numero maggiore tre quelli dati
  if (max<b){
    max = b;
  }
  if (max<c) {
    max = c;
  }

  if (errore != 1){
    printf("\n Il maggiore dei numeri è %d",max);
    return 0;
  } else {
    printf("\n Uno dei numeri è non accettabile, riprova inserendo altri valori");
    return 1;
  }
}
