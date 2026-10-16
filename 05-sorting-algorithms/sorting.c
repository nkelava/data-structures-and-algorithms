#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

bool choosePivot;
int numMin;

// helper functions
void print_array(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void shuffle(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int k1 = rand() % n;
		int tmp = arr[i];
		arr[i] = arr[k1];
		arr[k1] = tmp;
	}
}

// array generation and printing
int* generate_array(int n) {
	int* arr = (int*)malloc(sizeof(int) * n);
	if (!arr) return 0;

	arr[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		arr[i] = arr[i - 1] + rand() % 5;
	}
	shuffle(arr, n);

	return arr;
}

// selection sort
void selection_sort(int* arr, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[maxi])
				maxi = j;
		}

		tmp = arr[maxi];
		arr[maxi] = arr[i];
		arr[i] = tmp;
	}
}

// insertion sort
void insertion_sort(int* arr, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

// quick sort
int calc_median(int a, int b, int c) {
	return (a >= b) ? ((c >= a) ? a : ((b >= c) ? b : c)) : ((c >= b) ? b : ((a >= c) ? a : c));
}

int partition(int* arr, int n) {
	if (choosePivot == true) {
		int pivot = calc_median(arr[0], arr[n/2], arr[n-1]);
		int temp = arr[0]; 
		arr[0] = pivot;
		if (pivot == arr[n/2])
			arr[n/2] = temp;
		if (pivot == arr[n-1])
			arr[n-1] = temp;
	}

	int l = 1, r = n - 1;

	while (l < r) {
		if (arr[r] >= arr[0]) {
			r--;
		}
		else if (arr[l] < arr[0]) {
			l++;
		}
		else {
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
	}
	if (arr[0] < arr[r]) { // 1
		return 0;
	}
	else { // 3
		int tmp = arr[r];
		arr[r] = arr[0];
		arr[0] = tmp;
		return r;
	}
}

void quicksort(int* arr, int n) {
	if (n < numMin) {
		selection_sort(arr, n);
	}
	else {
		if (n < 2)
			return;
		int pi = partition(arr, n);
		quicksort(arr, pi);
		quicksort(arr + pi + 1, n - pi - 1);
	}
}

// merge sort
void merge(int* arr, int l, int m, int r) {
	// implement the merge function
	int i, j, k, sizeLeft = m - l + 1, sizeRight = r - m;

	int *left = (int*)malloc(sizeLeft * sizeof(int)), *right = (int*)malloc(sizeRight * sizeof(int)); // temporary left and right halves
	if (!left || !right) return;

	for (i = 0; i < sizeLeft; i++)  // copy the numbers into them
		left[i] = arr[l + i];
	for (j = 0; j < sizeRight; j++)
		right[j] = arr[m + 1 + j];

	for (i = 0, j = 0, k = l; i < sizeLeft && j < sizeRight; k++) {  // merge the temporary halves back into the array
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
	}

	for (; i < sizeLeft; i++, k++) {  // copy the remaining elements of the left and right halves, if any
		arr[k] = left[i];
	}

	for (; j < sizeRight; j++, k++) {
		arr[k] = right[j];
	}

	free(left), free(right);
}

// allocates and returns a copy of the array
int* duplicate(int* arr, int n) {
	int i;
	int* copy = (int*)malloc(sizeof(int) * n);
	if (!copy) return 0;

	for (i = 0; i < n; i++) {
		copy[i] = arr[i];
	}
	return copy;
}

void merge_sort(int* arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// measures the execution time of a sorting function
double measure(void(*sort)(int* arr, int n), int* arr, int n) {
	clock_t start_time = clock();
	sort(arr, n);
	clock_t end_time = clock();
	return ((double)(end_time - start_time) / CLOCKS_PER_SEC);
}


double merge_measure(void(*sort)(int* arr, int n), int* arr, int l, int r) {
	clock_t start_time = clock();
	sort(arr, l, r);
	clock_t end_time = clock();
	return ((double)(end_time - start_time) / CLOCKS_PER_SEC);
}
