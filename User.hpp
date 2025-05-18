#pragma once


#include <vector>

#include "Structs.hpp"

class User 
{
	std::vector<Grade*> gradeLists_;
	std::string username_;
public:
	User(const std::string& username) : username_(username) {}

	void setName(const std::string& username) {}
	const std::string getName()
	{
		return username_;
	}

	const std::vector<Grade*> getGradesList() const 
	{
		return gradeLists_;
	}

	float getPointsSum()
	{
		if (gradeLists_.size() == 0)
			return 0;
		float result = 0;
		for (auto& pt : gradeLists_)
		{
			result += pt->points;
		}
		return result;
	}



};