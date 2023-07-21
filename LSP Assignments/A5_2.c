// Write a program which accept file name from user which contains 
// information of all regular file in and then read teh contents of that file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employe
{
    int id;
    char Sname[20];
    float salary;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employe eobj;
    char Fname[20];
    int fd = 0;

    eobj.id = 11;
    eobj.salary = 89.997f;
    eobj.Age = 21;
    strcpy(eobj.Sname,"Shivam");

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&eobj,sizeof(eobj));

    return 0;
}