#include "MemoryAllocator.hpp"

// Constructor: Initialize the memory pool and free lists
MemoryAllocator::MemoryAllocator(size_t totalMemorySize, size_t minBlockSize)
    : totalMemorySize(totalMemorySize), minBlockSize(minBlockSize) {
    memoryPool = std::malloc(totalMemorySize);
    if (!memoryPool) {
        throw std::bad_alloc();
    }

    // Initially, the whole memory pool is one big free block
    freeLists[totalMemorySize] = memoryPool;
}

// Destructor: Free the memory pool
MemoryAllocator::~MemoryAllocator() {
    std::free(memoryPool);
}

// Allocate a block of memory
void* MemoryAllocator::allocate(size_t size) {
    std::lock_guard<std::mutex> lock(allocMutex); // Thread safety

    // Ensure the size is at least the minimum block size
    size = std::max(size, minBlockSize);

    // Find a suitable free block
    void* freeBlock = findFreeBlock(size);
    if (!freeBlock) {
        throw std::bad_alloc(); // No suitable block found
    }

    // Remove this block from the free list
    freeLists[size] = nullptr;

    // Split block if necessary
    splitBlock(freeBlock, totalMemorySize, size);

    return freeBlock;
}

// Deallocate a block of memory
void MemoryAllocator::deallocate(void* block, size_t size) {
    std::lock_guard<std::mutex> lock(allocMutex); // Thread safety

    // Insert the block back into the free list
    insertIntoFreeList(block, size);

    // Try to coalesce adjacent free blocks to reduce fragmentation
    coalesceFreeBlocks();
}

// Helper function to find a suitable free block of memory
void* MemoryAllocator::findFreeBlock(size_t size) {
    auto it = freeLists.lower_bound(size);
    if (it == freeLists.end()) return nullptr; // No suitable block found
    return it->second;
}

// Helper function to split a large block
void MemoryAllocator::splitBlock(void* block, size_t originalSize, size_t requestedSize) {
    size_t remainingSize = originalSize - requestedSize;
    if (remainingSize >= minBlockSize) {
        void* remainingBlock = static_cast<char*>(block) + requestedSize;
        freeLists[remainingSize] = remainingBlock; // Add remaining block to free list
    }
}

// Coalesce adjacent free blocks to reduce fragmentation
void MemoryAllocator::coalesceFreeBlocks() {
    // This implementation would depend on knowing block boundaries and their adjacency.
    // For simplicity, we'll skip this, but in a real implementation, this would require
    // more complex memory layout management.
}

// Insert a block into the free list
void MemoryAllocator::insertIntoFreeList(void* block, size_t size) {
    freeLists[size] = block;
}

// Debugging: Print current memory pool status
void MemoryAllocator::printStatus() const {
    std::cout << "Memory Pool Status:\n";
    for (const auto& [size, block] : freeLists) {
        std::cout << "Block Size: " << size << ", Block Address: " << block << std::endl;
    }
}
