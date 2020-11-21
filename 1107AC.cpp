#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int getpow(int n, int p);
int getd(int p);
int chkvld(vi& p, int l);
int vtoi(vi& digits, vi& r);

int main()
{
	int n, b;
	cin>>n>>b;
	vi bb(b), r, v;
	for(int i=0;i<b;i++) cin>>bb[i];
	if(!bb.empty()) sort(bb.begin(), bb.end());
	b=0;
	for(int i=0;i<10;i++){
		if(b<bb.size() && i==bb[b]){
			b++;
			continue;
		}
		r.push_back(i);
	}
	if(r.empty()){
		cout<<abs(n-100);
		return 0;
	}
	int ndigit=getd(n);
	for(int i=1;i<ndigit+2;i++){
		vi digits(i, 0);
		//cout<<i<<endl;
		while(chkvld(digits, r.size())){
			v.push_back(vtoi(digits, r));
			digits[0]++;//0 : digit of 1
		}
		if(v.back()>n) break;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	// for(int i:v) cout<<i<<" ";
	// cout<<endl;
	int lb=lower_bound(v.begin(), v.end(), n)-v.begin();
	if(v[lb]==n) cout<<((ndigit<abs(n-100))?ndigit:abs(n-100));
	else{
		int l=987654321, r, ans=abs(n-100);
		if(lb!=0) l=abs(v[lb-1]-n);
		l+=getd(v[lb-1]);
		r=abs(v[lb]-n);
		r+=getd(v[lb]);
		// cout<<l<<" "<<r<<endl;
		if(l>r) l=r;
		cout<<((l<ans)?l:ans);
	}
}

int getpow(int n, int p){
	int r=1;
	while(p--) r*=n;
	return r;
}

int getd(int p){
	int r=0;
	if(p==0) return 1;
	while(getpow(10, r)<=p) r++;
	return r;
}

int chkvld(vi& p, int l){
	for(int i=0;i<p.size()-1;i++){
		if(p[i]==l){
			p[i]=0;
			p[i+1]++;
		}
	}
	if(p.back()==l) return 0;
	else return 1;
}

int vtoi(vi& digits, vi& r){
	int res=0;
	for(int i=0;i<digits.size();i++) res+=r[digits[i]]*getpow(10, i);
	return res;
}

// #include<iostream>
// #include<cstdio>
// #include<string>
// #include<cmath>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> m;
// string s;
// int calc(vector<int> indxs){
//     int num=0;
//     for(int i=0;i<indxs.size();i++){
//         if(indxs[i]==-1) continue;
//         num+=m[indxs[i]]*pow(10, indxs.size()-i-1);
//     }
//     return num;
// }
// int digits(int newnum){
//     int i=1, cnt=0;
//     if(newnum==0)
//         return 1;
//     for(i;i<=newnum;i*=10)
//         cnt++;
//     return cnt;
// }
// int main()
// {
//     int M, cnt, orgn=0;
//     getline(cin, s);
//     for(int i=0;i<s.length();i++)
//         orgn+=(s.c_str()[i]-'0')*pow(10, s.length()-i-1);
//     //orgn : N
//     cnt=abs(orgn-100);//only by +/-
//     scanf("%d", &M);
//     for(int i=0;i<10;i++)
//         m.push_back(i);
//     for(int i=0;i<M;i++){
//         int j;
//         scanf("%d", &j);
//         m.erase(find(m.begin(), m.end(), j));
//     }
//     //m : vector of possible number buttons
//     if(m.size()==0){
//         printf("%d", cnt);
//         return 0;
//     }
    
//     int f=1;//search incompleted
//     vector<int> indxs(6, -1), vcmp(6, m.size()-1);
//     indxs[indxs.size()-1]=0;
//     while(f){
//         int newnum=calc(indxs), newcnt=abs(newnum-orgn)+digits(newnum);
//         if(cnt>newcnt) cnt=newcnt;
//         for(int i=indxs.size()-1;i>=0;i--){
//             if(++indxs[i]==m.size()){
//                 indxs[i]=0;
//                 if(i==0)
//                     f=0;
//             }
//             else break;
//         }
//     }
//     printf("%d", cnt);
//     return 0;
// } 