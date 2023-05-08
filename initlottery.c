#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
    int pid, ticket;

    if (argc != 3)
    {
        printf(2, "Usage: initlottery pid ticket\n");
        exit();
    }

    pid = atoi(argv[1]);
    ticket = atoi(argv[2]);

    if (initialize_lottery(pid, ticket) < 0)
    {
        printf(2, "Failed to initialize lottery for process with pid %d\n", pid);
        exit();
    }

    printf(1, "Initialized lottery for process with pid %d with ticket %d\n", pid, ticket);
    exit();
}
