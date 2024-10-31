#include <stdlib.h>
#include <stdio.h>

void main() {
    int *heap_array = malloc(1024 * 1024 * sizeof(char));
    printf("Address of heap_array: %p\n", heap_array);

    for (int i = 0; i < 4; i++) {
        printf("Metadata: %d\n", *&heap_array[-i]);
    }

    getchar();
}