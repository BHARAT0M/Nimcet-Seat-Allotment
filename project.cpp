#include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>
#include<string.h>
using namespace std;
const int PASSLEN = 7;
int n,no_clg,no_branch=10;
string passget();
struct student{
    string name;
    string cat;
    string alot;
    string clgname;
    string underCat;
    int rank;
};
struct branch
{
	string b_name;
	int seat;
};
struct college
{
	string c_name;
	struct branch b[10];
};
int check(struct college c[],string name,string branch,string &cate)
{
	int i,j;
	for(i=0;i<no_clg;i++)
	{
		if(c[i].c_name==name)
		{
          for(int j=0;j<no_branch;j++){
               if(branch==c[i].b[j].b_name)
                {
                   if(branch==c[i].b[0].b_name){
                     if(c[i].b[0].seat==0)
                     return -1;
                     else
                     {
                     c[i].b[0].seat--;
                     cate=c[i].b[0].b_name;
                     return 1;
                     }
                    }
                    else{
                        if(c[i].b[0].seat!=0){
                            c[i].b[0].seat--;
                            cate=c[i].b[0].b_name;
                            return 1;
                        }
                    }
                }
               }
               if(branch==c[i].b[1].b_name){
                   if(c[i].b[1].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[1].seat--;
                   cate=c[i].b[1].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[2].b_name){
                   if(c[i].b[2].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[2].seat--;
                   cate=c[i].b[2].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[3].b_name){
                   if(c[i].b[3].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[3].seat--;
                   cate=c[i].b[3].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[4].b_name){
                   if(c[i].b[4].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[4].seat--;
                   cate=c[i].b[4].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[5].b_name){
                   if(c[i].b[5].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[5].seat--;
                   cate=c[i].b[5].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[6].b_name){
                   if(c[i].b[6].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[6].seat--;
                   cate=c[i].b[6].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[7].b_name){
                   if(c[i].b[7].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[7].seat--;
                   cate=c[i].b[7].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[8].b_name){
                   if(c[i].b[8].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[8].seat--;
                   cate=c[i].b[8].b_name;
                   return 1;
                   }
               }
               if(branch==c[i].b[9].b_name){
                   if(c[i].b[9].seat==0)
                   return -1;
                   else
                   {
                   c[i].b[9].seat--;
                   cate=c[i].b[9].b_name;
                   return 1;
                   }
               }
		}
	}
	return 0;
}
string passget()
{
	char password[PASSLEN], letter;
	int loop;
	int len;
	string password2;
		loop = 0;
		while(loop != PASSLEN)
		{
			password[loop] = '\0';
			loop++;
		}
		loop = 0;
		len = 0;
		letter = '\0';
		while( letter != '\r' )
		{
			letter = getch();
			if( letter == '\b' && password[0] == '\0')
			{
				loop = 0;
				len = 0;
			}
			else
			{
				if( letter == '\b' && password[0] != '\0')
				{
					cout << "\b";
					cout << " ";
					cout << "\b";
					loop--;
					password[loop] = '\0';
					len--;
				}
				else
				{
					if( isprint( letter ) != 0 && loop < PASSLEN)
					{
						password[loop] = tolower(letter);
						cout << "*" ;
					}
					loop++;
					if (loop <= PASSLEN)
						len++;
				}
			}
		}
		loop = 0;
		len = len;
		password2 = "";
		while (loop != len)
		{
		password2 = password2+password[loop];
		loop++;
		}
	return password2;
 }

void display(struct student s[]){
    cout<<"NAME : \t\t\tCATEGORY : \t\tRANK :\t\tALLOTEMENT :\t\tCOLLEGE:\t\tUNDER_CAT:\n"<<endl;
    for(int i=0;i<n;i++){
        	cout<<s[i].name<<"\t"<<s[i].cat<<"\t\t\t"<<s[i].rank<<"\t\t"<<s[i].alot<<"\t\t"<<s[i].clgname<<"\t\t "<<s[i].underCat<<"\n\n";
    }
}
void sorting(struct student s[]){
    for(int i=0;i<n;i++){
    	int mid=i;
        for(int j=i+1;j<n;j++){
            if(s[mid].rank>s[j].rank){
            	mid=j;
            }
        }
                int t=s[i].rank;
                s[i].rank=s[mid].rank;
                s[mid].rank=t;
                string str=s[i].name;
                s[i].name=s[mid].name;
                s[mid].name=str;
                str=s[i].cat;
                s[i].cat=s[mid].cat;
                s[mid].cat=str;
    }
}
int main(){
    int choice,option,i,j,k,val,flag=0,tt,xx,zz=0;
    struct student s[1000];
    int b[1000]={0};
    struct college c[20];
    cout<<"\n\n\t\tSEAT ALLOTEMENT SYSTEM FOR NIMCET(MCA) ENTRANCE\n\n";
    P:
    cout<<"\n\n\t\tEnter \n\t\t\t0 For Admin panel \n\t\t\t1 For Student panel\n";
    cout<<".\t\t";
    cin>>choice;
    if(choice==1){
    fflush(stdin);
    cout<<"\n\tEnter number of Student\n\t";
    cin>>n;
    cout <<"\n\tInsert the data\n\n";
    for(int i=0;i<n;i++){
    fflush(stdin);
    cout << "\tName of student : \n\t";
    getline(cin,s[i].name);
    fflush(stdin);
    tt=(s[i].name).length();
    tt++;
    while(tt<20){
    	(s[i].name)+=' ';
    	tt++;
	}
    cout<<"\tCategory of student :\n\t";
    getline(cin,s[i].cat);
    int r;
    Z:
    cout<<"\tRank of Student \n\t";
    cin>>r;
    if(b[r]==0 && r<=n){
        s[i].rank=r;
        b[r]=1;
    }
    else{
        if(r>n)
         cout<<"\tEnter rank less then or eqaul to n\n";
         else
         cout<<"\tThis rank already allocated"<<endl;
        goto Z;
    }
    s[i].alot="Not allocated";
    s[i].clgname="Not allocated";
    s[i].underCat="Not allocated";
    cout<<"\n";
    }
    char cr;
    cout<<"\n\tStudents entry Successful..!!!\n";
    if(flag==0){
        flag=1;
        cout<<"\n\tNow Enter the details of college in Admin Panel, press Y\n\t";
        cin>>cr;
        goto P;
    }
    else{
    cout<<"\n\tPress Y for next step...!!!\n\t";
      cin>>cr;
     }
   }
   else{
       string password;
       cout << "\n\n";
       cout << "\tBEFORE ENTER ADMIN PANEL YOU NEED TO VERIFY PASSWORD";
       L:
       cout << "\n\n\tEnter Your Password: ";
       password = passget();
       if (password == "nitkmca") {
       cout<<"\n\n\tEnter no of colleges:";
       cin>>no_clg;
       fflush(stdin);
       for(i=0;i<no_clg;i++)
       {
           cout<<"\n\n\tEnter name of "<<i+1<<" college:";
           getline(cin,c[i].c_name);
           fflush(stdin);
           for(j=0;j<no_branch;j++)
           {
               cout<<"\n\tEnter Category name: ";
               getline(cin,c[i].b[j].b_name);
               fflush(stdin);
               cout<<"\n\tEnter no of seats: ";
               cin>>c[i].b[j].seat;
               fflush(stdin);
           }
       }
       char cr;
       cout<<"\n\t College entry Successful..!!!\n";
       if(flag==0){
           flag=1;
           cout<<"\n\tNow Enter the details of Student, press Y\n\t";
           cin>>cr;
           goto P;
         }
         else{
         cout<<"\n\tPress Y for next step...!!!\n\t";
           cin>>cr;
          }
       }
       else {
       cout << "\n\n";
       cout << "\tPassword Denied Try Again !!!\n";
       zz++;
       if(zz<3){
         if(zz==2){
            cout<<"\n\t@ Warning :- This is last attempt for YOU";
           }
          goto L;
          }
        else
        {
            cout<<"\n\tOOPS..SORRY YOU CAN'T TRY AGAIN\n ";
            exit(0);
        }
       }
   }
    while(1){
        cout << "\n\t#########################################\n\n";
        cout << "\t#  0.\tDisplay\t\t\t\t#\n";
        cout << "\t#  1.\tsorting\t\t\t\t#\n";
        cout << "\t#  2.\tFor going into seat allotement\t#\n";
        cout << "\n\t#########################################\n\n";
        cout << "\n\t Enter your choice : \n\t ";
        cin >> option;
        cout<<"\n";
        if(option==2)
             break;
        switch (option)
        {
        case 0:
            display(s);
            break;
        case 1:
            sorting(s);
            break;
        default:
            cout << "\n";
            break;
    }
}
cout<<"\n\tSeat allotement ...\n\n";
char ch;
string branch,name;
    system("cls");
    cout<<"\n\n\tSeats Available before admission!\n\n";
    for(i=0;i<no_clg;i++)
    {

            cout<<c[i].c_name<<"\t\t";
            for(k=0;k<no_branch;k++)
            {
            cout<<c[i].b[k].b_name<<"\t\t";
            }
            cout<<"\n\n\t\t";
            fflush(stdin);
            for(j=0;j<no_branch;j++)
            cout<<c[i].b[j].seat<<"\t\t";
            cout<<"\n\n";
            fflush(stdin);
    }
    //fflush(stdin);
    for(int x=0;x<n;x++){
    cout<<"\tEntry for student whose rank "<<x+1<<"\t Category = "<<s[x].cat<<"\n";
    A:
    fflush(stdin);
    cout<<"\n\tEnter name of college you want to choose:";
    getline(cin,name);
    fflush(stdin);
    val=check(c,name,s[x].cat,s[x].underCat);
    if(val==1){
    s[x].alot="allocated";
    s[x].clgname=name;
    cout<<"\n\tCongrates! Admission Successful";
      }
    else
    if(val==-1){
    cout<<"\n\tSorry Seats Full try again  please try another college\n";
    char ch;
    cout<<"\n\t If you want to try again press Y"<<endl;
    cin>>ch;
    if(ch=='Y'||ch=='y'){
        goto A;
    }
    }
    else{
    cout<<"\n\t Wrong Entry\n";
    char ch;
    cout<<"\n\t If you want to try again press Y"<<endl;
    cin>>ch;
    if(ch=='Y'||ch=='y'){
        goto A;
    }
    }
    cout<<"\n\n\n\tSeats Availability after admission\n\n";
    for(i=0;i<no_clg;i++)
    {
     cout<<c[i].c_name<<"\t\t";
     for(k=0;k<no_branch;k++)
     {
     cout<<c[i].b[k].b_name<<"\t\t";
     }
     cout<<"\n\n\t\t";
     fflush(stdin);
     for(j=0;j<no_branch;j++)
     cout<<c[i].b[j].seat<<"\t\t";
     cout<<"\n\n";
     fflush(stdin);
    }
   }
     cout<<"\n\n### FINAL LIST ###......\n\n";
      display(s);
     cout<<"\n\n\t\t...... DONE BY BHARAT PATIDAR (194CA014) ....\n";
     cout<<"\n\t\t ....THANK YOU....!!!";
    return 0;
}
