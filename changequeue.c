#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
    int pid, new_queue;

    if (argc != 3)
    {
        printf(2, "Usage: changequeue pid new_queue\n");
        exit();
    }

    pid = atoi(argv[1]);
    new_queue = atoi(argv[2]);

    if (change_queue(pid, new_queue) < 0)
    {
        printf(2, "Failed to change queue for process with pid %d\n", pid);
        exit();
    }

    printf(1, "Changed queue for process with pid %d to %d\n", pid, new_queue);
    exit();
}
