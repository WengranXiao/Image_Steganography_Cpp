#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include "constant.h"
#include "RowColClass.h"

// ColorClass is a class for storing three rgb values of a single pixel. 

class ColorClass
{
private:       
  int red;
  int green;
  int blue; 
  
public:
  ColorClass();

  //Three member functions to get the value of each RGB color
  int getRed();
  int getGreen();
  int getBlue();

  // This function modifies a pixel such that whether the individual RGB 
  void encodeColor(ColorClass& inColor, const int colorCode);

  // This function reads the rgb value of a pixel and convert this pixel to the
  //   color corresponding to the encoding message file. 
  void decodeColor(ColorClass& inColor);
  
  // Set RGB color to a provided color
  bool setTo(const ColorClass inColor);
  
  void readRgb(const ColorClass inColor);
  void readRgb(ifstream& inFile);

  // Write rgb values to files according to the provided ofstream object
  void writeRgb(ofstream& outFile);

  bool isEven(int num);

};
#endif