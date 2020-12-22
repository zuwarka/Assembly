#include <iostream>
using namespace std;

//Определить, является ли симметричным двоичное представление числа Х

//Для натурального 16-тиразрядного
int main()
{
	unsigned short int X;
	unsigned short int countbit = 0, midbit = 0, left = 0, right = 0, bits[15], sym = 0;
	cout << "Input X: ";
	cin >> X;
	for (int i = 0; i < 15; i++)
		bits[i] = 0;

	__asm
	{
		mox ax, X
		mov bx, countbit

		Iteration:
		shr ax, 1
		cmp ax, 0
		je Enditeration
		inc bx
		jmp Iteration

		Enditeration: 
		mov countbit, bx
		mov ax, bx
		mov bx, 2
		div bx
		mov midbit, bx 
		xor bx, bx

		cmp dx, 0
		je Even
		Odd:

		mov ax, X
		mov cx, countbit

		Cycle:
		dec cx
		shr ax, 1
		jb Right
		mov [bits + (type bits)*cx], 0
		jmp Step1
		Right:
		mov [bits + (type bits) * cx], 1
		Step1:
		cmp cx, 0
		jne Cycle
		
		mov cx, midbit
		mov si, 0
		mov di, countbit
		dec di
		Mirroring:
		mov ax, [bits + (type bits) * si]
		mov bx, [bits + (type bits) * di]
		inc si
		dec di
		dec cx
		cmp cx, 0
		je Wayout
		cmp ax, bx
		je Mirroring
		jmp Endodd

		Wayout:
		jmp Endsym

		Even:
		mov ax, X
		mov cx, countbit

		Cycleeven:
		dec cx
		shr ax, 1
		jb Righteven
		mov [bits + (type bits) * cx], 0
		jmp Step2
		Rightenen:
		mov [bits + (type bits) * cx], 1
		Step2:
		cmp cx, 0
		jne Cycleeven

		mov cx, midbit
		mov si, 0
		mov di, countbit
		dec di
		Mirroringeven:
		mov ax, [bits + (type bits) * si]
		mov bx, [bits + (type bits) * di]
		inc si
		dec di
		dec cx
		cmp cx, 0
		je Wayout
		cmp ax, bx
		je Mirroringeven
		jmp Endodd

		Endsym:	
		mov sym, 1
		jmp End

		Endodd:
		mov sym, 0
		jmp End

		End:
	}
	cout << "Your X is ";
	if (sym == 0)
		cout << "non-";
	cout << "symmetrical" endl;
	return 0;
}
