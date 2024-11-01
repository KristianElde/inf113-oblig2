#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void allocateOnce() {
    size_t size = 1024 * 1024 * 1024; // Start with 1 GB
    char *heap_array;

    while (1) {
        heap_array = (char *)malloc(size);

        if (heap_array == NULL) {
            printf("Failed to allocate %zu bytes (%.2f GB).\n", size, (double)size / (1024 * 1024 * 1024));
            break;
        }

        printf("Successfully allocated %zu bytes (%.2f GB).\n", size, (double)size / (1024 * 1024 * 1024));

        free(heap_array); // Free the memory to avoid system instability
        size += 1024 * 1024 * 1024 / 10; // Increase by 100 MB in each iteration
    }
    getchar();
}

void allocateMultipleTimes() {
    size_t blockSize = 512 * 1024 * 1024; // Fixed block size of 0.5 GB
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
        printf("Allocated %d blocks, Total allocated memory: %.2f GB\n", allocationCount, (double)totalAllocated / (1024 * 1024 * 1024));
    }

    printf("Maximum memory allocated with multiple blocks of %.2f GB each: %.2f GB\n", (double)blockSize / (1024 * 1024 * 1024), (double)totalAllocated / (1024 * 1024 * 1024));
    getchar();
}

void allocateAndWrite() {
    size_t blockSize = 512 * 1024 * 1024; // Fixed block size of 0.5GB
    size_t totalAllocated = 0;
    char *block;
    int allocationCount = 0;

    while (1) {
        block = (char *)malloc(blockSize);

        if (block == NULL) {
            printf("Failed to allocate more memory after %.2f GB.\n", (double)totalAllocated / (1024 * 1024 * 1024));
            break;
        }

        memset(block, 1, blockSize);

        totalAllocated += blockSize;
        allocationCount++;
        printf("Allocated and wrote to %d blocks, Total allocated memory: %.2f GB\n", allocationCount, (double)totalAllocated / (1024 * 1024 * 1024));
    }

    printf("Maximum memory allocated and written with multiple blocks of %.2f GB each: %.2f GB\n", (double)blockSize / (1024 * 1024 * 1024), (double)totalAllocated / (1024 * 1024 * 1024));
    getchar();
}

int main() {
    allocateOnce();
    allocateMultipleTimes();
    allocateAndWrite();

    return 0;
}
