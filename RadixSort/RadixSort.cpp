#include "ListBaseQueue.h"
#include <iostream>
using namespace std;

// 기수 정렬 LSD 기준 정렬

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)
{
	// 버켓(큐) 생성 및 초기화
	Queue buckets[BUCKET_NUM];
	int bi;				// 버켓 중 몇번째 버켓인지
	int pos;			// 데이터 길이 중 몇번째인지
	int di;				// 데이터 개수 중 몇개째인지
	int divfac = 1;		// N번째 자리 추출을 위한 피제수
	int radix;			// 추출한 N번째 자리 저장


	// 가장 긴 데이터 길이만큼 반복
	for (pos = 0; pos < maxLen; pos++)
	{
		// 정렬 대상의 수(= 데이터 개수)만큼 반복
		// ==> 한번 반복할때마다 N번째 자리 추출해서 그걸 기준으로 정렬 !!

		// 추출해서 버켓에 저장
		for (di = 0; di < num; di++)
		{
			// N번째 자리 추출
			radix = arr[di] / divfac % 10;
			// 데이터를 알맞은 버켓에 저장
			buckets[radix].Enqueue(arr[di]);
		}

		// 버켓에서 꺼내면서 정렬
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
		{
			// 버켓 0부터 9까지 들어온 순서대로 다시 꺼내서 arr에 저장
			while(!buckets[bi].QIsEmpty())
				arr[di++] = buckets[bi].Dequeue();
		}

		// 다음 번째 자리 추출 위해 피제수 증가
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