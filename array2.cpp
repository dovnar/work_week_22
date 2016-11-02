#include <iostream>
#include <stdlib.h>
#include <time.h>


void main()
{
	int size = 10;
	int** arr = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		arr[i] = (int*)malloc(size * sizeof(int));
	}
	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 1000 + 1;
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
