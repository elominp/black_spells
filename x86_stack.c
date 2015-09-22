#include <stdlib.h>
#include <stdio.h>

void main()
{
    void *ptrargc = NULL;
    void *ptrargv = NULL;
    void *ptrenv = NULL;

    size_t ebp = 0;
    size_t esp = 0;

    int argc = 0;
    char **argv = NULL;
    char **env = NULL;

    __asm__ ("\tmov %%ebp, %0\n" : "=r"(ebp));

    __asm__ ("\tmov %%esp, %0\n" : "=r"(esp));

    printf("\n========= Values of Stack registers ==============\n\n");
    printf("adress pointed by ebp : %p\n", (void *)ebp);
    printf("adress pointed by esp : %p\n", (void *)esp);
    printf("\n==================================================\n");

    ptrargc = (void *)ebp + (2 * sizeof(void *));
    ptrargv = ptrargc + sizeof(void *);
    ptrenv = ptrargv + sizeof(void *);

    printf("\n========== Address of main arguments =============\n\n");
    printf("adress of argc : %p\n", ptrargc);
    printf("adress of argv : %p\n", ptrargv);
    printf("adress of env : %p\n", ptrenv);
    printf("\n==================================================\n");

    argc = *((int *)ptrargc);
    argv = *((char ***)ptrargv);
    env = *((char ***)ptrenv);

    printf("\n========= Values of main arguments ===============\n\n");
    printf("value of argc : %d\n", argc);
    printf("\n**************************************************\n\n");

    for (int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    printf("\n**************************************************\n\n");

    for (int i = 0; env[i] != NULL; i++)
        printf("env[%d] = %s\n", i, env[i]);
    printf("\n==================================================\n\n");

    printf("\n======== Data store in stack between ebp and esp ===========\n\n");
    for (void *tmp = (void *)(ebp - 4); tmp > esp; tmp -= sizeof(void *))
        printf("%p\n", (void *)(*(size_t *)tmp));
    printf("\n============================================================\n");

    __asm__("\tmov $0x2A, %eax\n");
}
