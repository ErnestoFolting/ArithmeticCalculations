#include <string>
#include <iostream>

using namespace std;

string getInput(int argc, char* argv[]) {
    string str;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            str += argv[i][j];
        }
    }
    return str;
}

string token(string& str) {
    int k = 0;
    string tock;
    while (isdigit(str[k])) {
        k++;
    }
    if (k == 0) {
        tock = str.substr(0, 1);
        str.erase(0, 1);
    }
    else {
        tock = str.substr(0, k);
        str.erase(0, k);
    }
    return tock;
}

void replaceUnaryOperationsWithSymbols(string & str)
{
	if(str[0]=='-')
	{
		str[0]='m';
	}
	else if(str[0]=='+')
	{
		str[0]='p';
	}
	for(int i=0;i<static_cast<int>(str.length())-1;i++)
	{
        if(((str[i]=='(')||(str[i]=='*')||(str[i]=='/')||(str[i]=='-')||(str[i]=='+')||(str[i]=='m')||(str[i]=='p'))&&(str[i+1]=='-'))
	    {
		    str[i+1]='m';
	    }
        else if(((str[i]=='(')||(str[i]=='*')||(str[i]=='/')||(str[i]=='-')||(str[i]=='+')||(str[i]=='m')||(str[i]=='p'))&&(str[i+1]=='+'))
	    {
		    str[i+1]='p';
	    }
	}
}