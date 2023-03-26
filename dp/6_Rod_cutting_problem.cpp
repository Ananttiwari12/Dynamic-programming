 #include<bits/stdc++.h>
 #define endl "\n"
 using namespace std;
 #define mod 1000000007
 #define int long long
 
 int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }


   int length[n];
   
   for(int i=0;i<n;i++){
       length[i]=i+1;
   }
   
   int dp[n+1][n+1];
   for(int i=0;i<=n;i++){
       dp[i][0]=0;
   }
   for(int i=0;i<=n;i++){
       dp[0][i]=0;
   }
   
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(length[i-1]<=j){
               dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
           }
           else{
               dp[i][j]= dp[i-1][j];
           }
       }
   }
    cout<<dp[n][n];
   
    return 0;
 }
