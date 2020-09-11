/*************************************************************************
	> File Name: test.h
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 一  9/ 7 16:24:38 2020
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <haizei/linklist.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)


#define TEST(a, b)\
void a##_##b();\
__attribute__((constructor))\
void add##_##a##_##b(){\
    add_function(a##_##b, #a "." #b);\
}\
void a##_##b()

#define TYPE_STR(a) _Generic((a), \
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    const char * : "%s"\
)

#define P(a, color){\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE_STR(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, cmp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    test_info.total += 1;\
    if(_a cmp _b) test_info.success += 1;\
    else{\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect" #a " " #cmp " " #b " actual : "));\
        P(a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(b, YELLOW_HL);\
        printf("\n");\
    }\
    printf(GREEN("[-----------] ") #a " " #cmp " " #b);\
    printf(" %s\n", (_a) cmp (_b) ? GREEN_HL("True") : RED_HL("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)

extern struct FunctionInfo test_info;

typedef void(*TestFuncT)();

struct Function{
    TestFuncT func;
    const char *str;
    struct LinkNode p;
};

struct FunctionInfo {
    int total, success;  
};

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
