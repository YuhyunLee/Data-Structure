#include "UsefulHeap.h"
#include <iostream>
using namespace std;

// �켱���� �����ִ� ���� �Լ�
// ��ȯ �� > 0		n1�� �켱������ ����
// ��ȯ �� = 0		n1�� n2�� �켱������ ����
// ��ȯ �� < 0		n2�� �켱������ ����
int PriComp(int n1, int n2)
{
	return n2 - n1;			// �������� �����̱� ������
}

// �� ���� �Լ�
void HeapSort(int arr[], int len, PriorityComp comp)
{
	Heap heap(comp);	// �� ���� �� �ʱ�ȭ

	for (int i = 0; i < len; i++)
		heap.HInsert(arr[i]);		// ���� ������ �־��ָ� �˾Ƽ� ����

	for (int i = 0; i < len; i++)
		arr[i] = heap.HDelete();	// �ٽ� ���� �迭�� ���� ������� �־���
}

int main(void)
{
	int arr[4] = { 3,4,2,1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);
	return 0;
}