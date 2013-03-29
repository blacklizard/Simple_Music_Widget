#ifndef _MYCLASSES_H_
  #define _MYCLASSES_H_
UUID CID_CMusicServer_Manager = {0x9, 0xE5, 0x76, 0x91, 0x7F, 0x36, 0x4B, 0x59, 0x82, 0xB9, 0x89, 0x19, 0xEA, 0x18, 0xB6, 0xF8};
UUID IID_IMusicServer_Manager = {0xAE, 0x67, 0x65, 0x71, 0xB3, 0x99, 0x44, 0xBE, 0xA5, 0xF4, 0xE6, 0x96, 0xCA, 0x63, 0x18, 0x6B};
UUID IID_IMusicServer1 = {0x09, 0xF1, 0x89, 0xDF, 0xF4, 0x9B, 0x45, 0xF0, 0xB8, 0xF8, 0xBB, 0xCF, 0xD2, 0x7E, 0x74, 0xC0};
UUID IID_IMusicServer2 = {0x09, 0xF1, 0x89, 0xDF, 0xF4, 0x9B, 0x45, 0xF0, 0xB8, 0xF8, 0xBB, 0xCF, 0xD2, 0x7E, 0x74, 0xC0};
UUID IID_IMusicServer3 = {0x55, 0x8F, 0xD5, 0x57, 0xAA, 0x91, 0x41, 0xEB, 0x84, 0x96, 0x53, 0x97, 0xC4, 0xEA, 0x3E, 0x7A};
UUID IID_IMetaData={0xB1,0xEB,0x4F,0x97,0xB0,0xDD,0x42,0x09,0xB6,0x96,0xCE,0x11,0x2D,0x5E,0xD8,0xE8};
UUID CID_CMetaData={0x0B,0xCD,0x95,0x0F,0x9F,0xB6,0x4E,0x7A,0xA7,0xCD,0xCA,0x1D,0x87,0xBA,0x9A,0x27};
  
class ICBMusicServer;
class IMetaData;

class IUnknown
{
public:
    virtual void* pguid();
    virtual void* QueryInterface(UUID* pIID, void** ppInterface);
    virtual void* AddRef();
    virtual void* Release();
};

typedef struct
{
  wchar_t artist[0x100];
  wchar_t title[0x100];
  wchar_t album[0x100];
  wchar_t year[0x100];
  wchar_t genre[0x100];
  wchar_t x6[0x100];
  wchar_t x7[0x100];
  IMetaData * pMetaData;
}METADATA_DESC;


typedef struct
{
  char cover_type;
  int size;
  int cover_offset;
}COVER_INFO_DESC;

class IMetaData: public IUnknown
{
public:
  virtual int SetFile(wchar_t* path, wchar_t* name);
  virtual int method2(void * unk1, void * unk2);
  virtual int GetTag(int tagID, wchar_t * tag);
  virtual int GetTrackNum(int unk, int * track_num);
  virtual int GetCoverInfo(COVER_INFO_DESC * cover_info);
};

class IMusicServer1 : public IUnknown
{
public:
    virtual int StartMusicServer(ICBMusicServer* pICBMusicServer, u16 msgBase, int clientData, char StartMode, int track_id);
    virtual int Destroy(unsigned long subscriptionHandle);
    virtual int Subscribe(ICBMusicServer* pICBMusicServer, u16 msgBase, int clientData, unsigned long * pSubscriptionHandle);
    virtual int Unsubscribe(unsigned long subscriptionHandle);
    virtual int StartApplication(TMusicServer_Action action);
    virtual int StopApplication(void);
    virtual int SetPurchaseFlag(void);
    virtual int GetTags(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title);
    virtual int GetFullInfo(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title, wchar_t* filename,TIME_int* Fulltime,TIME_int* ElapsedTime,bool* HaveAlbumArt,bool* IsRealMediaFile);
    virtual int GetTrackFullpath(wchar_t track_id, int bufsize, wchar_t *buf);
    virtual int GetAlbumArt(int track_id, int bufsize, wchar_t* filename, int* Offset, int* Size, char* pImageType, TBool* IsDRMProtected);
    virtual int GetState(char* State);
    virtual int Play(int track_id);
    virtual int Pause(void);
    virtual int FastFoward(void);
    virtual int Rewind(void);
    virtual void* unk_0x50();
    virtual int Previous(void);
    virtual int SetElapsedTime(TIME time);
    virtual int GetElapsedTime(TIME* time);
    virtual int SetWindowMode(char mode);
    virtual int SetStarted(TBool started);
    virtual int SetStereoWidening(TBool enable);
    virtual int EnableEqualizer(void);
    virtual int DisableEqualizer(void);
    virtual int EqualizerGain_Set(int band, int level);
    virtual int EqualizerPreset_Set(int equalizerPreset);
};

class IMusicServer2 : public IUnknown
{
public:
    virtual void* unk_0x10();
    virtual void* unk_0x14();
    virtual int GetTags(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title);
    virtual int GetFullInfo(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title, wchar_t* filename,TIME_int* Fulltime,TIME_int* ElapsedTime,bool* HaveAlbumArt,bool* IsRealMediaFile);
    virtual int GetTrackFullpath(wchar_t track_id, int bufsize, wchar_t *buf);
    virtual int GetState(char* State);
    virtual int Play(int track_id);
    virtual int Pause(void);
    virtual int FastFoward(void);
    virtual int Rewind(void);
};

class IMusicServer3 : public IUnknown
{
public:
    virtual void* unk_0x10();
    virtual void* unk_0x14();
    virtual void* unk_0x1C();
    virtual int GetTags(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title);
    virtual int GetFullInfo(int track_id, int bufsize, wchar_t* artist, wchar_t* album, wchar_t* title, wchar_t* filename,TIME_int* Fulltime,TIME_int* ElapsedTime,bool* HaveAlbumArt,bool* IsRealMediaFile);
    virtual int GetTrackFullpath(wchar_t track_id, int bufsize, wchar_t *buf);
};

class IShell: public IUnknown
{
public:
    virtual int AllocateMemory(unsigned int Size, void** Buffer);
    virtual int method1();
    virtual int method2();
    virtual int method3();
    virtual int IShell_CreateInstance(PUUID cid, PUUID iid, void** pInterface);
};

class IMusicServer_Manager: public IUnknown
{
public:
    virtual int CreateMusicServer(void*, void ** );
    virtual int method1();
};

#endif

