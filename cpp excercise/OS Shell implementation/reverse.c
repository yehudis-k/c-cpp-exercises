#include <stdio.h>
int main(int argc, char* argv[])
{
    printf("*** Start Reverse ***\n");
    for (int i=argc-1; i > 0; i--)
    {
        printf("argument number %d: %s\n", argc-i, argv[i]);
    }
    printf("*** End Reverse ***\n");
    return 0;
}