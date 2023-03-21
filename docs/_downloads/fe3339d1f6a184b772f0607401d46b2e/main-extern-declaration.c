#include <stdio.h>


extern int global;

int main(void)
{
    printf("%d\n", global);
    return 0;
}
