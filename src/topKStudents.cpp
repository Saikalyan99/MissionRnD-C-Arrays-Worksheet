/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include <string.h>

struct student
{
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	if (K <= 0)
		return NULL;
	else
	{
		int index, index1;
		struct student **result = (struct student**)malloc(len*sizeof(struct student));

		for (index = 0; index < len; index++)
			for (index1 = index; index1 < len; index1++)
				if (students[index].score < students[index1].score)
				{
					struct student temp = students[index];
					students[index] = students[index1];
					students[index1] = temp;
				}

		if (K == 1)
		{
			result[0] = &students[0];
			return result;
		}
		if (K > len)
		{
			for (index = 0; index < len; index++)
				result[index] = &students[index];
			return result;
		}
		else
		{
			for (index = 0; index < K; index++)
				result[index] = &students[index];
			return result;
		}
	}
}