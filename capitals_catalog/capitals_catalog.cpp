#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    int Q;
    cin >> Q;

    map<string, string> catalog;

    for (int i = 0; i < Q; ++i)
    {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL")
        {
            string country, new_capital;
            cin >> country >> new_capital;

            if (catalog.count(country) > 0 && catalog.at(country) == new_capital)
            {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else if (catalog.count(country) > 0 && catalog.at(country) != new_capital)
            {
                cout << "Country " << country << " has changed its capital from " << catalog[country] << " to " << new_capital << endl;
            }
            else if (catalog.count(country) == 0)
            {
                cout << "Introduce new country " << country <<  " with capital " << new_capital << endl;
            }
            catalog[country] = new_capital;
        }
        else if (command == "RENAME")
        {
            string old_country, new_country;
            cin >> old_country >> new_country;

            if (catalog.count(old_country) == 0 || catalog.count(new_country) > 0 || old_country == new_country)
            {
                cout << "Incorrect rename, skip" << endl;
            }
            else
            {
                cout << "Country " << old_country << " with capital " << catalog[old_country] << " has been renamed to " << new_country << endl;
                catalog[new_country] = catalog[old_country];
                catalog.erase(old_country);
            }
        }
        else if (command == "ABOUT")
        {
            string country;
            cin >> country;

            if (catalog.count(country) == 0)
            {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else
            {
                cout << "Country " << country << " has capital " << catalog[country] << endl;
            }
        }
        else if (command == "DUMP")
        {
            if (catalog.size() == 0)
            {
                cout << "There are no countries in the world" << endl;
            }
            else
            {
                for (const auto& [country, capital] : catalog)
                {
                    cout << country << "/" << capital << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}