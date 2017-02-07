/*
 * Name: Hansen Wu
 * Class: CS 166-2
 * Date: 2017-02-04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Download `hw1.c`.  Add the missing `myreverse` function to this file. The function should take in an _input string, an output string, and the length of the strings_ (which may be assumed to be the same size).

 You may **NOT** change the main method in any way.

 Some sample executions of a reference implementation are available. Modify the comment block at the top of the file to include your information. [2 points]

 A sample run of this program, compiled to the executable 'revstr':
    $ ./revstr
    Usage: ./revstr <word to reverse>
    $ ./revstr hello
    Rev string is olleh
    $ ./revstr racecar
    Rev string is racecar
    $ ./revstr spartan
    Rev string is natraps
 */


// Func declarations
void myreverse(char* input, char * rev, int len);

/**
 * You may ***NOT** change the main method in any way.
 */
int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <word to reverse>\n", argv[0]);
    exit(1);
  }
  char* input = argv[1];
  int len = strlen(input);
  char rev[len + 1]; // Adding one for the null terminator
  myreverse(input, rev, len);
  printf("Rev string is %s\n", rev);
}

void myreverse(char* input, char * rev, int len) {
  // Operating directly on rev produces warnings
  // Instead use r and strcpy to rev
  char * r = (char*) malloc(sizeof(input));

  // reverse
  for (int i = 0; i < len; ++i) {
    r[len-1-i] = input[i];
  }
  r[len+1] = '\0'; // null terminator

  strcpy(rev, r);
}

