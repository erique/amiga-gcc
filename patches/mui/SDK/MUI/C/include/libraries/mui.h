--- SDK/MUI/C/include/libraries/mui.h	2020-12-28 10:47:33.000000000 +0100
+++ SDK/MUI/C/include/libraries/mui.h	2022-10-03 23:14:19.291054667 +0200
@@ -153,7 +153,7 @@ extern "C" {
 ***************************************************************************/
 
 #define MUIMASTER_NAME    "muimaster.library"
-#define MUIMASTER_VMIN    20
+#define MUIMASTER_VMIN    19
 #define MUIMASTER_VLATEST 20
 
 /*
@@ -633,72 +633,80 @@ struct MUI_List_TestPos_Result
 **
 ***************************************************************************/
 
-#define MenustripObject     MUI_NewObject(MUIC_Menustrip
-#define MenuObject          MUI_NewObject(MUIC_Menu
-#define MenuObjectT(name)   MUI_NewObject(MUIC_Menu,MUIA_Menu_Title,name
-#define PopmenuObject       MUI_NewObject(MUIC_Popmenu
-#define MenuitemObject      MUI_NewObject(MUIC_Menuitem
-#define WindowObject        MUI_NewObject(MUIC_Window
-#define DtpicObject         MUI_NewObject(MUIC_Dtpic
-#define ImageObject         MUI_NewObject(MUIC_Image
-#define BitmapObject        MUI_NewObject(MUIC_Bitmap
-#define BodychunkObject     MUI_NewObject(MUIC_Bodychunk
-#define PixmapObject        MUI_NewObject(MUIC_Pixmap
-#define NotifyObject        MUI_NewObject(MUIC_Notify
-#define ApplicationObject   MUI_NewObject(MUIC_Application
-#define TextObject          MUI_NewObject(MUIC_Text
-#define RectangleObject     MUI_NewObject(MUIC_Rectangle
-#define BalanceObject       MUI_NewObject(MUIC_Balance
-#define ListObject          MUI_NewObject(MUIC_List
-#define PropObject          MUI_NewObject(MUIC_Prop
-#define StringObject        MUI_NewObject(MUIC_String
-#define ScrollbarObject     MUI_NewObject(MUIC_Scrollbar
-#define ListviewObject      MUI_NewObject(MUIC_Listview
-#define RadioObject         MUI_NewObject(MUIC_Radio
-#define VolumelistObject    MUI_NewObject(MUIC_Volumelist
-#define FloattextObject     MUI_NewObject(MUIC_Floattext
-#define DirlistObject       MUI_NewObject(MUIC_Dirlist
-#define CycleObject         MUI_NewObject(MUIC_Cycle
-#define GaugeObject         MUI_NewObject(MUIC_Gauge
-#define ScaleObject         MUI_NewObject(MUIC_Scale
-#define NumericObject       MUI_NewObject(MUIC_Numeric
-#define SliderObject        MUI_NewObject(MUIC_Slider
-#define NumericbuttonObject MUI_NewObject(MUIC_Numericbutton
-#define KnobObject          MUI_NewObject(MUIC_Knob
-#define LevelmeterObject    MUI_NewObject(MUIC_Levelmeter
-#define BoopsiObject        MUI_NewObject(MUIC_Boopsi
-#define ColorfieldObject    MUI_NewObject(MUIC_Colorfield
-#define PenadjustObject     MUI_NewObject(MUIC_Penadjust
-#define ColoradjustObject   MUI_NewObject(MUIC_Coloradjust
-#define PaletteObject       MUI_NewObject(MUIC_Palette
-#define GroupObject         MUI_NewObject(MUIC_Group
-#define RegisterObject      MUI_NewObject(MUIC_Register
-#define VirtgroupObject     MUI_NewObject(MUIC_Virtgroup
-#define ScrollgroupObject   MUI_NewObject(MUIC_Scrollgroup
-#define PopstringObject     MUI_NewObject(MUIC_Popstring
-#define PopobjectObject     MUI_NewObject(MUIC_Popobject
-#define PoplistObject       MUI_NewObject(MUIC_Poplist
-#define PopaslObject        MUI_NewObject(MUIC_Popasl
-#define PendisplayObject    MUI_NewObject(MUIC_Pendisplay
-#define PoppenObject        MUI_NewObject(MUIC_Poppen
-#define AboutmuiObject      MUI_NewObject(MUIC_Aboutmui
-#define DataspaceObject     MUI_NewObject(MUIC_Dataspace
-#define DatamapObject       MUI_NewObject(MUIC_Datamap
-#define ObjectmapObject     MUI_NewObject(MUIC_Objectmap
-#define TextdataObject      MUI_NewObject(MUIC_Textdata
-#define VGroup              MUI_NewObject(MUIC_Group
-#define HGroup              MUI_NewObject(MUIC_Group,MUIA_Group_Horiz,TRUE
-#define ColGroup(cols)      MUI_NewObject(MUIC_Group,MUIA_Group_Columns,(cols)
-#define RowGroup(rows)      MUI_NewObject(MUIC_Group,MUIA_Group_Rows   ,(rows)
-#define PageGroup           MUI_NewObject(MUIC_Group,MUIA_Group_PageMode,TRUE
-#define VGroupV             MUI_NewObject(MUIC_Virtgroup
-#define HGroupV             MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Horiz,TRUE
-#define ColGroupV(cols)     MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Columns,(cols)
-#define RowGroupV(rows)     MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Rows   ,(rows)
-#define PageGroupV          MUI_NewObject(MUIC_Virtgroup,MUIA_Group_PageMode,TRUE
-#define RegisterGroup(t)    MUI_NewObject(MUIC_Register,MUIA_Register_Titles,(t)
-#define TitleObject         MUI_NewObject(MUIC_Title
-#define End                 TAG_DONE)
+#define MUI_MACRO_START(__cl) ({                                           \
+                                CONST_STRPTR ___cl = __cl;                 \
+                                struct TagItem ___tags[] = { 0
+/*                                                     <insert tag items> */
+#define MUI_MACRO_END                                        TAG_DONE };   \
+                                MUI_NewObjectA(___cl, ___tags + 1);        \
+                              })
+
+#define MenustripObject     MUI_MACRO_START(MUIC_Menustrip)
+#define MenuObject          MUI_MACRO_START(MUIC_Menu)
+#define MenuObjectT(name)   MUI_MACRO_START(MUIC_Menu),MUIA_Menu_Title,name
+#define PopmenuObject       MUI_MACRO_START(MUIC_Popmenu)
+#define MenuitemObject      MUI_MACRO_START(MUIC_Menuitem)
+#define WindowObject        MUI_MACRO_START(MUIC_Window)
+#define DtpicObject         MUI_MACRO_START(MUIC_Dtpic)
+#define ImageObject         MUI_MACRO_START(MUIC_Image)
+#define BitmapObject        MUI_MACRO_START(MUIC_Bitmap)
+#define BodychunkObject     MUI_MACRO_START(MUIC_Bodychunk)
+#define PixmapObject        MUI_MACRO_START(MUIC_Pixmap)
+#define NotifyObject        MUI_MACRO_START(MUIC_Notify)
+#define ApplicationObject   MUI_MACRO_START(MUIC_Application)
+#define TextObject          MUI_MACRO_START(MUIC_Text)
+#define RectangleObject     MUI_MACRO_START(MUIC_Rectangle)
+#define BalanceObject       MUI_MACRO_START(MUIC_Balance)
+#define ListObject          MUI_MACRO_START(MUIC_List)
+#define PropObject          MUI_MACRO_START(MUIC_Prop)
+#define StringObject        MUI_MACRO_START(MUIC_String)
+#define ScrollbarObject     MUI_MACRO_START(MUIC_Scrollbar)
+#define ListviewObject      MUI_MACRO_START(MUIC_Listview)
+#define RadioObject         MUI_MACRO_START(MUIC_Radio)
+#define VolumelistObject    MUI_MACRO_START(MUIC_Volumelist)
+#define FloattextObject     MUI_MACRO_START(MUIC_Floattext)
+#define DirlistObject       MUI_MACRO_START(MUIC_Dirlist)
+#define CycleObject         MUI_MACRO_START(MUIC_Cycle)
+#define GaugeObject         MUI_MACRO_START(MUIC_Gauge)
+#define ScaleObject         MUI_MACRO_START(MUIC_Scale)
+#define NumericObject       MUI_MACRO_START(MUIC_Numeric)
+#define SliderObject        MUI_MACRO_START(MUIC_Slider)
+#define NumericbuttonObject MUI_MACRO_START(MUIC_Numericbutton)
+#define KnobObject          MUI_MACRO_START(MUIC_Knob)
+#define LevelmeterObject    MUI_MACRO_START(MUIC_Levelmeter)
+#define BoopsiObject        MUI_MACRO_START(MUIC_Boopsi)
+#define ColorfieldObject    MUI_MACRO_START(MUIC_Colorfield)
+#define PenadjustObject     MUI_MACRO_START(MUIC_Penadjust)
+#define ColoradjustObject   MUI_MACRO_START(MUIC_Coloradjust)
+#define PaletteObject       MUI_MACRO_START(MUIC_Palette)
+#define GroupObject         MUI_MACRO_START(MUIC_Group)
+#define RegisterObject      MUI_MACRO_START(MUIC_Register)
+#define VirtgroupObject     MUI_MACRO_START(MUIC_Virtgroup)
+#define ScrollgroupObject   MUI_MACRO_START(MUIC_Scrollgroup)
+#define PopstringObject     MUI_MACRO_START(MUIC_Popstring)
+#define PopobjectObject     MUI_MACRO_START(MUIC_Popobject)
+#define PoplistObject       MUI_MACRO_START(MUIC_Poplist)
+#define PopaslObject        MUI_MACRO_START(MUIC_Popasl)
+#define PendisplayObject    MUI_MACRO_START(MUIC_Pendisplay)
+#define PoppenObject        MUI_MACRO_START(MUIC_Poppen)
+#define AboutmuiObject      MUI_MACRO_START(MUIC_Aboutmui)
+#define DataspaceObject     MUI_MACRO_START(MUIC_Dataspace)
+#define DatamapObject       MUI_MACRO_START(MUIC_Datamap)
+#define ObjectmapObject     MUI_MACRO_START(MUIC_Objectmap)
+#define TextdataObject      MUI_MACRO_START(MUIC_Textdata)
+#define VGroup              MUI_MACRO_START(MUIC_Group)
+#define HGroup              MUI_MACRO_START(MUIC_Group),MUIA_Group_Horiz,TRUE
+#define ColGroup(cols)      MUI_MACRO_START(MUIC_Group),MUIA_Group_Columns,(cols)
+#define RowGroup(rows)      MUI_MACRO_START(MUIC_Group),MUIA_Group_Rows   ,(rows)
+#define PageGroup           MUI_MACRO_START(MUIC_Group),MUIA_Group_PageMode,TRUE
+#define VGroupV             MUI_MACRO_START(MUIC_Virtgroup)
+#define HGroupV             MUI_MACRO_START(MUIC_Virtgroup),MUIA_Group_Horiz,TRUE
+#define ColGroupV(cols)     MUI_MACRO_START(MUIC_Virtgroup),MUIA_Group_Columns,(cols)
+#define RowGroupV(rows)     MUI_MACRO_START(MUIC_Virtgroup),MUIA_Group_Rows   ,(rows)
+#define PageGroupV          MUI_MACRO_START(MUIC_Virtgroup),MUIA_Group_PageMode,TRUE
+#define RegisterGroup(t)    MUI_MACRO_START(MUIC_Register),MUIA_Register_Titles,(t)
+#define TitleObject         MUI_MACRO_START(MUIC_Title)
+#define End                 MUI_MACRO_END
 
 #define Child             MUIA_Group_Child
 #define SubWindow         MUIA_Application_Window
@@ -4303,9 +4311,9 @@ struct MUI_AlphaData
 #ifndef TEXTINPUT_MCC_H
 #define TEXTINPUT_MCC_H
 #define MUIC_Textinput "Textinput.mcc"
-#define TextinputObject MUI_NewObject(MUIC_Textinput
+#define TextinputObject MUI_MACRO_START(MUIC_Textinput)
 #define MUIC_Textinputscroll "Textinputscroll.mcc"
-#define TextinputscrollObject MUI_NewObject(MUIC_Textinputscroll
+#define TextinputscrollObject MUI_MACRO_START(MUIC_Textinputscroll)
 #define MCC_TI_TAGBASE ((TAG_USER)|((1307<<16)+0x712))
 #define MCC_TI_ID(x) (MCC_TI_TAGBASE+(x))
 #define MCC_Textinput_Version 29
