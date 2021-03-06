#include "Header.h"

int main()
{
	srand(time(nullptr));
	int n = 0;
	printf("Input size of array : ");
	scanf("%i", &n);
	int k = 0;
	printf("Input how many we will look for in array\n");
	scanf("%i", &k);
	int* array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand()  * rand();
	}
	printf("Array is\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ",array[i]);
	}
	int* numbersWeLookForInArray = new int[k];
	for (int i = 0; i < k; ++i)
	{
		numbersWeLookForInArray[i] = rand() * rand();
	}
	printf("\nElements is\n");
	for (int i = 0; i < k; ++i)
	{
		printf("%i ", numbersWeLookForInArray[i]);
	}
	printf("\n");
	quickSort(n, array);
	for (int i = 0; i < k; ++i)
	{
		if (binarySearch(numbersWeLookForInArray[i], n, array))
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
	}

	delete[] array;
	delete[] numbersWeLookForInArray;
	return 0;
}