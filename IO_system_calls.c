#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<sys/stat.h>
#define WR_VALUE _IOW('a','a',int*)
#define RD_VALUE _IOR('a','b',int*)
int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("sample.txt", O_RDONLY | O_CREAT);
    int fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd3 = open("file3.txt", O_RDWR);
    char c[20];
    // reading from sample.txt
    read(fd, &c, 20);
    printf("Text in file is: %s\n",c);
    //writing into file2.txt which was stored in c
    write(fd2, c, read(fd, &c, 20));
    lseek(fd, 5, SEEK_CUR);
    char c1[20];
    read(fd, &c1, 20);
    printf("Text after lseek 10 characters: %s",c1);
    printf("Enter a value to write in the file: ");
    int number;
    scanf("%d",&number);
    ioctl(fd3, WR_VALUE,(int*) &number);
    struct stat sfile;
    stat("stat.c", &sfile);
    printf("st_mode = %o\n",sfile.st_mode);
    close(fd);
    close(fd2);
    close(fd3);
    return 0;
}
