#include <iostream>
#define N 5
using namespace std;
//2. Наименьший элемент в массиве поменять местами с последним элементом
int main()

{
	int A[N], min = 0, idmin = 0, idlast = N - 1;
	printf("Input your array: \n");
	for (int i = 0; i < N; i++)
		cin >> A[i];
	__asm
	{
		mov ebx, N
		mov ecx, 0
		mov eax, [A + (type A) * ecx]
		mov min, eax
		jmp Proc

		Cycle:
		mov eax, [A + (type A) * ecx]
		Proc:
		cmp eax, min
		jge Notmin
		mov min, eax
		mov idmin, ecx

		Notmin:
		dec ebx
		inc ecx
		cmp ebx, 0
		jne Cycle

		mov ecx, idmin
		mov [A + (type A)*ecx], eax
		mov ecx, idlast
		mov eax, min
		mov [A + (type A)*ecx], eax
	}
	printf("The result array:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
