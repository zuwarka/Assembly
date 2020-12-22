#include <iostream>
#define N 50
using namespace std;

//натуальное 16-тиразрядное
int main(void)
{
	unsigned short int X;
	//unsigned short 
	//unsigned short int countbit = 0;
	int countbit = 0, midbit = 0, bits[N], sym = 0;
	cout << "Input X: ";
	cin >> X;
	for (int i = 0; i < N; i++)
		bits[i] = 0;

	__asm
	{
		mov ax, X
		mov ebx, countbit

		Iteration:
		shr ax, 1
		inc ebx
		cmp ax, 0
		je Enditeration
		jmp Iteration

		Enditeration:
		mov countbit, ebx
		mov eax, countbit
		mov ebx, 2
		mov edx, 0
		div ebx 
		mov midbit, eax
		xor eax, eax

		cmp edx, 0
		je Even1
		xor eax, eax
		mov ax, X
		mov ecx, countbit

		Cycle:
		dec ecx
		shr ax, 1
		jb Right
		mov [bits + (type bits) * ecx], 0
		jmp Step1
		Right:
		mov [bits + (type bits) * ecx], 1
		Step1:
		cmp ecx, 0
		jne Cycle

		mov ecx, midbit
		mov esi, 0
		mov edi, countbit
		dec edi
		Mirroring:
		cmp ecx, 0
		je Wayout
		mov eax, [bits + (type bits) * esi]
		mov ebx, [bits + (type bits) * edi]
		inc esi
		dec edi
		dec ecx
		cmp eax, ebx
		je Mirroring
		jmp Endodd

		Wayout:
		jmp Endsym

		Even1:
		mov ax, X
		mov ecx, countbit

		Cycleeven:
		dec ecx
		shr ax, 1
		jb Righteven
		mov [bits + (type bits) * ecx], 0
		jmp Step2
		Righteven:
		mov [bits + (type bits) * ecx], 1
		Step2:
		cmp ecx, 0
		jne Cycleeven

		mov ecx, midbit
		mov esi, 0
		mov edi, countbit
		dec edi
		Mirroringeven:
		cmp ecx, 0
		je Wayout
		mov eax, [bits + (type bits) * esi]
		mov ebx, [bits + (type bits) * edi]
		inc esi
		dec edi
		dec ecx
		cmp eax, ebx
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
	cout << "symmetrical";
	return 0;
}
