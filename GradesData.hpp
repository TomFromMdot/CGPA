#pragma once

#include <map>

#include "Structs.hpp"



class GradesData
{
	std::map<char, float> data_;
public:
	void addNewGradeAndPoints(const char sing, float points)
	{
		data_.insert({sing, points});
	}

	void setGradePointsData(std::map<char, float> data)
	{
		data_ = std::move(data);
	}
	std::map<char, float>& getGradesData()
	{
		return data_;
	}
};