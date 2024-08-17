#include<iostream>
#include<string>
using namespace std;
string large_word(string text) {
    string result_string, temp_str;
    for(int i=0; i<text.length(); i++) {
        if(text[i]!=' ' && ((int(text[i])>=65&&int(text[i])<=90)||(int(text[i])>=97&&int(text[i])<=122)||(int(text[i])>=48&&int(text[i])<=57))) {
            result_string.push_back(text[i]);
        }
        else
            break;
    }
    for(int i=0; i<text.length(); i++) {
        if(text[i]!=' ' && ((int(text[i])>=65&&int(text[i])<=90)||(int(text[i])>=97&&int(text[i])<=122)||(int(text[i])>=48&&int(text[i])<=57))) {
            temp_str.push_back(text[i]);
            if(i+1==text.length() && temp_str.length()>result_string.length())
                result_string = temp_str;
        }
        else {
            if(temp_str.length()>result_string.length()) 
                result_string = temp_str;
            temp_str.clear();
        }
    }
    return result_string;
}
int main() {
    // char arr[100];
    // cin>>arr; //for input
    // cout<<arr<<endl; //for output
    // cout<<arr[2];

    // To check palindrome
    // int n;
    // cin>>n;
    // cin.ignore();
    // char arr[n+1];
    // cin>>arr;
    // bool check = true;
    // for(int i=0; i<=n/2; i++) {
    //     if(arr[i] != arr[n-1-i]) {
    //         check = false;
    //         break;
    //     }
    // }
    // if(check == true) 
    //     cout<<"It is palindrome";
    // else 
    //     cout<<"It is not palindrome";

    // To find largest word in sentence
    // cin.getline(arr, n+1);
    // cin.ignore();
    // int ans=0, count=0, i=0, st=0, maxst=0;
    // while(1) {
    //     if(arr[i]==' ' || arr[i]=='\0') {
    //         if(count>ans) {
    //             ans = count;
    //             maxst = st;
    //         }
    //         count = 0;
    //         st = i+1;
    //     }
    //     else 
    //         count++;
    //     if(arr[i]=='\0')
    //         break;
    //     i++;
    // }
    // cout<<ans<<endl;
    // for(int i=0; i<ans; i++) {
    //     cout<<arr[i+maxst];
    // }
    string str;
    getline(cin, str);
    cout<<"Word of maximum length is: "<<large_word(str);
    return 0;
}