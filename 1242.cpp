#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	vector<int> p;
	for(int i=1;i<=N;i++) p.push_back(i);
	
	K--;
	int pos=0, cur=-1, cnt=0;
	while(cur!=M){
		pos=(pos+K)%p.size();
		cur=p[pos];
		p.erase(p.begin()+pos);
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}