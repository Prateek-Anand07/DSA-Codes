#include<bits/stdc++.h>
using namespace std;
/* Sieve of Eratosthenes:
    Time complexity: O(N*log(N*log(N)))
    Space complexity: O(N) */
vector<int> findPrimeFactors(int N) {
    vector<int> ans;
    int prime[N+1];
    for(int i=2; i<=N; i++) {
        prime[i] = i;
    }
    for(int i=2; i*i<=N; i++) {
        if(prime[i] == i) {
            for(int j=i*i; j<=N; j+=i) {
                if(prime[j] == j)
                    prime[j] = i;
            }
        }
    }
    int temp = N;
    while(temp!=1) {
        ans.push_back(prime[temp]);
        temp /= prime[temp];
    }
    return ans;
}
int main() {
    vector<int> ans;
    int n; 
    cin>>n;
    ans = findPrimeFactors(n);
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}