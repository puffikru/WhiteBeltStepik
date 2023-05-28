#include <iostream>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;

class Date
{
public:
    Date() {}

    Date(int new_year, int new_month, int new_day)
    {
        if (new_month < 1 || new_month > 12)
        {
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        }
        else if (new_day < 1 || new_day > 31)
        {
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        }
        year = new_year;
        month = new_month;
        day = new_day;
    }

    int GetYear() const
    {
        return year;
    }

    int GetMonth() const
    {
        return month;
    }

    int GetDay() const
    {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

istream &operator>>(istream &is, Date &date)
{
    int year, month, day;
    char op1, op2;

    if (is)
    {
        string query;
        is >> query;
        stringstream ss(query);
        if (ss.peek() == '+') ss.ignore(1);
        ss >> year >> op1;
        if (ss.peek() == '+') ss.ignore(1);
        ss >> month >> op2;
        if (ss.peek() == '+') ss.ignore(1);
        ss >> day;

        if (ss && op1 == '-' && op2 == '-' && ss.peek() == -1)
        {
            date = Date(year, month, day);
        }
        else
        {
            throw invalid_argument("Wrong date format: " + query);
        }
    }

    return is;
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << setfill('0');
    os << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
    return os;
}

class Database
{
public:
    void AddEvent(const Date &date, const string &event)
    {
        data[date].insert(event);
    }

    bool DeleteEvent(const Date &date, const string &event)
    {
        if (data.count(date) > 0 && data.at(date).count(event) > 0)
        {
            data.at(date).erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date &date)
    {
        int result = 0;
        if (data.count(date) > 0)
        {
            result = data.at(date).size();
            data.at(date).clear();
        }
        return result;
    }

    set<string> Find(const Date &date) const
    {
        set<string> result;
        if (data.count(date) > 0)
        {
            result = data.at(date);
        }
        return result;
    }

    void Print() const
    {
        for (const auto &[date, events] : data)
        {
            for (const string& event : events)
            {
                cout << date << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> data;
};

int main()
{
    Database db;

    string command;
    try
    {
        while (getline(cin, command))
        {
            stringstream ss(command);
            string cmd;
            ss >> cmd;
            if (cmd == "Add")
            {
                Date date;
                string event;
                ss >> date >> event;
                db.AddEvent(date, event);
            }
            else if (cmd == "Del")
            {
                Date date;
                string event;
                ss >> date >> event;
                if (event.empty())
                {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
                else
                {
                    if (db.DeleteEvent(date, event))
                    {
                        cout << "Deleted successfully" << endl;
                    }
                    else
                    {
                        cout << "Event not found" << endl;
                    }
                }
            }
            else if (cmd == "Find")
            {
                Date date;
                ss >> date;
                set<string> events = db.Find(date);
                for (const string &e : events)
                {
                    cout << e << endl;
                }
            }
            else if (cmd == "Print")
            {
                db.Print();
            }
            else if (cmd == "")
            {
                continue;
            }
            else
            {
                cout << "Unknown command: " << command << endl;
            }
        }
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}