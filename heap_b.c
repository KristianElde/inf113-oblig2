#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

void main() {
    // Allocate 4 MB of memory
    size_t size = 4 * 1024 * 1024;
    char *heap_array = (char *)malloc(size);
   

    printf("Allocated 10 MB at %p\n", heap_array);
    getchar();  // Pause to check memory without accessing it

    // Write to each page to bring it into physical memory
    for (size_t i = 0; i < size; i += 4096) {
        heap_array[i] = 1;  // Write to the start of each 4 KB page
    }

    printf("Memory accessed. Press Enter to continue...\n");
    getchar();  // Pause again to inspect memory after access

}
