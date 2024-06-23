Q A
i. Write a program to calculate length of string using predefined function
#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
  int main()
{
    int a;
    char s1[10];
   printf("Enter a string= ");
     gets(s1);
  a=strlen(s1);
   printf("Length of string= %d",a);    
} 
ii. Write a program to copy the contents of one file to another.
  #include<stdio.h>
    int main()
{
    FILE *f1,*f2;
    int ch;
     f1=fopen("sm.txt","r");
     f2=fopen("abc.txt","w");
   if(f1==NULL)
    {
       printf("File does not found");
    }  
  while(!feof(f1))
   {
     ch=fgetc(f1);
     putc(ch,f2);
   }
 printf("File copied sucessfully.......................");  
}
Section II: Relational Database Management Systems
Consider the following database
Person (pno int, name varchar (20), birthdate date, income money)
Area (aid int, aname varchar (20), area_type varchar (5) )
The person and area related to many to one relationship. The attribute ‘area_type’ can have
values either ‘urban’ or ‘rural’.
Q 2)
A Create the above database in PostGreSQL and insert sufficient records. 
*  create table Area (aid int, aname varchar (20), area_type varchar (25) );
         insert into Area values(101,'pune','urban');   
         insert into Area values(102,'mumbai','urban');   
         insert into Area values(103,'newasa','urban');   
         insert into Area values(104,'belapur','rural');   
         insert into Area values(105,'amalner','rural'); 
*  create table  Person (pno int, name varchar (20), birthdate date, income money,aid int references Area(aid)); 
         insert into Person values(1,'om','12-4-2008','34000',101);  
         insert into Person values(2,'sai','11-2-2009','1334000',102);  
         insert into Person values(3,'ram','12-10-2010','4000',103);  
         insert into Person values(4,'ramesh','1-2-2018','124000',104);  
         insert into Person values(5,'sham','1-4-2002','94000',105);
i Write a trigger before inserting the record into the area table. If the area name is null then the trigger should get fired and display an
appropriate message.  
   create or replace function trigger1() returns trigger as'
   begin
     if new.aname=NULL then    
       raise exception ''Area name cannot be null ..................'';
     end if;
     return new;
  end;
'language 'plpgsql';  
create trigger t4 before insert or update on Area for each row execute procedure trigger1();   
ii Write a stored function that accepts the area name as an input parameter from the user and displays the count of persons living in
that area.  
   create or replace function pcount(aname1 text) returns  int  as'
         declare
             cnt int;
          begin
             select count(*)  into cnt from Area,Person where Area.ano=Person.ano and aname=aname1;
              return cnt;
         end;
         'language 'plpgsql';     
                
