
#include "GradesData.hpp"
#include "UserData.hpp"

class CPGA
{
	GradesData gradeData_;
	UserData usersData_;
public:
	void createNewUser(const std::string& username)
	{
		usersData_.addNewUser(username);
	}
	void removeUser(const std::string& username)
	{
		usersData_.removeUser(username);
	}
	void addGradeToUser(const std::string& username, char sign, GradeType type)
	{
		usersData_.addGradeToUser(username, sign, type, gradeData_.getGradesData());
	}
	void createGradeWithPoints(char sign, float point)
	{
		gradeData_.addNewGradeAndPoints(sign, point);
	}


	//Prints data
	void printAllUsers() {}
	void printUserData(const std::string& name) {}
	void printGradesList(){}
};