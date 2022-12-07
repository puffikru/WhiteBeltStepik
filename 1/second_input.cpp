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
            if (first)
            {
                pos = i;
                break;
            }
            else
            {
                first = true;
            }
        }
    }
    if (!first)
    {
        std::cout << "-2" << std::endl;
    }
    else
    {
        int res = pos < 0 ? -1 : pos;
        std::cout << res << std::endl;
    }
    return 0;
}