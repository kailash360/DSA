// C++ program to map elements of an array
// to equal elements of another array
#include <bits/stdc++.h>
using namespace std;
  
// Function to print the mapping of elements
void printMapping(int A[], int B[], int N, int M)
{
  
   // Create a hash table where all indexes are 
   // stored for a given value
   unordered_map<int, list<int>> m;
   for (int i=0; i<N; i++)
      m[A[i]].push_back(i);
  
   // Traverse through B[]
   for (int i=0; i<M; i++)
   {
       // If a mapping is found, print the mapping and
       // remove the index from hash table so that the
       // same element of A[] is not mapped again.
       if (m.find(B[i]) != m.end() && m[B[i]].size() > 0)
       {
           cout << m[B[i]].front() << " ";
           m[B[i]].pop_front();
       }
  
       else // No mapping found
       {
           cout << "NA ";
       }
   }
}
  
// Driver code
int main()
{
    int A[] = {2, 1, 2, 3, 3, 4, 2, 4, 1};
    int N = sizeof(A) / sizeof(A[0]);
    int B[] = {1, 2, 5, 1, 2, 4, 2, 3, 2, 1};
    int M = sizeof(B) / sizeof(B[0]);
    printMapping(A, B, N, M);
        return 0;
}