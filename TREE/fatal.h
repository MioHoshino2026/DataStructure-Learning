//报错函数
#ifndef _FATAL_H
#define _FATAL_H

#include <stdio.h>
#include <stdlib.h>

void FatalError( const char* ErrorMsg ){
    fprintf( stderr, "%s\n", ErrorMsg );
    exit(1);
}

#endif