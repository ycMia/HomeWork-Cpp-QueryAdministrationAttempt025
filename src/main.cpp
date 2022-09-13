#include<iostream>
#include<string>

#include"IOManager.hpp"

#include"ObjectTree.hpp"


int main(int argc, char* argv[])
{
	std::filesystem::path path("C:\\ProgramData\\ConsoleApplicationsYCMIA\\20220913\\");
	IOManager iom(path);


	return 0;
}
