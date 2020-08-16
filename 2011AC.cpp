#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	vector<int> e;
	for(int i=0;i<s.length();i++) e.push_back(s.at(i)-'0');
	vector<int> d(e.size()+1);
	d[0]=d[1]=(e[0]==0)?0:1;
	int ff=1;
	for(int i=2;i<=e.size() && ff;i++){
		if((e[i-2]==1 && e[i-1]!=0)||(e[i-2]==2 && (e[i-1]>0 && e[i-1]<7))) d[i]=(d[i-1]+d[i-2])%(int)1e6;
		else if((e[i-2]==1 || e[i-2]==2) && e[i-1]==0) d[i]=d[i-2];
		else if((e[i-2]==0 || e[i-2]>1) && e[i-1]!=0) d[i]=d[i-1];
		else ff=0;
	}
	if(ff=0) printf("0");
	else printf("%d", d[e.size()]);
	return 0;
}