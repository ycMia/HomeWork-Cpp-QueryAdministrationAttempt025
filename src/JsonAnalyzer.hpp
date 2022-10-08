#pragma once

#include<iostream>
#include<string>

#include"Student.hpp"

class JsonAnalyzer
{
public:
	JsonAnalyzer()
	{
		if (Instance == NULL)
			Instance = this;
	}
	static JsonAnalyzer * Instance;
private:
	std::string readyToProcess;

	class Reader
	{

	};
	class Writer
	{

	};
};
