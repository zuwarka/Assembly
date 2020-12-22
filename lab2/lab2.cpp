#include <iostream> 
using namespace std; 
//19. Y = (2A^3 - 4A^2)/B^2 
int main()  
{  
    unsigned int A, B, Y, rema;  
    cout << "Input your A and B values: " << endl;  
    cin >> A;  
    cin >> B;  
    __asm  
    {   
        mov eax, A   
        mul eax   
        mov ebx, 2   
        mul ebx  
        mov Y, eax   
        mov eax, A   
        sub eax, 2   
        mov ebx, Y   
        mul ebx   
        mov Y, eax    
        mov eax, B   
        mul eax   
        mov ebx, eax   
        mov eax, Y    
		    mov edx, 0
        div ebx   
        mov Y, eax   
        mov rema, edx   
    }  
    printf("The answer is: %d\n", Y); 
    printf("The reminder is: %d\n", rema);  
    return 0; 
}
