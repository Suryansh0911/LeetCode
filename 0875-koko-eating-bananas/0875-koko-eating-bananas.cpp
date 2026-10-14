class Solution {
public:
    bool canDo(vector<int>&piles, int mid, int h){
        int hours=0;
        for(int i=0; i<piles.size(); i++){
            hours += (piles[i] + mid - 1)/mid;
            if(hours > h) return false;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=*max_element(piles.begin(), piles.end());
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(canDo(piles, mid, h)){
                hi=mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};