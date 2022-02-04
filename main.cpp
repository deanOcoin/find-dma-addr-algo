
#include <stdint.h>
#include <vector>

// Find DMA Address Algo | C++/x86 MASM

uintptr_t FindDMAAddress(uintptr_t base, std::vector<uint32_t> offset_vec)
{
    uintptr_t addr = base;
    int vecsize = offset_vec.size();
    int i = 0;

    __asm
    {
    addl:
        mov addr, [addr]
        add addr, offset_vec[i]
        add i, 1
        cmp i, vecsize
        jl addl
    }
    return addr;
}
