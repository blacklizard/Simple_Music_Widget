#ifndef _STRUCT_H_
  #define _STRUCT_H_
  
#include "..\\include\types.h"
  
typedef unsigned long FUint32;
typedef long FSint32;
typedef unsigned long TUnsigned;
typedef bool TBool;

typedef struct
{
    unsigned long hours;
    unsigned long minutes;
    unsigned long seconds;
}TIME_int;

typedef enum
{
    TMusicServerAction_None,              ///< No action set.
    TMusicServerAction_CreateMaximized,   ///< Must be able to create player maximized from extern part, accessories.
    TMusicServerAction_CreateMinimized,   ///< Must be able to create player minimized from extern part, accessories.
    TMusicServerAction_Destroy,           ///< Must be able to destroy player from extern part, accessories.
    TMusicServerAction_Play,              ///< Starts player.
    TMusicServerAction_Pause,             ///< Pauses player.
    TMusicServerAction_Next,              ///< Get next file.
    TMusicServerAction_Previous,          ///< Get previous file.
    TMusicServerAction_StartFastForward,  ///< Starts fastforward of player.
    TMusicServerAction_StopFastForward,   ///< Stops fastfowardad of player, must be done before play.
    TMusicServerAction_StartRewind,       ///< Starts rewind of player.
    TMusicServerAction_StopRewind,        ///< Stops rewind of player, must be done before play.
    TMusicServerAction_Last               ///< Place holder. Put new data before this!
} TMusicServer_Action;

typedef struct _MyBOOK : BOOK
{
  GUI* gui_standby;
  DISP_OBJ *db;
  GC* gc;
  
  u16 timer; 
  u16 animation_timer; 
  u16 final_timer;
  
  wchar_t Artist[512];
  wchar_t Title[512];
  wchar_t Album[512];
  wchar_t filename[512];
  wchar_t Tempfilename[512];
  wchar_t buffer[256];
  wchar_t buffer_Temp[256];
  
  int Offset;
  int Size;
  char pImageType; 
  bool IsAlbumArt;
  IMAGEID CoverArtID;
  IMAGEID ImageID[4];
  
  TEXTID DATASID[6];
  
  int EnterAnim;
  int ExitAnim;
  int TitleStrW; 
  int ArtistStrW; 
  int AlbumStrW;
  int TotalStrW; 
  int RemainingStrW; 
  int ElapsedStrW; 
  int TotalSec;
  int RemSec;
  int ElpSec;
  int CoverW; 
  int CoverH; 
  int blob_w;
  int blob_h;
  
  TIME_int Total;
  TIME_int Remaining;
  TIME_int Elapsed;
}MyBOOK;

typedef struct
{
  BOOK * book;
}MSG;

typedef struct
{
  char dummy_0x0[0x28];
  int track_id;
  TIME_int ElapsedTime;
  char dummy_0x1[0x24];
  TIME_int FullTime;
}UI_MEDIAPLAYER_NEW_TRACK_DATA; 

typedef struct
{
  char dummy[0x24];
  TIME_int Elapsed;
}PLAY_TIME;
#endif
