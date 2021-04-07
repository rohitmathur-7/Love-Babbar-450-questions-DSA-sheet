//Ques: https://practice.geeksforgeeks.org/problems/reverse-a-string/1

//Q1

#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define w(t) ll t;cin>>t;while(t--)
#define mod 1000000007
using namespace std;

string reverseWord(string str){
    int n=str.size();
    int strt=0,end=n-1;
    while(strt<=end){
        int temp=str[strt];
        str[strt]=str[end];
        str[end]=temp;
        strt++;
        end--;
    }
    return str;
}

int main(){
    string str;
    cin>>str;
    cout<<reverseWord(str)<<endl;
}