#include <string>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size()!=goal.size())
            return false;
        // 断环成链
        s += s;
        return s.find(goal)!=string::npos;
    }
};