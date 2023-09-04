using namespace std;

long long solution(int price, int money, int count)
{
    long answer = -1;
    long sub = 0;
    
    for(int i=0; i<count; i++){
        sub = sub + price*(i+1);    
    }
    answer = sub-money;
    if(answer<=0)return 0;
    else return answer;
    
   
}