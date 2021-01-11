// //binary search, 1524ms
// #include<bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;

// int main()
// {
// 	ios::sync_with_stdio(false);cin.tie(0);
// 	int n, a[4000], b[4000], c[4000], d[4000];
// 	long long cnt=0;
// 	vi vab;
// 	cin>>n;
// 	for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
// 	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
// 		vab.push_back(a[i]+b[j]);
// 	sort(vab.begin(), vab.end());
// 	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
// 		int ps=c[i]+d[j];
// 		cnt+=upper_bound(vab.begin(), vab.end(), -ps)-lower_bound(vab.begin(), vab.end(), -ps);
// 	}
// 	cout<<cnt;
// }

//Two pointers, 952ms
#include<bits/stdc++.h>
using namespace std;
int n, abi=1, a[4000], b[4000], c[4000], d[4000], ab[16000002], cd[16000001];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long long cnt=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		ab[abi]=a[i]+b[j];
		cd[abi++]=c[i]+d[j];
	}
	sort(ab+1, ab+abi);
	sort(cd+1, cd+abi);
	ab[abi]=300000000;
	cd[0]=-300000000;
	int i=1, j=abi-1, sum=ab[i]+cd[j];
	while(i<abi && j>0){
		if(sum==0){
			long long abn=1, cdn=1;
			while(ab[i]==ab[++i]) abn++;
			while(cd[j]==cd[--j]) cdn++;
			cnt+=abn*cdn;
			sum=ab[i]+cd[j];
		}
		else if(sum>0) while(sum>0) sum=ab[i]+cd[--j];
		else while(sum<0) sum=ab[++i]+cd[j];
	}
	cout<<cnt;
}