#include <platform.h>

int main(int argc, char **argv) {
    char **envp = platform_get_envp();
    char *home = platform_getenv("HOME");

    (void)argc;
    (void)argv;
    (void)envp;
    (void)home;

    return 0;
}
