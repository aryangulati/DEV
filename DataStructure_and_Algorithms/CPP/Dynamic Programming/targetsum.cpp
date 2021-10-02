#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void solve();
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
     solve() ;  
}
  int countsum(vector<int> &nums,int sum){
        vector<vector<int>> dp(nums.size()+1,vector<int> (sum+1,0));
        for(int i=0;i<=nums.size();i++)
            dp[i][0]=0;
            dp[0][0]=1;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(j-nums[i-1]>=0)
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]]);
                else
                    dp[i][j]=dp[i-1][j];
            }
            debug(dp)
        }
        return dp[nums.size()][sum];
    }
 int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto c:nums)
            sum+=c;
        if(target>sum || (sum+target)&1)
            return 0;
        else 
            return countsum(nums,(sum+target)/2);
    }
  
void solve(){
    int t;
        cin>>t;
        vector<int> vec(9,0);
        for(int i=0;i<9;i++)
        cin>>vec[i];
        cout<<findTargetSumWays(vec,t);

}

