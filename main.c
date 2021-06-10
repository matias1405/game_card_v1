#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	int menu,i,c_jugador[7],v_jugador[7],c_pc[7],v_pc[7],puntaje_j,puntaje_pc;
	srand(time(NULL));
    inicio:
	system("cls");

	printf("\tBLACKJACK\n");
	printf("MENU\n");
	printf(" 1- Jugar al BlackJack\n 2- Leer las Reglas\n 3- Salir\n");
	printf("Elija una opcion\n");
	scanf("%d", &menu);
	switch(menu){
		case 1:
            system("cls");
            for(i=1;i<8;i++){
              c_jugador[i]=1+rand()%13;              
              if(c_jugador[i]==11 || c_jugador[i]==12 || c_jugador[i]==13){
                                  v_jugador[i]=10;
                                  }
              else{
                   v_jugador[i]=c_jugador[i];
                   }
              }
            for(i=1;i<8;i++){
              c_pc[i]=1+rand()%13;             
              if(c_pc[i]==11 || c_pc[i]==12 || c_pc[i]==13){
                                  v_pc[i]=10;
                                  }
              else{
                   v_pc[i]=c_pc[i];
                   }
              }
            printf("Jugador:\n");
            printf(" %d\n %d\n",c_jugador[1],c_jugador[2]);
            printf("Pc;\n");
            printf("%d\n",c_pc[1]);
            puntaje_j=v_jugador[1]+v_jugador[2];
            puntaje_pc=v_pc[1];
            printf("Su puntaje es %d y el puntaje de la pc es %d ¿que desea hacer?\n",puntaje_j,puntaje_pc);
			printf(" %s\n %s\n","1-Plantarse","2-Sacar una carta mas del maso");
            scanf("%d",&menu);
            if(menu==1){
                        goto juega_pc;
                        }
            if(menu==2){
                        for(i=3;i<8;i++){
                                         printf("Jugador:\n");
                                         printf("%d\n",c_jugador[i]);
                                         puntaje_j=puntaje_j+v_jugador[i];
                                         printf("Su puntaje es %d ¿que desea hacer?\n",puntaje_j);
                                         if(puntaje_j>21){
                                                          printf("PERDISTE\n");
                                                          goto preguntar;
                                                          }
			                             printf(" %s\n %s\n","1-Plantarse","2-Sacar una carta mas del maso");
                                         scanf("%d",&menu);
                                         if(menu==1){
                                                     goto juega_pc;
                                                     }
                                         }
                        }
            else{
                 printf("Opcion invalida");
                 system("pause");
                 goto inicio;
                 }
            juega_pc:
                  for(i=2;i<8;i++){
                                   printf("PC:\n");
                                   printf("%d\n",c_pc[i]);
                                   puntaje_pc=puntaje_pc+v_pc[i];
                                   printf("El puntaje de la pc es %d\n",puntaje_pc);
                                   system("pause");
                                   if(puntaje_pc>21){
                                                    printf("GANASTE\n");
                                                    goto preguntar;
                                                    }                                                                                      
                                   if(puntaje_pc>=17){
                                                   goto ganador;
                                                   }
                                   }
            ganador:
            if(puntaje_j>puntaje_pc){
                                     printf("GANASTE\n");
                                     }
            if(puntaje_j<puntaje_pc){
                                     printf("PERDISTE\n");
                                     }
            if(puntaje_j==puntaje_pc){
                 printf("EMPATE\n");
                 }                                         
            break;
		case 2:
            system("cls");
			printf("\nPara empezar, el blackjack es un juego de cartas");
            printf("\ndonde el apostador competira contra la casa o el crupier.\n"); 
            printf("\nEl juego consiste en que los jugadores deberan ir sacando cartas que tienen un valor especifico.\n");
            printf("\nPor ejemplo, todas las cartas de 1 a 10 tienen un valor basado en el numero que aparece en la carta.\n");
            printf("\ntodas las cartas de la corte: jotas, reinas y reyes del mazo tienen un valor de 10 cada una");	
			printf("\nEl objetivo del juego de blackjack es lograr una puntuacion lo mas cerca posible del 21.\n");
            printf("\nEsto debe lograrse sin pasarse del 21. Si no llegas al 21, el objetivo del juego es conseguir una puntuacion mayor a la del crupier.");
            printf("\nPara empezar, el crupier repartira dos cartas del zapato barajado para el jugador"); 
            printf("\nEl crupier tambien se repartira una carta a el mismo.");
            printf("\nUn apostador puede pedir otra carta todas las veces que quiera pero una vez sobrepasan el 21, la mano se ha pasado y pierde\n");
            printf("\nSi el jugador decide plantarse, el crupier sacara una carta. Si el crupier tiene menos de 17, debera continuar sacando cartas hasta que llegue a 17 o mas");
            printf("\nsin pasarse de 21. Cuando el crupier llegue a 17 o mas, se plantara y su puntuacion se comparara con la del jugador");
            
            break;
		case 3:
			goto fin;
			break;
		default:
			printf("Opcion no valida, vuelva a elegir una opcion");
			system("pause");
			goto inicio;
			break;
	  	}
	preguntar:
    printf("\n\n¿Desea salir del programa?\n");
	printf(" %s\n %s\n","1- Si","2- No");
	scanf("%d",&menu);
	if(menu== 2){
		goto inicio;
	}  	
	fin:
	system("PAUSE");	
}
