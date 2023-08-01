#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc , char * argv[])
{
    void *ptr = NULL;
    void (*fptr)(int argc, char * argv[]);

    ptr = dlopen("library2.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr,"FileCompare");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }
    
    fptr(argc,argv);
    return 0;
}