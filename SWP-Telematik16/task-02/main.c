#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "msg.h"

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

int main(void)
{
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);

    puts("This is Task-02");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
