#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

int getpow(int N){
	int pow=0;
	for(int i=10;i<1000000001;i*=10){
		if(N<i)
			break;
		pow++;
	}
	return pow;
}
int cnt(vector<int> prev, int N, vector<int>& digits);

int orgnpow;

int main()
{
	int N, pow=0;
	vector<int> ps(0, 0), digits(10, 0);
	vector<vector<int>> p;
	scanf("%d", &N);
	for(int i=1;i<10;i++)
		ps.push_back(i);
	p.push_back(ps);
	ps.insert(ps.begin(), 0);
	p.push_back(ps);//p[0]:[1, 9], p[1]:[0, 9]
	pow=getpow(N);
	orgnpow=pow;
	for(int i=0;i<pow;i++){//1234일 경우 999까지(1-9, 10-99, 100-999) 처리 완료
		vector<vector<int>> cur;
		cur.push_back(p[0]);
		for(int j=0;j<i;j++)
			cur.push_back(p[1]);
		for(int j=0;j<cur.size();j++){
			int multi=1, cindx=0;
			while(cindx!=cur.size()){
				if(cindx==j){
					cindx++;
					continue;
				}
				multi*=cur[cindx++].size();
			}
			for(int k=0;k<cur[j].size();k++)
				digits[cur[j][k]]+=multi;
		}
	}//위에 주석 치는거랑 cur constructed 나오는거랑 무슨상관? 치면 나오고 안치면 나옴
	//1000-1234
	vector<int> prev(0, 0);
	cnt(prev, N, digits);
	for(int i=0;i<digits.size();i++)
		printf("%d ", digits[i]);
	printf("\n");
	return 0;
}

int cnt(vector<int> prev, int N, vector<int>& digits){
	
	int pow=getpow(N), msd, exp=1;
	for(int i=0;i<pow;i++) exp*=10;
	msd=N/exp;
	if(N==0){
		if(prev.size()!=0 && orgnpow+1!=prev.size()){
			for(int i=0;i<prev.size();i++)
				digits[prev[i]]++;
			digits[0]++;
		}
		return 0;
	}
	for(int i=0;i<msd;i++){
		if(i==0 && prev.size()==0)
			continue;
		digits[i]+=exp;//msd번째에 추가
		if(prev.size()!=0){
			for(int j=0;j<prev.size();j++)
				digits[prev[j]]+=exp;
		}
		for(int i=0;i<digits.size();i++)
			digits[i]+=pow*exp/10;//digits전부에 추가
	}
	if(N%10==N){
		for(int i=0;i<prev.size();i++)
			digits[prev[i]]++;
		digits[msd]++;
	}
	
	prev.push_back(msd);
	int newN=N%exp, newpow=getpow(newN);
	for(int i=1;i<pow-newpow;i++)
		prev.push_back(0);
	cnt(prev, newN, digits);
	return 0;
}