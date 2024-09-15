/*
Problem Statement: Developing 'cp' command of the unix system using System Calls.
Developer: Akshay Mandalik 
Last Modified: Sun 15 Sep, 2024
*/


#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char buffer[2048];

void copy(int fdold,int fdnew)
       
{   
        int count;
        while((count=read(fdold,buffer,sizeof(buffer)))>0)
            write(fdnew,buffer,count);

}

int main(int argc,char *argv[]) 
       
{   
    int fdold, fdnew;
    if(argc != 3){
        printf("Need 2 arguments for copy program\n");
        exit(1);
    }
    fdold = open(argv[1],O_RDONLY); /* Open source file read only */
    if(fdold==-1){
        printf("Unable to open file %s\n",argv[1]);
        exit(1);
    }
    fdnew = creat(argv[2],0666);   /* Create target file rw for all*/
    if(fdnew == -1){
            printf("Unable to create file %s\n",argv[2]);
            exit(1);
    }   
    copy(fdold,fdnew);
    exit(0);
}

