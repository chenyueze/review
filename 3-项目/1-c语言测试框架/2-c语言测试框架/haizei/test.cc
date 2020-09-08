#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <haizei/linklist.h>

int func_cnt = 0;
struct Function func_head, *func_tail = &func_head;
struct FunctionInfo test_info;

int RUN_ALL_TESTS(){
    for(struct LinkNode *p  = func_head.p.next; p; p = p->next){
        struct Function *func = Head(p, struct Function, p);
        printf(GREEN("[====RUN====]") YELLOW(" %s\n"), func->str);
        test_info.total = test_info.success = 0;
        func->func();
        double rate = 100.0 * test_info.success / test_info.total;
        printf(GREEN("[  "));
        // if(fabs(rate - 100.0) < 1e-6)  <math.h>
        // if(rate == 100.0)
        if (test_info.total == test_info.success){
            printf(BLUE_HL("%6.2lf%%"), rate);
        }else{
            printf(RED("%6.2f%%"), rate);
        }
        printf(
              GREEN("  ]") " total : %d    success : %d\n", 
              test_info.total
              ,test_info.success
            );
        printf("\n");
    }
    return 0;
}

void add_function(TestFuncT func, const char *str){
    struct Function *temp = (struct Function *)calloc(1, sizeof(struct Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}
