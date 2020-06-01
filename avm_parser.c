#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void read_bin(){
  FILE* fp;
  fp = fopen("mikriloulou.abc", "r");
  if(!fp){
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char const *argv[]) {
  read_bin();
  return 0;
}
