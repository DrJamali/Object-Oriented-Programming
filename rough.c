#include <stdio.h>

int main() {
    
    int b=9;
    int *ptr =&b;
    printf("%d", *(ptr));

    return 0;
}