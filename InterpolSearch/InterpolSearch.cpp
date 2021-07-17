#include <iostream>
using namespace std;

int ISearch(int ar[], int first, int last, int target)		// target�� �ε��� �� ��ȯ
{
	int mid;

	if (target < ar[first] || target > ar[last])
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;		// mid�� ����

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;


	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;


	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);

	if (idx == -1)
		cout << "Ž�� ����" << endl;
	else
		cout << "Ÿ�� ���� �ε���: " << idx << endl;

	return 0;
}