#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void cal(int arr[], int n)
{
	int high = 0;
	long long total = 0;

	// 배열 뒤부터 high를 찾고 arr[i]가 high보다 작을 경우 total갱신
	for (int i = n-1; i > -1; i--)
	{
		if (arr[i] > high)
			high = arr[i];
		else
			total += (high - arr[i]);
	}
	printf(" %lld\n", total);
}

int main()
{
	int T = 0;	//테스트케이스
	int N = 0;	//N일	2~1,000,000 사이

	int *sale_price;	//매매가 10,000이하


	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		sale_price = (int*)malloc(sizeof(int) * N);
		if (sale_price == NULL)	return -1;

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &sale_price[i]);
		}
		printf("#%d", i + 1);
		cal(sale_price, N);
		
		free(sale_price);
	}
	
	return 0;
}