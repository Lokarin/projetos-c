#include <stdio.h> 
#include <stdlib.h> 
 
int main()    //Media de 3 notas 
 
{ 
    float n1, n2, n3, media=0; 
    puts("Digite a primeira nota:"); 
    scanf("%f",&n1); 
    puts("Digite a segunda nota:"); 
    scanf("%f",&n2); 
    puts("Digite a terceira nota:"); 
    scanf("%f",&n3); 
    if (media > 7) 
    { 
        media = (n1 + n2 + n3) / 3; 
        printf("Aprovado. Media: %f", media); 
    } 
    else 
    { 
        printf("Reprovado. Media: %f", media); 
    } 
    return 0; 
}
