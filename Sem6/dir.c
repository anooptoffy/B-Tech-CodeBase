// To implement Unix LS command.

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
int i;
DIR*dp;
struct dirent*dirp;

if (argc==2) 
      {
      dp = opendir(argv[1]);
        while ((dirp = readdir(dp)) != NULL)
      printf("%s\n", dirp->d_name);
      }
else
      {
      if (argc == 1)
            {
            dp = opendir("./");
              while ( (dirp = readdir(dp)) != NULL)
                printf("%s\n", dirp->d_name);
            }
      else 
            { 
            printf("ls - Error - too many parameters\n");
            exit(0);
            }

      };
        closedir(dp);
        return 0;
}
