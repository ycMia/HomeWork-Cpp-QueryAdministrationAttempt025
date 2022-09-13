#include<iostream>
#include<string>

#include"ObjectTree.hpp"

using namespace std;
using namespace MyTree;

int main(int argc, char* argv[])
{
	ObjectNode* node1 = new ObjectNode();
	cout << node1->GetID() << endl;

	return 0;
}
