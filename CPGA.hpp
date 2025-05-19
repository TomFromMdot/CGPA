
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
	void printAllUsers() 
	{
		const auto users = usersData_.getAllUsers();
		if (users.size() == 0)
		{
			std::cout << "No users...\n";
			return;
		}


		for (auto& user : users)
		{
			std::cout << "Name: " << user->getName() << "\n";
			std::cout << "Grade points: " << user->getPointsSum() << "\n";
		}
	}
	void printUserData(const std::string& name) 
	{
		auto user = usersData_.getUserByName(name);
		if (user.has_value()) 
		{
			std::cout << "Name: " << user.value()->getName();
			std::cout << "Name: " << user.value()->getPointsSum();
		}
	}
	void printGradesList(){}
};