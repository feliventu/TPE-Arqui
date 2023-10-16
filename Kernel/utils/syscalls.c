#include <naiveConsole.h>
#include "syscalls.h"
#include "keyboard.h"
#include "time.h"
#include "io.h"


// temp
#include <naiveConsole.h>

// Cast to a function pointer
typedef uint64_t (*syscall_t)(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

// Array of function pointers
static syscall_t syscalls[] = {
    (syscall_t)&sys_read,           // sys_id 0
    (syscall_t)&sys_write,          // sys_id 1
    (syscall_t)&pid,                // sys_id 2
    (syscall_t)&sys_exec,           // sys_id 3
    (syscall_t)&sys_ticks,          // sys_id 4
    (syscall_t)&sys_seconds,        // sys_id 5
    (syscall_t)&sys_random_number,  // sys_id 6
    (syscall_t)&sys_read_char       // sys_id 7
};

uint64_t syscall_dispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9) {


    syscall_t syscall = syscalls[r9];
    if (syscall != 0) {
        return syscall(rdi, rsi, rdx, rcx, r8);
    }
    return 0;
}

uint64_t sys_write(uint8_t fd, const char *buffer, uint64_t count, uint64_t fgcolor, uint64_t bgcolor) {
    if (buffer == 0) {
        return 0;
    }

    // @TODO: Check if fd is valid and replace magic numbers
    // stdout
    if (fd == 1) {
        return printf_color(buffer, fgcolor, bgcolor);
    }

    // stderr
    else if (fd == 2)
        return printf_color(buffer, 0xFF, 0x40);

    return 0;

}

char *sys_read(uint8_t fd, char *buffer, uint64_t count)
{
    // char c = get_last_input();
    // putchar(c);
    // for (int i = 0; i < count; i++) {
    //     do {
    //         buffer[i] = get_first_input();
    //         if (buffer[i] != 0)
    //             // putchar(buffer[i]);
    //     } while (buffer[i] == 0);
    // }
    return 0;
    // return get_buffer(buffer, count);
}

char sys_read_char(){
    char c = get_last_input();
    // putchar(c);
    return c; 
}

uint64_t pid() {
    return 0;
}
void sys_exec(){

}

uint64_t sys_ticks(){
    return ticks_elapsed();
}

uint64_t sys_seconds(){
    return seconds_elapsed();
}

uint64_t sys_random_number(){
    return get_random_number();
}