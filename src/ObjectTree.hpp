#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<filesystem>

using namespace std;

namespace MyTree
{
#define MAX_UNDEFINED_HASH_LENGTH 32
	class ObjectNode
	{
	public:
		ObjectNode(string strSet)
		{
			_hashID = strSet;
		}

		//The deafult construct function initiates out the _hashID
		ObjectNode()
		{
			stringstream ss;
			
			srand((unsigned int)time(0));
			for (int i = 0; i < MAX_UNDEFINED_HASH_LENGTH; i++)
			{
				int t = rand() % 16;
				ss.put((t < 10) ? (char)t + '0' : (char)t + 'a' - 10);
			}
			_hashID = ss.str();
		}
		~ObjectNode()
		{

		}
		void GetTree(std::string hash)
		{

		}
		std::string GetID()
		{
			return _hashID;
		}

		void PlaceTo(std::filesystem::path path)
		{

		}
	private:
		ObjectNode* next = NULL;
		std::string _hashID;
	};
#undef MAX_UNDEFINED_HASH_LENGTH
}


