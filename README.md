🧠 Custom Memory Allocator
An efficient and scalable C++ memory allocator that provides fast, thread-safe dynamic memory management with support for variable block sizes, block splitting, and memory coalescing to reduce fragmentation.

📂 Project Structure
MemoryAllocator.cpp: Core implementation of the memory allocator, handling memory allocation, deallocation, block splitting, and coalescing.
MemoryAllocator.hpp: Header file for MemoryAllocator.cpp, containing class definitions and method declarations.
main.cpp: Demonstrates the usage of the custom memory allocator by allocating and deallocating various-sized memory blocks.
MemoryAllocator.sln: Visual Studio solution file to open the project.
MemoryAllocator.vcxproj: Project configuration file for Visual Studio.

🚀 Key Features
Variable Block Size Allocation: Efficiently allocates memory blocks of different sizes, maximizing memory usage.
Block Splitting: Splits larger blocks to fulfill smaller allocation requests, optimizing memory utilization.
Memory Coalescing: Merges adjacent free blocks upon deallocation to reduce fragmentation.
Thread-Safe: Uses mutexes to ensure safe concurrent access to memory operations in multithreaded environments.
Memory Pool: Manages a single memory pool to minimize system calls like malloc and free, boosting performance.
🛠️ Technologies Used
💻 C++: Implements dynamic memory management logic.
🧵 Multithreading: Thread-safe operations using mutexes.
📚 Custom Memory Management: Handles memory block splitting, coalescing, and efficient allocation/deallocation.
🎯 How to Get Started
🔗 Clone the Repository:

bash
Copy code
git clone https://github.com/aditya28301/Meomary-Allocator.git
📂 Open the Solution in Visual Studio:

Navigate to the project directory.
Open MemoryAllocator.sln in Visual Studio.
▶️ Run the Allocator:

Build the project by pressing Ctrl + Shift + B or selecting Build > Build Solution.
Run the application by pressing F5 (Debug) or Ctrl + F5 (Run Without Debugging).

## 📞 Contact
- Name: Aditya Ashok Darekar
- Email: aditya28301@gmail.com
- LinkedIn: [aditya-darekar](https://www.linkedin.com/in/aditya-darekar-318a26143/)
- GitHub: [aditya28301](https://github.com/aditya28301)
🤝 Contributing
Contributions are welcome! Feel free to open an issue or submit a pull request to improve the project.

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
