#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char **argv){
	string s, text="#include<bits/stdc++.h>\nusing namespace std;\ntypedef pair<int, int> pii;\ntypedef vector<int> vi;\ntypedef long long lld;\n\nint main(){\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\t\n\treturn 0;\n}\n";
	s.append(argv[1]);
	s.append(".cpp");
	ofstream code(s.c_str());
	if(code.is_open()) code.write(text.c_str(), text.length());
	code.close();
	return 0;
}