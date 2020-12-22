#include <iostream>
using namespace std;
//19. Обнулить одну из четырех ячеек, где находится минимальное число
int main()

{
	int A, B, C, D, min;
	cout << "Input yours A, B, C, D values: " << endl;
	cin >> A; 
	cin >> B;	
	cin >> C;
	cin >> D;
	__asm
	{
		mov eax, A
		cmp eax, B
		jl Proc1
		mov eax, B
		mov min, eax
		Back:
		mov eax, C
		cmp eax, min
		jl Proc2
		Back1:
		mov eax, D
		cmp eax, min
		jl Proc3
		jmp Result

		Proc1:
		mov min, eax
		jmp Back
		Proc2:
		mov min, eax
		jmp Back1
		Proc3:
		mov ebx, D
		mov min, ebx
		jmp Result

		Result:
		mov eax, min
		cmp eax, A
		je Answer1
		Findother1:
		cmp eax, B
		je Answer2
		Findother2:
		cmp eax, C
		je Answer3
		Findother3:
		cmp eax, D
		je Answer4
		jmp Exit

		Answer1:
		mov A, 0
		jmp Findother1
		Answer2:
		mov B, 0
		jmp Findother2
		Answer3:
		mov C, 0
		jmp Findother3
		Answer4:
		mov D, 0
		jmp Exit

		Exit:
	}
	printf("The answer is: %d %d %d %d\n", A, B, C, D);
	return 0;
}
