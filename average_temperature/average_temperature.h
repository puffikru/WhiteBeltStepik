#pragma once
#include <iostream>
#include <vector>

using namespace std;

void AverageTemperature()
{
    int N;
    int sum = 0;
    int avr = 0;
    vector<int> temperature;
    vector<int> result;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        sum += temp;
        temperature.push_back(temp);
    }

    avr = sum / N;
    int average_greater_count = 0;
    for (int i = 0; i < temperature.size(); ++i)
    {
        if (temperature[i] > avr)
        {
            average_greater_count++;
            result.push_back(i);
        }
    }

    cout << average_greater_count << endl;
    for (int r : result)
    {
        cout << r << " ";
    }
}