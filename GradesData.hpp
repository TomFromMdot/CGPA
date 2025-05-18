#pragma once

#include <map>

#include "Structs.hpp"



class GradesData
{
	std::map<char, float> data;
public:
	void addNewGradeAndPoints(const char sing, float points)
	{
		data.insert({sing, points});
	}
};