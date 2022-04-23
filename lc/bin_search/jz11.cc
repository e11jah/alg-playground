class Solution {
public:

    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0, r = rotateArray.size()-1,m,target=rotateArray[r],ans=target;
        while (l<r) {
            m=(l+r)/2;
            if (rotateArray[m]<target)
                r=m,ans=min(ans,rotateArray[m]);
            else if (rotateArray[m]==target) 
                // 更新边界和 target
                r-=1,target=rotateArray[r],ans=min(ans,target);
            else l=m+1;
        }
        return ans;
    }
    
};