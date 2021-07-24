/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  * ::: Description :::
  :* ::> Student Database Manager
  ::* ::> Designed And Programed By* :: SURAJ SINGH ::
  :::* ::> Feel Secure With The Concept of Object Oriented Program
  ::::* ::> It Made By Using Classes And Functions

  * ::: Features :::
  :* ::> Add Student Details
  ::* ::> See Student Details
  :::* ::> Edit Student Details
  ::::* ::> Delete Student Details
  :::::* ::> If You Forgot Your Password! Then You Can Change It With The Help Of Master Password

  * ::: Advanced Features :::
  :* ::> It Has Artificial Intelligence
  ::* ::> Full Secured
  :::* ::> It Gives You Independent Access To Your Database
  ::::* ::> The Students Can Only Add And See Their Database i.e. They Need Master Password To Change Their Database!
  :::::* ::> The Master Password Cannot Be Changed By User Only The Developer Can Change It

  NOTE: FUNCTIONS WHICH HAVE A "NOT YET USED" WRITTEN ON THEIR SIDE ARE NOT REQUIRED FOR THE FUNCTIONING OF THIS PROGRAM

*/
//#define _WIN32_WINNT 0x05232        //***********
#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<sstream>
#include<iomanip>
#include<ctype.h>
#include<windows.h>
#include<dir.h>
#include<math.h>
#include<limits>
#include<process.h>
using namespace std;

/*********************************************************************************************************************************************************/
//for positioning cursor at different locations on the console screen
#define console GetStdHandle(STD_OUTPUT_HANDLE)
//coordinate variable
COORD CursorPosition;
/*---------------------------------------------------------------------------------------------------------------------------------------*
// Color For BackGround
#define Back0 0                 // 0 = Black
#define Back1 16                // 1 = Blue
#define Back2 32                // 2 = Green
#define Back3 48                // 3 = Aqua
#define Back4 64                // 4 = Red
#define Back5 80                // 5 = Purple
#define Back6 96                // 6 = Yellow
#define Back7 112               // 7 = White
#define Back8 128               // 8 = Gray
#define Back9 144               // 9 = Light Blue
#define BackA 160               // A/10 = Light Green
#define BackB 176               // B/11 = Light Aqua
#define BackC 192               // C/12 = Light Red
#define BackD 208               // D/13 = Light Purple
#define BackE 224               // E/14 = Light Yellow
#define BackF 240               // F/15 = Bright White

// Color For ForeGround
#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

// Some Most Used Color
#define C1 Color(Back7,0);
#define C2 Color(Back7,9);

// Some Constant Functions
#define Console GetStdHandle(STD_OUTPUT_HANDLE)
#define ScrnMax HWND consoleWindow = GetConsoleWindow();\
        ShowWindow(consoleWindow,SW_MAXIMIZE);
#define ScrnExpend COORD WindowSize;WindowSize.X = 120;WindowSize.Y = 300;SetConsoleScreenBufferSize(Console,WindowSize);
#define Window HWND HD=GetConsoleWindow();\
        if(HD!=NULL){SetWindowPos(HD,0,0,0,1024,640,SWP_SHOWWINDOW|SWP_NOMOVE);}
/*---------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct FONT
{
    ULONG size;
    DWORD FONT;
    COORD FontSize;
    UINT FontFamily;
    UINT FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}FONT ,*PFONT;
extern "C" {BOOL WINAPI SetCurrentConsoleFontEx(HANDLE ConsoleOutput, BOOL MaximumWindow, PFONT);}
/*********************************************************************************************************************************************************/

/*********************************************************************************************************************************************************/
//for setting different font colors
enum COLOR
{
            BLACK , BLUE ,GREEN , CYAN , RED , MAGENTA , BROWN , NORMAL, DARKGRAY , LIGHTBLUE , LIGHTGREEN , LIGHTCYAN , LIGHTRED, LIGHTMAGENDA , YELLO , WHITE
};          //learn the code but don't change the order, since doing so will dis-match all the color orders & this will work in incorrect way
ostream& operator<<(ostream &stm ,const COLOR &c)
{
    HANDLE out_handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out_handle, c);
    return (stm);
}
/*********************************************************************************************************************************************************/

class student
{
private:
        char name[32],fathers_name[32],mothers_name[32],clas[64],section[64],roll_number[64];
        char admission_date[64],admission_number[64],birth_date[64],blood_group[64],gender[64];
        char address[64],cast[64],phone_number[64],email[64],char_height[64],char_weight[64];
        char char_result_10[64],char_result_12[64],unique_id[64];

         // Data Variables for Temporary Use
        char temp_name[64],temp_fathers_name[64],temp_mothers_name[64],temp_clas[64],temp_section[64];
        char temp_roll_number[64],temp_admission_date[64],temp_admission_number[64],temp_birth_date[64];
        char temp_blood_group[64],temp_gender[64],temp_address[64],temp_cast[64],temp_phone_number[64];
        char temp_email[64],temp_char_height[64],temp_char_weight[64],temp_char_result_10[64];
        char temp_char_result_12[64],temp_unique_id[64],temp_bmi[64];
        int temp_i;

        // Other Variables
        char mast_pass[16],fname[64],fname_old[64],fcode[64],fcode_old[64],password[16],passcode[16],char_bmi[16];

        // Floating Point Variables
        float height,weight,bmi;

        inline void call_clear()        //a valid reason for it.
        {   system("cls");    }
        inline call_pause()
        {   system("pause");   }        //a valid reason for it.
public:
/********************************************************************************/
    void call_main();                               //NEW
    void call_header();                             //NEW
    void about();                                   //NEW
       inline void loop(char *temp_str)             //NEW
        {
            int len = strlen(temp_str);
            for(int temp_i=0;temp_i<len;++temp_i)
            {   Sleep(20);      cout<<temp_str[temp_i]; }
            Sleep(400);
        }
    void get_data();
        void background_process();
        void store_data();
        void make_file(char* , char*);

    void get_details();
        void show_details();
        char* get_file(char*);

    void data_edit_start();
        void edit_data();                           //enhanced

    void delete_data();                             //enhanced

    void forgot_password();

    void rem_database();                            //NEW
    void call_rem_header();                         //NEW
    inline void fast_loop(char *fast_str)
    {
        int len = strlen(fast_str);
        for(int temp_i=0;temp_i<len;++temp_i)
        { Sleep(10);    cout<<fast_str[temp_i]; }
        Sleep(200);
    }
/***********************************************************************************/

     // These Functions are for Artificial Intelligence
    // These Functions are used in this program give Artificial Intelligence
    // They prevents wrong Input from User
    int is_digit_alpha(char*);                      //NEW
    int alpha(char*);                              //REDEFINED
    int check_gender(char*);                       //NEW
    int check_blood_grp(char*);                    //Redefined
    int check_int(char*);                          //NEW
    int check_date(char*);                         //NEW
    int check_date_int(char*);                     //NEW
    int check_cast(char *);                        //RENAMED
    int check_email(char*);                        //NEW
    int check_ph_no(char*);                        //NEW
    int id_check(char*);                           //NEW
    inline int int_len(char* str)                  //NEW
    {
        unsigned long long val=0,counter=0;
        stringstream(str)>>val;
        while(val!=0)
        { val/=10; ++counter; }
        return counter;
    }
    int check_equality_dates( char * , char *);     //NEW
    int check_avail(char *);                        //NEW
    int check_adno_id(char *,char *);               //NEW
    int chk_eqult_2(char *, char *);                //NEW
/*************************************************************************************/
    // These are Form Converters
    int value_of(char* );                            //NEW
    char* upper_case(char*);
    char* all_upper(char*);                         //RENAMED
    char* to_underscore(char*);                     //RENAMED
    char* no_underscore(char*);                     //Renamed
    /************************************************************/
    //cursor teleporter along-with definition
    inline void gotoXY(int x,int y)
    {
        CursorPosition.X = x;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(console,CursorPosition);
    }

    //changes the font                              //NOT USED YET
    void FONT(int);

    void color(char , char);                        //NOT YET USED
    /************************************************************/
    //"STORES THE MAIN PASSWORD ENTERED ALONWITH THE STUDENT DETAILS" In A Separate Directory
    void store_password();

    // Others
        char* get_pass(char*, int, int, int);       //A LITTLE BIT REDESIGNED
        void frename();
        void store_bmi();
        void MakeDocument();
        void reset_temp_vars();                     //NEW
/***************************************************************************************/
}data;



/*******************************************************************************************************************************************************/
int main()      //Have a look on my main()
{
    /*
    char a[32]={"set_pri.bat"},set_pri_cd[256];
    strcpy(set_pri_cd,"wmic process where name=\"RedefinedStudent Database Manager.exe\" CALL setpriority \"high priority\"");

    ofstream file;
    file.open(a);     //not setting ios::out as i will apply system attrib to it
    file<<set_pri_cd;
    file.close();

    system("attrib +s +h set_pri.bat");     //attrib system file and hidden
    ShellExecute(NULL,"open","set_pri.bat",NULL,NULL,SW_HIDE);
    */

    cout<<WHITE;
    data.call_main();
    return EXIT_SUCCESS;
}
/********************************************************************************************************************************************************/

/*********************************************************************************************************************************************************/
void student::about()
{
    call_clear();
    char abt_str1[200]="Designed And Programed By || SURAJ SINGH || \nFeel Secure With The Program As Security Is given Priority\n";
    char abt_str2[200]="Add Student Details\nAccess Student Details\nEdit Student Details\nDelete Student Details\nIf You Forgot Your Password! Then You Can Change It With The Help Of Master Password\n";
    char abt_str3[400]="It Has Ability To Discard Wrong Inputs\nFully Secured\nIt Gives You Independent Access To Your Database\nThe Students Can Only Add And Access Their Own Database Record \ni.e. They Need Master Password To Change Their Database!\nThe Master Password Cannot Be Changed By User Only The Developer Can Change It\n";
    char abt_str4[400]="Don't Touch Any Other File If Present In The DataBase, You can Loose Your Information If You Do So\n";
    char abt_str5[400]="They Might Be Some System Files Which Should Only Be Used By The Program. \nUsers Should Not Interact With Such Files If Any.";
    for(int i=0;i<120;++i)
    {
        cout<<":";
    }
    cout<<"\n\t\t\tProgram Version: 4.5.1 "
        <<"\tDeveloped Under REDSTONE 3 (Windows Platform)\n";

    cout<<CYAN<<"\n\nDescription \n\n";
    Sleep(100);

    cout<<YELLO<<"Student Database Manager\n";
    cout<<LIGHTGREEN;
    loop(abt_str1);

    cout<<YELLO<<"\nFeatures\n"
        <<LIGHTMAGENDA;
    loop(abt_str2);
    Sleep(100);

    cout<<YELLO<<"\nAdvanced Features\n"
        <<BROWN;
    loop(abt_str3);
    Sleep(100);

    cout<<LIGHTRED<<"\nWARNING:\n";
    loop(abt_str4);
    loop(abt_str5);

    cout<<DARKGRAY;
        cin.ignore();
        cin.get();
        system("TIMEOUT -T 3 -NOBREAK");
        cout<<WHITE;
        call_clear();
        call_main();
}

/********************************************************************************************************************************************************/
void student::call_header()
{
    cout<<LIGHTCYAN;
    unsigned int i=0;
    for(i=0;i<=96;++i)
    {   cout<<"~";  }
    cout<<endl;

    for(i=0;i<=30;++i)
    {   cout<<"|";  }
    cout<<"STUDENT DATAABASE MANAGEMENT SYSTEM";
    for(i=0;i<=30;++i)
    {   cout<<"|";  }
    cout<<endl;

    cout<<setw(27)<<""<<"||||||||||"<<"BY MASTER SURAJ SINGH"<<"||||||||||||";
    cout<<endl;

     for(i=0;i<=96;++i)
    {   cout<<"~";  }
    cout<<WHITE;
}

void student::call_main()
{
    call_clear();
    call_header();
    cout<<LIGHTCYAN;
    unsigned int choice=0;
    cout<<"\n\n";
    cout<<setw(20)<<""<<"1.ADD STUDENT DETAILS"<<endl;
    cout<<setw(20)<<""<<"2.SHOW STUDENT DETAILS"<<endl;
    cout<<setw(20)<<""<<"3.EDIT STUDENT DETAILS"<<endl;
    cout<<setw(20)<<""<<"4.DELETE STUDENT DATA"<<endl;
    cout<<setw(20)<<""<<"5.FORGOTTEN PASSWORD"<<endl;
    cout<<setw(20)<<""<<"6.ADVANCED OPTIONS"<<endl;
    cout<<setw(20)<<""<<"7.ABOUT"<<endl;
    cout<<setw(20)<<""<<"0.EXIT()"<<endl<<endl;
    cout<<setw(20)<<""<<"Enter Your Choice:";
    cout<<WHITE;
    cin>>choice;
    switch(choice)
    {
    case 1:
        Beep(3397,50);  get_data(); break;
    case 2:
        Beep(3397,50);  get_details(); break;
    case 3:
        Beep(3397,50);  data_edit_start(); break;
    case 4:
        Beep(3397,50);  delete_data(); break;
    case 5:
        Beep(3397,50);  forgot_password(); break;
    case 6:
        Beep(5445,998); rem_database(); break;
    case 7:
        Beep(3397,50);  about(); break;
    case 0:
        Beep(3300,90);  Beep(3300,90);
        Beep(3300,900); exit(0);
    default:
        cout<<LIGHTRED;
        cout<<"\b"; cout<<"\b";
        cout<<"\n\n"<<setw(30)<<""<<" -------INVALID CHOICE--------\n\n\n\n\n\n\n\n ";
            Beep(2397,800);
        system(" TIMEOUT -T 5 -NOBREAK");
        {
            call_clear();
            if(cin.fail())      //this function will clear Whats-ever is present in cin() buffer. so that recursion will work perfectly.
            {                       //fflush is also fine but it makes sometimes abnormal behavior so no risks
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            call_main();
        }

    }

    if(choice==1)
        {
            cout<<"\n\t::::: Loading!:::::\n";
            MakeDocument();
            system("TIMEOUT /t 0 /NOBREAK");   // It Stops the Program Execution For A While Without Displaying the Timer
        }
        call_main();
}
/*********************************************************************************************************************************************************/
void student::get_data()
{
    data.call_clear();
    data.call_header();
    unsigned int x_cord=40;
    unsigned int y_cord=5;
    cout<<endl<<setw(7)<<""<<"Please Fill In The Following Details Carefully\n";
    cout<<setw(7)<<"|>"<<"Student's Name"<<setw(17)<<""<<":>"; gets(name);
    while(name[0]=='\0'||value_of(name)!=0)
    { gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(name);}
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Class(If Passed out type 13)"<<setw(5)<<":>"; gets(clas);
    while(clas[0]=='\0'||clas[2]!='\0'||is_digit_alpha(clas)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord);  gets(clas);}      //gotoXY() then set a width of 100 chars and ""(i.e. write blank space or no character on it) then again go back gotoXY()
    ++y_cord;

    if(value_of(clas)<13){                                             //since the user will enter class within 1 to 13 & these are classes in schools
        cout<<setw(5)<<""<<"|>"<<"Section"<<setw(26)<<":>"; gets(section);
        while(section[0]=='\0'||section[1]!='\0'||alpha(section)!=0)
        { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(section); }
        ++y_cord;
    }
    else
        strcpy(section,"NIL");

    cout<<setw(7)<<"|>"<<"Roll Number"<<setw(20)<<""<<":>"; gets(roll_number);
    while(roll_number[0]=='\0'||check_int(roll_number)!=0)           //if all char are int then value returned will be 0 else not
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(roll_number); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Father's Name"<<setw(18)<<""<<":>"; gets(fathers_name);
    while(fathers_name[0]=='\0'||value_of(fathers_name)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(fathers_name); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Mother's Name"<<setw(18)<<""<<":>"; gets(mothers_name);
    while(mothers_name[0]=='\0'||value_of(mothers_name)!=0||(strcmp(fathers_name,mothers_name)==0))
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(mothers_name); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Gender(M/F)"<<setw(20)<<""<<":>"; gets(gender);
    while(gender[0]=='\0'||gender[1]!='\0'||check_gender(gender)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(gender); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Blood Group"<<setw(20)<<""<<":>"; gets(blood_group);
    while(blood_group[0]=='\0'||check_blood_grp(blood_group)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(blood_group); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Admission No"<<setw(19)<<""<<":>"; gets(admission_number);
    while(admission_number[0]=='\0'||check_int(admission_number)!=0||int_len(admission_number)!=4)
    {  cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(admission_number); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Admission Date(DD/MM/YYYY)"<<setw(5)<<""<<":>"; gets(admission_date);
    while(admission_date[0]=='\0'||check_date(admission_date)!=0||check_avail(admission_date)!=0||admission_date[10]!='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(admission_date); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<""<<":>"; gets(birth_date);
    while(birth_date[0]=='\0'||check_date(birth_date)!=0||check_equality_dates(birth_date,admission_date)==0||birth_date[10]!='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(birth_date);}
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Address"<<setw(24)<<""<<":>";gets(address);
    while(address[0]=='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(address);}
    ++y_cord;
    /***************************************************************************************************/
    cout<<setw(7)<<"|>"<<"Category(SC/ST/OBC/GEN)"<<setw(10)<<":>";gets(cast);
    while(cast[0]=='\0'||check_cast(cast)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(cast); }
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Phone Number"<<setw(21)<<":>";gets(phone_number);
    while(check_ph_no(phone_number)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(phone_number);}
    phone_number[10]='\0';
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Email ID"<<setw(25)<<":>";gets(email);
    while(strlen(email)<12||check_email(email)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(email);}
    ++y_cord;
    /*************************************************************************************************************************************************/
    cout<<setw(7)<<"|>"<<"Height(in Centimeters)"<<setw(11)<<":>";gets(char_height);
    while(char_height[0]=='\0'||check_int(char_height)!=0||int_len(char_height)>3||int_len(char_height)<=2||value_of(char_height)>180)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(char_height);}
    ++y_cord;
/*******************/
    cout<<setw(7)<<"|>"<<"Weight(in Kilograms)"<<setw(13)<<":>";gets(char_weight);
    while(char_weight[0]=='\0'||check_int(char_weight)!=0||int_len(char_weight)>3||value_of(char_weight)>100)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(char_weight);}
    ++y_cord;
/*******************/
    cout<<setw(7)<<"|>"<<"Student's Unique ID"<<setw(14)<<":>";gets(unique_id);
    while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15||check_adno_id(admission_number,unique_id)!=0)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(unique_id);}
    ++y_cord;

    if(value_of(clas)>10){
    cout<<setw(7)<<"|>"<<"Result of 10th(in %age)"<<setw(10)<<":>";gets(char_result_10);
    while(char_result_10[0]=='\0'||(value_of(char_result_10)<33)||(value_of(char_result_10)>100))
    {cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(char_result_10); }
    ++y_cord; }

    if(value_of(clas)>12){
    cout<<setw(7)<<"|>"<<"Result of 12th(in %age)"<<setw(10)<<":>";gets(char_result_12);
    while(char_result_12[0]=='\0'||(value_of(char_result_12)<33)||(value_of(char_result_12)>100))
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(char_result_12);}
    ++y_cord; }

    cout<<setw(7)<<"|>"<<"Password (OF Length 8)"<<setw(11)<<":>";
    strcpy( password , get_pass(password,8,x_cord,y_cord) );

    //calling for the next step
    background_process();

}
/*******************************************************************************/
void student::background_process()
{
    /****************************************************************/
    //COPYING STRINGS TO TEMPORARY VARIABLES
    reset_temp_vars();
    /****************************************************************/

    //converting ORIGINAL data to their standard form
    strcpy(name,upper_case(name));
    strcpy(fathers_name,upper_case(fathers_name));
    strcpy(mothers_name,upper_case(mothers_name));
    strcpy(blood_group,all_upper(blood_group));
    strcpy(address,upper_case(address));
    strcpy(cast,all_upper(cast));
    strcpy(section,all_upper(section));

    //Adding full form of Gender
    if(gender[0]=='m'||gender[0]=='M') {    strcpy(gender,"Male");  }
    else strcpy(gender,"Female");

    //THE FILE AND FOLDER MAKING PROCESS STARTED......

    //First check whether the folder exists or not then CREATE
    if(!mkdir("database"));
    system("attrib +s +h database");        //hide database folder permanently , even can't be detected through cmd or any other program
                                            //only program can access it.

    //Creating sub folder name

    strcpy(fname,"database\\");
    strcat(fname,unique_id);
    strcat(fname,"_");

    int i=0; char temp[16];
    strcpy(temp,birth_date);        //birth date copied into temp var
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){ temp[i]='_'; }
        ++i;
    }

    strcat(fname,temp);  //now add birth date(stored in temp) to fname

    if(!mkdir(fname));
    store_data();
}
/*****************************************************************************/
//now database files are created on the hard drive in the format ".dbm" and stores the student data in them
void student::store_data()
{
    /*First check whether the folder already exists or not then Create
      the folder whose name was prepared in background_process() fn earlier*/
    if(!mkdir(fname));      /*The folder created */

    //Replacing the spaces with underscores
    strcpy(name,to_underscore(name));
    strcpy(fathers_name,to_underscore(fathers_name));
    strcpy(mothers_name,to_underscore(mothers_name));
    strcpy(address,to_underscore(address));

    /********************************************************************************/
    //copying strings to temporary variables not only to reset but to use its CONTENT
    reset_temp_vars();      //ITS CONTENT IS BEING USED NOW
    /********************************************************************************/

    //creating files and storing the student data
    //"temp_var" is file name and "following_var" is data inside it
    make_file(temp_name,name);
    make_file(temp_fathers_name,fathers_name);
    make_file(temp_mothers_name,mothers_name);
    make_file(temp_clas,clas);                      //value of class is a numeric value here
    make_file(temp_section,section);                //section is also having its default value
    make_file(temp_roll_number,roll_number);
    make_file(temp_admission_date,admission_date);
    make_file(temp_admission_number,admission_number);
    make_file(temp_birth_date,birth_date);
    make_file(temp_blood_group,blood_group);
    make_file(temp_gender,gender);
    make_file(temp_address,address);
    if(strcmp(cast,"GEN")==0)                   // recent code_line
        strcpy(cast,"GENERAL");
    make_file(temp_cast,cast);
    make_file(temp_phone_number,phone_number);
    make_file(temp_email,email);
    make_file(temp_char_height,char_height);
    make_file(temp_char_weight,char_weight);
    if(value_of(clas)>10){                              //value_of class is completely numeric here
        make_file(temp_char_result_10,char_result_10);}
    if(value_of(clas)>12){                              //value_of class is completely numeric here
        make_file(temp_char_result_12,char_result_12);}
    make_file(temp_unique_id,unique_id);

    store_bmi();        //to create "bmi" files on hdd

    //It Stores The Password Separately in Secured Folder
    store_password();
}       //choice 1 ends here

/*******************************************************************************/
/*FUNCTION TO CREATE FILES OF DATABASE*/
void student::make_file(char* ch,char* ch_data)
{
    char spell[64],temp[16];
    int i=0;

    strcpy(spell,"database\\");     //will into database folder after creation
    strcat(spell,unique_id);
    strcat(spell,"_");

    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/') { temp[i]='_'; }
        ++i;
    }

    strcat(spell,temp);
    strcat(spell,"\\"); //will enter into the till named folder
    strcat(spell,ch);
    strcat(spell,".dbm");

    ofstream file_out;
    file_out.open(spell,ios::out);
    file_out<<ch_data;
    file_out.close();
}
/******************************************************************************/
void student::store_bmi()
{
    int i=0;
    //Calculating BMI (BODY MASS INDEX)
    height=value_of(char_height);
    weight=value_of(char_weight);
    height/=100;
    bmi=weight/pow(height,2);

    //storing BMI
    char spell[64],temp[64];
    strcpy(spell,"database\\");
    strcat(spell,unique_id);
    strcat(spell,"_");

    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){ temp[i]=' '; }
        ++i;
    }

    strcat(spell,temp);
    strcat(spell,"\\");
    strcat(spell,"bmi");
    strcat(spell,".dbm");
    ofstream file_out;
    file_out.open(spell);
    file_out<<bmi;
    file_out.close();
}
/*******************************************************************************/
void student::store_password()
{
    char temp[16]; int i=0;
    if(!mkdir("database"));
    if(!mkdir("database\\secured_dir"));

    system("attrib +s +h database\\secured_dir");       //hide database folder permanently , even can't be detected through cmd or any other program
                                                        //only program can access it.

    strcpy(fcode,"database\\secured_dir\\");
    strcat(fcode,unique_id);
    strcat(fcode,"_");

    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){ temp[i]='_'; }
        ++i;
    }
    strcat(fcode,temp);
    strcat(fcode,".hsec");          //.hsec means .high_security
    ofstream file_out;
    file_out.open(fcode,ios::out);
    file_out<<password;
    file_out.close();
}

/*******************************************************************************/
/*******************************************************************************/

int student::alpha(char *str)
{
    unsigned int c=0;
    for(int i=0;str[i]!='\0';++i)
    {
        if((str[i]>='A'&&str[i]<='K')||(str[i]>='a'&&str[i]<='k'))  c=0;
        else    { c=1; break; }
    }
        return c;
}
/********************************************************************************************************************************************************/
int student::value_of(char *str)
{
    unsigned int val=0;
    stringstream(str)>>val;
    return val;
}
/********************************************************************************************************************************************************/
int student::is_digit_alpha(char *str)
{
    unsigned int val=0;
    stringstream(str)>>val;

    if(val>=1&&val<=13)
        return 0;
    else
        return 1;
}
/********************************************************************************************************************************************************/
int student::check_int(char *str)
{
    unsigned long long val=0;
    int val_len=0;
    stringstream(str)>>val;

    while(val!=0)
    { val/=10; ++val_len; }
    if(strlen(str)==val_len)        //if total string is a int val then return 0 (success) else not
        return 0;
    else return 1;
}
/********************************************************************************************************************************************************/
int student::check_date(char *str)
{
    char dd[3],mm[3],yyyy[5];
    unsigned int d,m,y;
    if(str[2]!='/'||str[5]!='/') return 1;

    dd[0]=str[0];
    dd[1]=str[1];
    dd[2]='\0';
    if(check_date_int(dd)==1) {d=value_of(dd); }
    else return 1;

    mm[0]=str[3];
    mm[1]=str[4];
    mm[2]='\0';
    if(check_date_int(mm)==1) {m=value_of(mm); }
    else return 1;

    yyyy[0]=str[6];
    yyyy[1]=str[7];
    yyyy[2]=str[8];
    yyyy[3]=str[9];
    yyyy[4]='\0';
    if(check_date_int(yyyy)==1) {y=value_of(yyyy); }
    else return 1;

    if(m>12) return 1;

    if(d>31) return 1;

    if(y<1950||y>2050) return 1;

    switch(m)
    {
    case 1: if(d>31) return 1; break;
    case 2:
        if(d==31||d==30) return 1;
        else if(d==29)
        {
            if(y%4==0){}
            else
                return 1;
        }
        break;
    case 3: if(d>31) return 1; break;
    case 4: if(d>30) return 1; break;
    case 5: if(d>31) return 1; break;
    case 6: if(d>30) return 1; break;
    case 7: if(d>31) return 1; break;
    case 8: if(d>31) return 1; break;
    case 9: if(d>30) return 1; break;
    case 10: if(d>31) return 1; break;
    case 11: if(d>30) return 1; break;
    case 12: if(d>31) return 1; break;
    default: return 1; break;
    }


    return 0;
}
/*******************************************************************************************************************************************************/
int student::check_date_int(char *str)
{
    unsigned long long val=0;
    stringstream(str)>>val;

    int val_len=0;
    while(val!=0)
    { val/=10; ++val_len; }

    if(strlen(str)==val_len||strlen(str)==(val_len+1))        //if total string is a int val then return 1 (success) else not
        return 1;
    else return 0;
}
/*******************************************************************************************************************************************************/
int student::check_email(char *str)
{
    int i,len=strlen(str);
    for(i=0;i<=5;++i)
    {
        if(str[i]=='@'||str[i]=='.')
            return 1;
    }

    for(i=6;i<len;++i)
    {
        if((str[i]=='@')&&(str[i+5]!='.')&&(str[i+4]!='.')&&(str[i+3]!='.')&&(str[i+2]!='.')&&(str[i+1]!='.')&&(str[len-1]=='m'))      //@gmail.com
            return 0;
    }

    for(i=0;i<len;++i)       /*************/
    {
        if(str[i]==' ')
            return 1;
    }
    return 0;
}
/*******************************************************************************************************************************************************/
int student::check_equality_dates(char * b_date, char * a_date)
{
    char b[10];
    b[0]=b_date[6];
    b[1]=b_date[7];
    b[2]=b_date[8];
    b[3]=b_date[9];
    b[4]='\0';

    char a[10];
    a[0]=a_date[6];
    a[1]=a_date[7];
    a[2]=a_date[8];
    a[3]=a_date[9];
    a[4]='\0';

    int a_val = value_of(a);
    int b_val = value_of(b);

    unsigned c = (unsigned)(a_val-b_val);
    if(c>100) {  c=(unsigned)(b_val-a_val);  }
    unsigned d = value_of(clas);

    if(d==13)
    {
        if(c<50&&c>=18)
            return 1;
        else
            return 0;
    }
    /*******************************/

    if(c>=(d+3)&&(c<(d+9)))
        return 1;
    else
        return 0;

}
/*******************************************************************************************************************************************************/
int student::check_gender(char *str)
{
    if(str[0]=='m'||str[0]=='M'||str[0]=='f'||str[0]=='F')
        return 0;
    else return 1;
}
/******************************************************************************************************************************************************/
int student::check_blood_grp(char *str)
{
    unsigned int val=0;
    switch(str[0])              // first letter should be either 'a', 'A' , 'b' , 'B' , 'o', 'O'
    {
    case 'a':   break;
    case 'A':   break;
    case 'b':   break;
    case 'B':   break;
    case 'o':   break;
    case 'O':   break;
    default:
        ++val; break;
    }

    if(str[0]=='a'||str[0]=='A')        //if first letter is 'a' || 'A' then next xhar should be either '+' , '-' , 'b' or 'B'
    {
        switch(str[1])
        {
        case '+':   break;
        case '-':   break;
        case 'b':   break;
        case 'B':   break;
        default:
            ++val; break;
        }
    }
    else
    if(str[0]=='b'||str[0]=='B'||str[0]=='o'||str[0]=='O')      //if first char is any of these then next should be either '+' or '-'
    {
        switch(str[1])
        {
        case '+':   break;
        case '-':   break;
        default:
            ++val; break;
        }
    }

    if(str[1]=='b'||str[1]=='B')        //if first char is 'b' or 'B' then next char should be '+' or '-'
    {
        switch(str[2])
        {
        case '+':   break;
        case '-':   break;
        default:
            ++val; break;
        }
    }
    return val;
}
/*****************************************************************************************************************************************************/
int student::check_avail(char * adm_dt)
{
    char temp[5];
    temp[0]=adm_dt[8];
    temp[1]='\0';
    int val = value_of(temp);
    if(val>1)
        return 1;
    else
        return 0;
}
/*****************************************************************************************************************************************************/
int student::check_ph_no(char *str)
{
    unsigned long long val=0,counter=0;;
    stringstream(str)>>val;

    while(val!=0)
    { val/=10; ++counter; }

    if(counter==10) return 0;
    else return 1;
}
/******************************************************************************************************************************************************/
int student::id_check(char *str)
{
    unsigned long long val=0,counter=0;
    stringstream(str)>>val;

    while(val!=0)
    { val/=10; ++counter; }
    if(counter>15&&counter<20)
        return 0;
    else
        return 1;

}

/******************************************************************************************************************************************************/
int student::check_cast(char *str)
{
    for(int i=0;str[i]!='\0';++i)
    {   str[i]=toupper(str[i]); }
    if(strcmp(str,"SC")==0) return 0;
    else if(strcmp(str,"ST")==0) return 0;
    else if(strcmp(str,"GEN")==0) return 0;
    else if(strcmp(str,"OBC")==0) return 0;
    else
        return 1;

}

/***************************************************************************************************************************************************/
int student::check_adno_id(char *ad_no ,char * un_id)
{
    char temp[10];
    temp[0]=un_id[11];
    temp[1]=un_id[12];
    temp[2]=un_id[13];
    temp[3]=un_id[14];
    temp[4]='\0';
    if(strcmp(ad_no,temp)==0)
        return 0;
    else
        return 1;
}
/************************************************************************************************************************************************/
// It helps to Input Passwords Securely by Display "*" while inputting Passwords
// Names of coordinates are same but are still passed by value not by reference
char* student::get_pass(char* pass, int pass_len, int x_cord, int y_cord)
{
    int i=0;
    while(i<pass_len)
    {
        pass[i]=_getch();
        cout<<"*";

        while(pass[i]=='\b')
        {
            if(i>0)
            {--x_cord; --i;}
                gotoXY(x_cord,y_cord); cout<<setw(2)<<" "; gotoXY(x_cord,y_cord);
                pass[i]=_getch();
                cout<<"*";
        }

        if(i==pass_len-1)
            pass[pass_len]='\0';
        ++x_cord;
        ++i;

    }

    return pass;
}
/***********************************************************/
char* student::upper_case(char *str)
{
    int i=0;
    str[0]=toupper(str[0]);
    while(str[i]!='\0')
    {
        if(str[i-1]==' '){ str[i]=toupper(str[i]); }
        ++i;
    }
    return str;
}
/**********************************************************/
char* student::all_upper(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        str[i]=toupper(str[i]);
        ++i;
    }
    return str;
}
/**********************************************************/
char* student::to_underscore(char* str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')str[i]='_';
        ++i;
    }
    return str;
}
/*********************************************************/
char* student::no_underscore(char *spell)
{
    int i=0;
    while(spell[i]!='\0')
    {
        if(spell[i]=='_')spell[i]=' ';
        ++i;
    }
    return spell;
}

/***************************************************************/
// It Reads the Student Data Files From their Locations
char * student::get_file(char* ch)
{
    char spell[64];
    strcpy(spell,"database\\");
    strcat(spell,unique_id);
    strcat(spell,"_");
    char temp[16];
    int i=0;
    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){temp[i]='_';}
        i++;
    }
    strcat(spell,temp);
    strcat(spell,"\\");
    strcat(spell,ch);
    strcat(spell,".dbm");
    ifstream file_in;
    file_in.open(spell);
    file_in>>ch;
    file_in.close();
    return ch;
}
/*******************************************************************************************************************************/
int student::chk_eqult_2(char * b_date, char * a_date)
{
    char orig_clas[10],spell[64];        int i=0;
    strcpy(spell,fname_old);
    strcat(spell,"\\clas.dbm");

    ifstream file_in;
    file_in.open(spell,ios::in);
    file_in>>orig_clas;
    file_in.close();

    char b[10];
    b[0]=b_date[6];
    b[1]=b_date[7];
    b[2]=b_date[8];
    b[3]=b_date[9];
    b[4]='\0';

    char a[10];
    a[0]=a_date[6];
    a[1]=a_date[7];
    a[2]=a_date[8];
    a[3]=a_date[9];
    a[4]='\0';

    int a_val = value_of(a);
    int b_val = value_of(b);

    unsigned c = (unsigned)(a_val-b_val);
    if(c>100) {  c=(unsigned)(b_val-a_val);  }
    unsigned d = value_of(orig_clas);

    if(d==13)
    {
        if(c<50&&c>=18)
            return 1;
        else
            return 0;
    }

    if(c>=(d+3)&&(c<(d+9)))
        return 1;
    else
        return 0;
}
/******************************************************************************************************************************/
void student::call_rem_header()
{
    call_clear();
    cout<<GREEN;
    cout<<"\t ______      ______    _________   ______     _____      ______     ________      _______    \n";
    cout<<"\t||      \\\\ //      \\\\     ||     //      \\\\ //     ||  //      \\\\  //            //           \n";
    cout<<"\t||      || ||      ||     ||     ||      || ||     ||  ||      ||  ||            ||           \n";
    cout<<"\t||      || ||______||     ||     ||______|| ||_____||  ||______||  ||________    ||______    \n";
    cout<<"\t||      || ||      ||     ||     ||      || ||     ||  ||      ||           ||   ||           \n";
    cout<<"\t||      || ||      ||     ||     ||      || ||     ||  ||      ||           ||   ||           \n";
    cout<<"\t||______// ||      ||     ||     ||      || ||_____//  ||      ||   ________//   \\\\______   \n";
    cout<<LIGHTRED;
    cout<<"\t ______     ______                ______                  _______    _______   ______               \n";
    cout<<"\t//     \\\\ ||     \\\\  \\\\      //  //     \\\\   //\\\\   ||  //          //        ||     \\\\  \n";
    cout<<"\t||_____|| ||     ||   \\\\    //   ||_____||   || \\\\  ||  ||          ||______  ||     ||  \n";
    cout<<"\t||     || ||     ||    \\\\  //    ||     ||   ||  \\\\ ||  ||          ||        ||     ||  \n";
    cout<<"\t||     || ||_____//     \\\\//     ||     ||   ||   \\\\||  \\\\_______   \\\\______  ||_____//  \n";
    cout<<"\t         ____     _____  ________  ___  ___    ____                   ______        \n";
    cout<<"\t       //    \\\\  //   ||    ||        ||     //    \\\\   ||\\\\   ||   //               \n";
    cout<<"\t       ||    ||  ||___||    ||        ||     ||    ||   || \\\\  ||   ||______          \n";
    cout<<"\t       ||    ||  ||         ||        ||     ||    ||   ||  \\\\ ||          ||          \n";
    cout<<"\t       \\\\____//  ||         ||     ___||___  \\\\____//   ||   \\\\||    ______//           \n";
}
/******************************************************************************************************************************/
void student::frename()
{
    /*NOTE: we have stored the old folder name before editing
            now we are here because of either new "birth_date" or new "unique_id"
            because they cant be directly renamed so alternate & safe way is this.
    */
    char temp[20];
    int i=0;
    strcpy(fname,"database\\");
    strcat(fname,unique_id);        //new IF ENTERED unique id
    strcat(fname,"_");

    strcpy(temp,birth_date);        //new IF ENTERED birth_date
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){ temp[i]='_'; }
        ++i;
    }

    strcat(fname,temp);             //new folder name ready( eg. 111111111111111_12_12_2012 ) where
                                    //either unique id is new or either birth_date is new

    rename(fname_old,fname);        //rename previous folder which is fname_old to new which is fname
    strcpy(fname_old,fname);        //fname_old has been renamed and now it contains renamed folder name(new one)


    //now changing things for password dir.
    strcpy(fcode,"database\\secured_dir\\");
    strcat(fcode,unique_id);
    strcat(fcode,"_");
    strcat(fcode,temp);
    strcat(fcode,".hsec");
    rename(fcode_old,fcode);
    strcpy(fcode_old,fcode);        //fcode_old has been renamed and now it contains renamed folder name(new one)

}

/***************************************************************************************************************************************************/
void student::reset_temp_vars()
{
    //sometimes this function is called only to reset these temp variables
      //(in such case their data is not used)
    //sometimes it is called to reset as well as reassign them THIS data and then use them along with the data
      //(in such case data is used)
    strcpy(temp_name,"name");
    strcpy(temp_fathers_name,"fathers_name");
    strcpy(temp_mothers_name,"mothers_name");
    strcpy(temp_clas,"clas");
    strcpy(temp_section,"section");
    strcpy(temp_roll_number,"roll_number");
    strcpy(temp_admission_date,"admission_date");
    strcpy(temp_admission_number,"admission_number");
    strcpy(temp_blood_group,"blood_group");
    strcpy(temp_gender,"gender");
    strcpy(temp_address,"address");
    strcpy(temp_cast,"cast");
    strcpy(temp_phone_number,"phone_number");
    strcpy(temp_email,"email");
    strcpy(temp_char_height,"char_height");
    strcpy(temp_char_weight,"char_weight");
    strcpy(temp_char_result_10,"char_result_10");
    strcpy(temp_char_result_12,"char_result_12");
    strcpy(temp_bmi,"bmi");
    strcpy(temp_unique_id,"unique_id");
    strcpy(temp_birth_date,"birth_date");
}
/*______________________________________------------------------------------------------------___________________________________________*/
void student::MakeDocument()
{
    // Storing Names of File as before
    //because i dont want any invalid character to make me problem with these variables while doing operations with them.
    reset_temp_vars();

    // Reading Student Data from already stored Data
    strcpy(name,get_file(temp_name));
    strcpy(fathers_name,get_file(temp_fathers_name));
    strcpy(mothers_name,get_file(temp_mothers_name));

    strcpy(clas,get_file(temp_clas));
    /***********************************************************/
    if(value_of(clas)<=12||(strcmp(clas,"Passed Out")!=0))
    {
        strcpy(section,get_file(temp_section));
    }
    else
    {
        strcpy(section,"NIL");
    }
    /***********************************************************/
    strcpy(roll_number,get_file(temp_roll_number));
    strcpy(admission_date,get_file(temp_admission_date));
    strcpy(admission_number,get_file(temp_admission_number));
    strcpy(blood_group,get_file(temp_blood_group));
    strcpy(gender,get_file(temp_gender));
    strcpy(address,get_file(temp_address));
    strcpy(cast,get_file(temp_cast));
    strcpy(phone_number,get_file(temp_phone_number));
    strcpy(email,get_file(temp_email));
    strcpy(char_height,get_file(temp_char_height));
    strcpy(char_weight,get_file(temp_char_weight));
    if(value_of(clas)>10||strcmp(clas,"Passed Out")==0){
    strcpy(char_result_10,get_file(temp_char_result_10));}
    if(value_of(clas)>12||strcmp(clas,"Passed Out")==0){
    strcpy(char_result_12,get_file(temp_char_result_12));}
    strcpy(char_bmi,get_file(temp_bmi));
    strcpy(unique_id,get_file(temp_unique_id));
    strcpy(birth_date,get_file(birth_date));
    bmi=value_of(char_bmi);

    // Replacing the "_" with " "
    strcpy(name,no_underscore(name));
    strcpy(fathers_name,no_underscore(fathers_name));
    strcpy(mothers_name,no_underscore(mothers_name));
    strcpy(address,no_underscore(address));
    if(value_of(clas)==13||strcmp(clas,"Passed Out")==0)
    {
        strcpy(clas,"Passed Out");
        strcpy(section,"NIL");
    }
    char spell[64];

    strcpy(spell,"database\\");
    strcat(spell,unique_id);
    strcat(spell,"_");

    char temp[16];
    int i=0;
    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){temp[i]='_';}
        i++;
    }

    strcat(spell,temp);
    strcat(spell,"\\Document.ncpt");        //.ncpt - .encripted
    ofstream file_out(spell);
    file_out<<setfill(' ')<<endl;
    file_out<<setw(7)<<"|> "<<"Student's Name"<<setw(17)<<":> "<<name<<endl;
    file_out<<setw(7)<<"|> "<<"Class"<<setw(26)<<":> "<<clas<<endl;
    file_out<<setw(7)<<"|> "<<"Section"<<setw(24)<<":> "<<section<<endl;
    file_out<<setw(7)<<"|> "<<"Roll Number"<<setw(20)<<":> "<<roll_number<<endl;
    file_out<<setw(7)<<"|> "<<"Father's Name"<<setw(18)<<":> "<<fathers_name<<endl;
    file_out<<setw(7)<<"|> "<<"Mother's Name"<<setw(18)<<":> "<<mothers_name<<endl;
    file_out<<setw(7)<<"|> "<<"Gender(M/F)"<<setw(20)<<":> "<<gender<<endl;
    file_out<<setw(7)<<"|> "<<"Blood Group"<<setw(20)<<":> "<<blood_group<<endl;
    file_out<<setw(7)<<"|> "<<"Admission Number"<<setw(15)<<":> "<<admission_number<<endl;
    file_out<<setw(7)<<"|> "<<"Admission Date(DD/MM/YYYY)"<<setw(5)<<":> "<<admission_date<<endl;
    file_out<<setw(7)<<"|> "<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<":> "<<birth_date<<endl;
    file_out<<setw(7)<<"|> "<<"Address"<<setw(24)<<":> "<<address<<endl;
    file_out<<setw(7)<<"|> "<<"Category(SC/ST/OBC/GENERAL)"<<setw(4)<<":> "<<cast<<endl;
    file_out<<setw(7)<<"|> "<<"Phone Number"<<setw(19)<<":> "<<phone_number<<endl;
    file_out<<setw(7)<<"|> "<<"Email ID"<<setw(23)<<":> "<<email<<endl;
    file_out<<setw(7)<<"|> "<<"Height(in Centimeters)"<<setw(9)<<":> "<<char_height<<" cm"<<endl;
    file_out<<setw(7)<<"|> "<<"Weight(in Kilograms)"<<setw(11)<<":> "<<char_weight<<" kg"<<endl;
    file_out<<setw(7)<<"|> "<<"Student's Unique ID"<<setw(12)<<":> "<<unique_id<<endl;
    file_out<<setw(7)<<"|> "<<"BMI(Body Mass Index)"<<setw(11)<<":> "<<char_bmi<<" ";
    if(bmi>0&&bmi<18.5){file_out<<"(UNDER-WEIGHT)\n";}
    else if(bmi>=18.5&&bmi<25){file_out<<"(HEALTHY)\n";}
    else if(bmi>=25&&bmi<30){file_out<<"(OVER-WEIGHT)\n";}
    else {file_out<<"(OBESE)\n";}
    if(value_of(clas)>10||strcmp(clas,"Passed Out")==0){
    file_out<<setw(7)<<"|> "<<"Result of 10th(in %age)"<<setw(8)<<":> "<<char_result_10<<" %"<<endl;}
    if(strcmp(clas,"Passed Out")==0){
    file_out<<setw(7)<<"|> "<<"Result of 12th(in %age)"<<setw(8)<<":> "<<char_result_12<<" %"<<endl;}
    file_out.close();
}

/***************************************************************************************************************************************************/
void student::get_details()
{
    {   ofstream file;
        file.open("atr.bat");
        file<<"attrib +s +h database"<<endl<<"attrib +s +h database\\secured_dir"<<endl<<"erase /f /q atr.bat";
        file.close();
        ShellExecute(NULL,"open","atr.bat",NULL,NULL,SW_HIDE);
    }
    call_clear();
    call_header();
    cout<<YELLO;
    unsigned int x_cord=40, y_cord=5 ;
    cout<<setfill(' ')<<endl;
    cout<<setw(7)<<""<<"Please Fill Up The Following Details Carefully"<<endl;

    cout<<setw(7)<<"|>"<<"Student's Unique ID"<<setw(14)<<":>";gets(unique_id);
    while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15)
    {  gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(unique_id);}
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<""<<":>"; gets(birth_date);
    while(birth_date[0]=='\0'||check_date(birth_date)!=0||birth_date[10]!='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(birth_date);}
    ++y_cord;

    cout<<setw(7)<<"|>"<<"Password (OF Length 8)"<<setw(11)<<":>";
    strcpy( password , get_pass(password,8,x_cord,y_cord) );

    // Creating the File Location of the already Stored Password
    strcpy(fcode,"database\\secured_dir\\");
    strcat(fcode,unique_id);
    strcat(fcode,"_");
    char temp[16];
    int i=0;
    strcpy(temp,birth_date);
        // Replacing "/" with "_" of the Date of Birth
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){temp[i]='_';}
        i++;
    }

    strcat(fcode,temp);
    strcat(fcode,".hsec");      //.hsec means .high_security

    // Now Reading that Password from created Location
    ifstream file_in;
    file_in.open(fcode,ios::in);
    file_in>>passcode;
    file_in.close();

    // It Checks whether the Password is correct or not
    if(strcmp(password,passcode)==0||strcmp(password,"protectd")==0)
    {
        /**********************************************************************************************************************/
        // Storing Names of File as before
        //because i dont want any invalid character to make me problem with these variables while doing operations with them.
        reset_temp_vars();

        /**********************************************************************************************************************/
        // Reading Student Data from already stored Data
        strcpy(name,get_file(temp_name));
        strcpy(fathers_name,get_file(temp_fathers_name));
        strcpy(mothers_name,get_file(temp_mothers_name));
        strcpy(clas,get_file(temp_clas));

        strcpy(section,get_file(temp_section));
        strcpy(roll_number,get_file(temp_roll_number));
        strcpy(admission_date,get_file(temp_admission_date));
        strcpy(admission_number,get_file(temp_admission_number));
        strcpy(blood_group,get_file(temp_blood_group));
        strcpy(gender,get_file(temp_gender));
        strcpy(address,get_file(temp_address));
        strcpy(cast,get_file(temp_cast));
        strcpy(phone_number,get_file(temp_phone_number));
        strcpy(email,get_file(temp_email));
        strcpy(char_height,get_file(temp_char_height));
        strcpy(char_weight,get_file(temp_char_weight));

        if(value_of(clas)>10||strcmp(clas,"Passed Out")==0){
        strcpy(char_result_10,get_file(temp_char_result_10));}
        if(value_of(clas)>12||strcmp(clas,"Passed Out")==0){
        strcpy(char_result_12,get_file(temp_char_result_12));}
        strcpy(char_bmi,get_file(temp_bmi));
        bmi=value_of(char_bmi);

        // Replacing the "_" with
        strcpy(name,no_underscore(name));
        strcpy(fathers_name,no_underscore(fathers_name));
        strcpy(mothers_name,no_underscore(mothers_name));
        strcpy(address,no_underscore(address));
        if(value_of(clas)==13||strcmp(clas,"Passed Out")==0)
        {
            strcpy(clas,"Passed Out");
            strcpy(section,"NIL");
        }

        // It will send the Process to the Next Step which Display the Accessed Data
        show_details();
        cout<<"\n";
        call_pause();
        char strn[20]={"\nreturning........"};
        cout<<YELLO;
        loop(strn);
        cout<<WHITE;
        call_clear();
    }
    else
        {
            Beep(5980,400);
            cout<<"\n\n\n"<<setw(5)<<""<<"::::: Incorrect Details! :::::\n\n\n\n\n\n\n\n\n\n";
            system("TIMEOUT -T 3 -NOBREAK");
        }
}
/*****************************************************************/
void student::show_details()
{
    call_clear();
    call_header();

    if(strcmp(admission_number,"admission_number")==0)
    {
        cout<<YELLO;
        cout<<"\n"<<setw(5)<<""<<"::::: Incorrect Details! :::::\n\n\n\n\n\n\n\n\n\n\t\t";
        return;
    }
    char new_str[40]={"\nWait a moment......."},str2[40]={"\nPreparing Files........\n"};
    cout<<YELLO;
    loop(new_str);  loop(str2);
    cout<<setfill(' ')<<endl;
    cout<<CYAN;

    cout<<setw(7)<<"|> "<<"Student's Name"<<setw(17)<<":> "; cout<<name<<endl;
    cout<<setw(7)<<"|> "<<"Class"<<setw(26)<<":> "; cout<<clas;
    // Adding the Suffix to Class
    if(strcmp(clas,"Passed Out")==0) {cout<<" \n";}
    else if(clas[0]=='1'&&clas[1]=='\0') {cout<<"st\n";}
    else if(clas[0]=='2'&&clas[1]=='\0') {cout<<"nd\n";}
    else if(clas[0]=='3'&&clas[1]=='\0') {cout<<"rd\n";}
    else {if(value_of(clas)<13) cout<<"th\n";}

    if(strcmp(clas,"Passed Out")!=0)
        { cout<<setw(7)<<"|> "<<"Section"<<setw(24)<<":> "; cout<<section<<endl; }
    cout<<setw(7)<<"|> "<<"Roll Number"<<setw(20)<<":> "; cout<<roll_number<<endl;
    cout<<setw(7)<<"|> "<<"Father's Name"<<setw(18)<<":> "; cout<<fathers_name<<endl;
    cout<<setw(7)<<"|> "<<"Mother's Name"<<setw(18)<<":> "; cout<<mothers_name<<endl;
    cout<<setw(7)<<"|> "<<"Gender(M/F)"<<setw(20)<<":> "; cout<<gender<<endl;
    cout<<setw(7)<<"|> "<<"Blood Group"<<setw(20)<<":> "; cout<<blood_group<<endl;
    cout<<setw(7)<<"|> "<<"Admission Number"<<setw(15)<<":> "; cout<<admission_number<<endl;
    cout<<setw(7)<<"|> "<<"Admission Date(DD/MM/YYYY)"<<setw(5)<<":> "; cout<<admission_date<<endl;
    cout<<setw(7)<<"|> "<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<":> "; cout<<birth_date<<endl;
    cout<<setw(7)<<"|> "<<"Address"<<setw(24)<<":> "; cout<<address<<endl;
    if(strcmp(cast,"GEN"))
    {
        strcpy(cast,"GENERAL");
    }
    cout<<setw(7)<<"|> "<<"Category(SC/ST/OBC/GENERAL)"<<setw(4)<<":> "; cout<<cast<<endl;
    if(phone_number[10]!='\0')
    phone_number[10]='\0';
    cout<<setw(7)<<"|> "<<"Phone Number"<<setw(19)<<":> "; cout<<phone_number<<endl;
    cout<<setw(7)<<"|> "<<"Email ID"<<setw(23)<<":> "; cout<<email<<endl;
    cout<<setw(7)<<"|> "<<"Height(in Centimeters)"<<setw(9)<<":> "; cout<<char_height<<" cm"<<endl;
    cout<<setw(7)<<"|> "<<"Weight(in Kilograms)"<<setw(11)<<":> "; cout<<char_weight<<" kg"<<endl;
    cout<<setw(7)<<"|> "<<"Student's Unique ID"<<setw(12)<<":> "; cout<<unique_id<<endl;
    cout<<setw(7)<<"|> "<<"BMI(Body Mass Index)"<<setw(11)<<":> "; cout<<char_bmi<<" ";
    if(bmi>0&&bmi<18.5){cout<<"(UNDER-WEIGHT)\n";}
    else if(bmi>=18.5&&bmi<25){cout<<"(HEALTHY)\n";}
    else if(bmi>=25&&bmi<30){cout<<"(OVER-WEIGHT)\n";}
    else {cout<<"(OBESE)\n";}
    if(value_of(clas)>10||strcmp(clas,"Passed Out")==0){
    cout<<setw(7)<<"|> "<<"Result of 10th(in %age)"<<setw(8)<<":> "; cout<<char_result_10<<" %"<<endl;}
    if(strcmp(clas,"Passed Out")==0){
    cout<<setw(7)<<"|> "<<"Result of 12th(in %age)"<<setw(8)<<":> "; cout<<char_result_12<<" %"<<endl;}
    cout<<"\n";
    cout<<YELLO;
}           // It is the End of Option 2

/***********************************************************************************************************************************************/
void student::data_edit_start()
{
    if(system("attrib +s +h database")!=0||system("attrib +s +h database\\secured_dir")!=0)
    {   system("attrib +s +h database");    system("attrib +s +h database\\secured_dir");   }
    call_clear();
    call_header();
    unsigned x_cord=40 , y_cord=7;
    cout<<YELLO;

    cout<<"\n"<<setw(35)<<setfill(' ')<<""<<"Database Editing Module"<<endl;
    cout<<setw(98)<<setfill(':')<<" "<<setfill(' ')<<endl;

    cout<<setw(7)<<" "<<"Please Fill Up The Following Details Carefully"<<endl;
    cout<<setw(9)<<"|>"<<"Student's Unique ID"<<setw(12)<<":>"; gets(unique_id);
    while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15)
    { gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(unique_id); }
    ++y_cord;

    cout<<setw(9)<<"|>"<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<":>"; gets(birth_date);
    while(birth_date[0]=='\0'||check_date(birth_date)!=0||birth_date[10]!='\0')
    {gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(birth_date); }
    ++y_cord;

    cout<<setw(9)<<"|>"<<"Password (OF Length 8)"<<setw(9)<<":>";
    strcpy(password,get_pass(password,8,x_cord,y_cord));
    y_cord+=2;;

/*----------------------------------------------------------------------------------------------------------*/
    // Creating the File Location of the already Stored Password
    strcpy(fcode,"database\\secured_dir\\");
    strcat(fcode,unique_id);
    strcat(fcode,"_");
    char temp[16];
    int i=0;
    strcpy(temp,birth_date);    // Replacing "/" with "_" of the Date of Birth
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){ temp[i]='_'; }
        i++;
    }
    strcat(fcode,temp);
    strcat(fcode,".hsec");          // .hsec means .high_security

    // Now Reading that Password from created Location
    ifstream file_in(fcode);
    file_in>>passcode;
    file_in.close();
/*-----------------------------------------------------------------------------------------------------------*/

    if(strcmp(password,passcode)==0||strcmp(password,"protectd")==0)
    {
        if(strcmp(password,"protectd")!=0)
        {
            cout<<setfill(' ')<<endl;
            cout<<"\n"<<setw(5)<<":::::::"<<" Enter The Master Password (OF Length 8) :> ";
            strcpy(mast_pass , get_pass(mast_pass,8,x_cord+11,y_cord));
        }
        if(strcmp(password,"protectd")==0||strcmp(mast_pass,"protectd")==0)
        {
            /*---------------------------------------------------------------------------*/

            //getting the original folder name before editing
            //so as to be able to replace it with  new using rename()
            strcpy(fname_old,"database\\");
            strcat(fname_old,unique_id);
            strcat(fname_old,"_");
            char temp[16];
            int i=0;
            strcpy(temp,birth_date);
            while(temp[i]!='\0')
            {
                if(temp[i]=='/'){temp[i]='_';}
                i++;
            }
            strcat(fname_old,temp);

            strcpy(fcode_old,"database\\secured_dir\\");
            strcat(fcode_old,unique_id);
            strcat(fcode_old,"_");
            strcat(fcode_old,temp);
            strcat(fcode_old,".hsec");          //.hsec stands for .high_security
            /*------------------------------------------------------------------------------*/
            edit_data();        // It will send the Process to the Next Step to Edit
        }
        else {  Beep(5980,400); cout<<"\n\n\n"<<setw(5)<<""<<"Incorrect Master Password! \nPlease Contact the Software Developer For Further Help...\n\n\n";}
    }
    else { Beep(5980,400); cout<<"\n\n\n"<<setw(5)<<""<<"::::: Incorrect Details! :::::\n\n\n";}
    system("TIMEOUT -T 5");
}
/*___________________________________________________________________________________________________________________________________________*/

void student::edit_data()
{
    unsigned x_cord=40,y_cord=6;
    call_clear();
    call_header();
    int Choice;
    cout<<setfill(' ')<<endl;
    cout<<setw(7)<<"##"<<"What You Want To Change!"<<endl;
    cout<<setw(7)<<" 1."<<" Student's Name"<<endl;
    cout<<setw(7)<<" 2."<<" Class & Section(If Passed Out Type Class \"13\")"<<endl;
    cout<<setw(7)<<" 3."<<" Roll Number"<<endl;
    cout<<setw(7)<<" 4."<<" Father's Name & Mother's Name"<<endl;
    cout<<setw(7)<<" 5."<<" Gender(M/F)"<<endl;
    cout<<setw(7)<<" 6."<<" Blood Group"<<endl;
    cout<<setw(7)<<" 7."<<" Admission Date & Date of Birth"<<endl;
    cout<<setw(7)<<" 8."<<" Address"<<endl;
    cout<<setw(7)<<" 9."<<" Cast Category"<<endl;
    cout<<setw(7)<<" 10."<<" Phone Number"<<endl;
    cout<<setw(7)<<" 11."<<" Email ID"<<endl;
    cout<<setw(7)<<" 12."<<" Height & Weight"<<endl;
    cout<<setw(7)<<" 13."<<" Admission Number & Student's Unique ID"<<endl;
    cout<<setw(7)<<" 14."<<" Password (Max Length 8)"<<endl;
    cout<<setw(7)<<" 15."<<" Result of 10th or 12th (If Passed Out Type Class \"13\")"<<endl;
    cout<<setw(7)<<" 0."<<" Stop Editing"<<endl;
    cout<<setw(7)<<":::"<<" Enter Your Choice Number: ";
    cin>>Choice;
    call_clear();
    call_header();
    /*___________________________________________________________________________________________*/
    switch(Choice)
    {
        case 1: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Student's Name"<<setw(17)<<":> "; gets(name);
                while(name[0]=='\0'||value_of(name)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<"";  gotoXY(x_cord,y_cord); gets(name); }

                strcpy(temp_name,"name");
                strcpy(name,upper_case(name));
                strcpy(name,to_underscore(name));
                make_file(temp_name,name);  //will replace the previous stored name file by overwriting
                edit_data();
                break;

        case 2: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Class"<<setw(26)<<":> "; gets(clas);
                while(clas[0]=='\0'||clas[2]!='\0'||is_digit_alpha(clas)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(clas); }

                if(value_of(clas)<13)
                {
                    ++y_cord;
                    cout<<setw(9)<<"|> "<<"Section"<<setw(24)<<":> "; gets(section);
                    while(section[0]=='\0'||section[1]!='\0'||alpha(section)!=0)
                    { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(section); }

                    strcpy(section,all_upper(section));
                }

                if(value_of(clas)>10)
                {
                    cout<<setw(9)<<"|> "<<"Result of 10th(in %age)"<<setw(8)<<":> ";gets(char_result_10);
                    while(char_result_10[0]=='\0'||(value_of(char_result_10)<33)||(value_of(char_result_10)>100))
                    { cout<<'\a'; gotoXY(x_cord,y_cord+1); cout<<setw(80)<<""; gotoXY(x_cord,y_cord+1); gets(char_result_10); }

                    strcpy(temp_char_result_10,"char_result_10");
                    make_file(temp_char_result_10,char_result_10);
                }

                if(value_of(clas)>12)
                {
                    cout<<setw(9)<<"|> "<<"Result of 12th(in %age)"<<setw(8)<<":> ";gets(char_result_12);
                    while(char_result_12[0]=='\0'||value_of(char_result_12)<33||value_of(char_result_12)>100)
                    { cout<<'\a'; gotoXY(x_cord,y_cord+2); cout<<setw(80)<<""; gotoXY(x_cord,y_cord+2); gets(char_result_12); }

                    strcpy(temp_char_result_12,"char_result_12");
                    make_file(temp_char_result_12,char_result_12);
                }

/*---------------____________________________________________________________________------------------------------*/
                if(value_of(clas)<10)
                {
                    char temp[16];
                    int i=0;
                    strcpy(temp,birth_date);
                    while(temp[i]!='\0')
                    {
                        if(temp[i]=='/') { temp[i]='_'; }
                        i++;
                    }

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                    char del[164];

                        strcpy(del,"Del /F /Q ");       //is a command to delete the file(even read -only also) using command prompt by forcefully in quite mode
                        //lets add the location of desired file so as to delete it
                        strcat(del,"\"database\\");
                        strcat(del,unique_id);
                        strcat(del,"_");
                        strcat(del,temp);
                        strcat(del,"\\char_result_10.dbm\"");


                    ofstream file1;
                    file1.open("dlt_10_res.bat",ios::out);
                    file1<<del;
                    file1<<"\n";
                    file1<<"erase /f /q dlt_10_res.bat";
                    file1.close();
                    ShellExecute(NULL,"open","dlt_10_res.bat",NULL,NULL,SW_HIDE);       //executing the .bat file

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

                }
/*---------------____________________________________________________________________------------------------------*/

                if(value_of(clas)<=12)
                {
                    char temp[64];
                    int i=0;

                    strcpy(temp,birth_date);
                    while(temp[i]!='\0')
                    {
                        if(temp[i]=='/') { temp[i]='_'; }
                        i++;
                    }

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                    //lets check whether the file to be deleted exists or not
                    char del[164];

                        strcpy(del,"Del /F /Q ");       //is a command to delete the file(even read -only also) using command prompt by forcefully in quite mode
                        //lets add the location of desired file so as to delete it
                        strcat(del,"\"database\\");
                        strcat(del,unique_id);
                        strcat(del,"_");
                        strcat(del,temp);
                        strcat(del,"\\char_result_12.dbm\"");

                    ofstream file1;
                    file1.open("dlt_12_res.bat",ios::out);
                    file1<<del;
                    file1<<"\n";
                    file1<<"erase /f /q dlt_12_res.bat";
                    file1.close();
                    ShellExecute(NULL,"open","dlt_12_res.bat",NULL,NULL,SW_HIDE);       //executing the .bat file

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                }
/*---------------____________________________________________________________________------------------------------*/

                    //overwrite the clas' data by recreating the whole file
                    strcpy(temp_clas,"clas");
                    make_file(temp_clas,clas);


                    //overwrite the section' data by recreating the whole file
                    strcpy(temp_section,"section");
                    make_file(temp_section,section);

                    edit_data();
                    break;

        case 3: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Roll Number"<<setw(20)<<":> "; gets(roll_number);
                while(roll_number[0]=='\0'||check_int(roll_number)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(roll_number); }

                strcpy(temp_roll_number,"roll_number");
                make_file(temp_roll_number,roll_number);

                edit_data();
                break;

        case 4: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Father's Name"<<setw(18)<<":> "; gets(fathers_name);
                while(fathers_name[0]=='\0'||value_of(fathers_name)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(fathers_name); }

                cout<<setw(9)<<"|> "<<"Mother's Name"<<setw(18)<<":> "; gets(mothers_name);
                while(mothers_name[0]=='\0'||value_of(mothers_name)!=0||strcmp(mothers_name,fathers_name)==0)           /*00000000*/
                { cout<<'\a'; gotoXY(x_cord,y_cord+1); cout<<setw(80)<<""; gotoXY(x_cord,y_cord+1); gets(mothers_name); }

                strcpy(temp_mothers_name,"mothers_name");
                strcpy(mothers_name,upper_case(mothers_name));
                strcpy(mothers_name,to_underscore(mothers_name));
                make_file(temp_mothers_name,mothers_name);

                strcpy(temp_fathers_name,"fathers_name");
                strcpy(fathers_name,upper_case(fathers_name));
                strcpy(fathers_name,to_underscore(fathers_name));
                make_file(temp_fathers_name,fathers_name);

                edit_data();
                break;

        case 5: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Gender(M/F)"<<setw(20)<<":> ";gets(gender);
                while(gender[0]=='\0'||gender[1]!='\0'||check_gender(gender)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(gender); }

                strcpy(temp_gender,"gender");
                if(gender[0]=='m'||gender[0]=='M'){ strcpy(gender,"Male"); }
                else strcpy(gender,"Female");

                make_file(temp_gender,gender);

                edit_data();
                break;

        case 6: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Blood Group"<<setw(20)<<":> "; gets(blood_group);
                while(blood_group[0]=='\0'||check_blood_grp(blood_group)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(blood_group); }

                strcpy(temp_blood_group,"blood_group");
                strcpy(blood_group,all_upper(blood_group));

                make_file(temp_blood_group,blood_group);

                edit_data();
                break;

        case 7: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Admission Date(DD/MM/YYYY)"<<setw(5)<<":> "; gets(admission_date);
                while(admission_date[0]=='\0'||check_date(admission_date)!=0||check_avail(admission_date)!=0||admission_date[10]!='\0')
                { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(admission_date); }

                /*-----------------------------------------------------------------*/
                cout<<setw(9)<<"|> "<<"Date of Birth(DD/MM/YYYY)"<<setw(6)<<":> "; gets(birth_date);
                while(birth_date[0]=='\0'||check_date(birth_date)!=0||chk_eqult_2(birth_date,admission_date)==0||birth_date[10]!='\0')
                { cout<<'\a'; gotoXY(x_cord,y_cord+1); cout<<setw(200)<<""; gotoXY(x_cord,y_cord+1); gets(birth_date); }

                strcpy(temp_admission_date,"admission_date");
                make_file(temp_admission_date,admission_date);

                frename();      //fcode_old  contains folder name before edit which will be renamed by new-one
                strcpy(temp_birth_date,"birth_date");
                //now this will go into renamed folder
                make_file(temp_birth_date,birth_date);

                edit_data();
                break;

        case 8: cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Address"<<setw(24)<<":> ";gets(address);
                while(address[0]=='\0')
                { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(20)<<""; gotoXY(x_cord,y_cord); gets(address);}

                strcpy(temp_address,"address");
                strcpy(address,upper_case(address));
                strcpy(address,to_underscore(address));

                make_file(temp_address,address);

                edit_data();
                break;

        case 9:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Category(SC/ST/OBC/GEN)"<<setw(7)<<":> "; gets(cast);
                while(cast[0]=='\0'||check_cast(cast)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(20)<<""; gotoXY(x_cord,y_cord); gets(cast);}

                strcpy(temp_cast,"cast");
                strcpy(cast,all_upper(cast));
                if(strcmp(cast,"GEN")==0)
                { strcpy(cast,"GENERAL"); }

                make_file(temp_cast,cast);

                edit_data();
                break;

        case 10:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Phone Number"<<setw(19)<<":> "; gets(phone_number);
                while(check_ph_no(phone_number)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(40)<<""; gotoXY(x_cord,y_cord); gets(phone_number);}

                strcpy(temp_phone_number,"phone_number");

                make_file(temp_phone_number,phone_number);

                edit_data();
                break;

        case 11:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Email ID"<<setw(23)<<":> ";gets(email);
                while(strlen(email)<12||check_email(email)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord); cout<<setw(50)<<""; gotoXY(x_cord,y_cord); gets(email); }
                strcpy(temp_email,"email");
                make_file(temp_email,email);
                edit_data();
                break;

        case 12:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;

                cout<<setw(9)<<"|> "<<"Height(in Centimeters)"<<setw(9)<<":> "; gets(char_height);
                while(char_height[0]=='\0'||check_int(char_height)!=0||int_len(char_height)>3||int_len(char_height)<=2||value_of(char_height)>180)
                { cout<<'\a'; gotoXY(x_cord,y_cord);cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(char_height);}
                ++y_cord;

                cout<<setw(9)<<"|> "<<"Weight(in Kilograms)"<<setw(11)<<":> ";gets(char_weight);
                while(char_weight[0]=='\0'||check_int(char_weight)!=0||int_len(char_weight)>3||value_of(char_weight)>100)
                { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(char_weight);}
                --y_cord;

                store_bmi();

                strcpy(temp_char_height,"char_height");
                make_file(temp_char_height,char_height);

                strcpy(temp_char_weight,"char_weight");
                make_file(temp_char_weight,char_weight);

                edit_data();
                break;

        case 13:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Admission Number"<<setw(15)<<":> "; gets(admission_number);
                while(admission_number[0]=='\0'||check_int(admission_number)!=0||int_len(admission_number)!=4)
                {  cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(admission_number); }

                cout<<setw(9)<<"|> "<<"Student's Unique ID"<<setw(12)<<":> "; gets(unique_id);
                while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15||check_adno_id(admission_number,unique_id)!=0)
                { cout<<'\a'; gotoXY(x_cord,y_cord+1); cout<<setw(80)<<""; gotoXY(x_cord,y_cord+1); gets(unique_id); }
                frename();      //lets rename the folder

                strcpy(temp_admission_number,"admission_number");
                make_file(temp_admission_number,admission_number);

                strcpy(temp_unique_id,"unique_id");
                make_file(temp_unique_id,unique_id);

                edit_data();
                break;

        case 14:
                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n\tENTER THE NEW DETAILS"<<endl;
                cout<<setw(9)<<"|> "<<"Password (OF Length 8)"<<setw(9)<<":> ";
                strcpy(password,get_pass(password,8,x_cord,y_cord));
                store_password();       //writing new password file
                Beep(68990,200);
                cout<<"\n\n\n\n\t\tPassword Changed Successfully.\n";
                system("timeout /t 3");

                edit_data();
                break;
/*______________________________________________________________----------------------------------------____________________________________*/
        case 15:
                strcpy(temp_clas,"clas");
                get_file(temp_clas);


                cout<<setw(7)<<""<<"\nPlease Fill Up The Following Details Carefully\n"<<endl;
                cout<<setw(9)<<"|> "<<"First Provide With Class"<<setw(8)<<":> "; prev_loc: gets(clas);
                while(clas[0]=='\0'||clas[2]!='\0'||is_digit_alpha(clas)!=0)
                { gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(clas); }

                if(strcmp(temp_clas,clas)!=0)
                {
                    cout<<LIGHTRED;
                    Beep(6880,400);
                    cout<<setw(9)<<""<<"\n\n\t\aPLEASE ENTER THE CORRECT CLASS-INFORMATION IN ORDER TO CONTINUE......\n\t";
                    system("timeout /t 5");
                    gotoXY(x_cord,y_cord); cout<<setw(800)<<"";
                    gotoXY(x_cord,y_cord);
                    cout<<WHITE;
                    goto prev_loc;
                }

                cout<<"\n\n\tENTER THE NEW DETAILS\n";
                if(value_of(clas)<10)
                {
                    cout<<LIGHTRED;
                    cout<<"\n\n\n\t\t----->NO RECORDS AVAILABLE\n";
                    Beep(10000000,190);
                    cout<<WHITE;
                    system("timeout /t 3");
                    edit_data();
                }

                if(value_of(clas)>10)
                {
                    cout<<setw(9)<<"|> "<<"Result of 10th(in %age)"<<setw(8)<<":>"; gets(char_result_10);
                    while(char_result_10[0]=='\0'||(value_of(char_result_10)<33)||(value_of(char_result_10)>100))
                    { cout<<'\a'; gotoXY(x_cord,y_cord+4); cout<<setw(80)<<""; gotoXY(x_cord,y_cord+4); gets(char_result_10); }

                    strcpy(temp_char_result_10,"char_result_10");
                    make_file(temp_char_result_10,char_result_10);

                    if(value_of(clas)==13) { y_cord+=5; }
                }

                if(value_of(clas)>12)
                {
                    cout<<setw(9)<<"|> "<<"Result of 12th(in %age)"<<setw(8)<<":>"; gets(char_result_12);
                    while(char_result_12[0]=='\0'||(value_of(char_result_12)<33)||(value_of(char_result_12)>100))
                    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(80)<<""; gotoXY(x_cord,y_cord); gets(char_result_12); }

                    strcpy(temp_char_result_12,"char_result_12");
                    make_file(temp_char_result_12,char_result_12);
                    y_cord-=5;
                }

                /*---------------____________________________________________________________________------------------------------*/
                if(value_of(clas)<10)
                {
                    char temp[16];
                    int i=0;
                    strcpy(temp,birth_date);
                    while(temp[i]!='\0')
                    {
                        if(temp[i]=='/') { temp[i]='_'; }
                        i++;
                    }

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                    char del[164];

                        strcpy(del,"Del /F /Q ");       //is a command to delete the file(even read -only also) using command prompt by forcefully in quite mode
                        //lets add the location of desired file so as to delete it
                        strcat(del,"\"database\\");
                        strcat(del,unique_id);
                        strcat(del,"_");
                        strcat(del,temp);
                        strcat(del,"\\char_result_10.dbm\"");


                    ofstream file1;
                    file1.open("dlt_10_res.bat",ios::out);
                    file1<<del;
                    file1<<"\n";
                    file1<<"erase /f /q dlt_10_res.bat";
                    file1.close();
                    ShellExecute(NULL,"open","dlt_10_res.bat",NULL,NULL,SW_HIDE);       //executing the .bat file

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

                }
/*---------------____________________________________________________________________------------------------------*/

                if(value_of(clas)<=12)
                {
                    char temp[64];
                    int i=0;

                    strcpy(temp,birth_date);
                    while(temp[i]!='\0')
                    {
                        if(temp[i]=='/') { temp[i]='_'; }
                        i++;
                    }

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                    //lets check whether the file to be deleted exists or not
                    char del[164];

                        strcpy(del,"Del /F /Q ");       //is a command to delete the file(even read -only also) using command prompt by forcefully in quite mode
                        //lets add the location of desired file so as to delete it
                        strcat(del,"\"database\\");
                        strcat(del,unique_id);
                        strcat(del,"_");
                        strcat(del,temp);
                        strcat(del,"\\char_result_12.dbm\"");

                    ofstream file1;
                    file1.open("dlt_12_res.bat",ios::out); file1<<"\n";
                    file1<<del;
                    file1<<"\n";
                    file1<<"erase /f /q dlt_12_res.bat";
                    file1.close();
                    ShellExecute(NULL,"open","dlt_12_res.bat",NULL,NULL,SW_HIDE);   //executing the .bat file

                    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                }

                if(value_of(clas)==13)
                {
                    strcpy(section,"NIL");
                }

                strcpy(temp_clas,"clas");
                make_file(temp_clas,clas);

                strcpy(temp_section,"section");
                make_file(temp_section,section);

                edit_data();
                break;

        case 0: cout<<"\n"<<setw(7)<<"--->"<<" Entries Are Changed Successfully! :::";
                Beep(4000,800);
                cout<<"\n\n\n";
                break; break;
        default:
                {  Beep(5980,400);  cout<<"\n"<<setw(7)<<"------- Invalid Choice!!!! -------";
                    edit_data();
                }
    }
    MakeDocument();
    /*_________________________________________________________________________________________________*/
}           // It is the End of Option 4
/*___________________________________________________________________________________________________________________________________________*/
/*********************************************************************************************************************************************/
void student::delete_data()
{
    call_clear();
    call_header();
    unsigned x_cord=37,y_cord=8;
    {   ofstream file;
        file.open("atr.bat");
        file<<"attrib +s +h database"<<endl<<"attrib +s +h database\\secured_dir"<<endl<<"erase /f /q atr.bat";
        file.close();
        ShellExecute(NULL,"open","atr.bat",NULL,NULL,SW_HIDE);
    }

    cout<<LIGHTRED;
    cout<<setw(38)<<""<<"\t\t\t    DATABASE DELETION MODULE\n";
    char show[30]="\n\t\t WARNING: ";
    char show1[128]="Please Note You Will Still Be asked For A Conformation For Deleting Data.\n\t\t";
    char show2[128]="\t\tData Once Erased Can't Be Backed Up.....\n\n";

    loop(show);
    Beep(4520,800);
    loop(show1);
    Sleep(249);
    loop(show2);
    Sleep(2000);

    call_clear();
    call_header();
    cout<<LIGHTRED;
    cout<<setw(38)<<""<<"\t\t\t    DATABASE DELETION MODULE\n";
    cout<<"\n----->Enter the details Carefully\n\n";

    /*------------------------------------------------------------------------------------------------*/
    cout<<setw(7)<<"|> "<<"Student's Unique ID"<<setw(12)<<":> "; gets(unique_id);
    while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(unique_id);}
    ++y_cord;

    cout<<setw(7)<<"|> "<<"Date of Birth(DD/MM/YYYY)"<<setw(5)<<":>";gets(birth_date);
    while(birth_date[0]=='\0'||check_date(birth_date)!=0||birth_date[10]!='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(birth_date); }
    ++y_cord;

    cout<<setw(7)<<"|> "<<"Password (OF Length 8)"<<setw(8)<<":>";
    strcpy(password,get_pass(password,8,x_cord,y_cord));

    // Creating the File Location of the already Stored Password
    char temp[20];    int i=0;
    strcpy(temp,birth_date);
    while(temp[i]!='\0')
    {
        if(temp[i]=='/'){  temp[i]='_';   }
            ++i;
    }
    strcpy(fcode,"database\\secured_dir\\");
    strcat(fcode,unique_id);
    strcat(fcode,"_");
    strcat(fcode,temp);
    strcat(fcode,".hsec");

    // Now Reading that Password from created Location
    ifstream file_in(fcode);
    file_in>>passcode;
    file_in.close();

    if(strcmp(password,passcode)==0||strcmp(password,"protectd")==0)
    {
        if(strcmp(password,"protectd")!=0)
        {
            cout<<setfill(' ');
            cout<<"\n\n"<<setw(5)<<":::::"<<" Enter The Master Password (OF Length 8) :> ";
            strcpy(mast_pass,get_pass(mast_pass,8,x_cord,y_cord));
        }

        if(strcmp(password,"protectd")==0||strcmp(mast_pass,"protectd")==0)
        {
            char ch;
            cout<<"\n\n"<<setw(5)<<":::::"<<" Are You Sure, You Want To Delete The Data Associated With "<<unique_id<<"_"<<temp<<" (Y/N) :> ";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                char spell[64];

                strcpy(spell,"rmdir /s /q database\\");
                strcat(spell,unique_id);
                strcat(spell,"_");
                strcat(spell,temp);

                char pswrd_fl[64];
                strcpy(pswrd_fl,"del /f /q database\\secured_dir\\");
                strcat(pswrd_fl,unique_id);
                strcat(pswrd_fl,"_");
                strcat(pswrd_fl,temp);
                strcat(pswrd_fl,".hsec");

                ofstream file_out;
                file_out.open("drop_data.bat",ios::out);
                file_out<<spell;
                file_out<<"\n";
                file_out<<pswrd_fl;
                file_out<<"\n";
                file_out<<"erase /f /q drop_data.bat";
                file_out.close();
                ShellExecute(NULL,"open","drop_data.bat",NULL,NULL,SW_HIDE);

                cout<<"\n\n"<<setw(5)<<""<<"Data Successfully Erased.";
                system("timeout /t 3");
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
            }
            else
                {cout<<"\n\n"<<setw(20)<<""<<"|>"<<"Deletion Discarded.........\n";
                 system("timeout /t 3");}
        }
        else
            { Beep(5980,400);  cout<<"\n\n"<<setw(5)<<""<<"Incorrect Master Password! Contact the Software Developer for Help...\n\n\n";     system("timeout /t 3");}
    }
    else
        { Beep(5980,400);  cout<<"\n\n\n\n\n"<<setw(5)<<""<<"::::: Incorrect Details! :::::\n\n\n";  system("timeout /t 3");}


    /*------------------------------------------------------------------------------------------------*/
    call_main();
}

void student::forgot_password()
{
    call_clear();
    call_header();
    unsigned x_cord=37,y_cord=5;
    cout<<YELLO;
    cout<<endl;
    cout<<setw(7)<<""<<"Please Fill Up The Following Details Carefully"<<endl;

    cout<<setw(7)<<"|> "<<"Student's Unique ID"<<setw(12)<<":> ";gets(unique_id);
    while(unique_id[0]=='\0'||check_int(unique_id)!=0||int_len(unique_id)!=15)
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(unique_id);}
    ++y_cord;

    cout<<setw(7)<<"|> "<<"Date of Birth(DD/MM/YYYY)"<<setw(5)<<":>";gets(birth_date);
    while(birth_date[0]=='\0'||check_date(birth_date)!=0||birth_date[10]!='\0')
    { cout<<"\a"; gotoXY(x_cord,y_cord); cout<<setw(100)<<""; gotoXY(x_cord,y_cord); gets(birth_date);}
    ++y_cord;

    cout<<"\n"<<setw(5)<<":::::"<<" Enter The Master Password (OF Length 8) :> ";
    strcpy(mast_pass,get_pass(mast_pass,8,x_cord+12,y_cord+1));
    if(strcmp(mast_pass,"protectd")==0)
    {
        call_clear();
        call_header();
        cout<<YELLO;
        ++y_cord;
        cout<<"\n"<<setw(5)<<":::::"<<" Enter New Password (OF Length 8) :> ";
        strcpy(password,get_pass(password,8,42,4));
        store_password();
        Beep(5558,989);
        cout<<"\n\n----->Password changed Successfully!";
    }
    else
    { cout<<LIGHTRED;  Beep(5980,400);  cout<<"\n\t\t"<<setw(5)<<""<<"Incorrect Master Password! Contact the Software Developer for Help...";
    cout<<"\n\n\n";}
    system("timeout /t 3");
}
/****************************************************************************************************************************************************/
void student::rem_database()
{
    call_clear();
    call_rem_header();

        char str[64]="\n\t\tFetching Passwords........";
        char str2[64]="\n\t\tChecking Password........";
        char str3[64]="\n\n\t\t--------->INCORRECT PASSWORD...........\n";
        char str4[64]="\n\t\t\tEXITING";
        char strn[64]="\n\n\t\tPermission Granted.......";
        char strn1[64]="\n\n\t\tGetting Files........";
        char strn2[64]="\n\t\tCovering Database Securely.....";
        char strn3[64]="\n\t\tRemoving Database Files & Folders........";
        char strn4[64]="\n\n\t\tTASK COMPLETED.........\n\t\tDATA SUCCESSFULLY REMOVED.......";
    cout<<endl<<setw(7)<<"|> "<<"ENTER PASSWORD TO ACCESS ADVANCED OPTIONS"<<setw(8)<<":>";
    strcpy(password,get_pass(password,14,56,18));
    if(strcmp(password,"protected_data")==0)
    {
        fast_loop(str);
        fast_loop(str2);
        Sleep(900);
        fast_loop(strn);
        Sleep(670);
/*---------------------------____________________________________-------------------------------------_____________________________________---------*/
        call_rem_header();
        int of_choice;
        cout<<LIGHTBLUE;
        cout<<endl<<endl;
        cout<<setw(30)<<""<<"1.ERASE WHOLE DATABASE\n";
        cout<<setw(30)<<""<<"2.BACK TO MAIN()\n";
        cout<<setw(30)<<""<<"3.Exit\n";
        cout<<setw(25)<<""<<" ----->Enter Your Choice: ";
        cin>>of_choice;
        switch(of_choice)
        {
        case 1:
            char ch;
            cout<<"\n\n";
            cout<<LIGHTRED<<"WARNING: DELETED DATABASE CAN NEVER BE BACKED UP\n";
            cout<<LIGHTBLUE;
            cout<<setw(30)<<""<<"ARE YOU SURE YOU WANT TO PROCEED ?";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                 ofstream file;
                 file.open("rem_it.bat",ios::out);
                 file<<"attrib -s -h database\\secured_dir"<<endl;
                 file<<"attrib -s -h database"<<endl;
                 file<<"rmdir /s /q database "<<endl;
                 file<<"erase rem_it.bat";
                 file.close();
                 ShellExecute(NULL,"open","rem_it.bat",NULL,NULL,SW_HIDE);


                cout<<LIGHTRED;
                fast_loop(strn1);
                fast_loop(strn2);
                fast_loop(strn3);
                Sleep(200);
                fast_loop(strn4);
                cout<<"\n\n";
                Sleep(1400);
                exit(0);
            }
            else
                {   cout<<"\n\n\t\tDeletion Canceled.....\n"; Sleep(400); exit(0);  }

        case 2:
            cout<<"\n\t\tReturning to main()\n";    Sleep(400);
            call_main();
        case 3:
            exit(0);
        default:
            cout<<"\n\n\t\tOOPS!!!! You Entered An Invalid Choice"; Sleep(400);
            cout<<"\n\n\t\tTry Next Time.......";   Sleep(2000);
            call_main();
        }
    }
    else
    {
        fast_loop(str);
        fast_loop(str2);
        Sleep(789);
        fast_loop(str3);
        Sleep(300);
        fast_loop(str4);
        Sleep(98);
        exit(0);
    }
}
/**************************************************************************************************************************************************/
