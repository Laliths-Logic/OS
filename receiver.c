#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;
    int shmid;

    shmid = shmget(key, 1024, 0666);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Data read from shared memory: %s\n", str);

    shmdt(str);

    return 0;
}
