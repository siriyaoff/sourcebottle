#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int orgn;
string s;
vector<int> m;

int calc(vector<int> indxs){
	int num=0;
	for(int i=0;i<indxs.size();i++)
		num+=m[indxs[i]]*pow(10, s.length()-i-1);
	//printf("calc num : %d\n", num);
	return num;
}
int cmp(vector<int> indxs, int cnt);

int main()
{
	int M, cnt;

	getline(cin, s);
	for(int i=0;i<s.length();i++)
		orgn+=(s.c_str()[i]-'0')*pow(10, s.length()-i-1);
	//orgn : N
	scanf("%d", &M);
	vector<int> tmp;
	for(int i=0;i<M;i++){
		int j;
		scanf("%d", &j);
		tmp.push_back(j);
	}
	sort(tmp.begin(), tmp.end());
	for(int i=0;i<10;i++){
		if(i==tmp[0]){
			tmp.erase(tmp.begin());
			continue;
		}
		m.push_back(i);
	}
	//m : vector of possible number buttons
	cnt=abs(orgn-100);//only by +/-
	
	vector<int> indxs(s.length(), 0);
	cnt=cmp(indxs, cnt);
	printf("%d", cnt);
	return 0;
}

int cmp(vector<int> indxs, int cnt){
	int newcnt=abs(calc(indxs)-orgn)+indxs.size(), f=0;
	for(int i=0;i<indxs.size();i++){
		if(indxs[i]!=0)
			break;
		newcnt--;
	}
	if(cnt>newcnt){
		cnt=newcnt;
//		for(int i=0;i<indxs.size();i++)
//			printf("%d ", indxs[i]);
//		printf("newcnt=%d, val=%d", newcnt, calc(indxs));
//		printf("\n");
	}
	for(int i=indxs.size()-1;i>=0;i--){
		if(indxs[i]+1==m.size()){
			if(i==0){
				f=1;
				break;
			}
			indxs[i]=0;
		}
		else{
			indxs[i]++;
			break;
		}
	}
	if(f)
		return cnt;
	else
		return cnt=cmp(indxs, cnt);
}
