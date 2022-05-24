#include <stdio.h>
#include <stdlib.h>

#include "../src/print_para2.h"

int main (int argc, char* argv[])
{
    if (argc != 3) {
        printf("para error\n");
        printf("Usage: %s <str> <int>", argv[0]);
        return -1;
    }

    print_para2(argv[1], atoi(argv[2]));
}