#include <iostream>
#include <string>
#include <fstream>
#include "main.h"

int main(){
    int countRow, countColumn;
    float row, column, heigth;
    float maxRow, maxColumn;
    float incrementRow, increamentColumn;
    std::string myText;
    std::ifstream MyReadFile("coordinates.dat");

//    WriteCoordinatesFile(row, column, heigth, maxRow, maxColumn, incrementRow, increamentColumn, countRow, countColumn);

    while(std::getline(MyReadFile, myText)){
        std::cout<<myText<< "\n "<<std::endl;
        
    }


    return 0;
}



void WriteCoordinatesFile(float &row, float &column, float &heigth, float &maxRow, float &maxColumn, float &incrementRow, float &increamentColumn, int &countRow, int &countColumn)
{
    std::string sentence;
    std::ofstream Myfile("coordinates.dat");
    row = 0;
    column = 0;
    heigth = 0;
    maxRow = 1.0;
    maxColumn = 1.01;
    incrementRow = 0.1;
    increamentColumn = 0.1;
    countRow = 0;
    countColumn = 0;
    for (row = maxRow; row >= -0.1; row = row - incrementRow)
    {
        sentence = "";
        countColumn = 0;
        for (column = 0; column <= maxColumn; column = column + increamentColumn)
        {

            sentence = sentence + std::to_string(row) + "," + std::to_string(column) + "," + std::to_string(heigth) + " ,";
            countColumn++;
        };
        sentence = sentence + "\n";
        std::cout << sentence << std::endl;

        Myfile << sentence;
        countRow++;
    };
    Myfile << countRow << "," << countColumn;
    Myfile.close();
}