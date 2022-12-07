#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    bool first = false;
    int pos = -1;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'f')
        {
            if (!first)
            {
                first = true;
            }
            else
            {
                pos = i;
            }
        }
    }
    if (!first)
    {
        std::cout << "-2" << std::endl;
    }
    else if (first)
    {

    }
    return 0;
}