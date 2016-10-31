#include <iostream>
#include <windows.h>

bool IsDirectory(WIN32_FIND_DATAA const& findData)
{
	return findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
}

int testDirectory(HANDLE& findHandle, WIN32_FIND_DATAA& findData, char* Directory)
{
	findHandle = FindFirstFileA(Directory, &findData);
	if (findHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "No files Found. enter:";
		return 1;
	}
	return 0;
}

char* pathAppehd(char* Directory)
{

}

bool derictiryInFile(HANDLE findHandle, WIN32_FIND_DATAA findData, char*** allFile)
{
	int i = 0;
	int j = 0;
	while (FindNextFileA(findHandle, &findData))
	{
		allFile[j][i] = ; 
		if (IsDirectory(findData))
		{
			std::cout << "[DIR] ";

		}
		std::cout << findData.cFileName << std::endl;
	}
}

int main()
{
	char*** allFile = new char**[3];
	for (int i = 0; i < 100; i++)
	{
		*allFile = new char*[100];
	}
	for (int i = 0; i < 100; i++)
	{
		**allFile = new char[50];
	}
	char* Directory = new char[256];
	WIN32_FIND_DATAA findData;
	HANDLE findHandle;
	
	do
	{
		std::cout << "enter folder address: ";
		std::cin.getline(Directory, 256);
	} while (testDirectory(findHandle, findData, Directory) != 0);
	
	derictiryInFile(findHandle, findData, allFile);
	

	bool closeResult = FindClose(findHandle);
	if (!closeResult)
	{
		std::cout << "Can't close file search handle.";
		return 2;
	}

}
//C:\\Dovnar\\ConsoleApplication38\\*
//C:\Dovnar\ConsoleApplication38\*
