#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<int> vi;

int n, all1=0;

int solve(vi& rows, int row){
	if(row==n){
		int cnt=0;
		for(int i=0;i<n;i++){
			int tcnt=0;
			for(int j=0;j<n;j++){
				tcnt+=!(rows[j]&(1<<(n-i-1)));
			}
			cnt+=(tcnt>n/2)?n-tcnt:tcnt;
		}
		return cnt;
	}

	int nrow=solve(rows, row+1), yrow;
	rows[row]=rows[row]^all1;
	yrow=solve(rows, row+1);
	return (nrow>yrow)?yrow:nrow;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) all1|=1<<i;
	string s;
	vi rows(n, 0);
	
	for(int i=0;i<n;i++){
		int cnt=0;
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='H') rows[i]|=(1<<(n-j-1));
		}
	}
	cout<<solve(rows, 0);
	return 0;
}