#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    for (int i = 0; i < Q; ++i)
    {
        string command;
        cin >> command;

        if (command == "NEW_BUS")
        {
            string bus, stop;
            int stop_count;
            cin >> bus >> stop_count;

            for (int j = 0; j < stop_count; ++j)
            {
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }
        }
        else if (command == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;

            if (stops.count(stop) == 0)
            {
                cout << "No stop" << endl;
            }
            else
            {
                for (const string& bus : stops[stop])
                {
                    cout << bus << " ";
                }
                cout << endl;
            }
        }
        else if (command == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;

            if (buses.count(bus) == 0)
            {
                cout << "No bus" << endl;
            }
            else 
            {
                for (const string& stop : buses[bus])
                {
                    cout << "Stop " << stop << ": ";
                    if (stops[stop].size() == 1)
                    {
                        cout << "no interchange";
                    }
                    else
                    {
                        for (const string& s : stops[stop])
                        {
                            if (s != bus)
                            {
                                cout << s << " ";
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (command == "ALL_BUSES")
        {
            if (buses.size() == 0)
            {
                cout << "No buses" << endl;
            }
            else
            {
                for (const auto& [bus, stops] : buses)
                {
                    cout << "Bus " << bus << ": ";
                    for (const string& stop : stops)
                    {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}