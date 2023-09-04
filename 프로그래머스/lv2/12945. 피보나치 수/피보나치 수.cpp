#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer,i = 0;
    long box[100000] = {};
    box[0]=0;
    box[1]=1;
    
    for(i=0; i<n;i++){
        box[i+2] = (box[i]+box[i+1])%1234567;
    }
    answer=box[n];
    return answer;
}