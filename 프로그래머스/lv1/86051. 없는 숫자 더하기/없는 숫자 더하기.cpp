#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(int i=0;numbers.size()>i;i++){
        answer -= numbers[i];
    }
    
    return answer;
}