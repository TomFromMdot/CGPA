// CGPA.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <map>
#include <vector>
#include <optional>

enum class GradeType 
{
    MINUS,
    NORMAL,
    PLUS
};

struct Grade
{
    char gradeSignature_;
    GradeType type;

};

class Subject
{
    std::string name_;
    std::map<std::string, Grade*>* gradesList_;


public:
    Subject(std::map<std::string, Grade*>& gList) : gradesList_(&gList){  }
};

class User
{
    std::vector<Subject*> subjectList;
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
    const std::vector<Subject*>& getSubjectList()
    {
        return subjectList;
    }
    void addSubject(Subject* sub)
    {
        subjectList.push_back(sub);
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
    */

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



class CGPA
{
    UsersData usersData_;
    User*findUser(const std::string& username)
    {
       
    }
public:
    void createNewUser(const std::string& username) {}
    void addSubjectWithGradeToUser(const std::string& username, const std::string& subjectName, const std::string& grade) {}
    void printUsersData(){}
    void getUserInformationAll(const std::string& username){}
    float getUserInformationPoints(const std::string& username){}
    std::vector<std::string> getUserInfromationGradeList(const std::string& username){}

};



int main()
{
    //Initializacja Systemu CGPA
    //Utworzenie użytkowników
    //Dodanie ich do listy użytkwoników

    //Przypisanie przypisanie ocen do użytkowników
    //Pobranie liczby CPGA od użytkownika


    UsersData uData;
    
    std::unique_ptr<User> usr = std::make_unique<User>("Tomek");

    uData.addUser(std::move(usr));


    uData.printUsers();

    uData.removeUserFromListByName("Tomek");

    uData.printUsers();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
