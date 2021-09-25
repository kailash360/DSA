#include <bits/stdc++.h>
using namespace std;

struct job{
	int id;
	int deadline;
	int profit;
};

bool compareFunc(struct job job1, job job2){
	 if (job1.profit > job2.profit)
		return true;
	return false;
}

int solve(int deadline[], int profit[], int n) {
	struct job jobs[n];
	for(int i=0;i<n;i++){
        jobs[i].id = i+1;
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
    }
    
	sort(jobs, jobs+n, compareFunc); // compare according to deadline first and then profit
	
	// for(int i=0; i<n; i++){
	// 	cout << jobs[i].deadline <<" " <<jobs[i].profit << endl;
	// }
    int max_day = jobs[0].deadline;
	for(int i=1; i<n;i++){
        max_day = max(max_day, jobs[i].deadline);
    }

    int slot[max_day+1];
    memset(slot, -1, sizeof(slot));
    int count = 0, total_profit = 0;

    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline; j>0; j--){
            if(slot[j]==-1){
                slot[j] = i;
                count++;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    cout << count <<" "<< total_profit;
	return 0;
}

int main() {
	int n = 5;
	int deadline[] = {2,1,2,1,1};
	int profit[] = {100,19,27,25,15};
	solve(deadline,profit, n);
	
	return 0;
}