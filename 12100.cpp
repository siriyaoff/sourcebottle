#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int isUnique(vector<vector<int>> mat){
	vector<int> vals(0, 1);
	for(int i=0;i<mat.size();i++) for(int j=0;j<mat[i].size();j++){
		if(mat[i][j]==0)
			continue;
		if(find(vals.begin(), vals.end(), mat[i][j])!=vals.end())
			return 0;
		else
			vals.push_back(mat[i][j]);
	}
	return 1;
}
int biggest(vector<vector<int>> mat){
	int M=-1;
	for(int i=0;i<mat.size();i++) for(int j=0;j<mat[i].size();j++)
		M=(M<mat[i][j])?mat[i][j]:M;
	return M;
}
int outofrange(pair<int, int> dest, int maxcoord){
	if(dest.first<0 || dest.first>=maxcoord || dest.second<0 || dest.second>=maxcoord)
		return 1;
	return 0;
}
vector<vector<int>> transpose(vector<vector<int>> curmat){
	vector<vector<int>> matt;
	for(int i=0;i<curmat[0].size();i++){
		vector<int> tmp(0, 0);
		matt.push_back(tmp);
	}
	
	for(int i=0;i<curmat.size();i++)
		for(int j=0;j<curmat[i].size();j++)
			matt[j].push_back(curmat[i][j]);
	return matt;
}

int refresh(vector<vector<int>>& mat){
	for(int i=0;i<mat.size();i++) for(int j=0;j<mat[i].size();j++)
		if(mat[i][j]<0)
			mat[i][j]*=-1;
	return 0;
}

int move(vector<vector<int>> curmat, vector<int> pcmd);

void printmat(vector<vector<int>> mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<int>> mat;
    for(int i=0;i<N;i++){
        vector<int> tmp;
        for(int j=0;j<N;j++){
            int t;
            scanf("%d", &t);
            tmp.push_back(t);
        }
        mat.push_back(tmp);
    }
	
    //0:up, 1:down, 2:left, 3:right
    vector<int> pcmd(5, 0);
	vector<vector<int>> curmat;
    int f=1, maxn=biggest(mat), cur;
	if(isUnique(mat)){
		printf("%d", maxn);
		return 0;
	}
	
	while(f){
		curmat=mat;
		cur=move(curmat, pcmd);
		if(cur>maxn){
			maxn=cur;
			
		}
		for(int i=pcmd.size()-1;i>=0;i--){
			pcmd[i]++;
			if(pcmd[i]==4){
				if(i==0)
					f=0;
				else
					pcmd[i]=0;
			}
			else
				break;
		}
	}
	printf("%d", maxn);
    return 0;
}

int move(vector<vector<int>> curmat, vector<int> pcmd){
	int curcmd=1;
	while(!pcmd.empty()){
		curcmd=pcmd.front();
		pcmd.erase(pcmd.begin());
		if(curcmd==0 || curcmd==1)
			curmat=transpose(curmat);
		
		if(curcmd==0 || curcmd==2){
			for(int i=0;i<curmat.size();i++){
				vector<int> tmp(1, 0);
				for(int j=0;j<curmat[i].size();j++){
					if(curmat[i][j]==0)
						continue;
					if(tmp.back()==0) tmp.back()=curmat[i][j];
					else if(tmp.back()==curmat[i][j])
						tmp.back()=curmat[i][j]*(-2);
					else
						tmp.push_back(curmat[i][j]);
				}
				if(tmp.size()!=curmat[i].size()){
					vector<int> adder(curmat[i].size()-tmp.size(), 0);
					curmat[i]=tmp;
					curmat[i].insert(curmat[i].end(), adder.begin(), adder.end());
				}
				else
					curmat[i]=tmp;
			}
		}
		else{
			for(int i=curmat.size()-1;i>-1;i--){
				vector<int> tmp(1, 0);
				for(int j=curmat[i].size()-1;j>-1;j--){
					if(curmat[i][j]==0)
						continue;
					if(tmp.front()==0) tmp.front()=curmat[i][j];
					else if(tmp.front()==curmat[i][j])
						tmp.front()=curmat[i][j]*(-2);
					else
						tmp.insert(tmp.begin(), curmat[i][j]);
				}
				if(tmp.size()!=curmat[i].size()){
					vector<int> adder(curmat[i].size()-tmp.size(), 0);
					curmat[i].clear();
					curmat[i]=adder;
					curmat[i].insert(curmat[i].end(), tmp.begin(), tmp.end());
				}
				else
					curmat[i]=tmp;
			}
		}
		if(curcmd==0 || curcmd==1)
			curmat=transpose(curmat);
		refresh(curmat);
	}
	return biggest(curmat);
}