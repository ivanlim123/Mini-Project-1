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

class Block {
public:
    Block(string name = "");
    int BlockMatrix[4][4];
    string type;
    int row, col;
};

class Matrix {
private:
    int row, col;
    int **array;
public:
    Matrix(int Row = 0, int Col = 0);
    void printOutput();
    void insertBlock(Block newBlock, int initCol);
    
};


void initArray(int **array, int row, int col);
void insertBlock(int **array, Block block, int initCol);
bool GameOver = false;

int main() {
    int row = 0, col = 0;
    cin>>row>>col;
    
    // 1-index array
    row += 1;
    col += 1;
    
    Matrix myMatrix(row, col);
    
    string name = "";
    int initCol = 0;
    while(cin>>name && name!="End" && !GameOver) {
        cin>>initCol;
        myMatrix.insertBlock(Block(name), initCol);
    }
    myMatrix.printOutput();
    return 0;
}

Block::Block(string name) {
    type = name;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            BlockMatrix[i][j] = 0;
        }
    }
    if(name[0] == 'T') {
        if(name == "T1") {
            BlockMatrix[2][0] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[2][2] = 1;
            BlockMatrix[3][1] = 1;
            row = 2;
            col = 3;
        }
        else if(name == "T2") {
            BlockMatrix[2][0] = 1;
            BlockMatrix[1][1] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][1] = 1;
            row = 3;
            col = 2;
        }
        else if(name == "T3") {
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[3][2] = 1;
            row = 2;
            col = 3;
        }
        else {
            BlockMatrix[1][0] = 1;
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[2][1] = 1;
            row = 3;
            col = 2;
        }
    }
    else if(name[0] == 'L') {
        if(name == "L1") {
            BlockMatrix[1][0] = 1;
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            row = 3;
            col = 2;
        }
        else if(name == "L2") {
            BlockMatrix[2][0] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[2][2] = 1;
            BlockMatrix[3][0] = 1;
            row = 2;
            col = 3;
        }
        else if(name == "L3") {
            BlockMatrix[1][0] = 1;
            BlockMatrix[1][1] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][1] = 1;
            row = 3;
            col = 2;
        }
        else {
            BlockMatrix[2][2] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[3][2] = 1;
            row = 2;
            col = 3;
        }
    }
    else if(name[0] == 'J') {
        if(name == "J1") {
            BlockMatrix[3][0] = 1;
            BlockMatrix[1][1] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][1] = 1;
            row = 3;
            col = 2;
        }
        else if(name == "J2") {
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[3][2] = 1;
            row = 2;
            col = 3;
        }
        else if(name == "J3") {
            BlockMatrix[1][0] = 1;
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[1][1] = 1;
            row = 3;
            col = 2;
        }
        else {
            BlockMatrix[2][0] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[2][2] = 1;
            BlockMatrix[3][2] = 1;
            row = 2;
            col = 3;
        }
    }
    else if(name[0] == 'S') {
        if(name == "S1") {
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[2][2] = 1;
            row = 2;
            col = 3;
        }
        else {
            BlockMatrix[1][0] = 1;
            BlockMatrix[2][0] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][1] = 1;
            row = 3;
            col = 2;
        }
    }
    else if(name[0] == 'Z') {
        if(name == "Z1") {
            BlockMatrix[2][0] = 1;
            BlockMatrix[2][1] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[3][2] = 1;
            row = 2;
            col = 3;
        }
        else {
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            BlockMatrix[1][1] = 1;
            BlockMatrix[2][1] = 1;
            row = 3;
            col = 2;
        }
    }
    else if(name[0] == 'I') {
        if(name == "I1") {
            BlockMatrix[0][0] = 1;
            BlockMatrix[1][0] = 1;
            BlockMatrix[2][0] = 1;
            BlockMatrix[3][0] = 1;
            row = 4;
            col = 1;
        }
        else {
            BlockMatrix[3][0] = 1;
            BlockMatrix[3][1] = 1;
            BlockMatrix[3][2] = 1;
            BlockMatrix[3][3] = 1;
            row = 1;
            col = 4;
        }
    }
    else if(name[0] == 'O') {
        BlockMatrix[2][0] = 1;
        BlockMatrix[2][1] = 1;
        BlockMatrix[3][0] = 1;
        BlockMatrix[3][1] = 1;
        row = 2;
        col = 2;
    }
}

Matrix::Matrix(int Row, int Col) {
    row = Row;
    col = Col;
    array = new int*[row];
    for(int i = 0; i < row; i++) {
        array[i] = new int[col];
    }
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }
}

void Matrix::printOutput() {
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            cout<<array[i][j];
        }
        cout<<endl;
    }
}

// insert block
void Matrix::insertBlock(Block newBlock, int initCol) {
    int curRow = 4;
    int blockRow = 3;
    bool isBottom = false;
    bool doesNotFit = false;
    int newArray[row][col];
    int lastArray[row][col];
    
    while(!doesNotFit && !isBottom) {
        // store array for last state
        for(int i = 0; i < newBlock.row; i++) {
            for(int j = 0; j < newBlock.col; j++) {
                lastArray[curRow-1-i][initCol+j] = newArray[curRow-1-i][initCol+j];
            }
        }
        
        // drop from top
        for(int i = 0; i < newBlock.row; i++) {
            for(int j = 0; j < newBlock.col; j++) {
                newArray[curRow-i][initCol+j] = array[curRow-i][initCol+j] + newBlock.BlockMatrix[blockRow-i][j];
                // check the validity of new array
                if(newArray[curRow-i][initCol+j] >= 2) {
                    doesNotFit = true;
                    curRow -= 1;
                    goto nextloop;
                }
            }
            // check if the line can be deleted
        }
        curRow += 1;
        // reach bottom boundary
        if(curRow==row) {
            isBottom = true;
            curRow -= 1;
        }
        nextloop: ;
        
        // check the current row less or equal than 0
        // check the current col is out of boundary
        
    }
    
    if(doesNotFit) {
        for(int i = 0; i < newBlock.row; i++) {
            for(int j = 0; j < newBlock.col; j++) {
                array[curRow-i][initCol+j] = lastArray[curRow-i][initCol+j];
            }
        }
    }
    else {
        for(int i = 0; i < newBlock.row; i++) {
            for(int j = 0; j < newBlock.col; j++) {
                array[curRow-i][initCol+j] = newArray[curRow-i][initCol+j];
            }
        }
    }
}


// delete block
