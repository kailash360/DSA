class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int A = 0;
        int i = 0 , j = n-1;
        while(i<j){
            A = max(A , (j-i)*min(height[i],height[j]));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return A;
    }
};