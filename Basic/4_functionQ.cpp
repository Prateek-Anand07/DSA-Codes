#include<bits/stdc++.h>
#include<math.h>
using namespace std;
// Q1 To check Pythagorean triplet
// bool check(int x, int y, int z) {
//     int a = max(x, max(y,z));
//     int b, c;
//     if(a==x) {
//         b=y;
//         c=z;
//     }
//     else if(a==y) {
//         b=x;
//         c=z;
//     }
//     else {
//         b=x;
//         c=y;
//     }
//     if(a*a == b*b + c*c)
//     return true;
//     else
//     return false;
// }
// int main() {
//     int x, y, z;
//     cout<<"enter three numbers: ";
//     cin>>x>>y>>z;
//     if(check(x, y, z))
//     cout<<"Pythagorean triplet";
//     else
//     cout<<"Not a pythagorean triplet";
//     return 0;
// }

//Conversions between different number systems
int binaryToDecimal(int n) {
    int ans = 0, x=1;
    while(n>0) {
        int y = n%10; 
        ans += x*y;
        x *= 2;
        n/=10;
    }
    return ans;
}

int octalToDecimal(int n) {
    int ans = 0, x = 1;
    while(n>0) {
        int y = n%10;
        ans += x*y;
        x = 8*x;
        n/=10;
    }
    return ans;
}

int hexadecimalToDecimal(string n) {
    int ans = 0, x = 1;
    int s = n.size();
    for(int i=s-1; i>=0; i--) {
        if(n[i]>='0' && n[i]<='9')
            ans += x*(n[i]-'0');
        else if(n[i]>='A' && n[i]<='F')
            ans += x*(n[i]-'A'+10);
        x *= 16;
    }
    return ans;
}

int decimalToBinary(int n) {
    int ans = 0, x = 1;
    while(x<=n)
        x *= 2;
    x/=2;
    while(x>0) {
        int digit = n/x;
        n -= digit*x;
        x/=2;
        ans = ans*10+digit;
    }
    return ans;
}

int decimalToOctal(int n) {
    int ans = 0, x = 1;
    while(x<=n)
        x *= 8;
    x/=8;
    while(x>0) {
        int digit = n/x;
        n -= digit*x;
        x/=8;
        ans = ans*10+digit;
    }
    return ans;
}

// string decimalToHexadecimal(int n) {
//     int ans = 0, x = 1;
//     while(x<=n) 
//         x *= 16;
//     x/=16;
//     while (x>0)
//     {
//         int digit = n/x;
//         n -= digit*x;
//         x/=16;
//         if(digit<=9)
//             ans = ans + to_string(digit);
//         else
//             char c = digit + 'A' - 10;
//             ans.push_back(c);
//     }  
//     return ans;
// }

int reverse(int n) {
    int ans =0;
    while(n>0) {
        ans = ans*10 + (n%10);
        n/=10;
    }
    return ans;
}
int addBinary(int a, int b) {
    int ans =0, prevCarry=0;
    while(a>0 && b>0) {
        if(a%2==0 && b%2==0) {
            ans = ans*10+prevCarry;
            prevCarry=0;
        }
        else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0)) {
            if(prevCarry==1) {
                ans = ans*10+0;
                prevCarry=1;
            }
            else {
                ans = ans*10+1;
                prevCarry=0;
            }
        }
        else {
            ans = ans*10+prevCarry;
            prevCarry=1;
        }
        a/=10;
        b/=10;
    }
    while(a>0) {
        if(prevCarry==1) {
            if(a%2==0) {
                ans = ans*10+1;
                prevCarry=0;
            }
            else {
                ans = ans*10+0;
                prevCarry=1;
            }
        }
        else {
            ans = ans*10+(a%2);
        }
        a/=10;
    }
    while(b>0) {
        if(prevCarry==1) {
            if(b%2==0) {
                ans = ans*10+1;
                prevCarry=0;
            }
            else {
                ans = ans*10+0;
                prevCarry=1;
            }
        }
        else {
            ans = ans*10+(b%2);
        }
        b/=10;
    }
    if(prevCarry==1) {
        ans = ans*10+1;
        prevCarry=0;
    }
    ans = reverse(ans);
    return ans;
}
int main() {
    int a, b;
    cout<<"enter two binary numbers: ";
    cin>>a>>b;
    cout<<addBinary(a, b)<<endl;
    return 0;
}
