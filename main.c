
//String manipulation
#include <stdio.h>
#include <string.h>
#include "string.c"
#define len(arr) (sizeof(arr)/sizeof(arr[0]))
int main(){
    char *str1="Hi Hiro THis is  me Hiii";
    char **hi = split(str1," ");
    printf(hi[1]);
    char *str;
    str = toString(str,100);

    printf("%s HHS",str);
return 0;
}

//Expirement

//    int arr[] = {1,2,3};
//    char *ar1 = (char *) arr;
//    puts(ar1);
//    printf("%c",sizeof(arr));
