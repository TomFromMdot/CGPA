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

	void addGradeWithPoint(char gradeChar, GradeType type, std::map<char, float> data)
	{
		Grade gr;
		gr.sing = gradeChar;
		gr.type = type;
		gr.createPoints(data);
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