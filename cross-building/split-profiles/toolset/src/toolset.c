#include <stdio.h>
#include "libtoolset.h"

int main( int argc, char** argv )
{
    toolset_info_t info = toolset_info();
    char buf[1024]="";

    sprintf(buf, "%s    \"%s\", //version\n", buf, info.version);
    sprintf(buf, "%s    \"%s\", //os\n", buf, info.os);
    sprintf(buf, "%s    \"%s\", //arch\n", buf, info.arch);
    sprintf(buf, "%s    \"%s\", //build_type\n", buf, info.build_type);
    sprintf(buf, "%s    %s, //shared lib\n", buf, info.shared ? "true": "false");
    if(argc > 1){
        FILE* f = fopen(argv[1], "w");
        fwrite(buf, strlen(buf),1, f);
        fclose(f);
    }
    printf(buf);
    return 0;
}
