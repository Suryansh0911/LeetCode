class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0; i<n; i++){
            minHeap.push({arr[i], i});
        }
        vector<int> ans(n);
        int currank = 1;
        int prev = minHeap.top().first;
        while(!minHeap.empty()){
            auto [val, index] = minHeap.top();
            minHeap.pop();
            if(val > prev){
                currank++;
                prev = val;
            }
            ans[index] = currank;
        }
        return ans;
    }
};