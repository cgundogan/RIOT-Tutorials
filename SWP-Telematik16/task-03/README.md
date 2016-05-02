# 3. Custom Shell Commands, Timers and Threads

## 3.1. Writing a Custom Shell Command:
1.  Read [Here](http://doc.riot-os.org/group__sys__shell.html).
2.  Add a function with the following signature to `main.c`:

    ```c
    int cmd_func(int argc, char **argv);
    ```
    Any parameters following the shell command in the RIOT shell are accessible
    from the `argv` variable. `argc` contains the number of parameters used to call this shell
    command plus one for the name of the command.

    As an example, print out the number of parameters given to the shell command and echo back
    the first parameter with `printf`.
    Your function must return `0` if it runs successfully and `-1` if an error occurs.

3.  Add your function to the `shell_commands` array:
    ```c
    static const shell_command_t shell_commands[] = {
        { "command", "command description", cmd_func },
        { NULL, NULL, NULL }
    };
    ```

4.  Flash the modified code to your board and test your new shell command.
    ```sh
    BOARD=samr21-xpro make all flash term
    ```
    You can verify with `help` if your command was picked up by the shell handler. Call your
    shell command and observe the output.

5.  Include the `board.h` file and use `LED0_TOGGLE` in your custom shell command to toggle
    the onboard LED.

## 3.2 Timers
1.  Read [Here](http://doc.riot-os.org/group__sys__xtimer.html).
2.  Print the current system time in your custom shell command.

## 3.3 Threads
1.  Read [Here](http://doc.riot-os.org/thread_8h.html).
2.  Create a thread that prints the current system time every two seconds.
    Have a look at `thread_create()`, `xtimer_sleep()` and `xtimer_now()`.
