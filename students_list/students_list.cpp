#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};

int main()
{
    vector<Student> students;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string first_name;
        string last_name;
        int day = 0;
        int month = 0;
        int year = 0;
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }
    int M;
    cin >> M;
    for (int j = 0; j < M; ++j)
    {
        string command;
        int num;
        cin >> command >> num;
        if (command == "name" && num > 0 && num <= students.size())
        {
            cout << students[num - 1].first_name << " " << students[num - 1].last_name << endl;
        } 
        else if (command == "date" && num > 0 && num <= students.size())
        {
            cout << students[num - 1].day << "." << students[num - 1].month << "." << students[num - 1].year << endl;
        }
        else
        {
            cout << "bad request" << endl;
        }
    }
    return 0;
}