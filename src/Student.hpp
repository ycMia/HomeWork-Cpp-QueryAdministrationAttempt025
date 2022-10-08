#pragma once
#include"ScoreStruct.hpp"
#include<string>
struct Student
{
	int studentHashCode;
	std::string studentName;
	std::string studentGender;
	int studentGrade;
	std::string studentMajor;
	ScoreStruct scores[];
};
