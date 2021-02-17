
// String manipulation
#include <stdio.h>
#include <string.h>
#include "split-string.c"

int main(){
    char str[]="Hi Hiro";
    char** hi = split(str);
    printf(hi[0]);
return 0;
}