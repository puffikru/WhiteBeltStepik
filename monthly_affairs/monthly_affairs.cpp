#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int Q;
    string command;
    vector<int> day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_number = 0;
    vector<vector<string>> current_month(day_of_month[month_number]);
    cout << current_month.size() << endl;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int day;
        cin >> command;
        if (command == "ADD")
        {
            string affair;
            cin >> day >> affair;
            current_month[day - 1].push_back(affair);
        } 
        else if (command == "DUMP")
        {
            cin >> day;
            for (string todo : current_month[day - 1])
            {
                cout << todo << " ";
            }
        } 
        else if (command == "NEXT")
        {
            int next_month = 0;
            if (month_number == 11) 
            {
                next_month = 0;
            }
            else
            {
                next_month = month_number + 1;
            }
            for (int j = 0; j < current_month.size(); ++j)
            {
                for (int i = 0; i < current_month[j].size(); ++i)
                {
                    cout << j << " " << current_month[j][i] << endl;
                }
            }
            cout << "month days: " << month_number << endl;
            cout << "next month days: " << next_month << endl;
            int optional_day_count = day_of_month[next_month] - day_of_month[month_number];
            cout << "optional days: " << optional_day_count << endl;
            cout << "days of the next month: " << day_of_month[next_month] << endl;
            if (day_of_month[next_month] > day_of_month[month_number])
            {
                vector<vector<string>> optional_days(abs(optional_day_count));
                current_month.insert(end(current_month), begin(optional_days), end(optional_days));
            }
            else
            {
                cout << "next month days is less, then current" << endl;
                vector<string> last_day;
                for (int i = current_month.size() - abs(optional_day_count); i <= current_month.size(); ++i)
                {
                    for (string s : current_month[i])
                    {
                        last_day.push_back(s);
                    }
                }

                cout << "before resize: " << current_month.size() << endl;
                for (int j = 0; j < current_month.size(); ++j)
                {
                    for (int i = 0; i < current_month[j].size(); ++i)
                    {
                        cout << j << " " << current_month[j][i] << endl;
                    }
                }
                current_month.resize(day_of_month[next_month]);
                current_month[current_month.size() - 1] = last_day;
            }

            cout << "after resize: " << current_month.size() << endl;
            for (int j = 0; j < current_month.size(); ++j)
            {
                for (int i = 0; i < current_month[j].size(); ++i)
                {
                    cout << j << " " << current_month[j][i] << endl;
                }
            }
        }
    }
    return 0;
}