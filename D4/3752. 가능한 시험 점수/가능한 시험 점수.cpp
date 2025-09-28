#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
	int T = 0;	// TestCase(배점 가능성)
	int N = 0;	// 배점 개수
	int total_sum = 0;
	int possible[10001] = { 0 };	// 나올 수 있는 모든 배점 값
	int count = 0;	// 나올 수 있는 배점 개수


	int scores[101] = { 0 };
	int* result;

	scanf("%d", &T);
	//Testcase T번 돌리기 결정
	result = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++)
	{
		total_sum = 0;
		count = 0;
		memset(possible, 0, sizeof(possible));
		memset(scores, 0, sizeof(scores));

		scanf("%d", &N);

		for (int j = 0; j < N; j++)
		{
			scanf("%d", &scores[j]);
			total_sum += scores[j];
		}

		possible[0] = 1;
		// 인덱스는 점수를 뜻함. 0은 나올 수 있는 배점이라는 뜻(1=true)

		for (int x = 0; x < N; x++)
		{
			for (int y = total_sum; y >= 0; y--)
			{
				if (possible[y] == 1)
					possible[(y + scores[x])] = 1;
				// 가능한 배점에 입력한 배점을 더한 값은 나올 수 있는 배점이다.
			}
		}

		for (int c = 0; c <= total_sum; c++)
		{
			if (possible[c] == 1)
				count++;
		}
		result[i] = count;

	}

	for (int i = 0; i < T; i++)
	{
		printf("#%d %d\n", i + 1, result[i]);
	}
	free(result);

	return 0;
}