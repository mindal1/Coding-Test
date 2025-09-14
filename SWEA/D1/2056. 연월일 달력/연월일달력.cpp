#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	int T;
	// 총 테스트 케이스의 개수

	int date = 0;
	int year, month, day = 0;
	int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	scanf("%d", &T);

	char** results;
	char imsi[100];
	int size=0;
	
	results = (char**)malloc(sizeof(char*) * T);
	//T값에 맞춰 포인터를 저장할 공간을 동적할당

	for(int n=0; n < T; n++)
	{ 
		scanf("%d", &date);
		year = date / 10000;
		month = (date / 100) % 100;
		day = date % 100;

		if ((month >= 13)||(month <=0)||(day<=0)||(day > daysInMonth[month]))
		{
			sprintf(imsi, "#%d -1", (n + 1));
		}

		else
		{
			sprintf(imsi, "#%d %04d/%02d/%02d", (n + 1), year, month, day);
			//results[n]=("#%d %d/%02d/%02d\n", n, year, month, day);
			//%02d
			//2: 출력 폭(자릿수) 최소 2자리 출력
			//0: 빈칸을 0으로 채움 

		}
		size = strlen(imsi);
		results[n] = (char*)malloc((sizeof(char) * size) + 1);

		strcpy(results[n], imsi);
	}

	for (int n = 0; n < T; n++)
	{
		printf("%s\n",results[n]);
	}

	for (int n = 0; n < T; n++)
	{
		free(results[n]);
	}

	return 0;
}