Q 1 A
i.Write a C program to find the area of a circle by using PI as macro
#include<stdio.h>
#define PI 3.14
  int main()
  {
     float a,r;
       printf("Enter radius= ");
         scanf("%f",&r);
       a=PI*r*r;
      printf("Area of circle= %f",a);   
  } 
Write a menu driven program to perform the following operations on strings using standard library functions:
i) Compare
ii) Copy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 int main()
{
   char s1[10],s2[10];
     int a;
    printf("Enter string= ");
      scanf("%s",s1);
   printf("Enter string= ");
      scanf("%s",s2);
  if(strcmp(s1,s2)==0)
    { 
     printf("\nString are equal");
    }  
    else if(strcmp(s1,s2)>0) 
    {
     printf("\nString 1 is greater= ",);
    }
 else if()
   { 
     printf("\n String 2 is greater");
   }  
    strcpy(s2,s1);
 printf("\ns1 string to copy= %s",s1);               
 printf("\nCopied string= %s",s2);    
} 
Q 1 A
Write a program to accept details of n employees (id, name, salary). Display all the details. Also, search for an employee by name.  
#include<stdio.h>
#include<stdlib.h>
  int main()
{
     struct emp
      {
        int id,sal;
        char name[10];
      }e1[10];
    int n,i,ch;
      printf("Enter limit= ");
        scanf("%d",&n); 
      for(i=0;i<n;i++)
       {
         printf("Enter id name sal= ");
           scanf("%d%s%d",&e1[i].id,e1[i].name,&e1[i].sal);
       }  
      do
      {
        printf("\n1-Display all details \n2-Display emp");
           printf("\nEnter chioce= ");
             scanf("%d",&ch);
           switch(ch)
            {
              case 1: for(i=0;i<n;i++)
               {
               printf("\nEnter id=%d",e1[i].id);
               printf("\nEnter name=%s",e1[i].name);
               printf("\nEnter salary=%d",e1[i].sal); 
             
               }
              break;
             case 2:  char ename[10];
                 printf("Enter emp name to search= ");
                    scanf("%s",ename); 
                  for(i=0;i<n;i++) 
              {                        
                  if(e1[i].name==ename)
               printf("\nEnter id=%d",e1[i].id);
               printf("\nEnter name=%s",e1[i].name);
               printf("\nEnter salary=%d",e1[i].sal); 
               break;    
             }                 
         }      
      }
while(ch<2); 
   }     
 
Section II : Relational Database Management Systems
Consider the following Customer- Account database.
Customer (cno integer, cname varchar(20), city varchar(20))
Account (accno integer, acc_type varchar(10), opening_date date, balance money)
Customer and Account are related with one to many relationship
  A. Create the above database in PostGreSQL and insert sufficient records.
  * create table Customer (cno int primary key, cname varchar(20), city varchar(20));
    insert into Customer values(101,'om','pune');
    insert into Customer values(102,'sai','mumbai');
    insert into Customer values(103,'ram','nashik');
    insert into Customer values(104,'sham','shrirampur');
    insert into Customer values(105,'ramesh','pune');
* create table Account (a_no int primary key, a_type varchar(10), opening_date date, balance money,cno int references Customer(cno));
    insert into Account values(1,'rural','12-5-2022','5000',101);
   insert into Account values(2,'rural','12-6-2023','42000',102);
   insert into Account values(3,'rural','15-10-2024','8000',103);
    insert into Account values(4,'urban','11-9-2012','50900',104);
   insert into Account values(5,'urban','12-5-2024','56000',105);
i Write a trigger before deleting an account record from Account table. Raise a notice and display the message “Account record is
being deleted.”   
create or replace function f1() returns trigger as'
   begin
     raise exception ''Account canot begin deleted'';
     return new;
   end;
   'language 'plpgsql';     
 create trigger t1 before delete on Account for each row execute procedure f1();
-------------------------------------------------------------------------------------------------------------------------------------------------------------
ii Write a cursor to display the account details of all customers from “Pune” city.
 create or replace function customer_det() returns void as'
   declare
     d1 Customer%rowtype;
     c1 cursor for select Customer.* from Customer,Account where Account.cno=Customer.cno and 
     city='pune';
    begin
      open c1;
        loop 
          fetch c1 into d1;
          exit when not found;
         raise notice''Customer no= %'',d1.cno; 
         raise notice''Customer name= %'',d1.cname;
         raise notice''Customer city= %'',d1.city;
      end loop;
     close c1;
    end;
   'language 'plpgsql';   

