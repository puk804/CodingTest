#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Map[5][9];
int newMap[5][9];
int is_rotate[5];
int K, Rst = 0;

void init(){
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 8; j++){
            scanf("%1d", &Map[i][j]);
        }
    }
    cin >> K;
}

void rotate(int x, int dir){
    is_rotate[x] = 1;
    if(dir == 1){
        newMap[x][1] = Map[x][8]; 
        for(int i = 1; i <= 7; i++){
            newMap[x][i+1] = Map[x][i];
        }
    } else {
        newMap[x][8] = Map[x][1];
        for(int i = 1; i<= 7; i++){
            newMap[x][i] = Map[x][i+1];
        }
    }
}

int reverse(int dir){
    if(dir == 1) return -1;
    return 1;
}

void start_rotate(int x, int dir){
    switch(x){
        case 1:
            rotate(1, dir);
            if(Map[1][3] != Map[2][7]){
                rotate(2, reverse(dir));
                if(Map[2][3] != Map[3][7]){
                    rotate(3, dir);
                    if(Map[3][3] != Map[4][7]){
                        rotate(4, reverse(dir));
                    }
                }
            }
            break;
        case 2:
            rotate(2, dir);
            if(Map[2][7] != Map[1][3]){
                rotate(1, reverse(dir));
            }
            if(Map[2][3] != Map[3][7]){
                rotate(3, reverse(dir));
                if(Map[3][3] != Map[4][7]){
                    rotate(4, dir);
                }
            }
            break;
        case 3:
            rotate(3, dir);
            if(Map[3][7] != Map[2][3]){
                rotate(2, reverse(dir));
                if(Map[2][7] != Map[1][3]){
                    rotate(1, dir);
                }
            }
            if(Map[3][3] != Map[4][7]){
                rotate(4, reverse(dir));
            }
            break;
        case 4:
            rotate(4, dir);
            if(Map[4][7] != Map[3][3]){
                rotate(3, reverse(dir));
                if(Map[3][7] != Map[2][3]){
                    rotate(2, dir);
                    if(Map[2][7] != Map[1][3]){
                        rotate(1, reverse(dir));
                    }
                }
            }     
    }
}

void update_map(){
    for(int i = 1; i <= 4; i++){
        if(is_rotate[i]){
            for(int j = 1; j <= 8; j++){
                Map[i][j] = newMap[i][j];
            }
        }
    } 
}

int main(){
    init();
    int start, dir;
    for(int iter = 0; iter < K; iter++){
        cin >> start >> dir;
        memset(is_rotate, 0, sizeof(is_rotate));
        memset(newMap, 0, sizeof(newMap));
        start_rotate(start, dir);
        update_map();
    }
    if(Map[1][1]) Rst += 1;
    if(Map[2][1]) Rst += 2;
    if(Map[3][1]) Rst += 4;
    if(Map[4][1]) Rst += 8;
    
    cout << Rst << endl;
}