#include<bits/stdc++.h>
using namespace std;

int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n){
    unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

int main()
{
    int n;
    cin>>n;
    cout<<isHappy(n)<<endl;
    return 0;
}
