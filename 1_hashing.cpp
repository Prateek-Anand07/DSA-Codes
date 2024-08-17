#include<bits/stdc++.h>
using namespace std;
int main() {
    // Hashing: storing frequency of numbers in array and fetching it later
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    // Pre-calculation
    // Input:
//     5
//     1 2 1 3 2
//     5
//     1 2 3 4 12
    // int hash[13] = {0}; // if frequency of element to find max is 12
    // for(int i=0; i<n; i++) {
    //     hash[arr[i]] += 1;
    // }
    // int q;
    // cin>>q;
    // for(int i=0; i<q; i++) {
    //     int number;
    //     cin>>number;
    //     // fetch
    //     cout<< hash[number]<<endl;
    // }

    // Hashing in characters:
    // string s;
    // cin>>s;
    // Input:
    // abcdabehf
    // 5
    // a g h b c
    // int q;
    // cin>>q;
    // pre-compute:
    // int arr[26] = {0}; // take size as 256 instead 26 if all characters are involved
    // for(int i=0; i<s.length(); i++) {
    //     arr[s[i]-'a'] += 1; // if all characters: arr[s[i]]
    // }
    // while(q--) {
    //     char ch;
    //     cin>>ch;
        // fetch
    //     cout<<arr[ch-'a']<<endl; // if all characters: arr[s[i]]
    // }
    // Best way for integer hash is map, it can also do for size more than 10^7
    // Pre-calculation
    map<int,int> mpp; // for each operation storing and fetching in map in all average, best and worst case 
                        // it takes time of log N where N is no. of elements in map
    // for unorderd_map each operation in average and best case takes time O(1) but very rare is O(N)
    // 1st preference is unordered_map if it gives TLE then use map
    for(int i=0; i<n; i++) {
        mpp[arr[i]] += 1; 
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++) {
        int number;
        cin>>number;
        // fetch
        cout<< mpp[number]<<endl;
    }
    return 0;
}
// Array max size in main() for int is 10^6 and for boolean is 10^7
// Array max size outside main(globally) for int is 10^7 and for boolean is 10^8
// Whatever method the map is using, if all the elements go to the same hash index, 
//      we will call it a case of collision.

// Note: In the map data structure, the data type of key can be anything like int, double, pair<int, int>, etc.
//       But for unordered_map the data type is limited to integer, double, string, etc. We cannot
//       have an unordered_map whose key is pair<int, int>.

// Notes for details: https://takeuforward.org/hashing/hashing-maps-time-complexity-collisions-division-rule-of-hashing-strivers-a2z-dsa-course/