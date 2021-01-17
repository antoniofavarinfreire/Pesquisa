#include<stdio.h>
#include<string.h>
#include<math.h>

//Default
double fator_subr = 40;
float gamna[2] = {7.0, 14.0};
float alpha[2] = {4.1, 7.0};
float R0_ [2] = {2.5, 6.0}; 





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
    return 0;
}