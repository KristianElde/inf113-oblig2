#include <stdlib.h>
#include <stdio.h>

void allocateOnce() {
    size_t size = 1024 * 1024 * 1024; // Start with 1 GB
    char *heap_array;

    while (1) {
        getchar();
        heap_array = (char *)malloc(size);

        if (heap_array == NULL) {
            printf("Failed to allocate %zu bytes (%.2f GB).\n", size, (double)size / (1024 * 1024 * 1024));
            break;
        }

        printf("Successfully allocated %zu bytes (%.2f GB).\n", size, (double)size / (1024 * 1024 * 1024));

        free(heap_array); // Free the memory to avoid system instability
        size += 1024 * 1024 * 1024 / 10; // Increase by 1 GB in each iteration
    }
}

void allocateMultipleTimes() {
    size_t blockSize = 2048 * 1024 * 1024; // Fixed block size of 100 MB
    size_t totalAllocated = 0;
    char *block;
    int allocationCount = 0;

    while (1) {
        block = (char *)malloc(blockSize);

        if (block == NULL) {
            printf("Failed to allocate more memory.\n");
            break;
        }

        totalAllocated += blockSize;
        allocationCount++;
        printf("Allocated %d blocks, Total allocated memory: %zu MB\n", allocationCount, totalAllocated / (1024 * 1024));
    }

    printf("Maximum memory allocated with multiple blocks of %zu MB each: %zu MB\n", blockSize / (1024 * 1024), totalAllocated / (1024 * 1024));
}

void writingToMemory() {
    size_t size = 1 * 1024 * 1024;
    char *heap_array = (char *)malloc(size);
    // Write to each page to bring it into physical memory
    for (size_t i = 0; i < size; i += 4096) {
        heap_array[i] = 1;  // Write to the start of each 4 KB page
    }
}

int main() {
    allocateOnce();
    //allocateMultipleTimes();
    // writingToMemory();

    return 0;
}
