/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		int index1 = 0, index2 = len - 1, temp;
		while (index1 != len)
		{
			if (Arr[index1] > Arr[index1 + 1])
				break;
			index1++;
		}
		while (index2 != 0)
		{
			if (Arr[index2 - 1] > Arr[index2])
				break;
			index2--;
		}
		temp = Arr[index1];
		Arr[index1] = Arr[index2];
		Arr[index2] = temp;
	}
}