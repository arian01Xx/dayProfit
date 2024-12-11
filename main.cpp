#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001]={0};
        int xMax=0, xMin=1e6; //1x10^6
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }

        int cnt=0, maxCnt=0;
        for(int l=xMin, r=xMin; r<=xMax; r++){
            cnt+=freq[r];
            while(r-l>2*k){
                cnt-=freq[l];
                l++;
            }
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

int main(){
    return 0;
}