#ifndef _MAIN_H_
#define _MAIN_H_

#include "..\\include\types.h"

#define ELF_BCFG_CONFIG_EVENT 994
#define UI_TRACK_CHANGED_EVENT 0x3030
#define TEXTID_DESTROY(a) if (a != EMPTY_TEXTID ) TextID_Destroy( a ); a= EMPTY_TEXTID;

int myFind(BOOK* book);
void DrawProgressBar( BOOK *bk, int value, int max_value, GC *gc,RECT rect, int Bcolor, int Ecolor,int bolb);
#endif
