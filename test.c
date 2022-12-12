#include <stdio.h>
#include <unistd.h>

int     to_hex(unsigned int ptr, char conversion)
{
    unsigned int    rem;
    char            c;
    static int      count;

    count = 0;
    rem = ptr % 16;
    if (rem <= 9)
        c = rem + '0';
    else if (rem > 9 && rem < 16 && conversion == 'X')
        c = (rem - 10) + 'A';
    else if (rem > 9 && rem < 16 && conversion == 'x')
        c = (rem - 10) + 'a';
    ptr = ptr / 16;
    if (ptr != 0)
        to_hex(ptr , conversion);
    write(1, &c, 1);
    count++;
    return(count);
}

int main(void)
{
    int count;

    count = to_hex(0, 'x');

    printf("\nheeee :%d", count);
}