#include "..\\include\Lib_Clara.h"
#include "..\\include\Dir.h"
#include "..\\include\cfg_items.h"
#include "config_data.h"
#include "conf_loader.h"
#include "struct.h"
#include "GUI.h"
#include "MYCLASSES.h"
#include "animation.h"
#include "main.h"

#define Info_Str "Simple Music Widget\n(c) blacklizard\n(r) Joker XT\nv.1.5"
#define PATH L"/card/other/ZBin/Config/SimpleMusicWidget"
#define BOOK_NAME "SimpleMusicWidget"

wchar_t * ImageName[4] = {L"nocover.png", L"overlay.png", L"panel.png", L"bolb.png"};

int TerminateElf(void * ,BOOK* book)
{
  FreeBook(book);
  return(1);
}

int myFind(BOOK* book)
{
  if(!strcmp(book->xbook->name,BOOK_NAME)) return(1);
  return(0);
}

int ShowAuthorInfo(void *mess ,BOOK* book)
{
  MSG * msg = (MSG*)mess;
  MessageBox(EMPTY_TEXTID,STR(Info_Str), NOIMAGE, 1, 0,msg->book);
  return(1);
}

void elf_exit(void)
{
  kill_data(&ELF_BEGIN, (void(*)(void*))mfree_adr());
}

int FindBookEx_Book( BOOK* book , int* param )
{
  return book == (BOOK*)param;
}

void DrawProgressBar( BOOK *bk, int value, int max_value, GC *gc,RECT rect, int Bcolor, int Ecolor,int bolb)
{	
  MyBOOK * mbk = (MyBOOK*)bk;
  int nx2( rect.x1 + (((float)(rect.x2-rect.x1)/(float)max_value)*(float)value) );
  DrawRect( rect.x1, rect.y1, rect.x2, rect.y2,Bcolor ,Bcolor );
  DrawRect( rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor );
  if(bolb)
  {
    int blob_x = nx2-(mbk->blob_w);
    int blob_y = (rect.y1-(mbk->blob_h)) + ((rect.y2-rect.y1)/2);
    GC_PutChar(gc, blob_x, blob_y, 0, 0, mbk->ImageID[3]);	
  }
}

wchar_t * GetType_str(int cover_type)
{
  if (cover_type<=3)
  {
    switch(cover_type)
    {
    case 0: return L"jpg";
    case 1: return L"gif";
    case 2: return L"png";
    case 3: return L"bmp";
    }
    return 0;
  }
  return 0;
}

void GetCover( wchar_t* ImageID, wchar_t *fullpath, int CoverSize,int CoverOffset, char cover_type)
{
  int f;
  if ((f=w_fopen(fullpath,WA_Read, 0x1FF, 0)))
  {
    if (w_lseek(f,CoverOffset,WSEEK_SET))
    {
      char * CoverBuff=new char[CoverSize+1];
      memset(CoverBuff,0,CoverSize+1);
      w_fread(f,CoverBuff,CoverSize);
      ImageID_GetIndirect(CoverBuff,CoverSize,0,GetType_str(cover_type),&*ImageID);
    }
    w_fclose(f);
  }
}

void GetCoverExist(MyBOOK * mybook)
{
  if(mybook->CoverArtID)
  {
    if(mybook->CoverArtID != mybook->ImageID[0])
    {
      ImageID_Free(mybook->CoverArtID);
      mybook->CoverArtID=0;
    }
    GetCover( &mybook->CoverArtID, mybook->filename, mybook->Size,mybook->Offset, mybook->pImageType);
  }
  else
  {
    GetCover( &mybook->CoverArtID, mybook->filename, mybook->Size,mybook->Offset, mybook->pImageType);
  }
}

void GetCoverNotExist(MyBOOK * mybook)
{
  if(mybook->CoverArtID)
  {
    if(mybook->CoverArtID != mybook->ImageID[0])
    {
      ImageID_Free(mybook->CoverArtID);
      mybook->CoverArtID=0;
    }
    mybook->CoverArtID = mybook->ImageID[0];
  }
  else
  {
    mybook->CoverArtID = mybook->ImageID[0];
  }
}

int MetaData_GetCoverInfo(wchar_t *fullpath, char* cover_type, int* size, int* cover_offset)
{
  UUID IID_IMetaData={0xB1,0xEB,0x4F,0x97,0xB0,0xDD,0x42,0x09,0xB6,0x96,0xCE,0x11,0x2D,0x5E,0xD8,0xE8};
  UUID CID_CMetaData={0x0B,0xCD,0x95,0x0F,0x9F,0xB6,0x4E,0x7A,0xA7,0xCD,0xCA,0x1D,0x87,0xBA,0x9A,0x27};
  METADATA_DESC * MetaData_Desc = new METADATA_DESC;
  MetaData_Desc->pMetaData=0;
  CoCreateInstance(&CID_CMetaData, &IID_IMetaData, PPINTERFACE(&MetaData_Desc->pMetaData));
  wchar_t * pos = wstrrchr(fullpath, '/');
  *pos = 0;
  MetaData_Desc->pMetaData->SetFile(fullpath,pos+1);
  COVER_INFO_DESC cover_info;
  if (((METADATA_DESC*)MetaData_Desc)->pMetaData->GetCoverInfo(&cover_info)<0) return(0);
  *cover_type = cover_info.cover_type;
  *size = cover_info.size;
  *cover_offset = cover_info.cover_offset;
  if (((METADATA_DESC*)MetaData_Desc)->pMetaData) 
  {
    ((METADATA_DESC*)MetaData_Desc)->pMetaData->Release();
    delete(MetaData_Desc);
  }
  return 1;
}

int OnNewTrack(void *mess, BOOK* book)
{
  MyBOOK *bk = (MyBOOK*)book;
  IShell * pIShell = NULL;
  IMusicServer_Manager * pIMusicServer_Manager = NULL;
  IMusicServer1* p1 = NULL;
  IMusicServer2* p2 = NULL;
  IMusicServer3* p3 = NULL;
  IUnknown* pIUnknown = NULL;
  int plat = GetChipID() & CHIPID_MASK;
  OSE_GetShell(PPINTERFACE(&pIShell));
  if (pIShell)
  {
    CoCreateInstance(&CID_CMusicServer_Manager, &IID_IMusicServer_Manager, PPINTERFACE(&pIMusicServer_Manager));
    if (pIMusicServer_Manager)
    {
      pIMusicServer_Manager->CreateMusicServer(pIShell, PPINTERFACE(&pIUnknown));
      if (pIUnknown)
      {
        pIUnknown->QueryInterface(&IID_IMusicServer1, PPINTERFACE(&p1));
        pIUnknown->QueryInterface(&IID_IMusicServer2, PPINTERFACE(&p2));
        pIUnknown->QueryInterface(&IID_IMusicServer3, PPINTERFACE(&p3));
        pIUnknown->Release();
        if (p1)
        {
          if (( plat == CHIPID_DB3210 ) || ( plat == CHIPID_DB3200 ) || ( plat == CHIPID_DB3350 ))
          {
            UI_MEDIAPLAYER_NEW_TRACK_DATA * Track_Data = (UI_MEDIAPLAYER_NEW_TRACK_DATA *)mess;
            p1->GetTags(Track_Data->track_id, 512, bk->Artist, bk->Album, bk->Title);
            p1->GetTrackFullpath(Track_Data->track_id, 512, bk->filename);
            wstrcpy(bk->Tempfilename,bk->filename);
            bk->Total = Track_Data->FullTime;
            bk->Elapsed = Track_Data->ElapsedTime;
          }
          p1->Release();
        }
        
        if (p2)
        {
          if ( plat == CHIPID_DB3150 )
          {
            UI_MEDIAPLAYER_NEW_TRACK_DATA * Track_Data = (UI_MEDIAPLAYER_NEW_TRACK_DATA *)mess;
            p2->GetTags(Track_Data->track_id, 512, bk->Artist, bk->Album, bk->Title);
            p2->GetTrackFullpath(Track_Data->track_id, 512, bk->filename);
            wstrcpy(bk->Tempfilename,bk->filename);
            bk->Total = Track_Data->FullTime;
            bk->Elapsed = Track_Data->ElapsedTime;
          }
          p2->Release();
        }
        
        if (p3)
        {
          if ( plat == CHIPID_DB3150 )
          {
            UI_MEDIAPLAYER_NEW_TRACK_DATA * Track_Data = (UI_MEDIAPLAYER_NEW_TRACK_DATA *)mess;
            p3->GetTags(Track_Data->track_id, 512, bk->Artist, bk->Album, bk->Title);
            p3->GetTrackFullpath(Track_Data->track_id, 512, bk->filename);
            wstrcpy(bk->Tempfilename,bk->filename);
            bk->Total = Track_Data->FullTime;
            bk->Elapsed = Track_Data->ElapsedTime;
          }
          p3->Release();
        }
      }
      if(!MetaData_GetCoverInfo(bk->filename, &bk->pImageType, &bk->Size, &bk->Offset))
      {
        bk->IsAlbumArt=0;
        wstrcpy(bk->filename,bk->Tempfilename);
        GetCoverNotExist(bk);
      }
      else
      {
        bk->IsAlbumArt=1;
        wstrcpy(bk->filename,bk->Tempfilename);
        GetCoverExist(bk);
      }
      snwprintf(bk->buffer, 256, L"%02d:%02d", bk->Total.minutes, bk->Total.seconds);
      TEXTID_DESTROY(bk->DATASID[0]);
      TEXTID_DESTROY(bk->DATASID[1]);
      TEXTID_DESTROY(bk->DATASID[2]);
      TEXTID_DESTROY(bk->DATASID[5]);
      bk->DATASID[0] = TextID_Create( bk->Title, ENC_UCS2, wstrlen(bk->Title) );
      bk->DATASID[1] = TextID_Create( bk->Artist, ENC_UCS2, wstrlen(bk->Artist) );
      bk->DATASID[2] = TextID_Create( bk->Album, ENC_UCS2, wstrlen(bk->Album) );
      bk->DATASID[5] = TextID_Create( bk->buffer, ENC_UCS2, wstrlen(bk->buffer) );      
      bk->TotalSec = ((bk->Total.minutes)*60) + bk->Total.seconds;
      pIMusicServer_Manager->Release();
    }
    pIShell->Release();
  }
  return 1;
}

void onfTimer (u16 unk, MyBOOK * mbk)
{
  DispObject_InvalidateRect(mbk->db, 0);
  Timer_ReSet(&mbk->timer, 1000, MKTIMERPROC(onfTimer), mbk); 
}

int StopTimer(void *mess, BOOK* book)
{
  MyBOOK *bk = (MyBOOK*)book;
  Timer_Kill( &bk->timer );
  bk->timer=0;
  return 1;
}

int StartTimer(void *mess, BOOK* book)
{
  MyBOOK *bk = (MyBOOK*)book;
  Timer_ReSet(&bk->timer, 1000, MKTIMERPROC(onfTimer), bk); 
  return 1;
}

void onBTimer (u16 unk, MyBOOK * mbk)
{
  Timer_Kill( &mbk->final_timer);
  if(mbk->timer)
  {
    Timer_Kill( &mbk->timer );
    mbk->timer=0;
  }
}
void onATimer (u16 unk, MyBOOK * mbk)
{
  if(!FindBook(get_IsAudioPlayerBook()))
  { 
    DispObject_SetAnimation( mbk->db, mbk->ExitAnim );
    Timer_ReSet(&mbk->final_timer, 1000, MKTIMERPROC(onBTimer), mbk);  
  }
  Timer_Kill( &mbk->animation_timer );
  mbk->animation_timer=0;
}

int PageExit(void* msg, BOOK* book, PAGE_DESC* page_desc, LPARAM ClientData, u16 event)
{
  bool exists = NULL!=FindBookEx( FindBookEx_Book, (int*) book );
  if(exists)
  {
    if((!strcmp(book->xbook->name, "MusicApplication_Book")))
    {
      if((!strcmp(page_desc->name,"MusicApplication_Main_Page")))
      {
        MyBOOK * mbk = (MyBOOK*)FindBook(myFind) ;
        Timer_ReSet(&mbk->animation_timer, 500, MKTIMERPROC(onATimer), mbk);     
      }
    }
  }
  return 0;
}

int ElapsedTime(void*mess, BOOK*book)
{
  MyBOOK *bk = (MyBOOK*)book;
  PLAY_TIME *pl=(PLAY_TIME*)mess;
  bk->Elapsed = pl->Elapsed;
  snwprintf(bk->buffer_Temp, 256, L"%02d:%02d", bk->Elapsed.minutes, bk->Elapsed.seconds);
  bk->RemSec = bk->TotalSec - (((bk->Elapsed.minutes)*60) + bk->Elapsed.seconds);
  bk->ElpSec = ((bk->Elapsed.minutes)*60)+ bk->Elapsed.seconds;
  return 1;
}
const PAGE_MSG SMW_Page_Player_Started[]@ "DYN_PAGE" ={
  UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT_TAG, ElapsedTime,
  UI_SLEEPMODE_ACTIVATED_EVENT_TAG, StopTimer,
  UI_SLEEPMODE_DEACTIVATED_EVENT_TAG, StartTimer,
  STANDBY_IDLE_EVENT_TAG, StartTimer,
  STANDBY_NOT_IDLE_EVENT_TAG, StopTimer,
  0,0
};

PAGE_DESC SMW_Page_Player_Started_page ={"SMW_BasePage",0,SMW_Page_Player_Started};

int PageEnter(void*mess, BOOK* book)
{ 
  MyBOOK *mbk = (MyBOOK*)book;
  mbk->gc=get_DisplayGC();
  if(mbk->gui_standby)
  {
    mbk->gui_standby = GUIObject_Destroy( mbk->gui_standby );
  }
  if(!mbk->gui_standby)CreateStandbyGUI( Find_StandbyBook(),mbk); 
  BookObj_GotoPage(book, &SMW_Page_Player_Started_page );
  DispObject_SetAnimation( mbk->db, mbk->EnterAnim );
  mbk->timer=0;
  onfTimer (mbk->timer,mbk);
  return 0;
} 

//========================BCFG=======================================
void SetBCFGData(MyBOOK * mbk)
{
  mbk->TitleStrW = (TITLE_POSITION.x2-TITLE_POSITION.x1); 
  mbk->ArtistStrW = (ARTIST_POSITION.x2-ARTIST_POSITION.x1);
  mbk->AlbumStrW = (ALBUM_POSITION.x2-ALBUM_POSITION.x1);
  
  mbk->TotalStrW = (TOTALTIME_POSITION.x2-TOTALTIME_POSITION.x1); 
  mbk->RemainingStrW = (REMAININGTIME_POSITION.x2-REMAININGTIME_POSITION.x1); 
  mbk->ElapsedStrW = (ELAPSEDTIME_POSITION.x2-ELAPSEDTIME_POSITION.x1); 
  
  mbk->CoverW = (COVERART_POSITION.x2-COVERART_POSITION.x1);
  mbk->CoverH = (COVERART_POSITION.y2-COVERART_POSITION.y1);
  mbk->EnterAnim = GetAnimationID(ANIMATION_ENTRANCE_SPEED, ANIMATION_ENTRANCE_FADE, ANIMATION_ENTRANCE_STYLE, ANIMATION_ENTRANCE_ENTERFROM);
  mbk->ExitAnim = GetAnimationID(ANIMATION_EXIT_SPEED, ANIMATION_EXIT_FADE, ANIMATION_EXIT_STYLE, ANIMATION_EXIT_EXITTO);
}

static int ReconfigElf(void *mess ,BOOK *book)
{
  RECONFIG_EVENT_DATA *reconf=(RECONFIG_EVENT_DATA *)mess;
  int result=0;
  if (wstrcmpi(reconf->path,successed_config_path)==0 && wstrcmpi(reconf->name,successed_config_name)==0)
  {
    InitConfig();
    MyBOOK *mbk = (MyBOOK*)book;
    SetBCFGData(mbk);
    result=1;
  }
  return(result);
}

int onBcfgConfig(void*mess, BOOK* book)
{
  FSTAT _fstat;
  wchar_t path[256];
  
  if(fstat(GetDir(DIR_ELFS|MEM_INTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_INTERNAL));
  }
  else if(fstat(GetDir(DIR_ELFS|MEM_EXTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_EXTERNAL));
  }
  else
  {
    MessageBox(EMPTY_TEXTID, STR("BcfgEdit.elf not found!"), NOIMAGE, 1 ,0, 0);
    return (1);
  }
  wstrcat(path,L"/BcfgEdit.elf");
  elfload(path,(void*)successed_config_path,(void*)successed_config_name,0);
  return (1);
}
//=====================================================

//================BOOK Stuff===========================
const PAGE_MSG SMW_PageEvents[]@ "DYN_PAGE" ={
  ELF_TERMINATE_EVENT , TerminateElf,
  ELF_SHOW_INFO_EVENT  , ShowAuthorInfo,
  UI_TRACK_CHANGED_EVENT,OnNewTrack,
  ELF_RECONFIG_EVENT, ReconfigElf,
  ELF_BCFG_CONFIG_EVENT,  onBcfgConfig,
  UI_MEDIAPLAYER_CREATED_EVENT_TAG, PageEnter,
  0,0
};

PAGE_DESC base_page ={"SMW_BasePage",0,SMW_PageEvents};


void onCloseSMWBook(BOOK * book)
{
  if (book)
  {
    MyBOOK *bk = (MyBOOK*)book;
    SUBPROC(elf_exit);
    
    if(bk->CoverArtID != bk->ImageID[0]) ImageID_Free( bk->CoverArtID );
    if(bk->gui_standby)GUIObject_Destroy( bk->gui_standby );
    
    if(bk->timer)
    {
      Timer_Kill( &bk->timer );
      bk->timer=0;
    }
    
    for ( int x = 0; x <= 3 ; x++)
    {
      if (!fstat(PATH, ImageName[x],0))
      {
        ImageID_Free( bk->ImageID[x] );
        bk->ImageID[x] = NOIMAGE;
      }
    }
    
    for ( int x = 0; x <= 5 ; x++)
    {
      if (bk->DATASID[x] != EMPTY_TEXTID ) 
      {
        TEXTID_DESTROY(bk->DATASID[x])
      }
    }
    ModifyUIPageHook(PAGE_EXIT_EVENT, PageExit, NULL, 0);
  }
}

MyBOOK *CreateSMWBook()
{
  MyBOOK * mybook = new MyBOOK;
  CreateBook(mybook,onCloseSMWBook,&base_page,BOOK_NAME,-1,0);
  return(mybook);
}
//=====================================================

int main (void)
{
  if (FindBook(myFind))
  {
    FreeBook(FindBook(myFind));
    MessageBox(EMPTY_TEXTID,STR("Simple Music Widget Stopped"), NOIMAGE, 1, 0,0);
    SUBPROC(elf_exit);
  }
  else
  { 
    MyBOOK * mbk = CreateSMWBook();
    InitConfig();
    SetBCFGData(mbk);
    for ( int x = 0; x <= 3 ; x++)
    {
      if (!fstat(PATH, ImageName[x],0))
      {
        ImageID_Get( PATH, ImageName[x], &mbk->ImageID[x] );
      }
      else
      {
        mbk->ImageID[x] = NOIMAGE;
      }
    }
    for ( int x = 0; x <= 5 ; x++)
    {
      mbk->DATASID[x] = EMPTY_TEXTID;
    }
    mbk->timer=0;
    mbk->gui_standby=0;
    mbk->animation_timer=0;
    mbk->CoverArtID = NOIMAGE;
    mbk->blob_w = (GetImageWidth( mbk->ImageID[3] ))/2;
    mbk->blob_h = (GetImageHeight( mbk->ImageID[3] ))/2;
    ModifyUIPageHook(PAGE_EXIT_EVENT, PageExit, NULL, PAGE_HOOK_ADD_AFTER); 
    MessageBox(EMPTY_TEXTID,STR("Simple Music Widget Started"), NOIMAGE, 1, 0,0);
  }
  return(0);
}
