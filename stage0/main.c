#include <platform.h>

int main(int argc, char **argv) {
    char **envp = get_envp();
    char *home = getenv("HOME");

    (void)argc;
    (void)argv;
    (void)envp;
    (void)home;

    return 0;
}
