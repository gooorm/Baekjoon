#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int stepByStep(int flag, int n, int stairs[], int** M, int lastStep) {

	if (flag == n)
		return stairs[n];

	if (lastStep == 1) {
		if (M[flag + 2][2] == 0) {
			M[flag + 2][2] = stepByStep(flag + 2, n, stairs, M, 2);
		}		
		return M[flag + 2][2] + stairs[flag];
	}
	else {
		if (n - flag <= 2)
			return stairs[n] + stairs[flag];
		if(M[flag + 1][1] == 0)
			M[flag + 1][1] = stepByStep(flag + 1, n, stairs, M, 1);
		if (M[flag + 2][2] == 0)
			M[flag + 2][2] = stepByStep(flag + 2, n, stairs, M, 2);

		if (M[flag + 2][2] < M[flag + 1][1])
			return M[flag + 1][1] + stairs[flag];
		else
			return M[flag + 2][2] + stairs[flag];
	}
}

int main(void) {
	int n, * stairs;
	int** M;
	int m1, m2;

	scanf("%d", &n);

	stairs = (int*)malloc(sizeof(int) * (n + 1));
	M = (int**)malloc(sizeof(int*) * (n + 1));
	for(int i = 0; i <= n; i++)
		M[i] = (int*)malloc(sizeof(int) * 3);

	stairs[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &stairs[i]);

	for (int i = 0; i <= n; i++)
		for(int j = 0; j < 3; j++)
			M[i][j] = 0;
	
	m1 = stepByStep(1, n, stairs, M, 0);
	m2 = stepByStep(2, n, stairs, M, 2);

	if(m1 > m2)
		printf("%d", m1);
	else
		printf("%d", m2);

	for (int i = 0; i <= n; i++)
		free(M[i]);
	free(M);
	free(stairs);
}
