#include <string>
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        auto it1 = word1.begin(), it2 = word2.begin();
        while (it1 != word1.end() || it2 != word2.end())
            ans += lexicographical_compare(it1, word1.end(), it2, word2.end())?*it2++:*it1++;

        return ans;
    }
};