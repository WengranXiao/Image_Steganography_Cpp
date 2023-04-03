#ifndef _ROWCOLCLASS_H_
#define _ROWCOLCLASS_H_

#include <iostream>
using namespace std;

#include "constant.h"
#include "ColorClass.h"

// An object of the RowColClass will store the information of an encoding message
//   file including size, initial placement and data.

class RowColClass
{
private:
  int ** messageInfo;      
  int rowPl;          
  int colPl;
  int rowMsg;
  int colMsg;

public:

  RowColClass(int row, int col, int rowM, int colM);

  // This function can read data from a txt file which contains the encoding 
  //   messages. 

  bool readMsg(const int rowInput, const int columnInput, int rowPl, 
               int colPl, int rowM, int colM, string theFileNanme);

  // These functions simply return the private attributes of RowColClass.
  int ** getMessageInfo();
  int getRowPl();
  int getColPl();
  int getRowMsg();
  int getColMsg();

};
#endif
