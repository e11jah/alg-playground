#include <vector>

using namespace std;


// lis
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (int x : nums) {
            if (lis.empty()||x>lis.back())
                lis.push_back(x);
            else
                *lower_bound(lis.begin(), lis.end(), x) = x;
        }
        return lis.size();
    }
};