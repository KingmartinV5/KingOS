// kernel.c
#include <stdint.h>

static uint16_t* const VGA_BUFFER = (uint16_t*)0xB8000;
static const int VGA_COLS = 80;
static const int VGA_ROWS = 25;

void kmain(void) {
    const char *msg = "HELLO WORLD";
    int i = 0;
    // Clear screen
    for (int y = 0; y < VGA_ROWS; y++) {
        for (int x = 0; x < VGA_COLS; x++) {
            VGA_BUFFER[y * VGA_COLS + x] = (0x07 << 8) | ' ';
        }
    }
    // Print message
    while (msg[i]) {
        VGA_BUFFER[i] = (0x07 << 8) | msg[i];
        i++;
    }
    // Hang forever
    for (;;) { __asm__ __volatile__("hlt"); }
}
