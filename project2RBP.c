/*
Ryan Postma
Opsys
Project 2 code
*/

//get my c tools
#include <stdio.h>
#include <stdlib.h>

//void function to run the code
void main(void) {

  //get my base variables
  int count = 0;
  char input[150];//limits how long the input can be

  //gets the input
  printf("\nWelcome to the vowel counter!\n");
  printf("Please enter a line of text: ");
  fgets(input, 80, stdin);

  //finds the vowels in the code
  for(int i = 0; input[i]!='\0'; ++i){
    if (input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || input[i]=='A' || input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U'){
      printf("found a vowel: %c\n", input[i]);
      count ++;
    }
  }
  //prints out total count
  printf("The number of vowels is: %d\n", count);
}
