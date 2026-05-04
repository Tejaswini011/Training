#include <stdint.h>

uint32_t my_value __attribute__((section(".my_reserved"))) = 0x12345678;

/* Access linker symbols */
extern uint8_t __my_start;
extern uint8_t __my_end;

int main(void)
{
    /* Access via pointer */
    uint32_t *ptr = (uint32_t *)&__my_start;

    ptr[1] = 0xDEADBEEF;   // write into reserved memory

    while (1);
}
