#include <iostream>
#include "MemoryAllocator.hpp"

int main() {
    const size_t totalMemorySize = 1024 * 1024;   // 1 MB of memory
    const size_t minBlockSize = 128;              // Minimum block size of 128 bytes

    try {
        // Create an instance of the MemoryAllocator
        MemoryAllocator allocator(totalMemorySize, minBlockSize);

        // Allocate memory blocks of various sizes
        void* block1 = allocator.allocate(256);
        void* block2 = allocator.allocate(512);
        void* block3 = allocator.allocate(1024);

        std::cout << "Allocated block 1 at: " << block1 << std::endl;
        std::cout << "Allocated block 2 at: " << block2 << std::endl;
        std::cout << "Allocated block 3 at: " << block3 << std::endl;

        // Print the current status of the memory pool
        allocator.printStatus();

        // Deallocate a block
        allocator.deallocate(block2, 512);
        std::cout << "Deallocated block 2." << std::endl;

        // Allocate another block (should reuse space)
        void* block4 = allocator.allocate(512);
        std::cout << "Allocated block 4 at (should reuse block 2's space): " << block4 << std::endl;

        // Print the status again
        allocator.printStatus();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    return 0;
}
