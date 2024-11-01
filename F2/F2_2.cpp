/* Programma che permette a l'utente di scegliere tra 4 opzioni:
Media Aritmetica, Geometrica, Armonica, Quadratica
Successivamente fa inserire un numero di valori di cui calcolare la media infine stampa la media */

#import <stdio.h>
#import <math.h>

int main(){
  int a, i, n;
  double x, sum;
  printf("Inserisci il tipo di media che vuoi applicare \n [1]Aritmetica \t [2]Geometrica \t [3]Armonica \t [4]Quadratica:");
  scanf("%d", &a);
  printf("\n Di quanti valori vuoi fare la media?");
  scanf("%d", &n);
  if (a!=1&&a!=3&&a!=4){sum=1;}
  for (i=0;i<n;i++){
    printf("\n Inserisci il %d° valore ---> ", i+1);
    scanf("%lf",&x);
    switch (a){
      case 1: sum+=x;
      break;
      case 2: sum*=x;
      break;
      case 3: sum+=1./x;
      break;
      case 4: sum+=x*x;
      break;
      default: sum*=x;
      break;
    }
  }
  if (a==1){sum = sum/n;} else if (a==2) {sum = pow(sum,1./n);} else if (a==3) {sum = n/sum;} else if (a==4){sum = sqrt(sum/n);}else{sum = pow(sum,1./n);}
  printf("La media è: %fl", sum);
}
