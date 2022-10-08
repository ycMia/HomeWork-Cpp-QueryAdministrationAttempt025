#include<iostream>
#include<string>

#include"ObjectTree.cpp"
#include"IOManager.hpp"

int main(int argc, char* argv[])
{
	std::filesystem::path path("C:\\ProgramData\\ConsoleApplicationsYCMIA\\20221004");
	IOManager iom(path);

	MyTree::ObjectNode node1("e38a5516be4041c8a50aae8e0c1a522b");
	node1 = iom.DeSerialize(node1);

	cout << node1._data << endl;

	cout << endl;
	return 0;
}
