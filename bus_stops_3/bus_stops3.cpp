#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    map<set<string>, int> buses;

    for (int i = 0; i < Q; ++i)
    {
        int number;
        string stop;
        set<string> stops;
        int bus_number = 1;
        cin >> number;

        for (int j = 0; j < number; ++j)
        {
            cin >> stop;
            stops.insert(stop);
        }

        if (buses.count(stops) == 0)
        {
            bus_number += buses.size();
            buses[stops] = bus_number;
            cout << "New bus " << bus_number << endl;
        }
        else
        {
            cout << "Already exists for " << buses[stops] << endl;
        }
    }
    return 0;
}