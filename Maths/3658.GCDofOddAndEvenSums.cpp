#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int Oddsum = 1;
        int count =1;
        int OddNum =1;
        while(count!=n){
            OddNum+=2;
            Oddsum +=OddNum;
            count++;
        }
        count = 1;
        int evenSum=2;
        int evenNum =2;
        while(count!=n){
            evenNum+=2;
            evenSum += evenNum;
            count++;
        }
        cout<<Oddsum<<endl;
        cout<<evenSum<<endl;
        return __gcd(evenSum,Oddsum);
    }
};