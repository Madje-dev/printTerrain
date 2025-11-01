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
    std::string myText, parsedCoordinates, fileName;
    std::stringstream auxString; 
    std::vector<std::vector<float>> aPos;
    std::vector<float> tempArray;
    std::vector<int> indiceArray;
    std::string indiceFileName;

    fileName = "coordinates.dat";
    indiceFileName = "indices.dat";

    //WriteCoordinatesFile(row, column, heigth, maxRow, maxColumn, incrementRow, increamentColumn, countRow, countColumn);
    ReadCoordinates(countArrayRow, fileName , myText, countArrayColumn, auxString, parsedCoordinates, tempArray, aPos);
    writeIndices(indiceArray, countArrayRow, countArrayColumn, indiceFileName);


      return 0;
}

void ReadCoordinates(int &countArrayRow, std::string &fileName, std::string &myText, int &countArrayColumn, std::stringstream &auxString, std::string &parsedCoordinates, std::vector<float> &tempArray, std::vector<std::vector<float>> &aPos)
{
    countArrayRow = 0;
    countArrayColumn=0;
    int reset=0;
    std::ifstream MyReadFile;
    MyReadFile.open(fileName);
    
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
            //std::cout << val << " ";
        }
        //std::cout << std::endl;
    }
    countArrayRow++;
    std::cout<< countArrayRow << "x" <<countArrayColumn<< std::endl;
    MyReadFile.close();
}

void WriteCoordinatesFile(float &row, float &column, float &heigth, float &maxRow, float &maxColumn, float &incrementRow, float &increamentColumn, int &countRow, int &countColumn)
{
    float delta=0.01;
    std::string sentence;
    std::ofstream Myfile("coordinates.dat");
    row = 0;
    column = 0;
    heigth = 0;
    maxRow = 1.0;
    maxColumn = 1.01;
    incrementRow = 0.01;
    increamentColumn = 0.01;
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

        if(row-incrementRow<=-delta){
                sentence = sentence;
        }
        else{
                sentence = sentence + " \n";
        }
        
        //std::cout << sentence << std::endl;

        Myfile << sentence;
        countRow++;
    };
    Myfile.close();
}



void writeIndices(std::vector<int> indiceArray, int row, int column, std::string indiceFileName){
    std::ofstream MyFile;
    int totalIndices;
    int m, n, i, j;
    int verticeNumber, reBasedI, lineAbove;
    m=row-1;
    n=column-1;
    
    for (i=0; i<m; i++){
        for ( j=0; j<n; j++){
            if(i==0){
                reBasedI=0;
            }else{
                reBasedI=column*i;
            }
            lineAbove=reBasedI+column;
            verticeNumber = reBasedI+j;
            indiceArray.push_back(verticeNumber);
            indiceArray.push_back(lineAbove+j);
            indiceArray.push_back(verticeNumber+1);
            
            indiceArray.push_back(verticeNumber+1);
            indiceArray.push_back(lineAbove+j+1);
            indiceArray.push_back(lineAbove+j);
            

        }
        std::cout << "i = "<< i << "; j = " << j << std::endl;
    }
    
    
    
    
    
    MyFile.open(indiceFileName);
    std::cout<< indiceArray.size()<< std:: endl;
    for(int i=0; i<=(indiceArray.size()-1); i=i+3){
        
        MyFile<<std::to_string(indiceArray[i]);
        MyFile<< ",";
        MyFile<<std::to_string(indiceArray[i+1]);
        MyFile<< ",";
        MyFile<<std::to_string(indiceArray[i+2]);
        MyFile<< ";";
        if(i!=indiceArray.size()-3){
        MyFile<< "\n";
        }



    }

    MyFile.close();

}
