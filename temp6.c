#include <stdio.h> 
 
int main (void) 
{ 
     int i; 
     int n; 
     int f = 1; 
     printf("Digite um número inteiro não negativo:"); 
     scanf("%d", &n); 
                                       
   for (i = 1; i <= n; i++) 
  { 
           f *= i; 
   } 
   printf(" Fatorial = %d \n", f); 
   return 0; 
} 
