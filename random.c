#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "log_normal.h"

float R0_ [2] = {2.5, 6.0};


int main(){
    double R0_params[2];
    int runs = 4;
    int i = 0;
    
    float mean, std;
    mean = pow((R0_[i] * R0_[i+1]), 0.5);
    std = pow((R0_[i]/R0_[i+1]), 0.25);
    i = 0;
    R0_params [i] = mean;
    R0_params [i+1] = std;

    double x;
    for (i=0;i<2;i++){
        x = R0_params[i];
        R0_params[i] = log(x);
        printf("Log(R0_params[%d] = %f\n",i, R0_params[i]);
    }
    i = 0;
    for (i=0 ; i<2 ; i++){
        printf("R0_params[%d] = %f\n",i, R0_params[i]);
    }
    double mu, sigma, ret;
    int *seed;
    for ( i = 0; i < 2; i++){
        
    }
    
    mu = R0_params[i];
    printf("MU = %f\n");
    sigma = R0_params[i+1];
    printf("Sigama = %f\n");
    seed = runs;
    printf("%d\n", seed);
    ret = log_normal_sample(mu, sigma, seed);
    printf("Sample = %f\n", ret);


    return 0;
}