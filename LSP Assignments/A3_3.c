// 3_3 Write a program which accept two directory names from user 
// and move all files from source directory to destination directory.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    DIR * dp = NULL;
    struct dirent * entry = NULL;
    char oldname [50];
    char newname [50];

    dp = opendir(argv[2]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname, "%s/%s", argv[1], entry -> d_name);
        sprintf(newname, "%s/%s", argv[2], entry -> d_name);

        rename(oldname,newname);
    }
    closedir(dp);
    return 0;
}