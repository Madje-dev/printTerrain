#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "main.h"
#include <cstdlib>
#include <vector>

int main(){
    int countRow, countColumn, count;
    int countArrayColumn, countArrayRow;
    float row, column, heigth;
    float maxRow, maxColumn;
    float incrementRow, increamentColumn;
    std::string myText, parsedCoordinates;
    std::stringstream auxString; 
    std::vector<std::vector<float>> aPos;
    std::vector<float> tempArray;

    //WriteCoordinatesFile(row, column, heigth, maxRow, maxColumn, incrementRow, increamentColumn, countRow, countColumn);
      std::ifstream MyReadFile("coordinates.dat");
      ReadCoordinates(countArrayRow, MyReadFile, myText, countArrayColumn, auxString, parsedCoordinates, tempArray, aPos);


      return 0;
}

void ReadCoordinates(int &countArrayRow, std::ifstream &MyReadFile, std::string &myText, int &countArrayColumn, std::stringstream &auxString, std::string &parsedCoordinates, std::vector<float> &tempArray, std::vector<std::vector<float>> &aPos)
{
    countArrayRow = 0;
    countArrayColumn=0;
    int reset=0;

    while (std::getline(MyReadFile, myText, ' '))
    {
        // std::cout<<myText<< "\n ";
        
        auxString << myText;
        if(myText == ""){
            countArrayRow++;
            reset=1;
            
        }
        while (std::getline(auxString, parsedCoordinates, ','))
        {

            tempArray.push_back(std::stof(parsedCoordinates));
        }
        aPos.push_back(tempArray);

        tempArray.clear();
        auxString.clear();
        if(!reset){
            countArrayColumn++;
        }
        
    }

    for (const auto &row1 : aPos)
    {
        for (float val : row1)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout<< countArrayRow << "x" <<countArrayColumn<< std::endl;
}

void WriteCoordinatesFile(float &row, float &column, float &heigth, float &maxRow, float &maxColumn, float &incrementRow, float &increamentColumn, int &countRow, int &countColumn)
{
    float delta=0.001;
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
    
    for (row = maxRow; row >= -delta; row = row - incrementRow)
    {
        sentence = "";
        countColumn = 0;
        for (column = 0; column <= maxColumn; column = column + increamentColumn)
        {

            sentence = sentence + std::to_string(row) + "," + std::to_string(column) + "," + std::to_string(heigth) + ", ";
            countColumn++;
        };
        sentence = sentence + " \n";
        std::cout << sentence << std::endl;

        Myfile << sentence;
        countRow++;
    };
    Myfile.close();
}