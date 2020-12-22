#include <iostream>
using namespace std;
//Для длинного целого
int main()
{
		long int X;
    int lenlong = 0, maxlong = 0; //Длина последовательных единичных разрядов 16-бит числа и 32-бит числа
		cout << "Input your 32-bit number X: ";
		cin >> X;
	
		__asm
		{
			mov eax, X
			mov ecx, 32
	
			Cycle:
			shr eax, 1
			jb Onebit
			mov lenlong, 0
			jmp Looping
	
			Onebit:
			mov ebx, lenlong
			add ebx, 1
			mov lenlong, ebx
			mov maxlong, ebx
			jmp Looping
	
			Looping:
			loop Cycle
		}

		cout << "A length of inputting 32-bit number X is: ";
		cout << maxlong << endl;
		return 0;
}
