Q 1 A
i. Write a program to interchange two numbers using pointers. 
#include<stdio.h>
  int main()
{
  int *p,*q,a,b,tempt;
    printf("Enter two nos= ");
      scanf("%d%d",&a,&b);
     p=&a;
     q=&b;
   tempt=*p;
   *p=*q;
   *q=tempt;
   printf("The interchange no is= %d\n%d",*p,*q);    
}
ii Write a program to perform the following operations on two strings using standard library functions:
a. Copy b. Compare
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
Write a program to read the contents of a text file and count the number of characters, lines and words in the file.
#include<stdio.h>
  int main()
{
  FILE *f1;
  int cc=0,lc=0,wc=0,ch;
  f1=fopen("a.txt","r");
   if(f1==NULL)
    {
       printf("File does not found ");
    }  
   while(!feof(f1)) 
    {
      ch=getc(f1);
      cc++;
      if(ch=='\n')
        {
          lc++;
        }
      if(isspace(ch))
        {
          wc++;
        }  
    }
   printf("Number of characters= %d",cc);
   printf("Number of words= %d",wc);
   printf("Number of lines= %d",lc);  
}
Section II : Relational Database Management Systems
Consider the following database
Customer (cno integer, cname varchar(20), city varchar(20))
Account (a_no int, a_type varchar(10), opening_date date, balance money)
Customer and Account are related with one to many relationship
Q 2)
A Create the above database in PostGreSQL and insert sufficient records.
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

i.Write a function which accepts account no as input and prints the details of that account.
       create or replace function acc(ano1 int) returns void as'
            declare
                det Account%rowtype;
            begin
                select * into det from Account where a_no=ano1;
                raise notice''Account no= %'',det.a_no;      
                raise notice''Account type= %'',det.a_type;      
                raise notice''Account opening_date= %'',det.opening_date;      
                raise notice''Account balance= %'',det.balance;
           end;
           'language 'plpgsql';           
ii.Write a trigger which is executed whenever update is made to the account table. If the balance becomes less than 1000, print an
error message that balance cannot be less than 1000.
   create or replace function f1() returns trigger as'
         begin
              if(new.balance<''1000'') then
                raise exception''Balance cannot be less than 1000'';
             end if;
           return new;
         end;
         'language 'plpgsql';       
create trigger t1 before update on Account for each row execute procedure f1();
