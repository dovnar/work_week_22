#include <iostream>
#include <stdlib.h>
#include <time.h>


void main()
{
	int size = 20;
	int* arr = (int*)calloc(size, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000 + 1;
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl << "adress: " << arr << std::endl << "new array: " << std::endl;
	int newSize = size * 2;
	arr = (int*)realloc(arr, newSize * sizeof(int));
	for (int i = size; i < newSize; i++)
	{
		arr[i] = rand() % 1000 + 1;
	}
	for (int i = 0; i < newSize; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl << "new adress: " << arr << std::endl;
	free(arr);
}
