# lib/ Directory – Project Specific Libraries

This directory is intended for **project-specific (private) libraries**.  
PlatformIO will compile them to static libraries and link them into the executable file.

The source code of each library should be placed in a separate directory:  
`lib/your_library_name/[Code]`

## Example Structure

```
lib/
├── Bar/
│   ├── docs/
│   ├── examples/
│   ├── src/
│   │   ├── Bar.c
│   │   └── Bar.h
│   └── library.json  ← Optional: custom build options
│
├── Foo/
│   ├── Foo.c
│   └── Foo.h
│
└── README.md ← THIS FILE

platformio.ini
src/
└── main.c
```

📘 Reference: [`library.json`](https://docs.platformio.org/page/librarymanager/config.html)

## Example `src/main.c` using Foo and Bar

```c
#include <Foo.h>
#include <Bar.h>

int main(void)
{
    // Your application code here
}
```

## Library Dependency Finder (LDF)

PlatformIO’s **Library Dependency Finder** will automatically detect required libraries  
by scanning your project's source code.

🔗 Learn more: [PlatformIO LDF Documentation](https://docs.platformio.org/page/librarymanager/ldf.html)
