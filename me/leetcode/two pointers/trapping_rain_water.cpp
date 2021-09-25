class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int i = 0;
        int j = n-1;
        int lh = 0;
        int rh = 0;
        int area = 0;
        while(i<=j){
            if(height[i] <= height[j]){
                if(height[i] >= lh){
                    lh = height[i];
                }
                else{
                    area += (lh - height[i]);
                }
                i++;
              }
            else{
              if(height[j] >= rh){
                  rh = height[j];
              }  
                else{
                    area += (rh-height[j]);
                }
                j--;
              }
            }
        return area;
        }
};