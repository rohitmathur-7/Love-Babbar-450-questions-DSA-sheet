//Ques: https://www.spoj.com/problems/PRATA/

/*
Idea:
So the main idea in this question is to use Binary search, we are using binary search here bcz we can find a Search space in this question where our answer will be.
So by using it we will do this in a lot less time(This was the basic intuition behind using binary seach).
*/


#include<bits/stdc++.h>
#define ll long long int
#define w(t) int t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

//this func will tell us if we can make the pratas in given amount of time or not.
bool canMakePratas(int maxTime,int totalPratas,int *cook,int l){
    int pratas=0;
    //iterating over the array which have ranks stored
    f(i,0,l){
        int time=0;
        int cnt=1;
        //for each element of the array we are checkig how many pratas can be made till max time which is given
        while(time<=maxTime){
            time+=(cook[i]*cnt);
            if(time>maxTime) break;
            pratas++;
            //if we can make pratas in given time then return true.
            if(pratas>=totalPratas) return true;
            cnt++;
        }
    }
    //if we couldn't make pratas in given time return false.
    return false;
}

int main(){
    w(t){
        int p,l;
        cin>>p>>l;
        int cook[l];

        //So what we will first do is, we will find a range(Search space) where our answer will probably be, and in this case if we think...the minimum time we could take to make all the pratas could be 0 if there we 0 pratas to make, so our starting point could be 0.Now what could be the ending point?....If we think then,if we take the maximum element in the array(i.e the cook who takes max time to make prata) and give him the responsibility to make all the pratas,then it would be the max time among all to make the given amount of pratas, which will be our ending point!.

        int mx_element=INT_MIN;
        f(i,0,l){
            cin>>cook[i];
            if(cook[i]>mx_element){
                mx_element=cook[i];
            }
        }
        int e=0;
        f(i,1,p+1){
            e=e+(mx_element*i);
        }
        int s=0;
        int ans;
        //now we will do binary search in the range that we found out,i.e frome s to e.
        //So here we will think mid as the maximum time taken to make pratas, and we will make a func and check for the particular mid(max time) that if we can make the given amount of pratas in the given max time(mid), if we can then we will set our end point as mid-1, bcz we want to see if there is some less time in which we can make the pratas, else we will set s as mid+1, bcz we couldn't make the pratas in the given time, so we want to inc our time and then check again!.
        while(s<=e){
            int mid=(s+e)/2;
            if(canMakePratas(mid,p,cook,l)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}