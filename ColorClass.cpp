#include <iostream>
#include <fstream>
using namespace std;

#include "constant.h"
#include "ColorClass.h"
#include "RowColClass.h"

ColorClass::ColorClass()
{
  red = MAX_COLOR;
  green = MAX_COLOR;
  blue = MAX_COLOR;
}


int ColorClass::getRed()
{
    return (red);
}

int ColorClass::getGreen()
{
    return (green);
}

int ColorClass::getBlue()
{
    return (blue);
}

bool ColorClass::isEven(int num)
{
    if (num % 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void ColorClass::encodeColor(ColorClass& inColor, const int colorCode)
{
  if (colorCode == BLACK)
  {
    if (inColor.red % 2 != 0)
    {
      inColor.red = inColor.red - 1;
    }
    if (inColor.green % 2 != 0)
    {
      inColor.green = inColor.green - 1;
    }
    if (inColor.blue % 2 != 0)
    {
      inColor.blue = inColor.blue - 1;
    };
  }

  if (colorCode == RED)
  {
    if (inColor.red % 2 == 0)
    {
      inColor.red = inColor.red + 1;
    }
    if (inColor.green % 2 != 0)
    {
      inColor.green = inColor.green - 1;
    }
    if (inColor.blue % 2 != 0)
    {
      inColor.blue = inColor.blue - 1;
    }
  }

  if (colorCode == GREEN)
  {
    if (inColor.red % 2 != 0)
    {
      inColor.red = inColor.red - 1;
    }
    if (inColor.green % 2 == 0)
    {
      inColor.green = inColor.green + 1;
    }
    if (inColor.blue % 2 != 0)
    {
      inColor.blue = inColor.blue - 1;
    }
  }
  if (colorCode == BLUE)
  {
    if (inColor.red % 2 != 0)
    {
      inColor.red = inColor.red - 1;
    }
    if (inColor.green % 2 != 0)
    {
      inColor.green = inColor.green - 1;
    }
    if (inColor.blue % 2 == 0)
    {
      inColor.blue = inColor.blue + 1;
    }
  }
  if (colorCode == WHITE)
  {
    if (inColor.red % 2 == 0)
    {
      inColor.red = inColor.red + 1;
    }
    if (inColor.green % 2 == 0)
    {
      inColor.green = inColor.green + 1;
    }
    if (inColor.blue % 2 == 0)
    {
      inColor.blue = inColor.blue + 1;
    }
  }
  if (colorCode == YELLOW)
  {
    if (inColor.red % 2 == 0)
    {
      inColor.red = inColor.red + 1;
    }
    if (inColor.green % 2 == 0)
    {
      inColor.green = inColor.green + 1;
    }
    if (inColor.blue % 2 != 0)
    {
      inColor.blue = inColor.blue - 1;
    }
  }
  if (colorCode == MAGENTA)
  {
    if (inColor.red % 2 == 0)
    {
      inColor.red = inColor.red + 1;
    }
    if (inColor.green % 2 != 0)
    {
      inColor.green = inColor.green - 1;
    }
    if (inColor.blue % 2 == 0)
    {
      inColor.blue = inColor.blue + 1;
    }
  }
  if (colorCode == CYAN)
  {
    if (inColor.red % 2 != 0)
    {
      inColor.red = inColor.red - 1;
    }
    if (inColor.green % 2 == 0)
    {
      inColor.green = inColor.green + 1;
    }
    if (inColor.blue % 2 == 0)
    {
      inColor.blue = inColor.blue + 1;
    }
  }
}


void ColorClass::decodeColor(ColorClass& inColor)
{
  if (inColor.red % 2 == 0 && inColor.green % 2 == 0 && inColor.blue % 2 == 0)
  {
    inColor.red = MIN_COLOR;
    inColor.green = MIN_COLOR;
    inColor.blue = MIN_COLOR;
  }
  if (inColor.red % 2 != 0 && inColor.green % 2 == 0 && inColor.blue % 2 == 0)
  {
    inColor.red = MAX_COLOR;
    inColor.green = MIN_COLOR;
    inColor.blue = MIN_COLOR;
  }
  if (inColor.red % 2 == 0 && inColor.green % 2 != 0 && inColor.blue % 2 == 0)
  {
    inColor.red = MIN_COLOR;
    inColor.green = MAX_COLOR;
    inColor.blue = MIN_COLOR;
  }
  if (inColor.red % 2 == 0 && inColor.green % 2 == 0 && inColor.blue % 2 != 0)
  {
    inColor.red = MIN_COLOR;
    inColor.green = MIN_COLOR;
    inColor.blue = MAX_COLOR;
  }
  if (inColor.red % 2 != 0 && inColor.green % 2 != 0 && inColor.blue % 2 != 0)
  {
    inColor.red = MAX_COLOR;
    inColor.green = MAX_COLOR;
    inColor.blue = MAX_COLOR;
  }
  if (inColor.red % 2 != 0 && inColor.green % 2 != 0 && inColor.blue % 2 == 0)
  {
    inColor.red = MAX_COLOR;
    inColor.green = MAX_COLOR;
    inColor.blue = MIN_COLOR;
  }
  if (inColor.red % 2 != 0 && inColor.green % 2 == 0 && inColor.blue % 2 != 0)
  {
    inColor.red = MAX_COLOR;
    inColor.green = MIN_COLOR;
    inColor.blue = MAX_COLOR;
  }
  if (inColor.red % 2 == 0 && inColor.green % 2 != 0 && inColor.blue % 2 != 0)
  {
    inColor.red = MIN_COLOR;
    inColor.green = MAX_COLOR;
    inColor.blue = MAX_COLOR;
  }
}


bool ColorClass::setTo(const ColorClass inColor)
{
  
  red = inColor.red;
  green = inColor.green;
  blue = inColor.blue;
  return true;
  
}


void ColorClass::readRgb(const ColorClass inColor)
{
  red = inColor.red;
  green = inColor.green;
  blue = inColor.blue;
}

void ColorClass::readRgb(ifstream& inFile)
{
  inFile >> red >> green >> blue;
}

void ColorClass::writeRgb(ofstream& outFile)
{
  outFile << red << " " << green << " " << blue << " ";
}