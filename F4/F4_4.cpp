/* Programma che approssima il pi greco tramite l'algoritmo di archimede*/

#import <stdio.h>
#import <math.h>

int main(){
  double sum=0,fatt;
  for (int k=0;k<=16;k++){
    fatt = 1;
    for (int i=k;i>=1;i--){
      fatt*=i;
    }
    sum+=1./fatt;
  }
  printf("L'errore relativo è %.15f",M_E-sum);
}
