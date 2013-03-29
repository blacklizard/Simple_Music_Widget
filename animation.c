#include "..\\include\Lib_Clara.h"
#include "..\\include\Dir.h"
#include "animation.h"


int GetSpeed(int id)
{
  if(id<=3)
  {
    switch(id)
    {
    case 0: return 0x40000000;
    case 1: return 0x60000000;
    case 2: return 0x80000000;
    case 3: return 0xA0000000;
    }
    return 0;
  }
  return 0;
}

int GetFade(int id)
{
  if(id<=1)
  {
    switch(id)
    {
    case 0: return 0x1;
    case 1: return 0x2;
    }
    return 0;
  }
  return 0;
}

int GetStyle(int id)
{
  if(id<=3)
  {
    switch(id)
    {
    case 0: return 0x100;
    case 1: return 0x200;
    case 2: return 0x1000;
    case 3: return 0x2000;
    }
    return 0;
  }
  return 0;
}

int GetPosition(int id)
{
  if(id<=7)
  {
    switch(id)
    {
    case 0: return 0x10;
    case 1: return 0x20;
    case 2: return 0x10000;
    case 3: return 0x20000;
    case 4: return 0x100000;
    case 5: return 0x200000;
    case 6: return 0x300000;
    case 7: return 0x400000;
    }
    return 0;
  }
  return 0;
}

int GetAnimationID(int speed, int fade, int style, int position)
{
  return GetSpeed(speed) + GetFade(fade) + GetStyle(style) + GetPosition(position);
}
