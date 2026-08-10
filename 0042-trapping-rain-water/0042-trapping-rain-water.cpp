class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=height.size()-1;
        int leftmax=0, rightmax=0, totalwater=0;
        while(i<j){
            leftmax = max(leftmax, height[i]);
            rightmax = max(rightmax, height[j]);

            if(leftmax < rightmax){
                totalwater += leftmax - height[i];
                i++;
            }else{
                totalwater += rightmax - height[j];
                j--;
            }
        }
        return totalwater;

    }
};