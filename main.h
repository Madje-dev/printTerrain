#pragma once
#include <vector>
void WriteCoordinatesFile(float &row, float &column, float &heigth, float &maxRow, float &maxColumn, float &incrementRow, float &increamentColumn, int &countRow, int &countColumn);

void ReadCoordinates(int &countArrayRow, std::string &fileName, std::string &myText, int &countArrayColumn, std::stringstream &auxString, std::string &parsedCoordinates, std::vector<float> &tempArray, std::vector<std::vector<float>> &aPos);
