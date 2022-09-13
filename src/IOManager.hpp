#pragma once
#include<string>
#include<filesystem>
#include<fstream>

using namespace std::filesystem;

class IOManager
{
public:
	IOManager(const std::filesystem::path operationPath)
	{
		this->operationPath = operationPath;

		if (!exists(operationPath))
		{
			try
			{
				create_directories(operationPath);
				std::cout << "Created operation path." << std::endl;
			}
			catch (filesystem_error e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
			std::cout << "Path exists." << std::endl;
			
	}

	/*ofstream StartWritingFile(path filePath)
	{
		return 
	}*/

private:
	path operationPath;
};
