// CGPA.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <vector>
#include <optional>

#include "CPGA.hpp"

/*




struct Grade
{
    std::string gradeSing;
    float points;
    Grade(const std::string sign, float pt) : gradeSing(sign), points(pt)
    {
        std::cout << "Create grade with sign: " << sign << " and points: " << pt << "\n";
    }
};

struct GradeData
{
    std::map<std::string, Grade> gradeWithValue;
};

class Subject
{
    std::map<std::string, Grade>* data_;
    std::string name_;
    Grade grade_;
    void createPoints() 
    {
        auto points = data_->find(grade_.gradeSing);
        if (points == data_->end())
        {
            std::cout << "Signature of this grade not exist in data..\n";
            return;
        }
        grade_.gradeSing = points->first;
        grade_.points = points->second.points;

    }

public:
    ~Subject() {}
    Subject(std::string name, Grade grade, std::map<std::string, Grade>* gradeData) : name_(name), grade_(grade), data_(gradeData)
    {

        //Later i need to think about exceptions with one arg (gradeData) if will be nullptr
        createPoints();
        std::cout << "Create new subject with name: " << name_ << "\n Grade: " << grade_.gradeSing << "\n Points: " << grade_.points << "\n";

    }

    float getPoints() const
    {
        std::cout << "Get points" << (float)grade_.points;
        return grade_.points;
    }

    void printSubject() const
    {
        std::cout
            << "--------------------------------\n\n"
            << "Subject name: " << name_ << "\n"
            << "Grade: " << grade_.gradeSing << "\n"
            << "Points: " << grade_.points << "\n";
    }

};

class User
{
    std::vector<std::unique_ptr<Subject>> subjectList;
    std::string username_;
public:
    User(const std::string& username) : username_(username)
    {

    }
    const std::string getName() { return username_; }
    void setUsername(const std::string& username)
    {
        username_ = username;
    }
    const std::vector<std::unique_ptr<Subject>> getSubjectList()
    {
        return subjectList;
    }
    void addSubject(std::unique_ptr<Subject> sub)
    {
        std::cout << "Add subject\n";
        subjectList.push_back(std::move(sub));
    }

    float getPointsSum()
    {
        float result = 0;
        std::cout << "Subject number: " << subjectList.size() << "\n";
        for (int i = 0; i < subjectList.size(); i++)
        {
            result += subjectList[i]->getPoints();
        }
        return result;
    }
};

class UsersData
{
    std::vector<std::shared_ptr<User>> usersList;
public:
    UsersData(){}
    ~UsersData(){}
    void addUser(std::unique_ptr<User> user)
    {
        usersList.push_back(std::shared_ptr<User>(std::move(user)));
    }
    void removeUserFromListByName(const std::string username)
    {
        for (int i = 0; i < usersList.size(); ++i)
        {
            if (usersList[i]->getName() == username)
            {
                usersList.erase(usersList.begin() + i);
            }
        }
    }
    size_t getUsersCount()
    {
        return usersList.size();
    }

    const std::vector<std::shared_ptr<User>> getUsersList() const
    {
        return usersList;
    }

    /*
    * @bref This method can be use to find user in array.
    * @params std::string username
    * 
    * @return If find user then return week_ptr User else return nullopt.
    
    std::optional<std::weak_ptr<User>> getUser(const std::string& username)
    {
        for (auto& user : usersList)
        {
            if (user->getName() == username)
            {
                auto result = std::make_optional<std::weak_ptr<User>>(user);
                return result;
            }
        }
        return std::nullopt;
    }

    void printUsers()
    {
        if(usersList.size() == 0)
        {
            std::cout << "No users...\n";
            return;
        }
        for (auto& u : usersList)
        {
            std::cout << "User: " << u->getName() << "\n";
        }
    }
};


/*
* @bref CGPA is facade patter for clear code.
* 
* 
* 
* CPGA can only show data by print to console but can modyfi real data
* 
* 

class CGPAOld
{
    UsersData usersData_;
    GradeData gradeData_;


    User* findUser(const std::string& username)
    {
        auto usr = usersData_.getUser(username);
        if (!usr.has_value())
        {
            std::cout << "Can't find user with this name: " << username << "\n";
            return nullptr;
        }
        if (auto sp = usr->lock())
        {
            return sp.get();
        }
        return nullptr;
    }
public:
    /*
    * @bref Create new user by name
    
    void addGradeWithValue(const std::string& grade, float points)
    {
        Grade grd(grade, points);

        gradeData_.gradeWithValue.insert({grade, grd});
    }
    void createNewUser(const std::string& username) 
    {
        // Create temporary pointer
        auto usr = std::make_unique<User>(username);
        // Move to storage
        usersData_.addUser(std::move(usr));
    }
    void addSubjectWithGradeToUser(const std::string& username, const std::string& subjectName, const std::string& grade) 
    {
        auto usr = usersData_.getUser(username);
        if (!usr.has_value())
        {
            std::cout << "Can't find user with name: " << username << "\n";
            return;
        }
        if(auto sp = usr->lock())
        {
            auto gr = gradeData_.gradeWithValue.find(grade);
            if (gr == gradeData_.gradeWithValue.end())
            {
                std::cout << "Sorry but can't find this sing in data of grades lists..\n";
                return;
            }
            Grade x = gr->second;
            auto subj = std::make_unique<Subject>(subjectName, gr->second, &gradeData_.gradeWithValue);
            sp->addSubject(std::move(subj));

        }


    }
    void printUsersData()
    {
        usersData_.printUsers();
    }
    void getUserInformationAll(const std::string& username)
    {
        auto usr = findUser(username);
        std::cout << usr->getPointsSum();

    }
    void getUserInformationPoints(const std::string& username)
    {
        
    }
    std::vector<std::string> getUserInfromationGradeList(const std::string& username){}

};
 
*/

void createGrades(CPGA& cpga)
{
    cpga.createGradeWithPoints('A', 10.0);
    cpga.createGradeWithPoints('B', 8.0);
    cpga.createGradeWithPoints('C', 6.0);
    cpga.createGradeWithPoints('D', 4.0);
    cpga.createGradeWithPoints('E', 2.0);
    cpga.createGradeWithPoints('F', 1.0);

}
void createTestUser(const std::string& username, CPGA cpga)
{
    cpga.createNewUser(username);
}

void addToTestUserGrades()
{

}


int main()
{
    CPGA cpga;
    createGrades(cpga);
    cpga.createNewUser("Tomek");
    cpga.createNewUser("Bartek");
    cpga.createNewUser("Romek");
    cpga.createNewUser("Andrzej");



    cpga.addGradeToUser("Tomek","Matematyka", 'A', GradeType::MINUS);
    cpga.addGradeToUser("Tomek","Biologia", 'B', GradeType::MINUS);
    cpga.addGradeToUser("Tomek","Chemia", 'C', GradeType::MINUS);
    cpga.addGradeToUser("Tomek","WF", 'D', GradeType::MINUS);

    cpga.addGradeToUser("Bartek", "Matematyka", 'B', GradeType::MINUS);
    cpga.addGradeToUser("Bartek", "WF", 'C', GradeType::NORMAL);
    cpga.addGradeToUser("Bartek", "Chemia", 'D', GradeType::PLUS);

    cpga.printAllUsers();
    cpga.printUserData("Tomek");
    return 0;
}