#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count;
    
    for(int i=0; i<prices.size()-1; i++){
        count = 1;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i]>prices[j]){
                answer.push_back(count);
                j=prices.size();
            }
            else{
                count++;
                if(j==prices.size()-1){
                    answer.push_back(count-1);
                }
            }
        }
    }
    answer.push_back(0);
    return answer;
}