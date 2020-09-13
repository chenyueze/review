/*************************************************************************
	> File Name: main.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 一  9/ 7 15:53:29 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <haizei/test.h>

int add(int a, int b){
    return a + b;
}

TEST(testFunc, add){ //一个测试用例
    EXPECT_EQ(add(5, 3), 8); //多个测试点
    EXPECT_NE(add(5, 3), 9);
    EXPECT_GT(add(6, 7), 9);
    EXPECT_LE(add(6, 7), 13);
    EXPECT_GT(add(6, 7), 20);
                    
}


TEST(testFunc, add2)
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 9);
    EXPECT_EQ(add(6, 9), 15.5);
}

TEST(testFunc, add3){
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 4), 9);
    EXPECT_EQ(add(6, 7), 13);
}
int main(int argc, char *argv[]){
    return RUN_ALL_TESTS();
}
