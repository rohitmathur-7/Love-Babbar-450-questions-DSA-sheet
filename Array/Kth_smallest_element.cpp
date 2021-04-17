//QUES: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//Q3

#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define w(t) ll t;cin>>t;while(t--)
#define mod 1000000007
using namespace std;

int solve(int *arr,int n,int k){
    //the expected time cmp of this is O(n), but we if do normal sorting than that is going to 
    //take O(nlog(n)), so we will do Counting sort, which takes O(n) time.
        int mx=*(max_element(arr,arr+n));
        int count[mx+1];
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(int i=1;i<=mx;i++){
            count[i]+=count[i-1];
        }
        int b[n];
        for(int i=n-1;i>=0;i--){
            b[--count[arr[i]]]=arr[i];
        }
        for(int i=0;i<n;i++) arr[i]=b[i];
        return arr[k-1];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n) cin>>arr[i];
    int k;
    cin>>k;
    cout<<solve(arr,n,k)<<endl;
    
}