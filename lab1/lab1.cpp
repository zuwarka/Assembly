#include <iostream> 
using namespace std; 
//19. Y = (2A^3 - 4A^2)/B^2 
int main()  
{  
  int A, B, Y, rema;  
  cout << "Input your A and B values: " << endl;  
  cin >> A;  
  cin >> B;  
  __asm  
  {   
    mov eax, A   
    imul eax   
    mov ebx, 2   
    imul ebx   
    mov Y, eax   
    mov eax, A   
    sub eax, 2   
    mov ebx, Y   
    imul ebx   
    mov Y, eax    
    mov eax, B   
    imul eax   
    mov ebx, eax   
    mov eax, Y   
    cdq   
    idiv ebx   
    mov Y, eax   
    mov rema, edx   
  }  
  printf("The answer is: %d\n", Y);  
  printf("The reminder is: %d\n", rema);  
  return 0; 
} 
