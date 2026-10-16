#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

#define BEG_SIZE 1000
#define STEP 1000
#define NUM_STEP 5
#define REPEAT 5

int main() {

	srand(time(NULL));
	numMin = 200;
	clock_t start, end;
	double total;

	int i, size = BEG_SIZE, *array;

	for (i = 0; i < REPEAT; i++, size += STEP) {
		choosePivot = false;
		array = generate_array(size);
		printf("Unsorted array without pivot [%d]: %.10f sec\n", size, measure(quicksort, array, size));
		printf("Sorted array without pivot [%d]: %.10f sec\n", size, measure(quicksort, array, size));
		free(array);

		choosePivot = true, array = generate_array(size);
		printf("Unsorted array with pivot [%d]: %.10f sec\n", size, measure(quicksort, array, size));
		printf("Sorted array with pivot [%d]: %.10f sec\n\n", size, measure(quicksort, array, size));
		free(array);
	}

	for (i = 0, size = rand() % 100; i < 200; i += NUM_STEP, size += rand() % 40) {
		array = generate_array(size);
		printf("numMin[%d] with pivot [%d]: %.10f sec\n", numMin, size, measure(quicksort, array, size));
		free(array);
	}

	size = BEG_SIZE, array = generate_array(size);
	printf("\n\nUnsorted merge sort[%d]: %.5lf sec\n", size, merge_measure(merge_sort, array, 0, size-1));
	printf("Sorted merge sort[%d]: %.5lf sec\n", size, merge_measure(merge_sort, array, 0, size-1));
	free(array);

	return 0;
}
