//O(N^2logN)
//모든 i에 대해 먼저 lis(0, i), lds(i, n-1)을 먼저 구해놓고 같은 i에 대해 두개의 길이를 더해서 비교한다면 nlogn도 가능할듯
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int lds(vector<int>& v);

int main()
{
	int n, piv=0, mlen=0;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(piv=0;piv<n;piv++){
		vector<int> v1(a.begin(), a.begin()+piv+1), v2(a.begin()+piv, a.end());
		reverse(v1.begin(), v1.end());
		int curlen=lds(v1)+lds(v2);
		if(mlen<curlen-1) mlen=curlen-1;
	}
	printf("%d", mlen);
	return 0;
}

int lds(vector<int>& v){
	int idx=0;
	vector<int> ldsa(v.size(), -1);
	ldsa[idx++]=v[0];
	for(int i=1;i<v.size();i++){
		if(v[i]>ldsa[0]) continue;
		int cidx=lower_bound(ldsa.begin(), ldsa.end(), v[i], greater<int>())-ldsa.begin();
		if(ldsa[cidx]==-1) idx++;
		ldsa[cidx]=v[i];
	}
	return idx;
}