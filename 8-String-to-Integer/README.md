# LSATOI – Custom `atoi` Implementation

LSATOI is a custom implementation of the `atoi` (ASCII to Integer) function written in C.  
This library is designed to convert numeric strings into integers, supporting negative numbers as well.

---

## Features

- Lightweight and portable implementation
- Supports negative integers
- Available as **static (`.a`)** or **shared (`.so`)** library
- Easy to integrate into any C project

---

## Directory Structure

```
.
├── include/       # Header file (lsatoi.h)
├── src/           # Implementation (lsatoi.c)
├── Makefile       # Build script
└── README.md
```

---

## Building the Library

Use the provided `Makefile` to build either the **static** or **shared** version:

### Build static library

```bash
make static
```

This will generate `liblsatoi.a`.

### Build shared library

```bash
make shared
```

This will generate `liblsatoi.so`.

---

## Usage

1. Include the header in your project:

```c
#include "lsatoi.h"
```

2. Link against the compiled library (`.a` or `.so`) when building your project.

Example (static or shared):

```bash
gcc main.c -Iinclude -L. -llsatoi -o main
```

> If using the **shared library** without installing it system-wide, remember to set `LD_LIBRARY_PATH`:

```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./main
```

---

## Example

```c
#include <stdio.h>
#include "lsatoi.h"

int main() {
    printf("%d\n", LSATOI("-456")); // Output: -456
    return 0;
}
```

---

## Installing System-Wide (Optional)

To make the library available globally:

```bash
sudo cp liblsatoi.so /usr/local/lib/
sudo cp include/lsatoi.h /usr/local/include/
sudo ldconfig
```

Now you can compile without providing custom include/library paths:

```bash
gcc main.c -llsatoi -o main
```

---

## License

MIT License – feel free to use and modify this library in your projects.
