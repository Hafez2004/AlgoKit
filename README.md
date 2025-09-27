# AlgoKit

<p align="center">
  <img src="AlgoKit.png" alt="AlgoKit Logo" width="250"/>
</p>

<p align="center">
  <strong>A High-Performance C/C++ Toolkit for Algorithms & Data Structures</strong>
</p>

<p align="center">
  <a href="#features">Features</a> •
  <a href="#installation">Installation</a> •
  <a href="#quick-start">Quick Start</a> •
  <a href="#api-reference">API Reference</a> •
  <a href="#examples">Examples</a> •
  <a href="#contributing">Contributing</a>
</p>

---

## Overview

**AlgoKit** is a lightweight, high-performance C/C++ library designed to provide reusable implementations of essential algorithms and data structures. Built with efficiency and ease of use in mind, AlgoKit helps developers, students, and professionals write clean, optimized code without reinventing fundamental programming constructs.

### Key Highlights

- ⚡ **High Performance**: Optimized implementations with minimal overhead
- 🔄 **Generic Design**: Type-safe operations across multiple data types
- 🛡️ **Memory Safe**: Automatic memory management with proper cleanup
- 🔧 **Easy Integration**: Simple header-only inclusion
- 📚 **Well Documented**: Comprehensive API documentation and examples
- 🔀 **Cross Compatible**: Works seamlessly with both C and C++ projects

---

## Features

### Dynamic Array
A powerful, automatically resizing array implementation that supports multiple data types.

**Core Capabilities:**
- **Automatic Memory Management**: Power-of-2 capacity scaling for optimal performance
- **Generic Type Support**: Built-in support for `char`, `short`, `int`, `float`, `double`, `long`, and `long double`
- **Rich API**: Comprehensive set of operations including insert, remove, search, and copy
- **Memory Efficient**: Automatic shrinking when utilization drops below 25%
- **Safety First**: Bounds checking and error handling built-in

**Supported Operations:**
- Initialization and cleanup (`da_init`, `da_free`)
- Element manipulation (`da_push_back`, `da_pop_back`, `da_insert`, `da_remove`)
- Data access (`da_get`, `da_set`, `da_find`)
- Utility functions (`da_print`, `da_println`, `da_get_size`, `da_get_capacity`)
- Array operations (`da_copy`)

### Sorting Utilities
Foundation components for sorting algorithms.

- **Memory-Safe Swap Function**: Generic swap operation for any data type
- *Note: Full sorting algorithms are planned for future releases*

---

## Installation

### Prerequisites
- GCC or G++ compiler
- Standard C library support
- Make (optional, for using provided Makefile)

### Method 1: Direct Integration
1. Clone or download the AlgoKit repository
2. Include the main header in your project:
   ```c
   #include "AlgoKit_lib.h"
   ```
3. Add the source files to your compilation command

### Method 2: Using Make
```bash
# Clone the repository
git clone <repository-url>
cd AlgoKit

# Build the project
make build

# Run the example
make run

# Clean build files
make clean
```

---

## Quick Start

Here's a simple example demonstrating AlgoKit's Dynamic Array functionality:

```c
#include "AlgoKit_lib.h"

int main(void) {
    // Initialize a dynamic array for integers
    DynamicArray numbers = da_init(_int_);
    
    // Add elements using push_back
    for (int i = 1; i <= 5; i++) {
        da_push_back(&numbers, PTR(i * 10, int));
    }
    
    // Print the array
    printf("Array contents: ");
    da_println(&numbers);  // Output: 10 20 30 40 50
    
    // Insert element at specific position
    da_insert(&numbers, 2, PTR(25, int));
    printf("After insertion: ");
    da_println(&numbers);  // Output: 10 20 25 30 40 50
    
    // Access and modify elements
    int *element = (int*)da_get(&numbers, 0);
    printf("First element: %d\n", *element);  // Output: 10
    
    da_set(&numbers, PTR(15, int), 0);
    printf("After modification: ");
    da_println(&numbers);  // Output: 15 20 25 30 40 50
    
    // Array information
    printf("Size: %d, Capacity: %d\n", da_get_size(&numbers), da_get_capacity(&numbers));
    
    // Clean up memory
    da_free(&numbers);
    return 0;
}
```

---

## API Reference

### Dynamic Array

#### Initialization & Cleanup
```c
DynamicArray da_init(dataType type);     // Initialize array with specified type
void da_free(DynamicArray* da);          // Free allocated memory
```

#### Element Operations
```c
void da_push_back(DynamicArray* da, void* const value);    // Add element at end
void da_pop_back(DynamicArray* da);                       // Remove last element
void da_insert(DynamicArray* da, const int index, const void* value);  // Insert at index
void da_remove(DynamicArray* da, const int index);        // Remove element at index
```

#### Data Access
```c
void* da_get(const DynamicArray* da, const int index);     // Get element at index
void da_set(DynamicArray* da, const void* value, const int index);  // Set element value
void* da_find(const DynamicArray* da, const void* value);  // Find first occurrence
```

#### Utility Functions
```c
int da_get_size(const DynamicArray* da);                  // Get current size
int da_get_capacity(const DynamicArray* da);              // Get current capacity
void da_print(const DynamicArray* da);                    // Print array contents
void da_println(const DynamicArray* da);                  // Print with newline
void da_copy(DynamicArray* dest, const DynamicArray* src); // Copy array contents
```

### Data Types
AlgoKit currently supports the following data types:
- `_char_` - Character type
- `_short_` - Short integer
- `_int_` - Integer
- `_float_` - Single precision floating point
- `_double_` - Double precision floating point  
- `_long_` - Long integer
- `_long_double_` - Extended precision floating point

### Helper Macros
```c
PTR(val, type)    // Create pointer to temporary value of specified type
```

### Sorting Utilities
```c
void swap(void* const a, void* const b, const size_t size);  // Generic swap function
```
*Note: Currently only the swap utility function is implemented. Full sorting algorithms are planned for future releases.*

---

## Examples

### Working with Different Data Types

```c
// Float array example
DynamicArray floats = da_init(_float_);
da_push_back(&floats, PTR(3.14f, float));
da_push_back(&floats, PTR(2.71f, float));
da_println(&floats);  // Output: 3.140000 2.710000

// Character array example
DynamicArray chars = da_init(_char_);
da_push_back(&chars, PTR('H', char));
da_push_back(&chars, PTR('i', char));
da_push_back(&chars, PTR('!', char));
da_println(&chars);  // Output: Hi!

// Double array example
DynamicArray doubles = da_init(_double_);
da_push_back(&doubles, PTR(1.414213, double));
da_push_back(&doubles, PTR(1.732050, double));
da_println(&doubles);  // Output: 1.414213 1.732050

// Don't forget to clean up
da_free(&floats);
da_free(&chars);
da_free(&doubles);
```

### Array Copying and Manipulation

```c
DynamicArray source = da_init(_int_);
DynamicArray destination;

// Populate source array
for (int i = 0; i < 5; i++) {
    da_push_back(&source, PTR(i * i, int));  // Add squares: 0, 1, 4, 9, 16
}

// Copy to destination
da_copy(&destination, &source);

// Both arrays now contain the same data
printf("Source: ");
da_println(&source);      // Output: 0 1 4 9 16
printf("Destination: ");
da_println(&destination); // Output: 0 1 4 9 16

// Modify destination independently
da_insert(&destination, 2, PTR(99, int));
printf("After modifying destination: ");
da_println(&destination); // Output: 0 1 99 4 9 16
printf("Source unchanged: ");
da_println(&source);      // Output: 0 1 4 9 16

da_free(&source);
da_free(&destination);
```

### Finding and Removing Elements

```c
DynamicArray numbers = da_init(_int_);

// Add some numbers
int values[] = {10, 20, 30, 20, 40};
for (int i = 0; i < 5; i++) {
    da_push_back(&numbers, &values[i]);
}

// Find an element
int search_val = 20;
int* found = (int*)da_find(&numbers, &search_val);
if (found) {
    printf("Found value: %d\n", *found);  // Output: Found value: 20
}

// Remove element at specific index
da_remove(&numbers, 1);  // Remove element at index 1 (first occurrence of 20)
printf("After removal: ");
da_println(&numbers);    // Output: 10 30 20 40

// Remove last element
da_pop_back(&numbers);
printf("After pop_back: ");
da_println(&numbers);    // Output: 10 30 20

da_free(&numbers);
```

---

## Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push Back | O(1) amortized | O(1) |
| Pop Back | O(1) amortized | O(1) |
| Insert | O(n) | O(1) |
| Remove | O(n) | O(1) |
| Access | O(1) | O(1) |
| Search | O(n) | O(1) |

**Memory Management:**
- Capacity grows by factor of 2 when full
- Capacity shrinks by factor of 2 when utilization ≤ 25%
- Minimum capacity maintained at 1

---

## Building from Source

### Using the Smart Makefile

AlgoKit includes an intelligent Makefile that automatically detects your project setup:

```bash
# View compiler information
make get_version

# Build project (auto-detects C/C++)
make build

# Build and run
make run

# Clean build artifacts
make clean
```

The Makefile automatically:
- Detects whether you're using C or C++
- Selects the appropriate compiler (GCC/G++)
- Handles source file discovery
- Provides clean build management

---

## Version Information

**Current Version:** 1.0.0  
**Author:** Mohamed Hafez  
**Release Date:** September 2025

---

## Contributing

We welcome contributions to AlgoKit! Here's how you can help:

1. **Report Issues**: Found a bug? Please open an issue with detailed reproduction steps
2. **Feature Requests**: Have an idea for a new algorithm or data structure? Let us know!
3. **Code Contributions**: Submit pull requests with new features or improvements
4. **Documentation**: Help improve our documentation and examples

### Development Guidelines
- Follow existing code style and conventions
- Include comprehensive tests for new features
- Update documentation for any API changes
- Ensure cross-platform compatibility

---

## License

This project is open source. Please refer to the LICENSE file for detailed terms and conditions.

---

## Roadmap

### Upcoming Features
- **Sorting Algorithms**: Complete implementation of selection sort and additional algorithms like quick sort, merge sort, heap sort
- **Advanced Data Structures**: Linked lists, stacks, queues, trees
- **Search Algorithms**: Binary search, hash tables
- **String Algorithms**: Pattern matching, string manipulation utilities
- **Graph Algorithms**: BFS, DFS, shortest path algorithms

### Currently Available
- ✅ **Dynamic Array**: Fully implemented with all core operations
- ✅ **Memory Management**: Automatic resizing with power-of-2 scaling
- ✅ **Generic Type Support**: Support for 7 fundamental data types
- ✅ **Utility Functions**: Complete set of array manipulation functions
- 🔧 **Sorting Module**: Basic infrastructure (swap function) - algorithms in development

---

## Support

For questions, issues, or suggestions:
- Open an issue on the project repository
- Check the `/features` directory for detailed examples
- Review the API documentation in header files

---

<p align="center">
  <strong>Built with ❤️ for the C/C++ community</strong>
</p>