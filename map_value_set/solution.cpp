#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m){
    std::set<std::string> res;
    for(auto& [k, v] : m) {
        res.insert(v);
    }
    return res;
}

int main() {
    std::set<std::string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const std::string& value : values) {
        std::cout << value << std::endl;
    }
    return 0;
}
