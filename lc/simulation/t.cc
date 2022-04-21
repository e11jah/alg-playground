class ATM {
    int am[5] = {20,50,100,200,500};
    long long cnt[5]={0},mid;
public:
    ATM() {

    }
 
    void deposit(vector<int> banknotesCount) {
        // 20 50 100 200 500
        for(int i = 0; i < 5; i++) {
            cnt[i]+=banknotesCount[i];
            if (cnt[i]) mid=i;
        }
    }
    void undo(vector<int> &v) {
        for (int i = 0; i < 5; i++)
            cnt[i]+=v[i];
    }
    vector<int> withdraw(int amount) {
        vector<int> ret(5);
        for(int i = 4; i >=0; i--) {
            if (amount<1) break;
            if (am[i]>amount||!cnt[i]) {
                continue;
            }
            long long l=0,r=cnt[i],m,k=0;
            while (l<=r) {
                m=(l+r)/2;
                if (amount>=am[i]*m) 
                    l=m+1,k=m;
                else r=m-1;
            }

            amount -= am[i]*k, cnt[i]-=k, ret[i]+=k;
            
        }
        if (amount>0) {
            undo(ret);
            return {-1};
        }
        return ret;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */