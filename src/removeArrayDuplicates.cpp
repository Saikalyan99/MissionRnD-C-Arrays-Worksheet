/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		int index1, index2, index3;
		for (index1 = 0; index1 < len; index1++)
		{
			index2 = index1 + 1;
			while (index2 != len)
			{
				if (Arr[index2] == Arr[index1])
				{
					for (index3 = index2; index3 < len; index3++)
						Arr[index3] = Arr[index3 + 1];
					len--;
				}
				else
					index2++;
			}
		}
	}
}