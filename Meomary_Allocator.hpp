#ifndef MEMORYALLOCATOR_HPP
#define MEMORYALLOCATOR_HPP

#include <cstdlib>
#include <map>
#include <mutex>
#include <iostream>

class MemoryAllocator {
public:
    // Constructor: Initialize with total memory pool size and minimum block size
    MemoryAllocator(size_t totalMemorySize, size_t minBlockSize);
    
    // Destructor: Frees the memory pool
    ~MemoryAllocator();

    // Allocate memory of a given size
    void* allocate(size_t size);

    // Deallocate a block of memory, returning it to the free list
    void deallocate(void* block, size_t size);

    // Print current memory pool status for debugging
    void printStatus() const;

private:
    void* memoryPool;    // Base memory pool pointer
    size_t totalMemorySize;  // Total size of the memory pool
    size_t minBlockSize;  // Minimum block size
    std::map<size_t, void*> freeLists;  // A map for multiple free lists per block size
    std::mutex allocMutex;  // Mutex for thread safety

    // Internal helper function to find a free block of a given size
    void* findFreeBlock(size_t size);

    // Helper function to split a large block into two smaller blocks
    void splitBlock(void* block, size_t originalSize, size_t requestedSize);

    // Helper function to coalesce adjacent free blocks
    void coalesceFreeBlocks();

    // Insert a block into the free list for a given size
    void insertIntoFreeList(void* block, size_t size);
};

#endif // MEMORYALLOCATOR_HPP
