#include <stdio.h>

int main()
{
    // Печать архитектуры, если определена

    switch (sizeof(void *)) {
    case 4:
        printf("32");

        break;
    case 8:
        printf("64");

        break;
    default:
        printf("неизвестно");
    }

    return 0;
}
