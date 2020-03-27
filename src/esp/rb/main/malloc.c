#undef malloc
#undef free

#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void* ptr;
    unsigned int size;
} ptr_info;

#define ARR_SIZE 40
static ptr_info ptr_arr[ARR_SIZE];
static unsigned int init_arr = 1;
static unsigned int total_malloc_size = 0;

void initArr()
{
    if (init_arr)
    {
        for (int i = 0; i<ARR_SIZE; ++i)
        {
            ptr_arr[i].size = 0;
            ptr_arr[i].ptr = 0;
        }
        init_arr = 0;
    }
}

void* my_ESP_malloc(unsigned int size)
{
    initArr();

    void* ptr = malloc(size);
    total_malloc_size += size;
    printf("New malloc: %dB, %dKB, Total size: %dB, %dkB\n", size, size/1024, total_malloc_size, total_malloc_size/1024);

    // add to array
    for(int i = 0; i <= ARR_SIZE; ++i)
    {
        if (ptr_arr[i].size == 0)
        {
            ptr_arr[i].size = size;
            ptr_arr[i].ptr = ptr;
            break;
        }

        if (i == ARR_SIZE)
            printf("New malloc: ERROR small array!!\n");
    }

    return ptr;
}

void my_ESP_free(void* ptr)
{
    // remove from array
    for(int i = 0; i <= ARR_SIZE; ++i)
    {
        if (ptr_arr[i].ptr == ptr)
        {
            total_malloc_size -= ptr_arr[i].size;
            printf("Free malloc: %dB, %dKB, Total size: %dB, %dkB\n", ptr_arr[i].size, ptr_arr[i].size/1024, total_malloc_size, total_malloc_size/1024);
            free(ptr);

            ptr_arr[i].size = 0;
            ptr_arr[i].ptr = 0;
            break;
        }

        if (i == ARR_SIZE)
            printf("Free malloc: ERROR not in array!!\n");
    }
}