//
//  main.cpp
//  Mini Project 1 Tetris
//
//  Created by Ivan Lim on 08/10/2019.
//  Copyright © 2019 Ivan Lim. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void initArray(int **array, int row, int col);

int main() {
    int row = 0, col = 0;
    cin>>row>>col;
    
    // 1-index array
    row += 1;
    col += 1;
    
    
    int **array = new int*[row];
    for(int i = 0; i < row; i++) {
        array[i] = new int[col];
    }
    initArray(array, row, col);
    
    string block = "";
    int initCol = 0;
    while(cin>>block>>initCol) {
        
    }
    
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            cout<<array[i][j];
        }
        cout<<endl;
    }
    return 0;
}

void initArray(int **array, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }
}
