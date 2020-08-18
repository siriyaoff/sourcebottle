// #include<cstdio>
// #include<iostream>
// #include<string>
// #include<vector>
// #include<utility>
// #include<algorithm>
// using namespace std;
// typedef pair<string, pair<int, pair<int, int>>> stds;

// bool cmp(stds s1, stds s2){
// 	if(s1.second==s2.second) return s1.first<s2.first;
// 	if(s1.second.first==s2.second.first){
// 		if(s1.second.second.first==s2.second.second.first) return s1.second.second.second>s2.second.second.second;
// 		else return s1.second.second.first<s2.second.second.first;
// 	}
// 	else return s1.second.first>s2.second.first;
// }

// int main()
// {
// 	int n;
// 	scanf("%d\n", &n);
// 	vector<stds> s(n);
// 	for(int i=0;i<n;i++) 	cin>>s[i].first>>s[i].second.first>>s[i].second.second.first>>s[i].second.second.second;
	
// 	sort(s.begin(), s.end(), cmp);
// 	for(int i=0;i<n;i++) printf("%s\n", s[i].first.c_str());
// }

// #include <tuple>
// #include <string>
// #include <iostream>

// void print(std::tuple<int, bool> tVal)
// {
// 	std::cout << std::get<0>(tVal) << ", " << std::get<1>(tVal) << std::endl;
// }

// int main()
// {
// 	// make tuple variable.
// 	typedef std::tuple<int, std::string, bool> OddOrEven;
// 	OddOrEven myNumber1 = std::make_tuple(10, std::string("Even"), true);
// 	OddOrEven myNumber2 = std::make_tuple(7, std::string("Odd"), false);

// 	// std::tie() and std::ignore.
// 	int nVal;
// 	bool bEven;

// 	std::tie(nVal, std::ignore, bEven) = myNumber1;
// 	std::cout << nVal << ", " << bEven << std::endl;

// 	// tuple_cat function.
// 	auto myNums = std::tuple_cat(myNumber1, myNumber2);

// 	std::cout << "Value 1 : " << std::get<0>(myNums) << ", " << std::get<1>(myNums) << ", " << std::get<2>(myNums) << std::endl;
// 	std::cout << "Value 2 : " << std::get<3>(myNums) << ", " << std::get<4>(myNums) << ", " << std::get<5>(myNums) << std::endl;

// 	// foward_as_tuple
// 	print(std::forward_as_tuple(nVal, bEven));

// 	return 0;
// }

#include<tuple>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef tuple<int, int, int, string> stds;

int main()
{
	int n;
	cin>>n;
	vector<stds> s(n);
	for(int i=0;i<n;i++){
		string st;
		int a, b, c;
		cin>>st>>a>>b>>c;
		s[i]=make_tuple(-a, b, -c, st);
	}
	sort(s.begin(), s.end());
	for(auto it:s) cout<<get<3>(it)<<'\n';
}