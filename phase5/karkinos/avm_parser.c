#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "avm.h"



void read_bin(){
  FILE* fp;
  int c;
  int g;
  //char* str;
  fp = fopen("mikriloulou.abc", "r");
  if(!fp){
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  while ((c = getc(fp)) != EOF){
    if(c == '|'){
      while((g = getc(fp)) != '|'){
        printf("%c",g);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  read_bin();
  return 0;
}
