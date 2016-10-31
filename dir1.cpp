#include <iostream>
#include <windows.h>

bool IsDirectory(WIN32_FIND_DATAA const& findData)
{
	return findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
}

int main()
{
	WIN32_FIND_DATAA findData;
	HANDLE findHandle = FindFirstFileA("C:\\Dovnar\\ConsoleApplication38\\*", &findData);
	
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
			std::cout << "[DIR] ";
		}
		std::cout << findData.cFileName << std::endl;
	}

	bool closeResult = FindClose(findHandle);
	if (!closeResult)
	{
		std::cout << "Can't close file search handle.";
		return 2;
	}

}
