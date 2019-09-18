// Hospital Information System
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
class patient
 {
  char status[10];
  int age;
  char sex;
  char nationality[20];
  char history[100];
  int dd,mm,yy;
  int hr,min;
  char pname[30];
  char diagnosis[100];
  char treatment[100];
  char fdd[9];
  char notes[100];
  char doctor[30];
 public:
  long int  pid;
   void enterpatientdetails()  
    {

     cout<<"\n PATIENT ID:";
     cin>>pid;
     cout<<"\n NAME:";
     gets(pname);
     cout<<"\n AGE:";
     cin>>age;
     cout<<"\n SEX(M/F):";
     cin>>sex;
     cout<<"\n NATIONALITY:";
     gets(nationality);
     cout<<"\n PATIENT HISTORY/SYMPTOMS:";
     gets(history);
     cout<<"\n STATUS:";
     gets(status);
     cout<<"\n DIAGNOSIS:";
     gets(diagnosis);
     cout<<"\n TREATMENT:";
     gets(treatment);
     cout<<"\n FOLLOW UP DATE:";
     gets(fdd);
     cout<<"\n OTHER NOTES:";
     gets(notes);
     cout<<"\n DOCTOR:";
     gets(doctor);
    }
   void displaypatientdetails()
    {
     cout<<"PATIENT ID:"<<pid;
     cout<<"\n\nNAME:"<<pname<<endl;
     cout<<"\nSTATUS:"<<status;
     cout<<"\n\nAGE:"<<age<<"                          SEX:"<<sex<<"                    NATIONALITY:"<<nationality<<endl;
     cout<<"\n\nPATIENT HISTORY:"<<history<<endl;
     //cout<<"_____________________________________________________________________________\n"<<endl;
     cout<<"\nDIAGNOSIS:"<<diagnosis<<endl;
     cout<<"\nTREATMENT:"<<treatment<<endl;
     cout<<"\nOTHER NOTES:"<<notes<<endl;
     cout<<"\nFOLLOW UP DATE:"<<fdd<<"                                DOCTOR:"<<doctor;
     cout<<"\n_______________________________________________________________________________";
     cout<<"\n_______________________________________________________________________________\n"<<endl;

    }
};

void popup()  //function to display pop-up window in every case
 {
  clrscr();
  system("color 1e");
  cout<<"\n\n\n\n\n                                RETURN TO HOMEPAGE(H)\n\n                                  REPEAT ACTION(Y)\n\n                                      EXIT(N)";
  cout<<"\n\n\n\n\n                                                                                                                  YOUR CHOICE: ";
 }


void main()
 {
  home:
  clrscr();
  system("color 1e"); //for background and text colour
  char enter;
  int c=0;
  int choice;
  cout<<"\n                                MEDICARE EYE HOSPITAL                             "<<endl<<endl<<endl;
  cout<<" 1.ENTER PATIENT DETAILS\n\n 2.VIEW APPOINTMENT LIST\n\n 3.SEARCH PATIENT DETAILS\n\n 4.ADD NEW RECORD\n\n 5.MODIFY PATIENT DETAILS\n\n 6.INSERT URGENT CASE\n\n 7.DELETE RECORD\n\n\n";
  cout<<" YOUR CHOICE: ";
  cin>>choice;
  patient p,pread,pnew,pdelete;
  fstream ffile;
  ifstream ifile;
  ofstream ofile;
  cout<<endl<<endl<<endl;
  switch(choice)
   {
    case 1:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            cout<<"\n                              ENTER PATIENT DETAILS\n\n";
            int reply;
            ofile.open("patient.dat",ios::out|ios::binary);
            do
             {
              p.enterpatientdetails();
              ofile.write((char*)&p,sizeof(patient));
              cout<<"\nTO ENTER MORE RECORDS,PRESS 2,OTHERWISE PRESS 1: ";
              cin>>reply;
             }
            while(reply==2);
            ofile.close();
            popup();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='n')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
            }
            break;
    case 2:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            long int id;
            int reply;
            cout<<"\n                               APPOINTMENT LIST\n\n\n";
            ifile.open("patient.dat",ios::in|ios::binary);
            ifile.seekg(0,ios::beg);
            ifile.read((char*)&pread,sizeof(pread));
            while(!ifile.eof())
             {
              pread.displaypatientdetails();
              ifile.read((char*)&pread,sizeof(pread));
              getch();
             }
            popup();
            ifile.close();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='n')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
            }
            break;
    case 3:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            int val=0;
            long int patid;
            cout<<"\n                             SEARCH A RECORD\n\n";
            cout<<"ENTER PATIENT ID OF THE RECORD TO BE SEARCHED: ";
            cin>>patid;
            cout<<endl;
            ifile.open("patient.dat",ios::in|ios::binary);
            ifile.seekg(0,ios::beg);
            while(!ifile.eof())
             {
              ifile.read((char*)&p,sizeof(patient));
              if(patid==p.pid)
               {
                p.displaypatientdetails();
                getche();
                val=1;
                break;
               }
             }
            if(val==0)
             {
              clrscr();
              system("color 1e");
              cout<<"\n                         INVALID ID"<<endl;
             }
            ifile.close();
            popup();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='n')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
            }
            break;
    case 4:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            int val=0;
            cout<<"                           ADD NEW RECORD\n\n";
            ofile.open("patient.dat",ios::binary|ios::app);
            do
            {
             pnew.enterpatientdetails();
             ofile.write((char*)&pnew,sizeof(patient));
             cout<<"TO ADD MORE RECORDS,PRESS 0, OTHERWISE PRESS 1: ";
             cin>>val;
             cout<<endl;
            }
            while(val==0);
            ofile.close();
            popup();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='n')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
            }
           break;
    case 5:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            int val=0,pos;
            long int patid;
            ffile.open("patient.dat",ios::in|ios::out|ios::binary);
            cout<<"\n                          MODIFY EXISTING RECORD\n\n";
            cout<<"ENTER PATIENT ID OF THE RECORD TO BE MODIFIED: ";
            cin>>patid;
            ffile.seekg(0,ios::beg);
            while(!ffile.eof())
             {
              ffile.read((char*)&p,sizeof(patient));
              if(patid==p.pid)
               {
                val=1;
                pos=ffile.tellg();
                clrscr();
                system("color 1e");
                cout<<"\n\n\n\n\                                                RECORD FOUND. LOADING...\n";
                getche();
                clrscr();
                system("color 1e");
                p.displaypatientdetails();
                getche();
                cout<<endl;
                break;
               }
             }
            if(val==1)
             {
              cout<<"ENTER NEW DETAILS: "<<endl;
              p.enterpatientdetails();
              ffile.seekp(pos);//use sizeof(p)??
              ffile.write((char*)&p,sizeof(patient));
              clrscr();
              system("color 1e");
              cout<<"\nMODIFICATION SUCCESSFUL.MODIFIED RECORD: "<<endl;
              getche();
              clrscr();
              system("color 1e");
              p.displaypatientdetails();
              getche();
             }
            else
             {
              cout<<"\nINVALID ID!"<<endl;
             }
            getche();
            ffile.close();
            popup();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='n')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
           }
           break;
    case 6:{
            char ans;
            do
            {
            clrscr();
            system("color 1e");
            cout<<"\n                          INSERT URGENT CASE\n\n";
            int flag=0;
            ifile.open("patient.dat",ios::in|ios::binary);
            ofile.open("newfile.dat",ios::out|ios::binary);
            cout<<"\n ENTER DETAILS OF THE URGENT RECORD: "<<endl;
            pnew.enterpatientdetails();
            ifile.seekg(0,ios::beg);
            while(!ifile.eof())
             {
              ifile.read((char*)&p,sizeof(patient));
              if(pnew.pid < p.pid)
               {
                ofile.write((char*)&pnew,sizeof(patient));
                flag=1;
                break;
               }
              else
               {
                 ofile.write((char*)&p,sizeof(patient));
               }
             }
            if(flag==0) //last record
             ofile.write((char*)&pnew,sizeof(patient));
            else if(!ifile.eof())
             {
              while(!ifile.eof())
               {
                 ifile.read((char*)&p,sizeof(p));
                 ofile.write((char*)&p,sizeof(p));
               }
             }
            ifile.close();
            ofile.close();
            remove("patient.dat");
            rename("newfile.dat","patient.dat");
            ifile.open("patient.dat",ios::in|ios::binary);
            clrscr();
            system("color 1e");
            cout<<"\n URGENT RECORD INSERTED SUCCESSFULLY\n NEW APPOINTMENT LIST: "<<endl;
            getche();
            clrscr();
            system("color 1e");
            ifile.read((char*)&p,sizeof(patient));
            while(!ifile.eof())
             {

               p.displaypatientdetails();
               ifile.read((char*)&p,sizeof(patient));
               getche();

              }
            ifile.close();
            popup();
            cin>>ans;
            if(ans=='H'||ans=='h')
             goto home;
            else if(ans=='N'||ans=='N')
             exit(0);
            }
            while(ans=='Y'||ans=='y');
            }
           break;
   case 7:{
           char ans;
           do
           {
           clrscr();
           system("color 1e");
           cout<<"\n                        DELETE PATIENT RECORD"<<endl<<endl;
           ofile.open("delfile.dat",ios::binary|ios::out);
           ifile.open("patient.dat",ios::binary|ios::in);

           long int patid;
           int flag=0,val;
           cout<<"\nENTER PATIENT ID OF RECORD TO BE DELETED: ";
           cin>>patid;
           ifile.seekg(0,ios::beg);
           while(!ifile.eof())
            {
             ifile.read((char*)&pdelete,sizeof(patient));
             if(patid==pdelete.pid)
              {
               pdelete.displaypatientdetails();
               flag=1;
               cout<<"\n\nDELETE THIS RECORD?(3 FOR YES, 2 FOR NO)";
               cin>>val;
               if(val==2)
                {
                 ofile.write((char*)&pdelete,sizeof(patient));
                }
              }
             else
              ofile.write((char*)&pdelete,sizeof(patient));
            }
           ifile.close();
           ofile.close();
           if(flag==0)
            {
             cout<<"\n RECORD DOES NOT EXIST!";
             getche();
             goto end;
            }

           remove("patient.dat");
           rename("delfile.dat","patient.dat");
           clrscr();
           system("color 1e");
           cout<<"\n\n\n                       RECORD DELETED SUCCESSFULLY. NEW APPOINTMENT  LIST:";
           getche();
           clrscr();
           system("color 1e");
           ifile.open("patient.dat",ios::in);
           while(!ifile.eof())
            {
              ifile.read((char*)&p,sizeof(p));
              p.displaypatientdetails();
              getche();
            }
          ifile.close();
          end:
          popup();
          cin>>ans;
          if(ans=='H'||ans=='h')
           goto home;
          else if(ans=='N'||ans=='N')
           exit(0);
           }
          while(ans=='Y'|| ans=='y');
           }
         break;
     default:cout<<"\n WRONG CHOICE ! ";
   }
 getche();
} 
 


                                    
        
