#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<filesystem>
#include<fstream>

using namespace std;

#define MAX_UNDEFINED_HASH_LENGTH 32
namespace MyTree
{
	//Led your Acrobystia off
	string DHeavyMedalHead(string);
	string GetHeavyMedalHead(string);
	string GenerateHash(int);

	class ObjectNode
	{
	public:
		//The deafult construct function initiates out the _hashID
		ObjectNode(void);
		ObjectNode(string strSet);
		void GetNode(std::string hash);
		std::string GetID();
		void PlaceTo(std::filesystem::path path);
		string DumpData();
		string _data;
		void OverWriteData(string);
		ObjectNode operator= (ObjectNode other)
		{
			_data = other._data;
			_hashID = other._hashID;
			return *this;
		}
	private:
		ObjectNode* next = NULL;
		std::string _hashID;
	};

}
#undef MAX_UNDEFINED_HASH_LENGTH


