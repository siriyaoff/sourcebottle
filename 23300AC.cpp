#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
using vi=vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, c=-1;
	char cmd;
	cin>>n>>q;
	stack<int> prev, next;
	while(q--){
		cin>>cmd;
		if(cmd=='B'){
			if(prev.size()==0) continue;
			next.push(c);
			c=prev.top();
			prev.pop();
		}
		else if(cmd=='F'){
			if(next.size()==0) continue;
			prev.push(c);
			c=next.top();
			next.pop();
		}
		else if(cmd=='A'){
			int to;
			cin>>to;
			while(!next.empty()) next.pop();
			if(c!=-1) prev.push(c);
			c=to;
		}
		else{
			int tmp, l=prev.size();
			stack<int> tt;
			for(int i=0;i<l;i++){
				tmp=prev.top();
				if(!tt.size()) tt.push(tmp);
				else if(tt.size() && tmp!=tt.top()) tt.push(tmp);
				prev.pop();
			}
			l=tt.size();
			for(int i=0;i<l;i++){
				prev.push(tt.top());
				tt.pop();
			}
		}
	}
	cout<<c<<'\n';
	if(prev.size()){
		int l=prev.size();
		for(int i=0;i<l;i++){
			cout<<prev.top()<<' ';
			prev.pop();
		}
	}
	else cout<<-1;
	cout<<'\n';
	if(next.size()){
		int l=next.size();
		for(int i=0;i<l;i++){
			cout<<next.top()<<' ';
			next.pop();
		}
	}
	else cout<<-1;
	return 0;
}