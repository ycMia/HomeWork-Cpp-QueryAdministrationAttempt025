#include "ObjectTree.hpp"

#define MAX_UNDEFINED_HASH_LENGTH 32
inline MyTree::ObjectNode::ObjectNode(string strSet)
{
	_hashID = strSet;
}
//The deafult construct function initiates out the _hashID
inline MyTree::ObjectNode::ObjectNode(void)
{
	_hashID = GenerateHash(MAX_UNDEFINED_HASH_LENGTH);
}

inline void MyTree::ObjectNode::GetNode(std::string hash)
{

}

inline std::string MyTree::ObjectNode::GetID()
{
	return _hashID;
}

inline void MyTree::ObjectNode::PlaceTo(std::filesystem::path path)
{

}

inline string MyTree::ObjectNode::DumpData()
{
	_data = "balabala";
	return _data;
}
inline void MyTree::ObjectNode::OverWriteData(string)
{

}
#undef MAX_UNDEFINED_HASH_LENGTH

//Reject the front 2 tit of string
inline string MyTree::DHeavyMedalHead(string hash)
{
	const char* p = &hash.c_str()[2];
	return string(p);
}

inline string MyTree::GetHeavyMedalHead(string hash)
{
	string res;
	res.append(&hash.c_str()[0], 2);
	return res;
}

inline string MyTree::GenerateHash(int length = 32)
{
	stringstream ss;
	srand((unsigned int)time(0));
	for (int i = 0; i < length ; i++)
	{
		int t = rand() % 16;
		ss.put((t < 10) ? (char)t + '0' : (char)t + 'a' - 10);
	}
	return ss.str();
}

