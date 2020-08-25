#include <stdio.h>
#include <libtoolset.h>
struct toolset_info_t toolsinfo ={
#include "tool-set.c"
};

int main(){
    printf("---------------- Linked package information ---------------------\n");
    print_info();

    printf("================ Build tools information ======================\n");
    printf(" version = %s\n", toolsinfo.version);
    printf(" os =  %s\n", toolsinfo.os);
    printf(" arch = %s\n", toolsinfo.arch);
    printf(" build_type = %s\n", toolsinfo.build_type);
    printf(" shared lib = %s\n", toolsinfo.shared ? "true": "false");
    
    return 0;
}
