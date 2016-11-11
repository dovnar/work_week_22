#include <locale.h>
#include <iostream>
#include <windows.h>

bool IsDirectory(WIN32_FIND_DATAA const& findData)
{
	return findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Экзамен по дисциплине:\tПрограммирование на языке С" << std::endl
		<< "Студент академии:\tДовнар М. П." << std::endl
		<< "Назначение программы:\tвывод содержимого папки" << std::endl << std::endl
		<< "Введите папку для показа содержимого: ";
	

	char*  folderPath = new char[256];
	std::cin.getline(folderPath, 255);
	WIN32_FIND_DATAA findData;
	HANDLE findHandle = FindFirstFileA("C:\\*", &findData);

	if (findHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "No files Found.";
		return 1;
	}

	if (!strcmp(findData.cFileName, ".") &
		!strcmp(findData.cFileName, ".."))
	{
		std::cout << findData.cFileName << std::endl;
	}

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
		std::cout << findData.cFileName << " " << findData.nFileSizeLow << std::endl;
	}

	bool closeResult = FindClose(findHandle);
	if (!closeResult)
	{
		std::cout << "Can't close file search handle.";
		return 2;
	}

}
