//QUES: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

//Q2

#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define w(t) ll t;cin>>t;while(t--)
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n){
        cin>>arr[i];
    }
    int mx=INT_MIN;
    int mn=INT_MAX;
    f(i,0,n){
        if(arr[i]>mx) mx=arr[i];
        if(arr[i]<mn) mn=arr[i]; 
    }
    cout<<"MAX: "<<mx<<endl;
    cout<<"MIN: "<<mn<<endl;
}