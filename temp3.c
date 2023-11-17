#include <stdio.h> 
 
float proc(float n, int rep, int y) 
{ 
    int k, x=0; 
    for (k = 0; k < rep; k++) 
    { 
        n = n*y; 
        x += y; 
        printf("Proc: %d %.1f %d\n", k, n, x); 
    } 
    return n; 
} 
int main(void) 
{ 
    int r=4; 
    float num=2; 
    float result; 
    printf("Valor: %.2f\n", num); 
    result=proc(num, r, 2); 
    float result2=proc(8, 2, 2); 
    printf("Resultado: %.2f\n", result); 
    printf("Resultado2: %.2f\n", result2); 
    return 0; 
} 
