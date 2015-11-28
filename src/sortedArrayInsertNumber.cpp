/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int temp, temp1, index, index1, flag = 2;
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		for (index = 0; index <= len - 1; index++)
		{
			if (Arr[index] > num)
			{
				temp = Arr[index];
				Arr[index] = num;
				while (index != len - 1)
				{
					temp1 = Arr[index + 1];
					Arr[index + 1] = temp;
					temp = temp1;
					index++;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 2)
			Arr[len] = num;
		return Arr;
	}
}