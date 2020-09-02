//
// Created by student on 01/07/2020.
//
#include "memory_allocator.h"
#include <malloc.h>


int main()
{
    void *block1, *block2, *block3, *block4;
    void* my_heap=malloc(86);
    MemoryAllocator* m;
    size_t max_free;

    m=MemoryAllocator_init(my_heap, 86);
    block1=MemoryAllocator_allocate(m, 8);
    block2=MemoryAllocator_allocate(m, 8);
    block3=MemoryAllocator_allocate(m, 8);
    Print_heap(m);
    printf("**************\n");
    MemoryAllocator_free(m, block2);
    Print_heap(m);
    printf("**************\n");
    block4=MemoryAllocator_allocate(m, 12);
    Print_heap(m);
    printf("**************\n");
    MemoryAllocator_free(m,block3);
    Print_heap(m);
    printf("**************\n");
    max_free=MemoryAllocator_optimize(m);
    Print_heap(m);
    printf("max free: %ld\n",max_free);
    printf("**************\n");
    block2=MemoryAllocator_allocate(m, 24);
    Print_heap(m);
    printf("**************\n");

    MemoryAllocator_release(m);
    free(my_heap);
    return 0;
}
