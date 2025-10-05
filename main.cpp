#include <iostream>
#include <string>
#include <fstream>

int main(){
    int countRow, countColumn;
    float row, column, heigth;
    float maxRow, maxColumn;
    float incrementRow, increamentColumn;
    
    std::string sentence;
    std::ofstream Myfile("coordinates.dat");


    row=0;
    column=0;
    heigth=0;
    maxRow=1.01;
    maxColumn=1.01;
    incrementRow=0.1;
    increamentColumn=0.1;
    countRow=0;
    countColumn=0;
    for(row=0; row<=maxRow; row=row+incrementRow)
    {
        sentence="";
        countColumn=0;
        for(column=0; column<=maxColumn; column=column+increamentColumn){
           
            sentence = sentence + std::to_string(row) + "," + std::to_string(column) + "," + std::to_string(heigth) + " ,";
            countColumn++;
        };
        sentence= sentence +"\n";
        std::cout<< sentence<< std::endl;   

        Myfile<< sentence;
        countRow++;
    };
    Myfile<< countRow << "," << countColumn; 
    Myfile.close();
    return 0;

}