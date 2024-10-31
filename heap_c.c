#include <stdlib.h>
#include <stdio.h>

void allocateOnce() {
    // Allocate 10 MB of memory
    // Pause to check memory without accessing it

    size_t size = 100000 * 1024 * 1024;
    char *heap_array = (char *)malloc(size);
    if (heap_array == NULL) {
        printf("Too much memory allocated.");
        return;
    }
   

    printf("Allocated 10 MB at %p\n", heap_array);
    getchar(); 
}

void allocateMultipleTimes() {

}

void writingToMemory() {
    // Write to each page to bring it into physical memory
    for (size_t i = 0; i < size; i += 4096) {
        heap_array[i] = 1;  // Write to the start of each 4 KB page
    }
}

void main() {

}
