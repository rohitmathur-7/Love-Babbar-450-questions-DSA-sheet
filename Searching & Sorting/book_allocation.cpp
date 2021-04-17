/*
QUES: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

bool canKeep(int *arr,int n,int m,int minPages){
    int students=1;
    int pages=0;
    f(i,0,n){
        if(pages+arr[i]>minPages){
            students++;
            if(students>m) return false;
            pages=arr[i];
        }
        else pages+=arr[i];
    }
    return true;
}

void solve(int *arr,int n,int m,int sum){
    //in worst case the student will read minimum 0 pages, and maximum all the pages given in the array.So will have starting point as 0 and ending point as sum of all pages.
    //and then we will use Binary Search, Now we know that are search space is b/w 0 and sum of all pages.
    //So, we will first take out mid and check if we can distribute books among m students such that the max pages they read is less than mid.And then we will just try to find minimum mid which will be our answer.
    int s=0;
    int e=sum;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(canKeep(arr,n,m,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
}

int main(){
    w(t){
        int n,m;
        cin>>n>>m;
        int arr[n];
        int sum=0;
        f(i,0,n){
            cin>>arr[i];
            sum+=arr[i];
        }
        solve(arr,n,m,sum);
    }
    return 0;
}