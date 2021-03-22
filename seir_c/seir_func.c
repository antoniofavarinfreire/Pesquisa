#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include "seir.h"


// Modelo SEIR
void run_SEIR_BAYES_model(float N, float E0, float I0, float R0,
                          float *R0_params, float *gamna_inv_params,
                          float *alpha_inv_params, float fator_subr,
                         float t_max, int runs){

    printf("Entrou na função\n");
    I0 = fator_subr * I0;
    printf("I0 = %.1f\n", I0);
    E0 = fator_subr * E0;
    printf("E0 = %.1f\n", E0);
    float S0 = N - (I0 + R0 + E0);
    printf("S0 = %.1f\n", S0);
    int t_space[1000] ; // criando uma seguencia de 0 à t_max
    
    // Criando t_space
    int i;
    for(i=0;i<t_max; i ++){
      t_space[i] = i;
    }
    
    float S[180][1000];
    float E[180][1000];
    float I[180][1000];
    float R[180][1000];
    int j, k;
    
    
    for(j = 0 ; j < 1 ; j ++){ //Linhas
      for(k = 0 ; k < runs ; k ++){ //Colunas
          S[j][k] = S0; 
      }
    }

    for(j = 0 ; j < 1 ; j ++){ //Linhas
      for(k = 0 ; k < runs ; k ++){ //Colunas
          E[j][k] = E0; 
      }
    }


    for(j = 0 ; j < 1 ; j ++){ //Linhas
      for(k = 0 ; k < runs ; k ++){ //Colunas
          I[j][k] = I0; 
      }
    }

    for(j = 0 ; j < 1 ; j ++){ //Linhas
      for(k = 0 ; k < runs ; k ++){ //Colunas
          R[j][k] = R0; 
      }
    }
    i=0;

    double ret[2];
    double x;    
    for(i=0;i<2;i++){
      x = R0_params[i];
      ret [i] = log(x);
      printf("Log(R0_params[%d] = %f)\n",i, ret[i]);
    }
    /*
    for(j = 0 ; j < 6 ; j ++){ //Linhas
    printf(" (");
      for(k = 0 ; k < 5 ; k ++){ //Colunas
          printf("%f    ", S[j][k]); 
      }
      printf(")\n");
    }
    printf("\n");
    for(j = 0 ; j < 6 ; j ++){ //Linhas
    printf(" (");
      for(k = 0 ; k < 5 ; k ++){ //Colunas
          printf("%f    ", E[j][k]); 
      }
      printf(")\n");
    }
    printf("\n");
    for(j = 0 ; j < 6 ; j ++){ //Linhas
    printf(" (");
      for(k = 0 ; k < 5 ; k ++){ //Colunas
          printf("%f    ", I[j][k]); 
      }
      printf(")\n");
    }
    printf("\n");
    for(j = 0 ; j < 6 ; j ++){ //Linhas
    printf(" (");
      for(k = 0 ; k < 5 ; k ++){ //Colunas
          printf("%f    ", R[j][k]); 
      }
      printf(")\n");
    }*/

    
    

    for (i=t_max ; i>0 ; i --){
        //double SE = binomial((i-1), ());
        //double EI = binomial(, )
    }

    /*
    printf("R0 = %f\n", R0);
    printf("gamma = %f\n", gamma);
    printf("aplha = %f\n", alpha);
    printf("beta = %f\n", beta);
    for(i=0 ; i<2 ; i++){
        printf("S[%d] = %f\n", i, S[i]);
        printf("E[%d] = %f\n", i, E[i]);
        printf("I[%d] = %f\n", i, I[i]);
        printf("R[%d] = %f\n",i, R[i]);
    }*/
    
}

//calculo do log(x)

//Binomial
void binomial(double x, double y){
    int i, j, n, k, min, c[20][20]={0};
    //printf("This program is brought to you by www.c-program-example.com\n" );     
    //printf("\n Enter the value of n: ");     
    //scanf("%d", &n);     
    n = x;
    //printf("\n Enter the value of k: ");     
    scanf("%d", &k);
    k = y;
    if(n >= k) {         
        for(i=0; i<=n; i++) {             
            min = i<k? i:k;
            for(j = 0; j <= min; j++) {
                 if(j==0 || j == i) {
                     c[i][j] = 1;
                 } else {
                     c[i][j] = c[i-1][j-1] + c[i-1][j];
                 }
             }
         }
         printf("%d\t",c[n][k]);
         printf("\n");
     } else {
         printf("\n Invalid input \n Enter value n>=k \n");
     }
}