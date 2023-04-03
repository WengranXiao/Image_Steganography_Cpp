#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "constant.h"
#include "ColorClass.h"
#include "RowColClass.h"

RowColClass::RowColClass(int row, int col, int rowM, int colM)
{
  messageInfo = NULL;
  rowPl = row;
  colPl = col;
  rowMsg = rowM;
  colMsg = colM;
}

bool RowColClass::readMsg(const int rowInput, const int columnInput, int rowPl, 
                       int colPl, int rowM, int colM, string theFileName)
{
  int rowIn;
  int colIn;
  int encodeMsg;

  string eofTesting;
  ifstream inFile;

  inFile.open(theFileName.c_str());
  inFile >> colMsg >> rowMsg;   

  messageInfo = new int * [rowMsg];

  for (rowIn = 0; rowIn < rowMsg; rowIn ++)
  {
    messageInfo[rowIn] = new int[colMsg];
    for (colIn = 0; colIn < colMsg; colIn ++)
    {
      inFile >> encodeMsg;
      messageInfo[rowIn][colIn] = encodeMsg;
      if (inFile.fail() || encodeMsg < MIN_MSG_VALUE
                        || encodeMsg > MAX_MSG_VALUE)
      {
        cout << "Error: Reading message value at row/col: ";
        cout << rowIn << " " << colIn << endl;
        inFile.close();
        return false;
      }
    
    }
  }

  inFile.close();
  return true;
   
}

int RowColClass::getRowPl()
{
  return rowPl;
}
int RowColClass::getColPl()
{
  return colPl;
}
int RowColClass::getRowMsg()
{
  return rowMsg;
}
int RowColClass::getColMsg()
{
  return colMsg;
}
int ** RowColClass::getMessageInfo()
{
  return messageInfo;
}


