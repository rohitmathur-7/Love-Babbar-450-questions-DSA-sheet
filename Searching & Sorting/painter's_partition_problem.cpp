//Ques: https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/?page=1&category[]=Binary%20Search&query=page1category[]Binary%20Search#

#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

//this func returns true if the painter's can paint all the boards in given amount of times else returns false
bool canPaint(ll n,ll k,ll *arr,ll maxTime){
    ll time=0;
    ll painters=1;
    f(i,0,n){
        if(arr[i]>maxTime) return false;

        if((time+arr[i])>maxTime){
            painters++;
            if(painters>k) return false;
            time=0;
            time+=arr[i];
        }
        else time+=arr[i];
    }
    return true;
}

int main(){
    ll k,n;
    cin>>k>>n;
    ll arr[n];
    ll e=0;
    f(i,0,n){
        cin>>arr[i];
        e+=arr[i];
    }
    if(n==k){
        cout<<*max_element(arr,arr+n)<<endl;
    }
    else{
        ll s=0;
        ll ans;
        //binary search
        //So our main aim is to find the min time in which the painter's can paint all the boards,So to use binary search we first have to think of a search space, now as we want min time ..so we will have a search space based on time.So, our starting point can be 0, i.e there was no board ..so time taken is zero, and the ending point will be the maximum time taken to paint the boards, this will be the case when only 1 painter paints all the boards,So we definitely know that our answers lies in this range only.And now we can apply binary seach.
        while(s<=e){
            ll mid=(s+e)/2;
            //Checking if we can paint all the boards in the given time.
            //if we can paint all in given time then set ans as min of ans and the current time,and as we want min time, so make e as mid-1
            if(canPaint(n,k,arr,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }
            //if we cannot paint in given time then make s as mid+1, to check if it can be done in more amount of time
            else s=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}