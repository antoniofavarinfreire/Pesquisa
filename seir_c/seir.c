#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include "log_normal.h"
//gcc -o monstrinho prog1.o prog2.o prog3.o ...
//gcc -o nome nome.c -lm
//Default
double fator_subr = 40;
float gamna[2] = {7.0, 14.0};
float alpha[2] = {4.1, 7.0};
float R0_ [2] = {2.5, 6.0}; 

void run_SEIR_BAYES_model(float N, float E0, float I0, float R0,
                          float *R0_params, float *gamna_inv_params,
                          float *alpha_inv_params, float fator_subr,
                         float t_max, float runs);



int main(){
    float N = 13000000;
    float R0_params[2], gamma_inv_params[2], alpha_inv_params[2];
    float E0, I0, R0;
    float t_max, runs;
    float mean, std;
    int i=0;
    E0 = 300;
    I0 = 250;
    R0 =1;
    t_max = 30*6;
    runs = 1000;
    
    //construção de outra variavel.
    /*mean = gamna[i] * gamna[i+1];
    printf("%f", mean);*/
       
    mean = pow((gamna[i]*gamna[i+1]),0.5);
    printf("Meam = %f \n", mean);
    std = pow((gamna[i]/gamna[i+1]),0.25);
    printf("std = %f \n", std);

    gamma_inv_params[i] = mean;
    gamma_inv_params[i+1] = std;
    mean = 0;
    std = 0;
    i=0;
    for(i=0;i<2;i++){
        printf("%f\n", gamma_inv_params[i]);
    }

    printf("\n");

    mean = pow((alpha[i]*alpha[i+1]),0.5);
    printf("Meam = %f \n", mean);
    std = pow((alpha[i]/alpha[i+1]),0.25);
    printf("std = %f \n", std);
    i=0;
    alpha_inv_params[i] = mean;
    alpha_inv_params[i+1] = std;
    mean = 0;
    std = 0;
    for(i=0;i<2;i++){
        printf("%f\n", alpha_inv_params[i]);
    }
    i=0;
    printf("\n");

    mean = pow((R0_[i]*R0_[i+1]),0.5);
    printf("Meam = %f \n", mean);
    std = pow((R0_[i]/R0_[i+1]),0.25);
    printf("std = %f \n", std);
    i=0;
    R0_params[i] = mean;
    R0_params[i+1] = std;
    for(i=0;i<2;i++){
        printf("%f\n", R0_params[i]);
    }
    i=0;

    run_SEIR_BAYES_model(N, E0, I0, R0,  R0_params, gamma_inv_params,
                          alpha_inv_params, fator_subr,
                          t_max,  runs);
    /*int teste[2];
    teste[i] = 0;
    teste[i+1] = 1;
    i=0;
    for(i=0;i<2;i++){
        printf("Teste %d", teste[i]);
    }*/
    return 0;
}

void run_SEIR_BAYES_model(float N, float E0, float I0, float R0,
                          float *R0_params, float *gamna_inv_params,
                          float *alpha_inv_params, float fator_subr,
                         float t_max, float runs){

    printf("Entrou na função\n");
    I0 = fator_subr * I0;
    printf("I0 = %f\n", I0);
    E0 = fator_subr * E0;
    float S0 = N - (I0 + R0 + E0);
    float size[2];
    size[1] = t_max;
    size[2] = runs;
    int i = 0;
    float S[2], E[2], I[2], R[2];
    S[i] = 0;
    S[i+1] = S0;
    i=0;

    E[i] = 0;
    E[i+1] = E0;
    i=0;

    I[i] = 0;
    I[i+1] = I0;
    i=0;

    R[i] = 0;
    R[i+1] = R0;
    i=0;
  
    double x = R0_params[i];
    double mu = R0_params[i+1];

    R0 = log_normal_cdf(x, mu, runs);
    x = 0;
    mu = 0;
    i=0;

    double gamma;
    x = gamna_inv_params [i];
    mu = gamna_inv_params [i+1];
    gamma = 1/(log_normal_cdf(x, mu,runs));
    x = 0;
    mu = 0;    
    i=0;

    double alpha;
    x = alpha_inv_params [i];
    mu = alpha_inv_params [i+1];
    alpha = 1 / (log_normal_cdf(x,mu,runs));
    x = 0;
    mu = 0;
    i=0;

    double beta;
    beta = R0 * gamma;  
    //printf("R0 = %f\n", R0);
    //for(i=t_max ; i>0 ; i--){

    //}  
    printf("R0 = %f\n", R0);
    printf("gamma = %f\n", gamma);
    printf("aplha = %f\n", alpha);
    printf("beta = %f\n", beta);
    
}
