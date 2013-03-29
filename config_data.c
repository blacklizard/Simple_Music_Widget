#include "..\\include\cfg_items.h"
#include "config_data.h"

#pragma diag_suppress = Pe177



__root const CFG_HDR cfghdr1 = { CFG_LEVEL ,"Animation" , 1 , 0}; 


	__root const CFG_HDR cfghdr2 = { CFG_LEVEL ,"Entrance" , 1 , 0}; 
	
		__root const CFG_HDR cfghdr3 = { CFG_CBOX , "Speed" , 0 , 4 }; 
		__root const int ANIMATION_ENTRANCE_SPEED = 3; 
		__root const CFG_CBOX_ITEM cfgRadioBtn3[4] = {"Fast" , "Medium" , "Slow" , "Super Slow"};
		

		__root const CFG_HDR cfghdr4 = { CFG_CBOX , "Fade" , 0 , 2 }; 
		__root const int ANIMATION_ENTRANCE_FADE = 0; 
		__root const CFG_CBOX_ITEM cfgRadioBtn4[2] = {"In" , "Out"};
		

		__root const CFG_HDR cfghdr5 = { CFG_CBOX , "Style" , 0 , 4 }; 
		__root const int ANIMATION_ENTRANCE_STYLE = 2; 
		__root const CFG_CBOX_ITEM cfgRadioBtn5[4] = {"Maximize" , "Minimize" , "Enter" , "Exit"};
		

		__root const CFG_HDR cfghdr6 = { CFG_CBOX , "Enter From" , 0 , 8 }; 
		__root const int ANIMATION_ENTRANCE_ENTERFROM = 1; 
		__root const CFG_CBOX_ITEM cfgRadioBtn6[8] = {"Right" , "Left" , "Bottom" , "Top" , "Bottom Right" , "Bottom Left" , "Top Left" , "Top Right"};
		
	__root const CFG_HDR cfghdr8 = {CFG_LEVEL , "" , 0 , 0 }; 

	
	__root const CFG_HDR cfghdr7 = { CFG_LEVEL ,"Exit" , 1 , 0}; 
	

		__root const CFG_HDR cfghdr9 = { CFG_CBOX , "Speed" , 0 , 4 }; 
		__root const int ANIMATION_EXIT_SPEED = 3; 
		__root const CFG_CBOX_ITEM cfgRadioBtn9[4] = {"Fast" , "Medium" , "Slow" , "Super Slow"};
		

		__root const CFG_HDR cfghdr10 = { CFG_CBOX , "Fade" , 0 , 2 }; 
		__root const int ANIMATION_EXIT_FADE = 1; 
		__root const CFG_CBOX_ITEM cfgRadioBtn10[2] = {"In" , "Out"};
		

		__root const CFG_HDR cfghdr11 = { CFG_CBOX , "Style" , 0 , 4 }; 
		__root const int ANIMATION_EXIT_STYLE = 3; 
		__root const CFG_CBOX_ITEM cfgRadioBtn11[4] = {"Maximize" , "Minimize" , "Enter" , "Exit"};
		

		__root const CFG_HDR cfghdr12 = { CFG_CBOX , "Exit To" , 0 , 8 }; 
		__root const int ANIMATION_EXIT_EXITTO = 1; 
		__root const CFG_CBOX_ITEM cfgRadioBtn12[8] = {"Left" , "Right" , "Top" , "Bottom" , "Bottom Right" , "Bottom Left" , "Top Left" , "Top Right"};
		
	__root const CFG_HDR cfghdr14 = {CFG_LEVEL , "" , 0 , 0 }; 

	
__root const CFG_HDR cfghdr15 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr13 = { CFG_LEVEL ,"CoverArt" , 1 , 0}; 


	__root const CFG_HDR cfghdr16 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int COVERART_ENABLE = 1; 
	

	__root const CFG_HDR cfghdr17 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT COVERART_POSITION = {165 , 212 , 25 , 72}; 
	
__root const CFG_HDR cfghdr19 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr18 = { CFG_LEVEL ,"Overlay" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr20 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int OVERLAY_ENABLE = 1; 
	
	
	__root const CFG_HDR cfghdr21 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
	__root const int OVERLAY_POSITION_X = 150; 
	__root const int OVERLAY_POSITION_Y = 10; 
	
__root const CFG_HDR cfghdr23 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr22 = { CFG_LEVEL ,"Panel" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr24 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int PANEL_ENABLE = 1; 
	
	
	__root const CFG_HDR cfghdr25 = { CFG_COORDINATES , "Position" , 0 , 0 }; 
	__root const int PANEL_POSITION_X = 40; 
	__root const int PANEL_POSITION_Y = 20; 
	
__root const CFG_HDR cfghdr27 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr26 = { CFG_LEVEL ,"Title" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr28 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int TITLE_ENABLE = 1; 
	
	
	__root const CFG_HDR cfghdr29 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT TITLE_POSITION = {55 , 145 , 32 , 32}; 
	
	
	__root const CFG_HDR cfghdr30 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int TITLE_FONTSIZE = 0x10F; 
	
	
	__root const CFG_HDR cfghdr31 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int TITLE_TEXTCOLOR = 0xFFFFFFFF; 
	
	
	__root const CFG_HDR cfghdr32 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int TITLE_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn32[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr34 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr33 = { CFG_LEVEL ,"Artist" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr35 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int ARTIST_ENABLE = 1; 
	
	
	__root const CFG_HDR cfghdr36 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT ARTIST_POSITION = {55 , 140 , 48 , 48}; 
	
	
	__root const CFG_HDR cfghdr37 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int ARTIST_FONTSIZE = 15; 
	
	
	__root const CFG_HDR cfghdr38 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int ARTIST_TEXTCOLOR = 0xFFFFFFFF; 
	
	
	__root const CFG_HDR cfghdr39 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int ARTIST_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn39[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr41 = {CFG_LEVEL , "" , 0 , 0 }; 



__root const CFG_HDR cfghdr40 = { CFG_LEVEL ,"Album" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr42 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int ALBUM_ENABLE = 0; 
	
	
	__root const CFG_HDR cfghdr43 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT ALBUM_POSITION = {0 , 0 , 0 , 0}; 
	
	
	__root const CFG_HDR cfghdr44 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int ALBUM_FONTSIZE = 0x11; 
	
	
	__root const CFG_HDR cfghdr45 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int ALBUM_TEXTCOLOR = 0xFF000000; 
	
	
	__root const CFG_HDR cfghdr46 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int ALBUM_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn46[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr48 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr47 = { CFG_LEVEL ,"Total Time" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr49 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int TOTALTIME_ENABLE = 0; 
	
	
	__root const CFG_HDR cfghdr50 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT TOTALTIME_POSITION = {0 , 0 , 0 , 0}; 
	
	
	__root const CFG_HDR cfghdr51 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int TOTALTIME_FONTSIZE = 0x11; 
	
	
	__root const CFG_HDR cfghdr52 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int TOTALTIME_TEXTCOLOR = 0xFF000000; 
	
	
	__root const CFG_HDR cfghdr53 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int TOTALTIME_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn53[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr55 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr54 = { CFG_LEVEL ,"Remaining Time" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr56 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int REMAININGTIME_ENABLE = 0; 
	
	
	__root const CFG_HDR cfghdr57 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT REMAININGTIME_POSITION = {0 , 0 , 0 , 0}; 
	
	
	__root const CFG_HDR cfghdr58 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int REMAININGTIME_FONTSIZE = 0x11; 
	
	
	__root const CFG_HDR cfghdr59 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int REMAININGTIME_TEXTCOLOR = 0xFF000000; 
	
	
	__root const CFG_HDR cfghdr60 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int REMAININGTIME_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn60[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr62 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr61 = { CFG_LEVEL ,"Elapsed Time" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr63 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int ELAPSEDTIME_ENABLE = 0; 
	
	
	__root const CFG_HDR cfghdr64 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT ELAPSEDTIME_POSITION = {0 , 0 , 0 , 0}; 
	
	
	__root const CFG_HDR cfghdr65 = {CFG_FONT , "Font Size" , 0 , 0};
	__root const int ELAPSEDTIME_FONTSIZE = 0x11; 
	
	
	__root const CFG_HDR cfghdr66 = { CFG_COLOR_INT , "Text Color" , 0 , 0}; 
	__root const unsigned int ELAPSEDTIME_TEXTCOLOR = 0xFF000000; 
	
	
	__root const CFG_HDR cfghdr67 = { CFG_CBOX , "Align" , 0 , 3 }; 
	__root const int ELAPSEDTIME_ALIGN = 0; 
	__root const CFG_CBOX_ITEM cfgRadioBtn67[3] = {"Left" , "Right" , "Center"};
	
__root const CFG_HDR cfghdr69 = {CFG_LEVEL , "" , 0 , 0 }; 


__root const CFG_HDR cfghdr68 = { CFG_LEVEL ,"Progress Bar" , 1 , 0}; 

	
	__root const CFG_HDR cfghdr70 = {CFG_CHECKBOX , "Enable" , 0 , 0 }; 
	__root const int PROGRESSBAR_ENABLE = 1; 
	
	
	__root const CFG_HDR cfghdr71 = {CFG_CHECKBOX , "Bolb Image" , 0 , 0 }; 
	__root const int PROGRESSBAR_BOLBIMAGE = 0; 
	
	
	__root const CFG_HDR cfghdr72 = {CFG_RECT , "Position" , 0 , 0};
	__root const RECT PROGRESSBAR_POSITION = {30 , 229 , 214 , 227}; 
	
	
	__root const CFG_HDR cfghdr73 = { CFG_COLOR_INT , "Elapsed Color" , 0 , 0}; 
	__root const unsigned int PROGRESSBAR_ELAPSEDCOLOR = 0xFFFF8000; 
	
	
	__root const CFG_HDR cfghdr74 = { CFG_COLOR_INT , "Background Color" , 0 , 0}; 
	__root const unsigned int PROGRESSBAR_BACKGROUNDCOLOR = 0xFF000000; 
	
__root const CFG_HDR cfghdr75 = {CFG_LEVEL , "" , 0 , 0 }; 


