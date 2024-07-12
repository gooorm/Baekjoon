#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search_binary(int target, int right, int list[]) {
	int left = 0;
	int mid = right / 2;
	while (left < right) {
		mid = (right + left) / 2;
		if (target < list[mid])
			left = mid + 1;
		else 
			right = mid;
	}
	return left;
}
int main(void) {

	int len, i, j, idx;
	int* arr, *list;

	scanf("%d", &len);
	arr = (int*)malloc(sizeof(int) * len);
	list = (int*)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++) 
		scanf("%d", &arr[i]);
	
	list[0] = arr[0];
	j = 0; 
	i = 1;
	while (i < len) {
		if (list[j] > arr[i]) 
			list[++j] = arr[i];
		else {
			idx = search_binary(arr[i], j, list);
			list[idx] = arr[i];
		}
		i++;
	}

	printf("%d", ++j);

	free(arr);
	free(list);
}
