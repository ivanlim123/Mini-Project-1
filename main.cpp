//
//  main.cpp
//  Mini Project 1 Tetris
//
//  Created by Ivan Lim on 08/10/2019.
//  Copyright © 2019 Ivan Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

#define MAX_INPUT_NUMBER 1010

using namespace std;

class Block {
public:
    Block(string name = "");
    int BlockMatrix[4][4];
    string type;
    int row, col;
};

class Matrix {
public:
    Matrix(int Row = 0, int Col = 0);
    void printOutput();
    void insertBlock(Block newBlock, int initCol);
    int row, col;
    int **array;
};

void initArray(int **array, int row, int col);
void insertBlock(int **array, Block block, int initCol);
bool GameOver = false;

int main() {
    ifstream InputFile;
    ofstream OutputFile;
    InputFile.open("Tetris.data");
    
    string line;
    string command[MAX_INPUT_NUMBER];
    int index = 0;
    
    if(InputFile.is_open()) {
        while(!InputFile.eof()) {
            getline(InputFile, line);
            command[index++] = line;
        }
        InputFile.close();
    }
    else {
        cout<<"Cannot open Input"<<endl;
    }
    
    int row = 0, col = 0;
    string first_line = command[0];
    string first = "";
    string second = "";
    bool skip = false;
    unsigned long len = first_line.length();
    for(unsigned long i = 0; i < len; i++) {
        char ch = first_line[i];
        if(ch==' ') {
            skip = true;
            continue;
        }
        if(!skip) {
            first.push_back(ch);
        }
        else {
            second.push_back(ch);
        }
    }
    row = stoi(first);
    col = stoi(second);
    
    // 1-index array
    row += 1;
    col += 1;
    
    Matrix myMatrix(row, col);
    
    for(int i = 1; i < index && !GameOver; i++) {
        string name = "";
        string column = "";
        int initCol = 0;
        
        bool space = false;
        string cmd = command[i];
        unsigned long cmd_len = cmd.length();
        for(unsigned long j = 0; j < cmd_len; j++) {
            char ch = cmd[j];
            if(ch==' ') {
                space = true;
                continue;
            }
            if(!space) {
                name.push_back(ch);
            }
            else {
                column.push_back(ch);
            }
        }
        if(name=="End") break;
        initCol = stoi(column);
        myMatrix.insertBlock(Block(name), initCol);
    }
    
    OutputFile.open("Tetris.output");
    if(OutputFile.is_open()) {
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                OutputFile<<myMatrix.array[i][j];
            }
            OutputFile<<endl;
        }
        OutputFile.close();
    }
    else {
        cout<<"Cannot open Output"<<endl;
    }
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
    int curRow = newBlock.row;
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
        
        // drop from row 1
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
        }
        curRow += 1;
        // reach bottom boundary
        if(curRow==row) {
            isBottom = true;
            curRow -= 1;
        }
        nextloop: ;
    }
    
    // check the current col is out of boundary
    // test case is invalid
    
    // check the current row less or equal than 0
    int lessRow = curRow;
    int lessBlockRow = blockRow;
    int leftBlockRow = newBlock.row;
    bool isCompleted = false;
    bool hasChecked = false;
    
    while(lessRow<=newBlock.row && doesNotFit) {
        while(!hasChecked) {
            // find the first row to place new element
            for(int i = 0; i < newBlock.row; i++) {
                for(int j = 0; j < newBlock.col; j++) {
                    if(lessRow-i==0) {
                        hasChecked = true;
                        goto checkFinished;
                    }
                    if(array[lessRow-i][initCol+j] + newBlock.BlockMatrix[lessBlockRow-i][j] >= 2) {
                        lessRow -= 1;
                        goto checkFinished;
                    }
                }
            }
            hasChecked = true;
            checkFinished: ;
        }
        
        if(lessRow<=0) {
            // check the completion of insertion
            if(leftBlockRow == 0) {
                isCompleted = true;
            }
            else {
                GameOver = true;
            }
            break;
        }
        
        // drop from outside
        bool hasFailed = false;
        for(int j = 0; j < newBlock.col; j++) {
            newArray[lessRow][initCol+j] = array[lessRow][initCol+j] + newBlock.BlockMatrix[lessBlockRow][j];
            // check the validity of new array
            if(newArray[lessRow][initCol+j] >= 2) {
                lessRow -= 1;
                hasFailed = true;
                break;
            }
        }
        if(!hasFailed) {
            // update row
            int lessCount = 0;
            for(int j = 0; j < newBlock.col; j++) {
                array[lessRow][initCol+j] = newArray[lessRow][initCol+j];
            }
            // check the deletion
            for(int j = 1; j < col; j++) {
                if(array[lessRow][j]==1) lessCount++;
            }
            if(lessCount == col-1) {
                for(int i = lessRow; i > 1; i--) {
                    for(int j = 1; j < col; j++) {
                        array[i][j] = array[i-1][j];
                    }
                }
                for(int j = 1; j < col; j++) {
                    array[1][j] = 0;
                }
            }
            else {
                lessRow -= 1;
            }
            
            lessBlockRow -= 1;
            leftBlockRow -= 1;
        }
    }
    
    if(!GameOver && !isCompleted) {
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
        
        // delete block
        // check if the line can be deleted
        int FirstRowDeleted = 0;
        int total_no = 0;
        for(int i = 0; i < newBlock.row; i++) {
            int count = 0;
            // one-index
            for(int j = 1; j < col; j++) {
                if(array[curRow-i][j] == 1) {
                    count++;
                }
            }
            if(count==col-1) {
                // set row that need to be deleted to -1
                for(int j = 1; j < col; j++) {
                    array[curRow-i][j] = -1;
                }
                if(FirstRowDeleted==0) FirstRowDeleted = curRow-i;
                total_no += 1;
            }
        }
        
        if(total_no!=0) {
            for(int i = FirstRowDeleted; i >= 1; i--) {
                bool isFounded = false;
                // find row that is -1
                while(array[i][1]!=-1) continue;
                for(int j = i - 1; j >= 1 && !isFounded; j--) {
                    // find row that is 0 or 1
                    if(array[j][1]==-1) continue;
                    for(int k = 1; k < col; k++) {
                        array[i][k] = array[j][k];
                        array[j][k] = -1;
                        isFounded = true;
                    }
                }
                
            }
            
            // set -1 to 0
            for(int i = total_no; i >= 1; i--) {
                for(int j = 1; j < col; j++) {
                    array[i][j] = 0;
                }
            }
        }
    }
}
