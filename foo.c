#include "types.h"
#include "user.h"
#include "stat.h"

void cpu_intensive_task(void)
{
    for (int i = 0; i < 1e8; ++i)
    {
        int x = 5 + 10;
        x += 10;
    }
}

int main(void)
{
    int i, pid;

    for (i = 0; i < 10; ++i)
    {
        pid = fork();
        if (pid < 0)
        {
            printf(2, "Fork failed\n");
            exit();
        }
        else if (pid == 0)
        {
            // Child process runs the CPU-intensive task
            cpu_intensive_task();
            exit();
        }
    }

    // Parent process waits for all children to finish
    for (i = 0; i < 10; ++i)
    {
        wait();
    }

    printf(1, "All CPU-intensive tasks have completed.\n");
    exit();
}
