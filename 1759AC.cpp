#include<bits/stdc++.h>
using namespace std;

int L, C;
string res;

bool chk(string s){
	int vidx=0, cidx=0;
	for(char i:s){
		if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u') vidx++;
		else cidx++;
	}
	if(vidx>0 && cidx>1) return 1;
	else return 0;
}

void fn(vector<char>& ca, string s, int cidx){
	if(s.length()==L){
		if(chk(s)){
			res.append(s);
			res.push_back('\n');
		}
		return;
	}
	if(cidx==C) return;
	fn(ca, s+ca[cidx], cidx+1);
	fn(ca, s, cidx+1);
}

int main()
{
	cin>>L>>C;
	vector<char> ca(C);
	for(auto& i:ca) cin>>i;
	sort(ca.begin(), ca.end());
	fn(ca, "", 0);
	cout<<res;
}