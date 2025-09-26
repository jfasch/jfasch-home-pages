#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <print>

int main()
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        sleep(3);
        std::println("child exiting");
        return 7;
    }
    else {
        std::println("parent pid = {}, child pid = {}", getpid(), pid);
        pause();                                       // <-- don't care for kids
        return 0;
    }
}
