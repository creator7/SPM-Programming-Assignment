#include "BubbleSort.h"
#include<iostream>

void BubbleSort::sort(int* num, int numLength)
{
	int i, j;
	int temp;

	for (i = 1; (i <= numLength); i++)
	{
		for (j = 0; j < ((numLength) - i); j++)
		{
			if (num[j + 1] < num[j])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}