# Memory Leakage

1. Memory leakage occurs when a program allocates memory in the heap but does not release the memory back to the operating system when it is no longer needed.
2. In C++, when you use raw pointers, you need to manage the memory allocation and deallocation manually.

```cpp
void create_memory_leak() {
    int* ptr = new int[100]; // Allocating memory in the heap for an array of integers
    // Some code...
    // Code to deallocate the memory is missing: delete[] ptr;
}
// !IMP: ptr goes out of scope, memory block allocated is not deallocated, causing a memory leak.
```

**ptr goes out of scope, memory block allocated is not deallocated, causing a memory leak.**

**you should always ensure that memory is deallocated before a pointer goes out of scope or is reassigned.**

Some ways to achieve this include using the C++ smart pointers

```cpp

#include <memory>
void no_memory_leak() {
    std::shared_ptr<int> ptr = std::make_shared<int[]>(100); // Allocating memory in the heap for an array of integers using shared_ptr
    // Some code...
} // shared_ptr goes out of scope and it will automatically deallocate the memory block assigned to it.

```

**shared_ptr goes out of scope and it will automatically deallocate the memory block assigned to it.**
