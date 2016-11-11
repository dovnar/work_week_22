#include <locale.h>
#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Экзамен по дисциплине:\tПрограммирование на языке С" << std::endl
		<< "Студент академии:\tДовнар М. П." << std::endl
		<< "Назначение программы:\tвывод содержимого папки" << std::endl << std::endl
		<< "Введите папку для показа содержимого: ";
	

	char*  folderPath = new char[256];
	std::cin.getline(folderPath, 255);
	if (folderPath[strlen(folderPath)-1]!= '*' &&
		folderPath[strlen(folderPath) - 2] != '\\')
	{
		if (folderPath[strlen(folderPath) - 2] != '\\' && 
			folderPath[strlen(folderPath) - 1] != '\\')
		{
			if (folderPath[strlen(folderPath) - 1] != '\\')
			{
				strcat(folderPath, "\\*\0");
			}
		}
		else
		{
			strcat(folderPath, "*\0");
		}
	}
	

	WIN32_FIND_DATAA findData;
	HANDLE findHandle = FindFirstFileA(folderPath, &findData);

	if (findHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "No files Found.";
		return 1;
	}

	int emptyFolder = 0;
	while (FindNextFileA(findHandle, &findData))
	{
		if (!strcmp(findData.cFileName, ".") ||
			!strcmp(findData.cFileName, ".."))
		{
			continue;
		}
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			std::cout << "[D] ";
		}
		else
		{
			std::cout << "[F] ";
		}
		std::cout << findData.cFileName << "\t";
		if (strlen(findData.cFileName) < 5)
		{
			std::cout << "\t";
			
		}
		if (strlen(findData.cFileName) < 12)
		{
			std::cout << "\t";
			
		}
		if (strlen(findData.cFileName) < 18)
		{
			std::cout << "\t";

		}
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << findData.nFileSizeLow << "\t" << "bytes" << std::endl;
		}
		emptyFolder++;
	}
	if (emptyFolder < 1)
	{
		std::cout << "empty folder!";
	}

	bool closeResult = FindClose(findHandle);
	if (!closeResult)
	{
		std::cout << "Can't close file search handle.";
		return 2;
	}

}
