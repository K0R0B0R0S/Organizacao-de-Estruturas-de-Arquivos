#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int * a = malloc(4);
    scanf("%d", a);
    printf("%d",*a);
    return 0;
}