#include<cstdio>
#include<vector>

using namespace std;

int lcs(int ip1, int ip2);

int n;
vector<int> p1, p2;

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		p1.push_back(t);
	}
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		p2.push_back(t);
	}
	printf("%d", lcs(n-1, n-1));
	return 0;
}

int lcs(int ip1, int ip2){
	if(ip1==-1 || ip2==-1)
		return 0;
	if(p1[ip1]==p2[ip2])
		return lcs(ip1-1, ip2-1)+1;
	int l1=lcs(ip1, ip2-1), l2=lcs(ip1-1, ip2);
	return (l1>l2)?l1:l2;
}