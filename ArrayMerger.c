#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int* a, size_t a_size, int* b, size_t b_size, int** out_merged_array, size_t* output_size) {
    size_t i = 1;
    int j = 0;
    *out_merged_array = (int*)malloc((a_size+b_size) * sizeof(int));
    while (a_size > 0 && b_size > 0) {
        if (*a < *b) { (*out_merged_array)[j] = *a;a += i;j += 1;a_size -= i; *output_size+=i;}
        else if (*a > *b) { (*out_merged_array)[j] = *b;b += i;j += 1;b_size -= i; *output_size+=i;}
        else { (*out_merged_array)[j] = *a;a += i;b += i;j += 1;a_size -= i;b_size -= i; *output_size+=i;}
    }
    if (a_size > 0) {
        while (a_size > 0) { (*out_merged_array)[j] = *a;a += i;j += 1;a_size -= i; *output_size+=i;}
        }
    if (b_size > 0) {
            while (b_size > 0) { (*out_merged_array)[j] = *b;b += i;j += 1;b_size -= i;*output_size+=i; }
        }
    }


int main() {
    size_t a_size, b_size;

    // printf("Enter the size of array a: ");
    scanf("%zu", &a_size);
    int a[a_size];
    
    // printf("Enter %zu elements for array a (sorted order):\n", a_size);
    for (size_t i = 0; i < a_size; i++) {
        scanf("%d", &a[i]);
    }

    //printf("Enter the size of array b: ");
    scanf("%zu", &b_size);
    int b[b_size];
    
    //printf("Enter %zu elements for array b (sorted order):\n", b_size);
    for (size_t i = 0; i < b_size; i++) {
        scanf("%d", &b[i]);
    }

    int *merged_array = NULL;
    size_t merged_size = 0;
    merge_sorted_arrays(a, a_size, b, b_size, &merged_array, &merged_size);

    printf("Merged array:\n");
    for (size_t i = 0; i < merged_size; i++) {
        printf("%d ", merged_array[i]);
    }
    
    printf("size: %d\n", merged_size);

    free(merged_array);
    return 0;
}
