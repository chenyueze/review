//inttypes、sizeof、PRIdx
#include <stdio.h>
#include <inttypes.h>

int main(){
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
    int e;
    printf("size a = %lu\n", sizeof(a));
    printf("size b = %lu\n", sizeof(b));
    printf("size c = %lu\n", sizeof(c));
    printf("size d = %lu\n", sizeof(d));
    printf("size e = %lu\n", sizeof(e));
    a = 12;
    printf("a = %d, size a = %lu\n", a, sizeof(a));
    printf("a = %"PRId8"\n", a);
    printf("%s\n", PRId8);
    printf("%s\n", PRId16);
    printf("%s\n", PRId32);
    printf("%s\n", PRId64);
    printf("%d\n", INT8_MIN);
    printf("%d\n", INT8_MAX);
    return 0;
}