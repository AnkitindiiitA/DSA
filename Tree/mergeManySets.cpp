problem link: https://cses.fi/problemset/task/1139/
time complexity: n*(logn)^2
explaination: When you merge two sets, you only move the elements from the smaller set to the larger one. 
This way if the two sets are S1 and S2, such that |S1| < |S2|, then the resulting set will be of size |S1 + S2| ≥ 2 * |S1|. 
From this we see that when we merge two sets, we move the elements from one of the sets to another one, which is at least twice as large. 
Well obviously we have a finite number of elements in the sets so this process will end. Well if every time we double the size of the 
component of an element then we will move each element at most  times and this way we achieve  O(NlogN) amortized complexity.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define end1 "\n"
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
const int M = 1e9 + 7;
const int mod = 998244353;
#define inf 1000000000000000005
#define precise(x) cout << fixed << setprecision(10) << x << endl;
#define ff first
#define ss second
#define mp make_pair
#define mone cout<<-1<<endl

// int noOfSetBits(int n){
//     return __builtin_popcount(n);
// }
// int fastExponentiation(int a,int n){
//     // does the fast calc of a to the power n
//     int ans=1;
//     while(n>0){
//         int last_bit=n&1;
//         if(last_bit){
//             ans=a*ans;
//         }
//         a=a*a;
//         n=n>>1;
//     }
//     return ans;
// }

// int  decimalToBinary(int n){
//     int ans=0;
//     int p=1;
//     while(n>0){
//         int last_bit=(n&1);
//         ans+=p*last_bit;
//         p=p*10;
//         n=n>>1;
//     }
//     return ans;
// }

// bool IsPowerOfTwo(int n){
//     return (((n&(n-1))==0)?1:0);
// }
// bool isPrime(int n){
// 	vector<bool> prime(n+1,true);
    
  
//     for (int p=2; p*p<=n; p++)
//     {
        
//         if (prime[p] == true)
//         {
            
//             for (int i=p*2; i<=n; i += p)
//                 prime[i] = false;
//         }
//     }
//     return prime[n];
// }
// int gcd(int a, int b)
// {
//   return b ? gcd(b, a % b) : a;
// }

// int factorial(int n)
// {
//     return (n==1 || n==0) ? 1: n * factorial(n - 1);
// }

// bool isSorted(int a[], int n)
// {
//   if (n == 0 || n == 1)
//     return true;
 
//   for (int i = 1; i < n; i++){
//     if (a[i - 1] > a[i]){
//       return false;
//     }
//   }
 
//   return true;
// }
// bool isPerfectSquare(long double x)
// {
//     // Find floating point value of
//     // square root of x.
//     if (x >= 0) {
 
//         long long sr = sqrt(x);
         
//         // if product of square root
//         //is equal, then
//         // return T/F
//         return (sr * sr == x);
//     }
//     // else return false if n<0
//     return false;
// }
set<int> colors[200001];
vector<int> adj[200001];
vector<int> dcount(200001,0);

void pre_process(int node, int par=0){
    for(auto &ch:adj[node]){
        if(ch!=par){
            pre_process(ch, node);

            if(colors[node].size() < colors[ch].size()){
                swap(colors[node], colors[ch]);
            }

            for(auto &it:colors[ch]){
                colors[node].insert(it);
            }
        }
    }

    dcount[node] = colors[node].size();
}

void solve(){
    int n;cin>>n;

    for(int i=1;i<=n;i++){
        int a;cin>>a;
        colors[i].insert(a);
    }

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre_process(1);

    for(int i=1;i<=n;i++)cout<<dcount[i]<<' ';
    cout<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    #endif
    int t=1;
    //cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}
