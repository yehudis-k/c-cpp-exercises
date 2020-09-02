#include "memory_allocator.h"
#include <malloc.h>
#include <stdbool.h>

#define ALIGNMENT 8
#define META_DATA_SIZE sizeof(size_t)

struct MemoryAllocator{
    size_t m_size;
    void* m_memory_pool;
};

bool isAllocated(void* ptr)//checks if block is allocated
{
    return *(size_t*)ptr%2;
}

size_t round_to_alignment(size_t size)
{
    if(size%ALIGNMENT)
    {
        size=size+(ALIGNMENT-size%ALIGNMENT);
    }

    return size;
}

void* allocate_and_split(void* ptr, size_t size)
{
    if ((*(size_t*)ptr) == size)//exactly fits in free block
    {
        *(size_t*)ptr += 1;//mark as allocated
        return ptr+META_DATA_SIZE;
    }
    size_t save = *(size_t*)ptr;
    *(size_t*)ptr = size + 1;
    ptr += size;
    *(size_t*)ptr = save - size;

    return ptr - size + META_DATA_SIZE;
}

MemoryAllocator* MemoryAllocator_init(void* memoryPool, size_t size)
{
    size=round_to_alignment(size);
    MemoryAllocator* heap=(MemoryAllocator*)malloc(sizeof(MemoryAllocator));
    heap->m_size=size;
    heap->m_memory_pool=memoryPool;
    *((size_t*)heap->m_memory_pool)=size;

    return heap;
}

void* MemoryAllocator_release(MemoryAllocator* allocator)
{
    void* tmp = allocator->m_memory_pool;
    free(allocator);

    return tmp;
}

void* MemoryAllocator_allocate(MemoryAllocator* allocator, size_t size)
{
    size_t count, save;
    size = round_to_alignment(size) + META_DATA_SIZE;
    void* ptr = allocator->m_memory_pool;

    while (ptr < allocator->m_memory_pool + allocator->m_size)//still in memory pool
    {
        if(!(isAllocated(ptr)))//block is free
        {
            if((*(size_t*)ptr) >= size)//has enough space to allocate size
            {
                return allocate_and_split(ptr,size);
            }
            else//doesn't fit in current free block
            {
                count = (*(size_t*)ptr);
                while (count < size)//still doesn't fit
                {
                    ptr += (*(size_t*)ptr);
                    if (!(isAllocated(ptr)))
                    {
                        count += (*(size_t*)ptr);
                    }
                    else {
                        break;
                    }
                }
                if (count >= size)
                {
                    ptr -= count;
                    *(size_t*)ptr = count;
                    return allocate_and_split(ptr,size);
                }
            }
        }
        ptr += (*(size_t*)ptr>>1)<<1;
    }

    return NULL;
}

void MemoryAllocator_free(MemoryAllocator* allocator, void* ptr)
{
    ptr -= META_DATA_SIZE;
    void* tmp = ptr + *(size_t*)ptr -1;
    while ((!isAllocated(tmp))&&(tmp<allocator->m_memory_pool+allocator->m_size))//merge with next free blocks
    {
        tmp += (*(size_t*)tmp);
    }
    *(size_t*)ptr = tmp - ptr;
}

size_t MemoryAllocator_optimize(MemoryAllocator* allocator)
{
    size_t max_free=0;
    void* ptr=allocator->m_memory_pool;
    void* start_free=allocator->m_memory_pool;
    while (ptr < allocator->m_memory_pool + allocator->m_size)
    {
        if (!isAllocated(start_free))
        {
            while (!isAllocated(ptr))
            {
                ptr += (*(size_t*)ptr);
            }
            *(size_t*)start_free = ptr - start_free;
            if (*(size_t*)start_free > max_free)//update max free block
            {
                max_free = *(size_t*)start_free;
            }
            start_free = ptr;
        }
        else
        {
            ptr += (*(size_t*)ptr-1);
            start_free = ptr;
        }
    }

    return max_free;
}

void Print_heap(MemoryAllocator* allocator)
{
    void* ptr=allocator->m_memory_pool;
    size_t i=0;
    while (ptr<allocator->m_memory_pool+allocator->m_size)
    {
        printf("block number %ld: metadata: %ld, size: %ld,", i,*(size_t*)ptr, ((*(size_t*)ptr>>1)<<1)-META_DATA_SIZE);
        if(*(size_t*)ptr%2)
            printf(" block allocated\n");
        else
            printf(" block free\n");
        i++;
        ptr+=(*(size_t*)ptr>>1)<<1;
    }
}