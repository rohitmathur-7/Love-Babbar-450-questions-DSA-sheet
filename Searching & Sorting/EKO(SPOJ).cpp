//Ques: https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

bool canCut(ll *arr,ll n,ll m,ll maxHeight){
    ll cut_part=0;
    f(i,0,n){
        if(arr[i]>maxHeight){
            cut_part+=(arr[i]-maxHeight);
            if(cut_part>=m) return true;
        }
    }
    return false;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    ll s=0,e=0;
    f(i,0,n){
        cin>>arr[i];
        e+=arr[i]; //we can take e as sum of all elements or the max element in the array
    }
    // e=*max_element(arr,arr+n);
    ll ans=LLONG_MIN;
    //for using binary search we will first take out the seach space, and as we want the max height so our search space will be in terms of height, now our starting point can be 0 as max height to cut can be 0, and our end point will be sum of all the height or the max height present in the array, as that will be our end case so we will take ending point as that.
    //Now in binary search we take out mid and assume it as our max height and check through a func that if we will be able to get atleast 'm' amount of cutted wood, and just take the max mid as our ans.
    while(s<=e){
        ll mid=(s+e)/2;
        if(canCut(arr,n,m,mid)){
            s=mid+1;
            ans=max(ans,mid);
        }
        else e=mid-1;
    }
    cout<<ans<<endl;

    return 0;
}