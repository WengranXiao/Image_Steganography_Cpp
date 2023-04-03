#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "ColorClass.h"
#include "constant.h"
#include "ColorImageClass.h"
#include "RowColClass.h"

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main(int argc, char* argv[])     
{
  
  if (argc != CORRECT_INPUT)  
  {
    cout << "Usage: " << argv[0] << " <inputFileName.ppm>" << endl; 
    exit(2);
  }

  ColorImageClass imageMatrix;
  ifstream inFile;
  string imgFileName;
  string writeFileName;
  int userChoice;

  cout << "Reading initial image from: " << argv[1] << endl;
  imgFileName = argv[1];
  inFile.open(imgFileName.c_str());
  if (inFile.fail())
  {
    cout << "Can not open the file" << endl;
    inFile.close();
  }
  else
  {
    if (!imageMatrix.readColorImage(imgFileName))
    {
      cout << "Image read successful: No" << endl; 
      exit(3);
    }
    else
    {
      cout << "Image read successful: Yes" << endl;
      inFile.close();
    }
  }

  userChoice = 0;
  while (userChoice != EXIT)         
  {
    cout << ENCODE_IMAGE << ". Encode a message from file" << endl;
    cout << DECODE_IMAGE << ". Perform decode" << endl;
    cout << WRITE_IMAGE << ". Write current image to file" << endl;
    cout << EXIT << ". Exit the program" << endl;
    cout << "Enter your choice: ";                   
   
    bool validChoice = false;
    while (!validChoice)
    {
      cin >> userChoice;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(IGNORE_LENGTH, '\n');  
        cout << "Please input an int " << endl;   
        cout << "Enter your choice: ";     
      }
      else if ((userChoice > EXIT) || (userChoice < ENCODE_IMAGE))
      {
          cout << "Please enter an integer between 1-4!" << endl;
          cout << "Enter your choice: ";
      }
      else
      {
          validChoice = true;
      }
    }

    if (userChoice == DECODE_IMAGE)
    {
      imageMatrix.decodeImg();                 
      cout << "Image modified to decoded image contents" << endl;
       
    }
    else if (userChoice == ENCODE_IMAGE) 
    {
      string encodingFileName;
      int rowPl;
      int colPl;
      int colMsg;
      int rowMsg;

      cout << "Enter name of file containing message: ";
      cin >> encodingFileName;
      inFile.open(encodingFileName.c_str());
      inFile >> colMsg >> rowMsg; 

      if (inFile.fail() || rowMsg < MIN_PIXEL || colMsg < MIN_PIXEL)
      {
        cout << "File does not exist or file is empty" << endl;
        cin.clear();
        cin.ignore(IGNORE_LENGTH, '\n');
      }
      else
      {
        cout << "Enter row and column for message placement: ";
        cin >> rowPl >> colPl;  
        RowColClass messageInfo(rowPl, colPl, colMsg, rowMsg);   
        if (messageInfo.readMsg(imageMatrix.getRow(), imageMatrix.getCol(), 
                              rowPl, colPl, colMsg, rowMsg, encodingFileName))
        {                                              
          imageMatrix.encodeImg(messageInfo);
          cout << "Message encode successful: Yes" << endl;
        }
        else
        { 
          cout << "Message encode successful: No" << endl;
        }
      }  
    }

    else if (userChoice == WRITE_IMAGE)
    {
      cout << "Enter name of file to write image to: ";
      cin >> writeFileName;
      imageMatrix.writeToFile(writeFileName); 
    }
    else if (userChoice == EXIT)
    {
      cout << "Thanks for using this program!" << endl;
    }
  }
  return 0;
}

#endif



