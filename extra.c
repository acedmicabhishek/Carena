#include <stdio.h>
#include <string.h>



void test_storeag();

int global_var = 100;


void scope_and_storage(void) {
    
    auto int local_auto_var = 10;
    local_auto_var++;
    printf("   - local_auto_var (auto): %d\n", local_auto_var);

    static int static_var = 0;
    static_var++;
    printf("   - static_var (static): %d (value persists across calls)\n", static_var);

    printf("   - Accessing global_var from function: %d\n", global_var);


    register int register_var = 20;
    printf("   - register_var: %d\n", register_var);

}
