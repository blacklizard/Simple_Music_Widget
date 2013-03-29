#include "..\\include\Lib_Clara.h"
#include "..\\include\Dir.h"
#include "..\\include\cfg_items.h"
#include "config_data.h"
#include "conf_loader.h"
#include "main.h"
#include "struct.h"


static const char StandbyGuiName[] = "Gui_Standby";

void DrawSID(int font,int text,int ct, int XPos, int YPos, int width ,int NormalColor)
{
  if (text && text!=EMPTY_TEXTID)
  {
    SetFont(font);
    DrawString(text,ct,XPos,YPos,XPos+width,YPos+(font&0xFF),60,0x05,NormalColor,NormalColor); 
  }
}

int StandbyGUIOnCreate( DISP_OBJ* db )
{
  DispObject_Show(db,1);// (r) Joker XT
  return 1;
}

void MyGuiOnLayout(DISP_OBJ *db)
{
  DispObject_SetLayerColor(db,0x00000000);// (r) Joker XT
}

void StandbyGUIOnClose( DISP_OBJ* db )
{
}

void StandbyGUIOnRedraw( DISP_OBJ* db, int, int, int )
{
  MyBOOK * mbk = (MyBOOK*)FindBook(myFind) ;
  
  if(PANEL_ENABLE)GC_PutChar( mbk->gc, PANEL_POSITION_X, PANEL_POSITION_Y, 0, 0, mbk->ImageID[2] );
  if(COVERART_ENABLE)GC_PutChar( mbk->gc, COVERART_POSITION.x1, COVERART_POSITION.y1,mbk->CoverW ,mbk->CoverH, mbk->CoverArtID );
  if(OVERLAY_ENABLE)GC_PutChar( mbk->gc, OVERLAY_POSITION_X, OVERLAY_POSITION_Y, 0, 0, mbk->ImageID[1] );
  
  if(TITLE_ENABLE)DrawSID(TITLE_FONTSIZE,mbk->DATASID[0],TITLE_ALIGN, TITLE_POSITION.x1, TITLE_POSITION.y1,mbk->TitleStrW ,TITLE_TEXTCOLOR);
  if(ARTIST_ENABLE)DrawSID(ARTIST_FONTSIZE,mbk->DATASID[1],ARTIST_ALIGN, ARTIST_POSITION.x1, ARTIST_POSITION.y1, mbk->ArtistStrW ,ARTIST_TEXTCOLOR);
  if(ALBUM_ENABLE)DrawSID(ALBUM_FONTSIZE,mbk->DATASID[2],ALBUM_ALIGN, ALBUM_POSITION.x1, ALBUM_POSITION.y1, mbk->AlbumStrW,ALBUM_TEXTCOLOR); 
  
  if(REMAININGTIME_ENABLE)
  {
    snwprintf(mbk->buffer, 256, L"-%02d:%02d", (mbk->RemSec/60), (mbk->RemSec%60));
    mbk->DATASID[3] = TextID_Create( mbk->buffer, ENC_UCS2, wstrlen(mbk->buffer) );
    DrawSID(REMAININGTIME_FONTSIZE,mbk->DATASID[3],REMAININGTIME_ALIGN, REMAININGTIME_POSITION.x1, REMAININGTIME_POSITION.y1, mbk->RemainingStrW,REMAININGTIME_TEXTCOLOR);
    TEXTID_DESTROY(mbk->DATASID[3]);
  }
  
  if(ELAPSEDTIME_ENABLE)
  {  
    mbk->DATASID[4] = TextID_Create( mbk->buffer_Temp, ENC_UCS2, wstrlen(mbk->buffer_Temp) );
    DrawSID(ELAPSEDTIME_FONTSIZE,mbk->DATASID[4],ELAPSEDTIME_ALIGN, ELAPSEDTIME_POSITION.x1, ELAPSEDTIME_POSITION.y1, mbk->ElapsedStrW,ELAPSEDTIME_TEXTCOLOR);
    TEXTID_DESTROY(mbk->DATASID[4]);
  }
  
  if(TOTALTIME_ENABLE)DrawSID(TOTALTIME_FONTSIZE,mbk->DATASID[5],TOTALTIME_ALIGN, TOTALTIME_POSITION.x1, TOTALTIME_POSITION.y1, mbk->TotalStrW,TOTALTIME_TEXTCOLOR);
  if(PROGRESSBAR_ENABLE)DrawProgressBar((MyBOOK*)mbk, mbk->ElpSec, mbk->TotalSec, mbk->gc,PROGRESSBAR_POSITION, PROGRESSBAR_BACKGROUNDCOLOR, PROGRESSBAR_ELAPSEDCOLOR,PROGRESSBAR_BOLBIMAGE);
}

void StandbyGui_constr( DISP_DESC* desc )
{
  DISP_DESC_SetName( desc, StandbyGuiName );
  DISP_DESC_SetSize( desc, sizeof( DISP_OBJ) );
  DISP_DESC_SetOnCreate( desc, ( DISP_OBJ_ONCREATE_METHOD )StandbyGUIOnCreate );
  DISP_DESC_SetOnClose( desc, ( DISP_OBJ_ONCLOSE_METHOD )StandbyGUIOnClose );
  DISP_DESC_SetOnRedraw( desc, ( DISP_OBJ_ONREDRAW_METHOD )StandbyGUIOnRedraw );
  DISP_DESC_SetOnLayout(desc,(DISP_OBJ_METHOD)MyGuiOnLayout);
}

void StandbyGui_destr( GUI* gui )
{
}

void CreateStandbyGUI( BOOK* myBook,MyBOOK * mybook)
{
  mybook->gui_standby = new GUI;
  if ( !GUIObject_Create( mybook->gui_standby, StandbyGui_destr, StandbyGui_constr, myBook, 0, 0, 0 ) )
  {
    delete mybook->gui_standby;
  }
  BookObj_AddGUIObject( myBook, mybook->gui_standby );
  GUIObject_SetStyle( mybook->gui_standby, UI_OverlayStyle_FullScreen );
  GUIObject_SetTitleType( mybook->gui_standby, UI_TitleMode_None );
  GUIObject_SoftKeys_Hide( mybook->gui_standby );
  mybook->db=GUIObject_GetDispObject(mybook->gui_standby);
}
