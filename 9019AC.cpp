#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, ns, ne, v[10000];
	string res;
	cin>>t;
	while(t--){
		cin>>ns>>ne;
		for(int i=0;i<10000;i++) v[i]=987654321;
		v[ns]=0;
		queue<pair<int, string>> q;
		q.push({ns, string()});
		while(!q.empty()){
			int cur=q.front().first;
			string cmd=q.front().second;
			if(cur==ne){
				res=res+cmd+'\n';
				break;
			}
			for(int i=0;i<4;i++){
				int t=cur;
				if(i==0){
					if(2*t>9999) t= 2*t%10000;
					else t= 2*t;
				}
				else if(i==1){
					if(t<1) t= 9999;
					else t= t-1;
				}
				else if(i==2){
					int tt=t/1000;
					t=t%1000*10+tt;
				}
				else{
					int tt=t%10;
					t=t/10+1000*tt;
				}
				if(v[t]==987654321){
					v[t]=v[cur]+1;
					q.push({t, cmd+"DSLR"[i]});
				}
			}
			q.pop();
		}
	}
	cout<<res;
}

//????????????????????????
// #include<stdio.h>
// #include<vector>
// using namespace std;

// vector<pair<int, int>>inp[10000];
// vector<vector<char>>ans;

// int update[10000];
// int dist[10001];
// int path[10000];
// int chk[10000];
// int que[10010], idx1, idx2;
// char chr[4] = { 'D', 'S', 'L', 'R' };

// int main() {
// 	int t;
// 	scanf("%d", &t);
// 	ans.resize(t);
// 	for (int i = 0; i < t; i++) {
// 		int a, b;
// 		scanf("%d %d", &a, &b);
// 		inp[a].push_back(make_pair(b, i));
// 	}
// 	for (int i = 0; i < 10000; i++) {
// 		if (inp[i].size() == 0)continue;
// 		int num = 0;
// 		for (int j = 0; j < inp[i].size(); j++) {
// 			if (!chk[inp[i][j].first]) {
// 				num++;
// 				chk[inp[i][j].first] = 1;
// 			}
// 		}
// 		dist[i] = path[i] = 0;
// 		update[i] = i + 1;
// 		idx1 = idx2 = 0;
// 		que[idx1++] = i;
// 		while (num) {
// 			int no = que[idx2++];
// 			int lst[4] = { no << 1, no ? no - 1 : 9999, no % 1000 * 10 + no / 1000 , no / 10 + no % 10 * 1000 };
// 			if (lst[0] >= 10000)lst[0] -= 10000;
// 			for (int j = 0; j < 4; j++) {
// 				if (update[lst[j]] != i + 1) {
// 					update[lst[j]] = i + 1;
// 					if (chk[lst[j]]) {
// 						num--; chk[lst[j]] = 0;
// 					}
// 					dist[lst[j]] = dist[no] + 1;
// 					path[lst[j]] = no * 10 + j + 1;
// 					que[idx1++] = lst[j];
// 				}
// 			}
// 		}
// 		for (int j = 0; j < inp[i].size(); j++) {
// 			int m = inp[i][j].first;
// 			int idx = inp[i][j].second;
// 			while (path[m]) {
// 				ans[idx].push_back(chr[path[m] % 10 - 1]);
// 				m = path[m] / 10;
// 			}
// 		}
// 	}
// 	for (auto& i : ans) {
// 		for (int j = i.size() - 1; j >= 0; j--) {
// 			printf("%c", i[j]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }