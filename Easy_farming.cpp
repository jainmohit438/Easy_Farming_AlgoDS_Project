#include <iostream>
#include <windows.h>
#include <mysql.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<string>
#include<windows.h>


using namespace std;
MYSQL* conn;
 MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL_RES *res1;
string current_user;
 string loanamount;
 string account_no;
 string account_balance;

 int balance;
 void bankdetails();
 void shop1();
void payloan();
void main_menu();
void purchase();
void sell();
void alluser();
void register1();
void adminpage();
void updatemandi();
void shop1();
struct item{
    string item_name;
    int price;
    struct item *right;
}*start2;
struct category{
    string name;
    struct category *down;
    struct item *right;
}*start;
struct item *linkedll(struct item *a)
{
    struct item *temp,*curr,*starts;
    temp= new struct item;
    cout<<"ENTER NAME OF ITEM "<<endl;
    cin>>temp->item_name;
    cout<<"ENTER PRICE OF ITEM "<<endl;
    cin>>temp->price;
    temp->right=NULL;
    start2=a;
    if(start2==NULL)
    {
        start2=temp;
    }
    else{
        curr=start2;
    while(curr->right!=NULL)
        curr=curr->right;

     curr->right=temp;
    }
    return start2;
}
void display(struct category *a)
{
    while(a!=NULL)
    {   cout<<endl<<a->name<<".   ";
        struct item *temp;
        temp=a->right;
        while(temp!=NULL)
        {
            cout<<temp->item_name<<" ";
            cout<<temp->price<<" ";
            temp=temp->right;
        }
        a=a->down;
    }
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
    shop1();

}
class mandi
{   private:
    string fasal_name;
    string fasal_price;
public:
    mandi()
    {
       cout<<"UPDATE FASAL INFORMATION IN MANDI"<<endl;
       cout<<"ENTER NAME OF FASAL"<<endl;
       cin>>fasal_name;
       cout<<"ENTER PRICE OF FASAL"<<endl;
       cin>>fasal_price;

    }
   string name()
   {
       return fasal_name;

   }
   string price()
   {
       return fasal_price;
   }

};
void updatemandi()
{  mandi:
   system("CLS");
   string fasal_name;
   string fasal_price;
   mandi m;
   fasal_name=m.name();
   fasal_price=m.price();
    int qstate;
   string query="insert into mandishop(fasal_name,fasal_price) values('"+fasal_name+"','"+fasal_price+"')";
        const char* q=query.c_str();
       qstate=mysql_query(conn,q);
        if(!qstate){
            cout<<"MANDI UPDATED SUCESSFULLY!"<<endl;
        }
        cout<<'\n'<<"PRESS 1 TO ADD MORE ITEMS"<<endl;
         cout<<'\n'<<"PRESS ANY NUMBER TO  GOTO MENU";
        int p;
        cin>>p;
        if(p==1){
            goto mandi;
        }
        else{
       adminpage();
        }

}
 class shop
{  private:
    string item_category;
    string item_name;
    string price;
   public:
       shop()
       {
           cout<<"ENTER ITEM CATEGORY"<<endl;
           cin>>item_category;
           cout<<"ENTER ITEM NAME"<<endl;
           cin>>item_name;
           cout<<"ENTER PRICE"<<endl;
           cin>>price;
       }
     string category()
       {
           return item_category;
       }

      string item()
      {
          return item_name;
      }

      string pricei()
      {
          return price;
      }

};
void updatekrishishop(){
    system("CLS");
   start=NULL;

    bool insert;
    bool insert2;
    cout<<"PRESS 1 TO CONTINUE ADD NEW CATEGORY";
    cin>>insert;
    while(insert)
    {
        struct category *temp,*curr;
        temp=new struct category;
        cout<<"ENTER NAME OF CATEGORY";
        cin>>temp->name;
        temp->down=NULL;
        temp->right=NULL;

        if(start==NULL)
        {
            start=temp;
            curr=temp;
        }
        else{
                curr=start;
            while(curr->down!=NULL)
                curr=curr->down;
            curr->down=temp;
        }

        cout<<"PRESS 1 TO INSERT ITEMS IN CATEGORY";
        cin>>insert2;
        while(insert2){
            curr->right=linkedll(curr->right);

            cout<<"PRESS 1 TO INSERT MORE ITEM IN THIS CATEGORY";
            cin>>insert2;
        }
        cout<<endl<<"WANT TO ADD MORE CATEGORY PRESS 1";
        cin>>insert;

         adminpage();
    }


}



MYSQL * connection(){
 conn = mysql_init(0);

     conn = mysql_real_connect(conn,"localhost","root","","piyush",0,NULL,0);

     if(conn)
        cout<<"connection to mca databse successful "<<endl;


     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
        return conn;
}

void adminpage()
{system("cls");
    cout<<"******************************EASY FARMING*************************************"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*     HELLO ADMIN                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                    1.FOR SEE ALL USER DETAILS.                               *"<<endl;
 cout<<"*                    2.FOR ADD ITEMS IN KRISHI SHOPS.                          *"<<endl;
 cout<<"*                    3.FOR UPDATE MANDI ITEMS.                                 *"<<endl;
 cout<<"*                    4.FOR LOGGING OFF.                                        *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*******************************EASY FARMING*************************************"<<endl;
 int i;
 cin>>i;
 switch(i)
 {
 case 1:
    alluser();
    break;
 case 2:
    updatekrishishop();
    break;
 case 3:
    updatemandi();
    break;
 case 4:
    main_menu();
    break;
 }

}

void alluser()
{  system("CLS");
     string qustate="SELECT * FROM farmers";
  const char* q=qustate.c_str();
int qstate=mysql_query(conn,q);

 res = mysql_store_result(conn);

 while( row=mysql_fetch_row(res))
 {

    cout<<"************************************EASY FARMING************************************"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                              NAME :"<<row[0]<<"                                  *"<<endl;
    cout<<"                               USERNAME :"<<row[1]<<"                              *"<<endl;
    cout<<"                               AGE :"<<row[3]<<"                                   *" <<endl;
    cout<<"                               NO OF FAMILY MEMBERS :"<<row[4]<<"                  *"<<endl;
    cout<<"                               LAND AREA  :"<<row[6]<<"                            *"<<endl;
    cout<<"                               ACCOUNT NO :"<<row[5]<<"                            *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"*                                                                                   *"<<endl;
    cout<<"************************************EASY FARMING************************************"<<endl;
  cout<<"PRESS ANY KEY TO GO BACK"<<endl;
  getch();
  adminpage();
 }
}
class farmer{
private :
string name;
string username;
string password;
string age;
string family_member;
string land_area;
string account_no;
public:
    farmer()
    { system("CLS");
    cout<<"***************************************FARMER REGISTRATION*******************************"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                                                                        *"<<endl;
    cout<<"*                                       ENTER YOUR NAME: ";
      cin>>name;
      cout<<"                                     ENTER YOUR USER NAME: ";
      cin>>username;
      cout<<"                                     ENTER YOUR PASSWORD: ";
      cin>>password;
      cout<<"                                     ENTER YOUR AGE: ";
      cin>>age;
      cout<<"                                ENTER NO OF MEMBERS IN YOUR FAMILY: ";
      cin>>family_member;
      cout<<"                                 ENTER YOUR ACCOUNT NO: ";
      cin>>account_no;
      cout<<"                                 ENTER AREA OF YOUR LAND: ";
      cin>>land_area;

      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"*                                                                                        *"<<endl;
      cout<<"***************************************FARMER REGISTRATION*******************************"<<endl;
    }


string naam()
{
    return name;
}
string usrname()
{
    return username;

}
string pass()
{
    return password;
}
string aged()
{
    return age;
}
string f_no()
{

    return family_member;
}
string account()
{
    return account_no;

}

string land_Ar()
{
    return land_area;
}
};
void afterlogin()

{ system("CLS");


    string name;


  string duemonth;
  string account_balance;
  string qustate="SELECT * FROM farmers WHERE USERNAME = '"+current_user+"'";

  const char* q=qustate.c_str();
int qstate=mysql_query(conn,q);

 res = mysql_store_result(conn);

 while( row=mysql_fetch_row(res))
 {


    name=row[0];
    account_no=row[5];

 }
  string qustate1="SELECT * FROM bankaccount WHERE account_no='"+account_no+"'";
   const char* q1=qustate1.c_str();
   int qstate1=mysql_query(conn,q1);

     res1 = mysql_store_result(conn);

     while( row=mysql_fetch_row(res1))
       {

           loanamount=row[2];
           duemonth=row[3];
           account_balance=row[1];
           balance=atoi(row[1]);

       }


 cout<<"******************************EASY FARMING*************************************"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*     HELLO "<<name<<"                         YOUR ACCOUNT BALANCE IS:"<<balance <<"                  *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*     SIR YOU HAVE PENDING LOAN AMOUNT OF: "<<loanamount<<"          DUE MONTH: "<<duemonth<<"    *"<<endl;
 cout<<"*                                                                             *"<<endl;
 cout<<"*                                                                             *"<<endl;
 cout<<"*                                                                             *"<<endl;
 cout<<"*                                                                             *"<<endl;
 cout<<"*                    1.FOR CHECK YOUR BANKDETAILS.                        *"<<endl;
 cout<<"*                    2.FOR PURCHASE ITEMS FROM OUR KRISHI FARMING SHOPS.       *"<<endl;
 cout<<"*                    3.FOR SELL YOUR PRODUCTS TO OUR MANDI.                    *"<<endl;
 cout<<"*                    4.FOR PAY YOU LOAN AMOUNT                                   *"<<endl;
 cout<<"*                                                                             *"<<endl;
 cout<<"*                    5.FOR LOGGING OFF.                                        *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*******************************EASY FARMING*************************************"<<endl;
 cout<<"                           ENTER YOUR CHOICE                                    "<<endl;
 int k;
 cin>>k;
 switch(k)
 {
 case 1:
    bankdetails();
    break;
 case 2:
    shop1();
    break;
 case 3:
    sell();
    break;
 case 4:
    payloan();
 case 5:
   main_menu();
    break;

 }

}

void payloan(){
    int amount;
cout<<"YOUR LOAN AMOUNT IS :  " <<loanamount<<endl;
cout<<"ENTER AMOUNT YOU WANT TO PAY"<<endl;
cin>>amount;
int balance3;
 string qustate1="SELECT * FROM bankaccount WHERE account_no='"+account_no+"'";
   const char* q1=qustate1.c_str();
   int qstate1=mysql_query(conn,q1);

     res1 = mysql_store_result(conn);

     while( row=mysql_fetch_row(res1))
       {
           int loan=atoi(row[2]);
           loan=loan-amount;
           string loan1;
           balance3=atoi(row[1]);
           balance3=balance3-amount;
           string balance4;
             ostringstream convert,convertloan;
             convert <<balance3;
             convertloan<< loan;
             balance4=convert.str();
             loan1=convertloan.str();
             string qustate2="UPDATE bankaccount SET balance ='"+balance4+"',loan_amount='"+loan1+"' WHERE account_no='"+account_no+"'";
             const char* q2=qustate2.c_str();
            int qstate2=mysql_query(conn,q2);
            cout<<"LOAN PAID SUCCESSFULLY"<<endl;
            cout<<"PRESS ANY KEY TO GO BACK"<<endl;
            getch();
            afterlogin();


       }






}
void bankdetails()

{   string duemonth;

    system("cls");
      string qustate1="SELECT * FROM bankaccount WHERE account_no='"+account_no+"'";
   const char* q1=qustate1.c_str();
   int qstate1=mysql_query(conn,q1);

     res1 = mysql_store_result(conn);

     while( row=mysql_fetch_row(res1))
       {

           loanamount=row[2];
           duemonth=row[3];
           account_balance=row[1];

           cout<<" *********************************BANK DETAILS*****************************************"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                YOUR ACCOUNT NO IS: "<<account_no<<"                                                  *"<<endl;
    cout<<"*                YOUR BALANCE IS: "<<account_balance<<"                                                  *"<<endl;
    cout<<"*                YOUR LOAN AMOUNT IS "<<loanamount <<"                                                  *"<<endl;
    cout<<"*                DUE MONTH TO PAY YOUR LOAN: "<<duemonth<<"                                                  *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    "<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;

    cout<<" *********************************BANK DETAILS*****************************************"<<endl;
    cout<<"PRESS ANY KEY TO GO BACK"<<endl;
    getch();
    afterlogin();

       }

}
void sell()
{   string crop;
    cout<<" *********************************WELCOME TO GOVERNMENT MANDI*****************************************"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                        WHICH CROP YOU WANT TO SELL HERE :";
    cin>>crop;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"*                                                                                                    *"<<endl;
    cout<<"******************************************************************************************************"<<endl;
      string qustate1="SELECT * FROM mandishop WHERE fasal_name='"+crop+"'";
   const char* q1=qustate1.c_str();
   int qstate1=mysql_query(conn,q1);

     res1 = mysql_store_result(conn);

     while( row=mysql_fetch_row(res1))
       {

          int price=atoi(row[1]);
          cout<<"THE PRICE OF "<<crop<<"IN KG IN OUR MANDI IS : "<<price<<"/KG"<<endl;

          cout<<"DO YOU WANT TO SELL IT ???"<<endl;
          bool sell;
          cin>>sell;

          if(sell)
          {  int wt;
             cout<<"ENTER WIEGHT OF CROP YOU WANT TO SELL"<<endl;
             cin>>wt;
             price=price+wt*price;
             balance=balance+price;
             string balance1;
             ostringstream convert;
             convert <<balance;
             balance1=convert.str();
             string qustate2="UPDATE bankaccount SET balance ='"+balance1+"' WHERE account_no='"+account_no+"'";
             const char* q2=qustate2.c_str();
            int qstate2=mysql_query(conn,q2);



             cout<<"THANK YOU FOR SELLING!!!!!"<<endl;
             cout<<"YOUR MONEY IS ADDED TO YOUR ACCOUNT BALANCE"<<endl;
             cout<<"WE WILL SEND A AGENT TO YOUR PLACE FOR COLLECTING OUR CROPS"<<endl;
             cout<<"PRESS ANY KEY TO GO BACK"<<endl;

             getch();
             afterlogin();

          }




       }



}


void shop1()
{
  system("CLS");
  cout<<"*************************WELCOME TO KRISHI SHOP********************************"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                  1.FOR VIEW ALL THE ITEMS IN OUR SHOP.                       *"<<endl;
  cout<<"*                  2.FOR PURCHASE ITEMS.                                        *"<<endl;
  cout<<"*                  3.FOR GO BACK.                                                           *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"*                                                                              *"<<endl;
  cout<<"********************************************************************************"<<endl;
  int i;
  cout<<"                          ::ENTER YOUR CHOICE::                                "<<endl;
  cin>>i;
  switch(i)
  {
  case 1:
    display(start);
    break;
  case 2:
    purchase();
    break;
  case 3:
    afterlogin();
    break;
  }
}
void purchase()
  {

  }
void logincheck(){

  string username;
  string password;
  system("CLS");
 cout<<"******************************EASY FARMING*************************************"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                            ENTER YOU USER NAME:";
 cin>>username;
 cout<<"*                            ENTER YOUR PASSWORD:";
 cin>>password;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*******************************EASY FARMING*************************************"<<endl;
 string qustate="SELECT * FROM farmers WHERE USERNAME = '"+username+"'";
  const char* q=qustate.c_str();
int qstate=mysql_query(conn,q);

 res = mysql_store_result(conn);

 while( row=mysql_fetch_row(res))
 {


    current_user=username;
    if(row[2]==password)
    {
      afterlogin();    }
 }

}


void adminlogin(){


  system("CLS");
   string username;
  string password;
 cout<<"******************************EASY FARMING*************************************"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                            WELCOME ADMIN (X"  "X)                                                  *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                            ENTER YOU ADMIN USER NAME: ";
 cin>>username;
 cout<<"*                            ENTER YOUR ADMIN PASSWORD: ";
 cin>>password;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*******************************EASY FARMING*************************************"<<endl;
string admin="admin";
 if(username==admin && password==admin )
 {
     adminpage();
 }
 else
 {
     cout<<"PLEASE ENTER VALID CRENDENTIALS"<<endl;
     cout<<"PRESS ANY KEY TO TRY AGAIN"<<endl;
     getch();
     adminlogin();
 }
}


void main_menu()
{ int i;
system("CLS");
 menu:
 cout<<"******************************EASY FARMING*************************************"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                            1.FARMER LOGIN                                    *"<<endl;
 cout<<"*                            2.FARMER REGISTRATION                             *"<<endl;
 cout<<"*                            3.ADMIN LOGIN                                     *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*                                                                              *"<<endl;
 cout<<"*******************************EASY FARMING*************************************"<<endl;
 cout<<"*                            ENTER YOUR CHOICE :";
 cin>>i;
 switch(i){
  case 1:
      logincheck();
      break;
  case 2:
       register1();
       break;
  case 3:
      adminlogin();
      break;

 }
}
void register1()
 {  string name;
string username;
string password;
string age;
string family;
string land_area;
string account_no;
int qstate;
     farmer f;

     name=f.naam();
     username=f.usrname();
     password=f.pass();
     age=f.aged();
     account_no=f.account();
     family=f.f_no();
     land_area=f.land_Ar();
     bool q;
   string qustate="SELECT * FROM bankaccount";
   const char* q1=qustate.c_str();
   int qstate1=mysql_query(conn,q1);

     res = mysql_store_result(conn);

     while( row=mysql_fetch_row(res))
       {
          if(row[0]==account_no)
          {
              q=1;
          }


       }

  if(q)
  {


      string query="insert into farmers(NAME,USERNAME,PASSWORD,AGE,FAMILY_MEMBER,ACCOUNT_NO,LAND_AREA) values('"+name+"','"+username+"','"+password+"','"+age+"','"+family+"','"+account_no+"','"+land_area+"')";
        const char* q=query.c_str();
       qstate=mysql_query(conn,q);
        if(!qstate){
            cout<<"YOU REGISTERED SUCESSFULLY!"<<endl;
        }
        cout<<'\n'<<"PRESS ANY KEY TO GOTO MAIN MENU";
        getch();
        main_menu();
  }

  else{

    cout<<"                        ::PLEASE ENTER CORRECT BANKACCOUNT NO::                "<<endl;
    cout<<"                            PRESS ANY KEY TO TRY AGAIN                         "<<endl;
    getch();
    register1();
  }
 }

int main()
{
   system("color F0");



    connection();
    main_menu();


    return 0;
}

