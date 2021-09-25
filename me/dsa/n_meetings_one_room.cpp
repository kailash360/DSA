// Greedy approach
#include <bits/stdc++.h>
using namespace std;

struct meet{
    int start;
    int end;
    int pos;
};

bool comparefn(struct meet m1, meet m2)
{
    if(m1.end < m2.end) return true;
    else if(m1.end  > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

int solve(int start[], int end[], int N){
    struct meet m[N];
    for(int i=0;i<N;i++){
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i;
    }
    
    sort(m, m+N, comparefn);

    int limit = m[0].end;
    int count = 1;
    for(int i=1;i<N;i++){
        if(m[i].start > limit){
            limit = m[i].end;
            count++;
        }
    }
    return count;
}

int main(){
    int start[] = {1,3,0,5,8,5};
    int end[] =  {2,4,6,7,9,9};
    int N = 6;
    int ans = solve(start, end, N);
    cout << "Max meetings: "<<ans<<endl;
    return 0;
}