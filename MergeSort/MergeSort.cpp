#include <iostream>
using namespace std;

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = new int[right + 1];		// ���ĵ� �迭�� ���� ���ο� �迭 �����Ҵ�
	int sIdx = left;	// sortArr�� �ε��� �� ������ ����

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		
		sIdx++;
	}

	// ���� ������ �־� �ֱ�
	if (fIdx > mid)			// �� �κ��� ��� �Ű����ٸ�
	{
		for (int i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else					// �� �κ��� ��� �Ű����ٸ�
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	// sortArr�� ������ ������� arr�� �Ű��ֱ�
	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete[] sortArr;
}

// ���� ���� �Լ�
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)		// �����Ͱ� �� �� �̻�, �� �� ���� �� �ִٴ� ��
	{
		mid = (left + right) / 2;

		// ����
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// ���� & ����
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	
	// �迭 arr ���� ����
	MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);

	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	return 0;
}