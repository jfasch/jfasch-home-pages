#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>

int main()
{
    void* memory = mmap(
        NULL,                                          // <-- (addr) let kernel choose address
        16*1024*1024,                                  // <-- (length) 16 MiB *virtually contiguous* memory
        PROT_READ|PROT_WRITE,                          // <-- (prot) memory access protection
        MAP_ANONYMOUS|MAP_PRIVATE,                     // <-- (flags) anon, copy-on-write (we don't share anyway though)
        -1,                                            // <-- (fd) no fd, this is an anonymous mapping
        0                                              // <-- (offset) no offset, this is an anonymous mapping
    );
    if (memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    *(((char*)memory)+16) = 'a';                       // <-- access memory in first page of mapping
                                                       //     will cause page to be allocated

    munmap(memory, 16*1024*1024);                      // <-- technically not necessary; done anyway at exit

    return 0;
}
