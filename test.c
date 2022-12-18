#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main(void)
{
    ft_printf("hello %% %d", -42);
}