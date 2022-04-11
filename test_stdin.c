#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
        char buff[50];

        read(0, buff, 50);
        printf("%s\n", buff);
}

