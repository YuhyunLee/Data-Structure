#include "UsefulHeap.h"
#include <iostream>
using namespace std;

// 우선순위 정해주는 기준 함수
// 반환 값 > 0		n1이 우선순위가 높음
// 반환 값 = 0		n1과 n2의 우선순위가 같음
// 반환 값 < 0		n2이 우선순위가 높음
int PriComp(int n1, int n2)
{
	return n2 - n1;			// 오름차순 정렬이기 때문에
}

// 힙 정렬 함수
void HeapSort(int arr[], int len, PriorityComp comp)
{
	Heap heap(comp);	// 힙 생성 및 초기화

	for (int i = 0; i < len; i++)
		heap.HInsert(arr[i]);		// 힙에 데이터 넣어주면 알아서 정렬

	for (int i = 0; i < len; i++)
		arr[i] = heap.HDelete();	// 다시 원래 배열에 정렬 순서대로 넣어줌
}

int main(void)
{
	int arr[4] = { 3,4,2,1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);
	return 0;
}