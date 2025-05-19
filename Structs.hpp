#pragma once
#include <string>
#include <map>

enum class GradeType
{
	PLUS,
	NORMAL,
	MINUS
};

struct Grade
{
	std::string subject;
	char sing;
	GradeType type;
	float points;

	void createPoints(std::map<char, float>& data)
	{
		auto s = data.find(sing);
		if (s == data.end())
		{
			std::cout << "Cant't find data...\n";
			return;
		}

		float sum = s->second;
		switch (type)
		{
		case GradeType::PLUS: { sum += 0.5; break; }
		case GradeType::NORMAL: { break; }
		case GradeType::MINUS: { sum -= 0.5; break; }
		}
		points = sum;
		std::cout << "Create points: " << points << "\n";
	}
};
