#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/display.h"
#include "../drivers/keyboard.h"

#include "util.h"
#include "mem.h"

void* alloc(int n) {
    int *ptr = (int *) mem_alloc(n * sizeof(int));
    if (ptr == NULL_POINTER) {
        print_string_defcol("Memory not allocated.\n");
    } else {
        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
//            ptr[i] = i + 1; // shorthand for *(ptr + i)
        }

        for (int i = 0; i < n; ++i) {
//            char str[256];
//            int_to_string(ptr[i], str);
//            print_string_defcol(str);
        }
//        print_nl();
    }
    return ptr;
}

void start_kernel() {
    clear_screen();
    print_string_defcol("Installing interrupt service routines (ISRs).\n");
    isr_install();

    print_string_defcol("Enabling external interrupts.\n");
    asm volatile("sti");

    print_string_defcol("Initializing keyboard (IRQ 1).\n");
    init_keyboard();

    print_string_defcol("Initializing dynamic memory.\n");
    init_dynamic_mem();

    //clear_screen();

    print_string_defcol("init_dynamic_mem()\n");
    print_dynamic_node_size();
    print_dynamic_mem();
    print_nl();

    int *ptr1 = alloc(5);
    print_string_defcol("int *ptr1 = alloc(5)\n");
    print_dynamic_mem();
    print_nl();

    int *ptr2 = alloc(10);
    print_string_defcol("int *ptr2 = alloc(10)\n");
    print_dynamic_mem();
    print_nl();

    mem_free(ptr1);
    print_string_defcol("mem_free(ptr1)\n");
    print_dynamic_mem();
    print_nl();

    int *ptr3 = alloc(2);
    print_string_defcol("int *ptr3 = alloc(2)\n");
    print_dynamic_mem();
    print_nl();

    mem_free(ptr2);
    print_string_defcol("mem_free(ptr2)\n");
    print_dynamic_mem();
    print_nl();

    mem_free(ptr3);
    print_string_defcol("mem_free(ptr3)\n");
    print_dynamic_mem();
    print_nl();

    clear_screen();
    print_string("Welcome to ShineOS 1.0.1!\n", mix_color(BLACK, WHITE));

    //draw prompt
    print_string_defcol("> ");
}

void execute_command(char *input) {
    if (compare_string(input, "EXIT") == 0) {
        print_string_defcol("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    else if (compare_string(input, "HELP") == 0) {
        print_string_defcol("JinxOS, a hubby os developed by Abolfazl Malekpour. the commands are HELP, EXIT and CLEAR\n> ");
    }
    else if (compare_string(input, "") == 0) {
        print_string_defcol("\n> ");
    }
    else if (compare_string(input, "CLEAR") == 0) {
      clear_screen();
      print_string_defcol("> ");
    }
    else {
        print_string_defcol("Unknown command: ");
        print_string_defcol(input);
        print_string_defcol("\n> ");
    }
}
