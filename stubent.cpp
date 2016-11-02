#include <iostream>


struct Student
{
	int Year;
	char Group[11];
	char Name[256];
};

int main()
{
	Student student;
	char* filePath = "student.bin";
	FILE* file = fopen(filePath, "rb+"); 
	if (file == nullptr)
	{
		std::cout << "can't open file: " << filePath << std::endl;
		file = fopen(filePath, "wb+");
		std::cout << "enter Year: ";
		std::cin >> student.Year;
		std::cout << "enter group: ";
		std::cin.getline(student.Group, 11);
		std::cout << "enter name: ";
		std::cin.getline(student.Name, 256);
		fwrite();
		fflush(file);
	}
	else
	{
		fread((int*)student.Year, 4, 1, file);
		std::cout << "Year: " << student.Year << std::endl;
		fread(student.Group, 11, 1, file);
		std::cout << "Group: " << student.Group << std::endl;
		fread(student.Name, 256, 1, file);
		std::cout << "Name: " << student.Name << std::endl;
	}
	fclose(file);
}
