#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, string> pis;

bool cmp(pis p1, pis p2){
	return p1.first<p2.first;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<pis> s(n);
	for(int i=0;i<n;i++){
		scanf("%d ", &s[i].first);
		getline(cin, s[i].second, '\n');
	}
	stable_sort(s.begin(), s.end(), cmp);
	for(int i=0;i<n;i++) printf("%d %s\n", s[i].first, s[i].second.c_str());
}