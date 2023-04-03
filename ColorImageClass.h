#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "constant.h"
#include "ColorClass.h"

// An object of ColorImageClass stores an image as a dynamic 2D array. 
class ColorImageClass
{
private:
  ColorClass ** imageMatrix;      
  int rowInput;             
  int columnInput;

public:
  // Constructor
  ColorImageClass();
  
  // Return the size information of the image
  int getRow();
  int getCol();

  // This function open the ppm file and read the image information.
  bool readColorImage(string fileName);

  // This function write the current ColorImageClass object (image) to a ppm
  void writeToFile(string fileName);
  
  // This function performs encoding for the whole image by modifying each 
  //   pixel according to the encoding message file.
  void encodeImg(RowColClass msg);

  // This function performs decoding for the whole image
  void decodeImg();

}; 

#endif
