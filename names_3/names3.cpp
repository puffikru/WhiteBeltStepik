#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(const string& first_name, const string& last_name, int year)
    {
        first_names[year] = first_name;
        last_names[year] = last_name;
        birth_year = year;
    }

    void ChangeFirstName(int year, const string& first_name)
    {
        if (year >= birth_year)
        {
            first_names[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name)
    {
        if (year >= birth_year)
        {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const
    {
        string first_name;
        string last_name;
        string full_name;

        if (year < birth_year)
        {
            return "No person";
        }

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

    string GetFullNameWithHistory(int year) const
    {
        string first_name = GetName(first_names, year);
        string last_name = GetName(last_names, year);
        string first_name_hist = BuildHistory(first_names, year);
        string last_name_hist = BuildHistory(last_names, year);
        string full_name;

        if (year < birth_year)
        {
            return "No person";
        }

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
    int birth_year = 0;

    string GetName(const map<int, string> names, int year) const
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

    string BuildHistory(const map<int, string> names, int year) const
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
//     Person person("Polina", "Sergeeva", 1960);
//     for (int year : {1959, 1960}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }
    
//     person.ChangeFirstName(1965, "Appolinaria");
//     person.ChangeLastName(1967, "Ivanova");
//     for (int year : {1965, 1967}) {
//         cout << person.GetFullNameWithHistory(year) << endl;
//     }

//     return 0;
// }