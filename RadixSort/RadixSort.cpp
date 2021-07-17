#include "ListBaseQueue.h"
#include <iostream>
using namespace std;

// ��� ���� LSD ���� ����

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)
{
	// ����(ť) ���� �� �ʱ�ȭ
	Queue buckets[BUCKET_NUM];
	int bi;				// ���� �� ���° ��������
	int pos;			// ������ ���� �� ���°����
	int di;				// ������ ���� �� �°����
	int divfac = 1;		// N��° �ڸ� ������ ���� ������
	int radix;			// ������ N��° �ڸ� ����


	// ���� �� ������ ���̸�ŭ �ݺ�
	for (pos = 0; pos < maxLen; pos++)
	{
		// ���� ����� ��(= ������ ����)��ŭ �ݺ�
		// ==> �ѹ� �ݺ��Ҷ����� N��° �ڸ� �����ؼ� �װ� �������� ���� !!

		// �����ؼ� ���Ͽ� ����
		for (di = 0; di < num; di++)
		{
			// N��° �ڸ� ����
			radix = arr[di] / divfac % 10;
			// �����͸� �˸��� ���Ͽ� ����
			buckets[radix].Enqueue(arr[di]);
		}

		// ���Ͽ��� �����鼭 ����
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
		{
			// ���� 0���� 9���� ���� ������� �ٽ� ������ arr�� ����
			while(!buckets[bi].QIsEmpty())
				arr[di++] = buckets[bi].Dequeue();
		}

		// ���� ��° �ڸ� ���� ���� ������ ����
		divfac *= 10;
	}
	
	
}

int main(void)
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	return 0;
}