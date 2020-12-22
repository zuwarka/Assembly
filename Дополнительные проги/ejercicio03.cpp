#include <iostream>
using namespace std;

/*2. Подсчитать вес каждого байта числа Х*/

//Для натурального 16-тиразрядного
int main()
{
	unsigned short int X;
	unsigned short int w1 = 0, w2 = 0; //Вес первого байта числа, вес второго байта числа, буфер для записи (х-1)
	cout << "Your X: ";
	cin >> X;

	__asm
	{
		mov ax, X
		mov ecx, 15

		While:
		shr ax, 1
		jb Plusw
		cmp ecx, 8
		je Approp
		jmp Cycle

		Plusw:
		mov bx, w2
		add bx, 1
		mov w2, bx
		cmp ecx, 8
		je Approp
		jmp Cycle

		Approp:
		mov bx, w2
		xchg w1, bx
		mov w2, 0

		Cycle:
		loop While
	}

	cout << "Weight of the first byte of number X is: ";
	cout << w1 << endl;
	cout << "Weigt of the second one is: ";
	cout << w2 << endl;
	return 0;
}
