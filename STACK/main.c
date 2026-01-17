//测试文件: 输入 gcc main.c stack.c -o test_stack 和  .\test_stack.exe 即可

#include <stdio.h>
#include "stack.h" //包含栈头文件

int main() {
    Stack S;
    int i;

    printf("=== Test_Stack ===\n\n");

    // 1. 测试创建栈
    printf("[1] CreateStack...\n");
    S = CreateStack();
    if(IsEmpty(S)) {
        printf("    -> Success: Stack is created.\n");
    } else {
        printf("    -> Failed!\n");
    }

    // 2. 测试入栈 (Push)
    printf("\n[2] Push 10.0 -> 50.0...\n");
    for(i = 1; i <= 5; i++) {
        double val = i * 10.0;
        Push(val, S);
        printf("    Push: %.2f\n", val);
    }
    
    // 3. 测试栈顶 (Top)
    printf("\n[3] Test Top...\n");
    printf("    The Current Top: %.2f\n", Top(S));

    // 4. 测试出栈 (Pop)
    printf("\n[4] Test Pop...\n");
    Pop(S);
    printf("    Pop once.\n");
    printf("    The New Top: %.2f\n", Top(S));

    // 5. 测试清空 (MakeEmpty)
    printf("\n[5] MakeEmpty...\n");
    MakeEmpty(S);
    if(IsEmpty(S)) {
        printf("    -> Success: Stack is made empty.\n");
    } else {
        printf("    -> Failed!\n");
    }

    // 6. 测试销毁 (DisposeStack)
    printf("\n[6] DisposeStack...\n");
    DisposeStack(S);
    // 注意：销毁后 S 变为野指针，不应再使用 IsEmpty(S) 检查
    printf("    -> Stack is disposed.\n");

    printf("\n=== Test_End ===\n");

    return 0;
}