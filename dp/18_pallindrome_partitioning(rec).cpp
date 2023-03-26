#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

bool isPallindrome(string s, int i, int j){

	int cnt=0;

	while(i<=j){
		if(s[i]!=s[j]){
			cnt++;
			break;
		}
		i++;
		j--;
	}

	if(cnt==1) return false;
	return true;

}

int solve(string s, int i, int j,vector<string>&v){
	if(i==j){
		string ans="";
		ans+=s[i];
		v.push_back(ans);
	}

	if(i>=j) return 0;

	if(isPallindrome(s,i,j)){ 
		string ans="";
		for(int l=i;l<=j;l++){
			ans+=s[l];
		}

		v.push_back(ans);
		return 0;

	}

	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++){
		int temp= 1+solve(s,i,k,v)+solve(s,k+1,j,v);
		
		mn=min(mn,temp);
	}

	return mn;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s; cin>>s;
    vector<string>v;
    int a= solve(s,0,s.length()-1,v);

    set<string>se;

    for(int i=0;i<v.size();i++){
    	se.insert(v[i]);
    }
    vector<string>ans;
    for(auto x: se){
    	ans.push_back(x);
    }
    

    

    
    
    return 0;
}