//测试文件: 输入 gcc main.c stack.c -o test_stack 和  .\test_stack.exe 即可
#include <stdio.h>
#include "stack.h" // 确保文件名与你的头文件一致

void print_separator() {
    printf("--------------------------------------------------\n");
}

int main() {
    int max_size = 5;
    Stack S;

    print_separator();
    printf("TEST 1: Creating Stack\n");
    S = CreateStack(max_size);
    printf(">> Stack created with capacity: %d\n", max_size);
    
    if (IsEmpty(S)) {
        printf(">> [Pass] Stack is initially empty.\n");
    } else {
        printf(">> [Fail] Stack should be empty.\n");
    }

    print_separator();
    printf("TEST 2: Pushing Elements\n");
    // 测试入栈，填满栈
    for (int i = 0; i < max_size; i++) {
        double val = (i + 1) * 10.5; // Example values: 10.5, 21.0, etc.
        printf(">> Pushing value: %.2f\n", val);
        Push(val, S);
    }

    print_separator();
    printf("TEST 3: Checking Full Stack\n");
    if (IsFull(S)) {
        printf(">> [Pass] Stack is now full.\n");
    } else {
        printf(">> [Fail] Stack should be full (Capacity: %d, Top: %.2f).\n", 
               max_size, Top(S));
    }

    // 尝试在满栈时再 Push (如果取消注释下一行，程序应报错退出)
    // printf(">> Attempting to push to full stack (Should crash)...\n");
    // Push(999.9, S);

    print_separator();
    printf("TEST 4: Top and Pop Operations\n");
    
    // 检查栈顶
    double topVal = Top(S);
    printf(">> Current Top element: %.2f\n", topVal);

    // 依次弹出所有元素
    printf(">> Popping all elements:\n");
    int count = 0;
    while (!IsEmpty(S)) {
        double val = TopAndPop(S);
        printf("   [%d] Popped: %.2f\n", ++count, val);
    }

    if (IsEmpty(S)) {
        printf(">> [Pass] Stack is empty after popping all elements.\n");
    }

    print_separator();
    printf("TEST 5: Resource Management\n");
    DisposeStack(S);
    printf(">> Stack memory disposed successfully.\n");
    print_separator();

    printf("All tests completed.\n");

    return 0;
}