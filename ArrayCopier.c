#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatinate_arrays(int* a, size_t a_size, int* b, size_t b_size, int** out_merged_array, size_t* output_size) {
	*out_merged_array=(int*)malloc((a_size+b_size)*sizeof(int));
	size_t j = 1;
	for(size_t i=0; i<a_size; i++){
	    memcpy((*out_merged_array)+i, a, j);a++;}
    for(size_t i=0; i<b_size; i++){
	    memcpy((*out_merged_array)+a_size+i, b, j);b++;}
	*output_size=a_size+b_size;
}

int main() {
 
	size_t a_size, b_size;
	printf("Enter the size of array a: ");
	scanf("%zu", &a_size);
	int *a = (int*)calloc(sizeof(int), a_size);
	printf("Enter %zu elements for array a:\n", a_size);
	for (size_t i = 0; i < a_size; i++) {
		scanf("%d", &a[i]);
	}

	printf("Enter the size of array b: ");
	scanf("%zu", &b_size);
	int *b = (int*)calloc(sizeof(int), b_size);

	printf("Enter %zu elements for array b:\n", b_size);
	for (size_t i = 0; i < b_size; i++) {
		scanf("%d", &b[i]);
	}

	int* merged_array = NULL;
	size_t merged_size = 0;
	concatinate_arrays(a, a_size, b, b_size, &merged_array, &merged_size);

	printf("Concatenated array:\n");
	for (size_t i = 0; i < merged_size; i++) {
		printf("%d ", merged_array[i]);
	}
	printf("\n");
	free(a);
	free(b);
	free(merged_array);
	return 0;
}
