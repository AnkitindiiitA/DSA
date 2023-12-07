#include<bits/stdc++.h>
using namespace std;

class SGTree{
     public:
     
     vector<int> seg;
     
     SGTree(int n){
         seg.resize(4*n+1); 
     }
     
     int f(int &a, int &b){
          //change the function according to question
          return min(a,b);
     }
     
     void build(int ind, int low, int high, vector<int> &a){
          if(low==high){
               seg[ind]=a[low];
               return;
          }
          
          int mid=low+(high-low)/2;
          build(2*ind+1,low,mid,a);
          build(2*ind+2,mid+1,high,a);
          
          seg[ind]=f(seg[2*ind+1], seg[2*ind+2]);//min(left,right);
     }
     
     int query(int ind, int low, int high, int sl, int sr){
          //no overlap
          if(sr < low || high < sl)return INT_MAX;
          
          //complete overlap
          if(low >= sl && high <= sr)return seg[ind];
          
          //partial overlap
          int mid=low+(high-low)/2;
          int left=query(2*ind+1,low,mid,sl,sr);
          int right=query(2*ind+2,mid+1,high,sl,sr);
          
          return f(left, right);//min(left,right);
     }
     
     void update(int ind, int low, int high, int i, int val){
          if(low == high){
               seg[ind]=val;
               return;
          }
          
          int mid=low+(high-low)/2;
          if(i<=mid){
               update(2*ind+1, low, mid, i, val);
          }
          else{
               update(2*ind+2, mid+1, high, i, val);
          }
          
          seg[ind]=f(seg[2*ind+1], seg[2*ind+2]);
     }
     
     
};



void solve(){
     int n;
     cin>>n;
     vector<int> a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     
     SGTree sg1(n);
    
     
     sg1.build(0, 0, n-1, a);
     
     
     int q;cin>>q;
     while(q--){
          int type;cin>>type;
          
          if(type == 1){
               int l,r;cin>>l>>r;
               cout<< sg1.query(0, 0, n-1, l, r)<<"\n";
          }
          else{
               int i,val;
               cin>>i>>val;
               sg1.update(0, 0, n-1, i, val);
               a[i]=val;
          }
     }
     
      
     
}

int main(){
     
     solve();

     
     return 0;
}
