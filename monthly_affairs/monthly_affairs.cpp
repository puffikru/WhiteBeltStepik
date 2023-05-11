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
            cout << current_month[day - 1].size() << " ";
            for (string todo : current_month[day - 1])
            {
                cout << todo << " ";
            }
            cout << endl;
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
       
            int optional_day_count = day_of_month.at(next_month) - day_of_month.at(month_number);
         
            if (day_of_month.at(next_month) > day_of_month.at(month_number))
            {
                vector<vector<string>> optional_days(abs(optional_day_count));
                current_month.insert(end(current_month), begin(optional_days), end(optional_days));
            }
            else
            {
                vector<string> last_day;
                for (int i = current_month.size() - abs(optional_day_count) - 1; i <= current_month.size() - 1; ++i)
                {
                    for (string s : current_month.at(i))
                    {
                        last_day.push_back(s);
                    }
                }

                current_month.resize(day_of_month[next_month]);
                current_month.at(current_month.size() - 1) = last_day;
            }
            month_number = next_month;
        }
    }
    return 0;
}