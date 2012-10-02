#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**********************************************
  A simple c program that creates a file using
  the open() system call
  Usage: create file_name
  Author: mshirlaw
  Date: 2/10/12
***********************************************/

main(int argc, char* argv[])
{
  pid_t child;
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  if(argc != 2)
  {
    printf("Usage: ./create filename\n");
    exit(1);
  }

  if((child=fork()) == 0 )
  {
    if( (fd = open(argv[1], O_RDWR | O_CREAT, mode)) == -1)
       perror("Could not open the file");
    else
    {
      printf("Opened file successfully! Now closing it\n");
      close(fd);
    }
  }
  else
  {
    printf("Child pid : %lx\n", (long)child);     
  }
}
