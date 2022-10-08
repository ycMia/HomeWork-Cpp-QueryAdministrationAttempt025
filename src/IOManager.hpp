#pragma once
#include<string>
#include<filesystem>
#include<fstream>
#include<conio.h>

#include<cassert>

#include"ObjectTree.hpp"

using namespace std::filesystem;
using namespace std;



namespace IOManagerTools
{
	bool TryCreatePath(path path)
	{
		try
		{
			//cout << "called"<<endl;
			return create_directories(path);
		}
		catch (filesystem_error e) 
		{
			cout << e.what();
			return false;
		}
	}

	//Try create path Recursively
	void TryCreatePathRec(path path)
	{
		try
		{
			if(!exists(path))
			{	
				TryCreatePathRec(path.parent_path());
			}
			TryCreatePath(path);
		}
		catch (filesystem_error e) { cout << e.what() << endl; }
		return;
	}
}



class IOManager
{
public:
	IOManager(const path operationPath)
	{
		this->operationPath = operationPath;
		IOManagerTools::TryCreatePathRec(operationPath);
	}

	void Serialize(MyTree::ObjectNode node)
	{
		string pForehead = MyTree::GetHeavyMedalHead(node.GetID());
		path p = operationPath.append(pForehead);
		cout << p << endl;
		IOManagerTools::TryCreatePath(p);
		ofstream ofs;
		ofs.open(p.append(MyTree::DHeavyMedalHead(node.GetID())),
			ios::out | ios::trunc | ios::binary);
		ofs << node.DumpData();
		ofs.close();
	}

	MyTree::ObjectNode DeSerialize(MyTree::ObjectNode node)
	{
		return DeSerialize(node.GetID());
	}

	MyTree::ObjectNode DeSerialize(string _hashID)
	{
		MyTree::ObjectNode resNode(_hashID);
		ifstream ifs;
		path filePath = operationPath / MyTree::GetHeavyMedalHead(_hashID) / MyTree::DHeavyMedalHead(_hashID);
		ifs.open(filePath,ios::in | ios::binary);
			ifs.seekg(0, ios::end);
			int bLength = (int)ifs.tellg();
			ifs.seekg(0, ios::beg);
			char* buffer = new char[bLength];
			ifs.read(buffer, bLength + 1);
			buffer[bLength] = '\0';
			string fileContent(buffer);
		resNode.OverWriteData(fileContent);
		ifs.close();
		return resNode;
	}
	
	/*ofstream StartWritingFile(path filePath)
	{
		return 
	}*/

private:
	IOManager * _Instance;
	path operationPath;
};
