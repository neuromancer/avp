#ifndef _BINK_H_
#define _BINK_H_

extern BOOL BinkSys_Init();
extern void BinkSys_Release();

//--- intro/outro
extern void PlayBinkedFMV(char *filenamePtr, int volume);

//--- menu background
extern void StartMenuBackgroundBink();
extern int 	PlayMenuBackgroundBink();
extern void EndMenuBackgroundBink();

//---- music
extern int StartMusicBink(char* filenamePtr, BOOL looping);
extern int PlayMusicBink(int volume);
extern void EndMusicBink();


//---- ingame fmv
typedef unsigned int 	FMVHandle;

extern FMVHandle  	CreateBinkFMV(char* filenamePtr);
extern int			UpdateBinkFMV(FMVHandle aFmvHandle, int volume);
extern void 		CloseBinkFMV(FMVHandle aFmvHandle);
extern char*		GetBinkFMVImage(FMVHandle aFmvHandle);



#endif //_BINK_H_
