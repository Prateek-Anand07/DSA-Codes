#include<bits/stdc++.h>
using namespace std;
/* Sieve of Eratosthenes:
    Time complexity: O(2N + N*log(N*log(N))) = O(N*log(N*log(N)))
    Space complexity: O(N) */
int countPrimes(int n) { // Count number of prime numbers till n
    if(n==0 || n==1)
        return 0;
    int prime[n+1];
    for(int i=2; i<=n; i++) // O(N)
        prime[i] = 1;
    for(int i=2; i*i<=n; i++) {  // O(N*log(N*log(N)))
        if(prime[i] == 1) {
            for(int j=i*i; j<=n; j+=i) {
                prime[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i=2; i<=n; i++) { // O(N)
        if(prime[i] == 1)
            count++;
    }
    return count;
}
int main() {
    int i;
    cin>>i;
    cout<<countPrimes(i);
    return 0;
}