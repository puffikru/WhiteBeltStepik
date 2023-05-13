#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    map<vector<string>, int> buses;

    for (int i = 0; i < Q; ++i)
    {
        int count;
        int bus_number = 1;
        string stop;
        vector<string> stops;
        cin >> count;
        for (int j = 0; j < count; ++j)
        {
            cin >> stop;
            stops.push_back(stop);
        }
        if (buses.count(stops) != 0)
        {
            cout << "Already exists for " << buses[stops] << endl;
        }
        else
        {
            bus_number += buses.size();
            buses[stops] = bus_number;
            cout << "New bus " << bus_number << endl;
        }
    }
    return 0;
}