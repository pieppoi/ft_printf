#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int n1, n2;

    n1 = ft_printf("[%10s] [%-.5s]\n", "hello", "world");
    n2 = printf   ("[%10s] [%-.5s]\n", "hello", "world");
    ft_printf("ret=%d vs %d\n", n1, n2);

    n1 = ft_printf("[%#08x] [%#-10X]\n", 255, 255);
    n2 = printf   ("[%#08x] [%#-10X]\n", 255, 255);
    ft_printf("ret=%d vs %d\n", n1, n2);

    n1 = ft_printf("[%+8d] [% d] [%.0d] [%.5d]\n", -42, 42, 0, 42);
    n2 = printf   ("[%+8d] [% d] [%.0d] [%.5d]\n", -42, 42, 0, 42);
    ft_printf("ret=%d vs %d\n", n1, n2);

    void *p = (void*)0x1234abcd;
    n1 = ft_printf("[%20p] [%p]\n", p, NULL);
    n2 = printf   ("[%20p] [%p]\n", p, NULL);
    ft_printf("ret=%d vs %d\n", n1, n2);

    n1 = ft_printf("[%-05%] [%5%] [%.3%]\n");
    n2 = printf   ("[%-05%] [%5%] [%.3%]\n");
    ft_printf("ret=%d vs %d\n", n1, n2);
    return 0;
}
