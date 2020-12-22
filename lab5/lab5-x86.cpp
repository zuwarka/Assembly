#include <iostream>
using namespace std;
/*19. В числе Х определить длину самой большой последовательности из единичных разрядов*/
//Для натурального 16-тиразрядного
int main()

{
		unsigned short int X;
    unsigned short int lenshort = 0, maxshort = 0; //Длина последовательных единичных разрядов и максимальная длина
		cout << "Input your 16-bit number X: ";
		cin >> X;
		
		__asm
		{
			mov ax, X
			mov cx, 16

			Cycle:
			shr ax, 1
			jb Onebit
			mov lenshort, 0
			jmp Looping

			Onebit:
			mov bx, lenshort
			add bx, 1
			mov lenshort, bx
			mov maxshort, bx
			jmp Looping
	
			Looping:
			loop Cycle
		}

		cout << "A length of inputting 16-bit number X is: ";
		cout << maxshort << endl;
		return 0;
}
