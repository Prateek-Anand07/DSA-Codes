#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    // To find greatest number
    // string str = "53214";
    // sort(str.begin(), str.end(), greater<char>());

    // To find maximum frequency of character in string 
    string str = "fsasda";
    // int freq[26];
    // for(int i=0; i<26; i++)
    //     freq[i]=0;
    // for(int i=0; i<str.length(); i++)
    //     freq[str[i]-'a']++;
    // int fMax=0;
    // char ans = 'a';
    // for(int i=0; i<26; i++) {
    //     if(fMax<freq[i]) {
    //         fMax = freq[i];
    //         ans = i+'a';
    //     }
    // }
    // cout<<fMax<<" "<<ans<<endl;
    string sb = str.substr(1);
    cout << sb<<endl;
    sb.replace(1, 2, "123");
    cout << sb<<endl;
    string s = "";
    s += 'a';
    s += 'b';
    s.pop_back();
    cout<<s.back(); // last character in string
    cout<<"Check string: "<<s;
    return 0;
}