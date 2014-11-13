
#include <stdio.h>

#ifdef __cplusplus

void foo(int i) {
    printf("int");
}

void foo(char c) {
    printf("char");
}

#endif

int main() {
    printf("sizeof character literal - %ld\n", sizeof('a'));

#ifdef __cplusplus
    foo('a');
#endif

    return 0;
}

