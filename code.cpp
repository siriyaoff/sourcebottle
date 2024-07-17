#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    string s, text =
                  ""
                  "#include<iostream>\n"
                  "#include<vector>\n"
                  "#include<utility>\n"
                  "#include<algorithm>\n\n"
                  "using namespace std;\n"
                  "using pii=pair<int, int>;\n"
                  "using vi=vector<int>;\n"
                  "using ll=long long;\n\n"
                  "int main(){\n"
                  "\tios::sync_with_stdio(0);\n"
                  "\tcin.tie(0), cout.tie(0);\n\n\n"
                  "\treturn 0;\n"
                  "}";
    s.append(argv[1]);
    s.append(".cpp");
    ofstream code(s.c_str());
    if (code.is_open()) code.write(text.c_str(), text.length());
    code.close();
    return 0;
}