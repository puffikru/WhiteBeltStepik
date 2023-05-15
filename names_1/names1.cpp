#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        last_names[year] = last_name;
    }
    string GetFullName(int year)
    {
        string first_name;
        string last_name;
        string full_name;

        for (const auto& [years, names] : first_names)
        {
            if (years <= year)
            {
                first_name = names;
            }
        }
        for (const auto& [years, names] : last_names)
        {
            if (years <= year)
            {
                last_name = names;
            }
        }

        if (first_name.size() == 0 && last_name.size() == 0)
        {
            full_name = "Incognito";
        }
        else if (first_name.size() == 0 && last_name.size() > 0)
        {
            full_name =  last_name + " with unknown first name";
        }
        else if (first_name.size() > 0 && last_name.size() == 0)
        {
            full_name =  first_name + " with unknown last name";
        }
        else
        {
            full_name =  first_name + " " + last_name;
        }
    
        return full_name;
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}