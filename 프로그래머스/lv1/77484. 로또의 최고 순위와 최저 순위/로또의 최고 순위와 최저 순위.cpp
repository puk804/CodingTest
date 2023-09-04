#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int num = 7;
    
    for(int i=0; i<6; i++){
        if(lottos[i] == 0){
            zero += 1;
        } 
        else{
            for(int j=0;j<6;j++){
             if(lottos[i] == win_nums[j]){
                 num -= 1;
             }
            }
        }
    }
    if(num-zero == 7)answer.push_back(6);
    else answer.push_back(num-zero);
    
    if (num ==7) num =6;
    
    answer.push_back(num);
   
    return answer;
}