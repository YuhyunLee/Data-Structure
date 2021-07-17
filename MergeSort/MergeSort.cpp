#include <iostream>
using namespace std;

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = new int[right + 1];		// 정렬된 배열을 담을 새로운 배열 동적할당
	int sIdx = left;	// sortArr의 인덱스 값 저장할 변수

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		
		sIdx++;
	}

	// 남은 데이터 넣어 주기
	if (fIdx > mid)			// 앞 부분이 모두 옮겨졌다면
	{
		for (int i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else					// 뒷 부분이 모두 옮겨졌다면
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	// sortArr의 값들을 순서대로 arr로 옮겨주기
	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete[] sortArr;
}

// 병합 정렬 함수
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)		// 데이터가 한 개 이상, 즉 더 나눌 수 있다는 뜻
	{
		mid = (left + right) / 2;

		// 분할
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// 병합 & 정렬
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	
	// 배열 arr 병합 정렬
	MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);

	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	return 0;
}