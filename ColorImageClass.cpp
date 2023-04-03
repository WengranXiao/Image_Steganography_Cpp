#include <iostream>
#include <fstream>
using namespace std;

#include "ColorImageClass.h"
#include "constant.h"
#include "ColorClass.h"

ColorImageClass::ColorImageClass()
{
  imageMatrix = 0;
  rowInput = MIN_PIXEL;
  columnInput = MIN_PIXEL;
}

int ColorImageClass::getRow()
{
  return rowInput;
}

int ColorImageClass::getCol()
{
  return columnInput;
}

bool ColorImageClass::readColorImage(string fileName)
{
  ifstream inFile;
  int maxColor;
  int colIndex;
  int rowIndex;
  string MAGIC_NUM;
  ColorClass inColor;

  inFile.open(fileName.c_str());
  if (!inFile.fail())
  {
    inFile >> MAGIC_NUM >> columnInput >> rowInput >> maxColor;
    if (inFile.fail() || MAGIC_NUM != "P3" || columnInput > MAX_PIXEL 
        || rowInput > MAX_PIXEL || columnInput < MIN_PIXEL 
        || rowInput < MIN_PIXEL || maxColor != MAX_COLOR)
    {
      inFile.close();
      return false;
    }

    else{
      imageMatrix = new ColorClass * [rowInput];
      for (rowIndex = 0; rowIndex < rowInput; rowIndex ++)  
      {
        imageMatrix[rowIndex] = new ColorClass[columnInput];
        for (colIndex = 0; colIndex < columnInput; colIndex ++)
        {
          inColor.readRgb(inFile);
          if (inFile.fail() || !imageMatrix[rowIndex][colIndex].setTo(inColor))
          { 
            inFile.close();
            return false;                                  
          }
        }
      }
    }
    inFile.close();
    return true; 
  }
  return true;
}


void ColorImageClass::writeToFile(string fileName)
{
  ColorClass inColor;
  ofstream outFile;
  outFile.open(fileName.c_str());

  if (outFile.fail())
  {
    cout << "Fail to open file" << endl;
  }
  else
  {
    outFile << "P3" << endl;
    outFile << columnInput << " " << rowInput << endl;
    outFile << MAX_COLOR << endl;

    for (int row = 0; row < rowInput; row ++)
    {
      for (int col = 0; col < columnInput; col ++)
      {
        imageMatrix[row][col].writeRgb(outFile);   
      }
      outFile << endl;
    }
    cout << "Image write successful: Yes" << endl;
  }
}

void ColorImageClass::encodeImg(RowColClass msg)
{

  int encodeMsg;
  int rowIn;
  int colIn;

  for (rowIn = msg.getRowPl(); 
           rowIn < msg.getRowMsg() + msg.getRowPl();
           rowIn ++)
  {
    for (colIn = msg.getColPl();
             colIn < msg.getColMsg() + msg.getColPl();
             colIn ++)
    {
      if (rowIn < rowInput && colIn < columnInput &&
          rowIn >= MIN_PIXEL && colIn >= MIN_PIXEL)
      {
        encodeMsg = msg.getMessageInfo()[rowIn - msg.getRowPl()][colIn - msg.getColPl()];
        imageMatrix[rowIn][colIn].encodeColor(imageMatrix[rowIn]
                                                     [colIn], encodeMsg);
      }
    }
  }
}

void ColorImageClass::decodeImg()
{
  for (int row = 0; row < rowInput; row ++)
  {
    for (int col = 0; col < columnInput; col ++)
    {
      imageMatrix[row][col].decodeColor(imageMatrix[row][col]);
    }
  }
}
