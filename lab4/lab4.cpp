#include <iostream>
#define N 6
using namespace std;
//19. Переписать из массива А в массив В те элементы массива А, индексы которых совпадают со значениями
int main()
{
	int id = 0, A[N], B[N];
	printf("Input your string A: \n");
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		B[i] = 0;
	__asm
	{
		mov ebx, N
		mov ecx, id

		Looping:
		mov eax, [A + (type A) * ecx]
		cmp ecx, eax
		jne Toward
		mov [B + (type B) * ecx], eax

		Toward:
		dec ebx
		inc ecx
		cmp ebx, 0
		jne Looping

	}
	printf("The result string B is:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}
