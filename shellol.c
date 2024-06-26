/*
 * Module: shellol.c
 * Author: mp3skater
 * License: MIT License
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
  char prog[15];

  // Ask for name
  char * name;
  printf("Please type here your name: ");
  scanf("%s", name);

  // Program runs until you type "q"
  while(strcmp(prog,"q"))
  {
    // Get working directory and user-id
    char cwd[30];
    getcwd(cwd, 29);
    int uid = getuid();
    printf("%s:%s$ ", name, cwd);

    // Get name of call
    char prog[15];
    scanf("%s", prog);


    // Exit
    if(strcmp(prog,"q") == 0)
      return 0;

    // Print Working Directory
    else if(strcmp(prog,"pwd") == 0)
      printf("%s\n", cwd);

    // Print User ID
    else if(strcmp(prog,"puid") == 0)
      printf("%i\n", uid);

    // idk
    else if(strcmp(prog,"lol") == 0)
      printf("lolol\n");

    // Print name
    else if(strcmp(prog,"pname") == 0)
      printf("%s\n", name);

    // Program call
    else {
      int parent = fork();

      // Parent
      if(parent) {
        wait();
      }

      // Child
      else {
        // Execution
        execlp(prog, prog);

        // Execution failed
        printf("Can't find program called: \"%s\".\n", prog);
        return 1;
      }
    }
  }
}
