#include <stdio.h>
#include <stdlib.h>

int global_var;             
int initialized_global = 42; 
const int const_global = 100; 


void f(int i) {

    if (i == 0)

        return;

     printf("Stack address of i = %p for i = %d\n", (void*)&i, i);

    f(i - 1);

}

int main() {

    // 1. Stack addresses
    f(5);

    // 2. Heap Allocation
    // Allocate >1MB on the heap
    int *heap_array = (int *)malloc(1024 * 1024 * sizeof(int));
    printf("Address of heap: %p\n", heap_array);

    // 3. Program code
    printf("Address of function f (program code): %p\n", (void*)&f);

    // 4. Global Variables
    printf("Address of uninitialized global variable: %p\n", (void*)&global_var);
    printf("Address of initialized global variable: %p\n" ,(void*)&initialized_global);
    printf("Address of const global variable: %p\n", (void*)&const_global);
    
    return 0;
}