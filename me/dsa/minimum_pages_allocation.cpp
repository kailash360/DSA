// 
class Solution 
{
    public:
    int chk(int x, int arr[], int n, int m){
        int sum = 0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(sum + arr[i] > x){
                cnt++;
                sum = arr[i];
                if(sum > x) return false;
            }
            else{
                sum += arr[i];
            }
        }
        if(cnt <= m) return true;
        return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        if(m > n) return -1;// sorting the books in ascending order of pages
        //code here
        int low = arr[0];
        int high = 0;
        for(int i=0; i<n;i++){
            low = min(arr[i], low);
            high += arr[i];
        } 
        int res = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(chk(mid, arr, n, m)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};