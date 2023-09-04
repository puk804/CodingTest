#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    for(int i=0; i<skill_trees.size(); i++){
        vector<int> com;
        
        for(int j=0; j<skill_trees[i].size(); j++){
            for(int k=0; k<skill.size(); k++){
                if(skill_trees[i][j] == skill[k]){
                    com.push_back(skill_trees[i][j]);
                }
            }
        }
        
        for(int j=0; j<com.size(); j++){
            if(com[j] != skill[j]){
                answer--;
                break;
            }
        }
    }
    return answer;
}