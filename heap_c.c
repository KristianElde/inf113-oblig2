#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void allocateOnce() {
    size_t size = 1024 * 1024 * 1024; // Start with 1 GB
    char *heap_array;

    while (1) {
        heap_array = (char *)malloc(size);

        if (heap_array == NULL) {
            printf("Failed to allocate %.2f GB.\n", (double)size / (1024 * 1024 * 1024));
            break;
        }

        printf("Successfully allocated %.2f GB.\n", (double)size / (1024 * 1024 * 1024));

        free(heap_array);
        size += 1024 * 1024 * 1024 / 10; // Increase by 0.1 GB in each iteration
    }
}

void allocateMultipleTimes() {
    size_t blockSize = 1024 * 1024 * 1024; // Fixed block size of 1 GB
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
        printf("Allocated %d blocks, Total allocated memory: %zu GB\n", allocationCount, totalAllocated / (1024 * 1024 * 1024));
    }

    printf("Maximum memory allocated with multiple blocks of %zu GB each: %zu GB\n", blockSize / (1024 * 1024 * 1024), totalAllocated / (1024 * 1024 * 1024));
}

void allocateAndWrite() {
    size_t blockSize = 1024 * 1024 * 1024; // Fixed block size of 1 GB
    size_t totalAllocated = 0;
    char *block;
    int allocationCount = 0;

    while (1) {
        block = (char *)malloc(blockSize);

        if (block == NULL) {
            printf("Failed to allocate more memory after %.zu GB.\n", totalAllocated / (1024 * 1024 * 1024));
            break;
        }

        memset(block, 1, blockSize);

        totalAllocated += blockSize;
        allocationCount++;
        printf("Allocated and wrote to %d blocks, Total allocated memory: %zu GB\n", allocationCount, totalAllocated / (1024 * 1024 * 1024));
    }

    printf("Maximum memory allocated and written with multiple blocks of %zu GB each: %zu GB\n", blockSize / (1024 * 1024 * 1024), totalAllocated / (1024 * 1024 * 1024));
}

int main() {
    
    allocateOnce();
    // allocateMultipleTimes();
    // allocateAndWrite();

    return 0;
}
