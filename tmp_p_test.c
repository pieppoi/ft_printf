#include <stdio.h>
#include "srcs/ft_printf.h"

int main(void) {
    int ret1, ret2;
    void *ptr = NULL;

    printf("=== NULL pointer width test ===\n");

    ret1 = printf("std :[%10p]\n", (void *)ptr);
    ret2 = ft_printf("mine:[%10p]\n", ptr);
    printf("ret std = %d, mine = %d\n\n", ret1, ret2);

    ret1 = printf("std :[%3p]\n", (void *)ptr);
    ret2 = ft_printf("mine:[%3p]\n", ptr);
    printf("ret std = %d, mine = %d\n\n", ret1, ret2);

    ret1 = printf("std :[%p]\n", (void *)ptr);
    ret2 = ft_printf("mine:[%p]\n", ptr);
    printf("ret std = %d, mine = %d\n", ret1, ret2);

    return 0;
}
