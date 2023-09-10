#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> data;
    int year;
    
    for(int i=0; i<name.size(); ++i){
        data.insert({name[i], yearning[i]});    
    }
    
    for(int i=0; i<photo.size(); ++i){
        year = 0;
        for(int j = 0; j<photo[i].size(); ++j){
            year += data[photo[i][j]];
        }
        answer.push_back(year);
    } 
    
    return answer;
}