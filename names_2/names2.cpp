#include <iostream>
#include <map>
#include <string>
#include <vector>

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

    string GetFullNameWithHistory(int year)
    {
        string first_name = GetName(first_names, year);
        string last_name = GetName(last_names, year);
        string first_name_hist = BuildHistory(first_names, year);
        string last_name_hist = BuildHistory(last_names, year);
        string full_name;

        if (first_name.size() == 0 && last_name.size() == 0)
        {
            full_name = "Incognito";
        }
        else if (first_name.size() == 0 && last_name.size() > 0)
        {
            full_name = last_name_hist.size() > 0 ? last_name + last_name_hist + " with unknown first name" : last_name + " with unknown first name";
        }
        else if (first_name.size() > 0 && last_name.size() == 0)
        {
            full_name = first_name_hist.size() > 0 ? first_name + first_name_hist + " with unknown last name" : first_name + " with unknown last name";
        }
        else
        {
            first_name = first_name_hist.size() > 0 ? first_name + first_name_hist : first_name;
            last_name = last_name_hist.size() > 0 ? last_name + last_name_hist : last_name;
            full_name = first_name + " " + last_name;
        }
    
        return full_name;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;

    string GetName(const map<int, string> names, int year)
    {
        string result;
        for (const auto& [years, name] : names)
        {
            if (years <= year)
            {
                result = name;
            }
        }
        return result;
    }

    string BuildHistory(const map<int, string> names, int year)
    {
        vector<string> history;
        string current_name = "";
        for (const auto& [years, name] : names)
        {
            if (years <= year && name != current_name)
            {
                history.push_back(name);
                current_name = name;
            }
        }

        string result;
        int hist_size = history.size();
        if (hist_size - 1 > 0)
        {
            result += " (";
            for (int i = history.size() - 2; i >= 0; --i)
            {
                result += history[i];
                if (i > 0) result += ", ";
            }
            result += ")";
        }
        return result;
    }
};

// int main()
// {
//     Person person;
  
//     person.ChangeFirstName(1965, "Polina");
//     person.ChangeLastName(1967, "Sergeeva");
//     for (int year : {1900, 1965, 1990}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }
    
//     person.ChangeFirstName(1970, "Appolinaria");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }
    
//     person.ChangeLastName(1968, "Volkova");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }
    
//     person.ChangeFirstName(1990, "Polina");
//     person.ChangeLastName(1990, "Volkova-Sergeeva");
//     cout << person.GetFullNameWithHistory(1990) << endl;
    
//     person.ChangeFirstName(1966, "Pauline");
//     cout << person.GetFullNameWithHistory(1966) << endl;
    
//     person.ChangeLastName(1960, "Sergeeva");
//     for (int year : {1960, 1967}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }
    
//     person.ChangeLastName(1961, "Ivanova");
//     cout << person.GetFullNameWithHistory(1967) << endl;

// //     Person person;

// //   person.ChangeFirstName(1900, "Eugene");
// //   person.ChangeLastName(1900, "Sokolov");
// //   person.ChangeLastName(1910, "Sokolov");
// //   person.ChangeFirstName(1920, "Evgeny");
// //   person.ChangeLastName(1930, "Sokolov");
// //   cout << person.GetFullNameWithHistory(1940) << endl;
    
//     return 0;
// }