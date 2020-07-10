#include<iostream>
#include<fstream>
#include<random>
#define PAIRS 10000
using namespace std;
int main()
{
	ofstream fout("input.txt");
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 20000);
	fout<<PAIRS<<endl;
	for(int i=0;i<PAIRS;i++)
		fout<<dis(gen)-10000<<" "<<dis(gen)-10000<<endl;
	
	fout.close();
	return 0;
}