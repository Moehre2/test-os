#include "print.h"

const char* abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopgrstuvwxyz";

void kernel_main(void) {
	print_clear();
	print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
	print_str("Welcome to Test OS, a 64-bit kernel!");
	print_str(" \n");
	print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
	for(size_t i = 0; i < 10000; i++) {
		print_char(abc[i % 62]);
	}
}
