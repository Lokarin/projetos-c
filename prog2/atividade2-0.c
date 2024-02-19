#include <stdio.h>  
 
void chg(int *p, int v) 
{  
  *p = *p + v;  
}  
int main(void)   {  
  int y=1, *py, x[]={88, 77, 66}, *px;  
  py = &y;   
  px = &x[0];  
  printf ("A. val. apontado por px = %d\n", *px);  
  px++;  
  printf ("B. val. apontado por px = %d\n", *px);  
  chg(py, -3);  
  printf ("C. y = %d\n", y);  
  y--;  
  printf("D. val. apontado por py = %d\n", *py);  
  *px = *py - 10;  
  printf("E. val. apontado por px = %d\n", *px);  
  printf("F. x[0]: %d, x[2]: %d\n", x[0], x[2]);  
  printf("G. Op: = %d\n", (x[0]-80) | (x[2]-60));  
  return(0);  
}
