#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int left= 0;

    for(int i=0; i<s.size(); i++){    
        if(s[i] == '(') left++;
        else left--;

        if(left==-1) return false;
    }

    if(left == 0) return answer;
    else return false;
}
