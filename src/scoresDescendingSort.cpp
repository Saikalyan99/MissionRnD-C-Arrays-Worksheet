/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include <string.h>

struct student
{
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) 
{
	if (students == NULL || len < 0)
		return NULL;
	else
	{
		int index1,index2,temp1,temp2;
		char temp[10];
		for (index1 = 0; index1 < len; index1++)							//selection sort
		{
			temp1 = index1;
			for (index2 = index1+1; index2 < len; index2++)
				if (students[temp1].score < students[index2].score)
					temp1 = index2;
			if (temp1 != index1)											//swaping score and name at a time
			{
				temp2 = students[index1].score;
				strcpy(temp, students[index1].name);

				students[index1].score = students[temp1].score;
				strcpy(students[index1].name, students[temp1].name);

				students[temp1].score = temp2;
				strcpy(students[temp1].name, temp);
			}
		}
	}
}