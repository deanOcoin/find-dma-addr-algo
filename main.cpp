
#include <stdint.h>
#include <vector>

// Find DMA Address Algo | C++/x86 MASM

uintptr_t FindDMAAddress(uintptr_t ptr, std::vector<uint32_t> offsets)
{
    uintptr_t addr = ptr;
    int vecsize = offsets.size();
    int i = 0;

    __asm
    {
    addl:
        mov addr, [addr]
        add addr, offsets[i]
        add i, 1
        cmp i, vecsize
        jl addl
    }
    return addr;
}