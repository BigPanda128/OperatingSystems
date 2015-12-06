//Ryan Postma project 1 with extra credit
//12/3/15
//'Operating systems'

//include the tools i'll need
#include <stdio.h>
#include <stdlib.h>

//basic student structure layout.
struct StudentStruct {
  char name[30];
  int compSci;
  int calc;
  int writing;
  int bio;
  int volleyball;
  int totalGrade;
  int rank;
};

//main method to run everything
void main(void) {

  //global variables for number of students and input length
  int numStudents = 0;
  char input[80];

  //get the amount of students your working with
  printf("\nHow many students: ");
  numStudents = atoi(fgets(input, 80, stdin));

  //create empty structures for each of hte students
  struct StudentStruct students[numStudents];

  //goes through each student and asks for each grade.
  for(int i = 0; i < numStudents; i++) {

    //gets name
    printf("\nStudent %d's name is: ",i+1);
    fgets(students[i].name, 80, stdin);
    strtok(students[i].name, "\n");//gets rid of the newline after name

    //get compsci grade
    printf("%s's Computer Science 1 Grade: ",students[i].name);
    students[i].compSci = atoi(fgets(input, 80, stdin));

    //get calc grade
    printf("%s's Calculus Grade: ",students[i].name);
    students[i].calc = atoi(fgets(input, 80, stdin));

    //gets writing grade
    printf("%s's Technical Writing Grade: ",students[i].name);
    students[i].writing = atoi(fgets(input, 80, stdin));

    //gets bio grade
    printf("%s's Biology Grade: ",students[i].name);
    students[i].bio = atoi(fgets(input, 80, stdin));

    //gets volleyball grade
    printf("%s's Advanced Volleyball Grade: ",students[i].name);
    students[i].volleyball = atoi(fgets(input, 80, stdin));

    //calculates the total grade
    students[i].totalGrade = students[i].volleyball +
    students[i].bio + students[i].writing +
    students[i].calc + students[i].compSci;

  }//end for

//this calculates the ranking for the students
  //goes through each student and compares them
  //to everyone else and adjusts there rank accordingly
  for(int i = 0; i < numStudents; i++){
		int count = 1;
		for(int x = 0; x < numStudents; x++){
			if(students[i].totalGrade < students[x].totalGrade){
				count++;
			}//end if
		}//end for
		students[i].rank = count;
	}//end for

  //spacer for distcintion between sections
  printf("===========================================================\n");

  //lays out the top of the table
  printf("%7s %7s %7s %7s %7s %7s %7s %7s\n","Rank", "CSci", "Clac",
  "Write", "Bio", "Volley", "Total", "Name");

  //keeps track of the current rank
  int rankCount = 1;

  //goes through each person and prints the highest rank first
  //then second highest etc etc
  while(rankCount <= numStudents){
    for(int i = 0; i < numStudents; i++) {
      if(rankCount == students[i].rank){
        printf("%7d %7d %7d %7d %7d %7d %7d %7s\n",students[i].rank, students[i].compSci,
        students[i].calc, students[i].writing, students[i].bio,
        students[i].volleyball, students[i].totalGrade, students[i].name);

        rankCount++;
      }//end if
    }//end for

  }//end while

}//end main
