//报错函数
#include <stdio.h>
#include <stdlib.h>

void FatalError( const char* ErrorMsg ){
    fprintf( stderr, "%s\n", ErrorMsg );
    exit(1);
}