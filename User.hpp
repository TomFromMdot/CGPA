#pragma once


#include <vector>

#include "Structs.hpp"

class User 
{
	std::vector<Grade*> gradeLists_;
	std::string username_;
public:
	User(const std::string& username) : username_(username) {}
	~User()
	{
		clearGrade();
	}
	void setName(const std::string& username) {}
	const std::string getName()
	{
		return username_;
	}

	const std::vector<Grade*> getGradesList() const 
	{
		return gradeLists_;
	}

	void addGradeWithPoint(const std::string& subjectName, char gradeChar, GradeType type, std::map<char, float> data)
	{
		Grade* gr = new Grade;
		gr->subject = subjectName;
		gr->sing = gradeChar;
		gr->type = type;
		gr->createPoints(data);
		gradeLists_.push_back(gr);
	}

	float getPointsSum()
	{
		if (gradeLists_.size() == 0)
		{
			std::cout << "No grades..\n";
			return 0;
		}
		float result = 0;
		for (auto& pt : gradeLists_)
		{
			result += pt->points;
		}
		return result;
	}

private:

	void clearGrade()
	{
		if (gradeLists_.size() == 0)
			return;
		std::cout << "Clearing grade lists..\n";
		for (auto gr : gradeLists_)
		{
			delete gr;
		}

		gradeLists_.clear();

	}

};