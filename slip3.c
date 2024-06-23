Q.1)  A  i. Write a programto calculate length of string using standard library function. 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  int main()
{
   char s1[10];
   int a; 
      printf("Enter the string= ");
         scanf("%s",&s1);
      a=strlen(s1); 
     printf("Length of string= %d",a);   
}  
ii.Write a program to allocate memory dynamically for n integers.Accept the elements and calculate their sum and average.
#include<stdio.h>
 int main()
{
   int *p,n,i,s=0;
   float a;
   printf("enter limit= ");
     scanf("%d",&n);
   p=(int *)malloc(n*sizeof(int));  
   printf("Number= ");
    for(i=0;i<n;i++)
     {
       scanf("%d",p+i);
     } 
     for(i=0;i<n;i++)
      {
       s=s+*(p+i);
      }   
   a=(float)s/n;
   printf("sum= %d",s);
   printf("avg= %f",a);
} */
---------------------------------------------------------------------------------------OR----------------------------------------------------------------------------------------
Q 1) A Write a program to declare a structure person (name, address) which contains another structure birthdate (day, month, year)
. Accept the details of n persons and display them.
#include<stdio.h>
#include<stdlib.h>
   int main()
{
    struct student
    {
       char name[10],address[10];  
    struct date
    {
        int dd,mm,yy;
    }d1;        
    }s1[10];
  int n,i;
    printf("Enter a limit= ");
      scanf("%d",&n); 
    for(i=0;i<n;i++)
     {
        printf("Enter Name Address= ");
          scanf("%s%s",&s1[i].name,&s1[i].address);  
        printf("Enter date in dd-mm-yyyy= ");
          scanf("%d%d%d",&s1[i].d1.dd,&s1[i].d1.mm,&s1[i].d1.yy);           
     }    
    for(i=0;i<n;i++)
    {
       printf("\nEnter Name= %s",s1[i].name);
       printf("\nEnter Address= %s",s1[i].address);
       printf("\nDate in dd-mm-yyyy= %d-%d-%d",s1[i].d1.dd,s1[i].d1.mm,s1[i].d1.yy);
    }
} 
---------------------------------------------------------------------------------------------------------------------------------------------------------
section 2 B Consider the following database
Doctor (d_no int, d_name varchar(30), specialization varchar(35), charges int)
Hospital (h_no int, h_name varchar(20), city varchar(10))
Doctor and Hospital are related with many to one relationship.

A) Create the above database in PostGreSQL and insert sufficient records.
*  create table Hospital(h_no int primary key,h_name varchar(20), city varchar(10));
insert into hospital values(101,'unnde','shrirampur');
insert into hospital values(102,'city','pune');
insert into hospital values(103,'badak','mumbai');
insert into hospital values(104,'patil','shrirampur');
insert into hospital values(105,'vighnaharta','newasa');
* create table Doctor (d_no int primary key, d_name varchar(30), specialization varchar(35), charges int,h_no int references Hospital(h_no));
1)insert into doctor values(1,'om','mbbs',2300,101);
2)insert into doctor values(2,'sai','mba',2400,102);
3)insert into doctor values(3,'ram,'pgd',2200,103);
4)insert into doctor values(4,'sham','mbbs',2600,104);
5)insert into doctor values(5,'rames','mba',2900,105);
[i] Write a trigger before insert/update on Doctor table. Raise exception if charges are <0.
create or replace function doctor() returns trigger as'
   begin
     if new.charges<0 then
        raise exception ''Charges less than zero'';
     end if; 
     return new;
    end;
    'language 'plpgsql'; 
 create trigger t1 before insert or update on doctor1 for each row execute procedure doctor(); 
  ii. Write a function which will accept the name of the doctor and print the hospital details that the doctor is visiting. 
create or replace function hospital_details(dname1 doctor1.dname%type) returns void as' 
   declare 
       h1 hospital%rowtype;
   begin
     select into h1 hospital.* from hospital,doctor1 where hospital.hno=doctor1.hno and dname1=dname;    
     raise notice ''Hospital no= %'',h1.hno;
     raise notice ''Hospital name= %'',h1.hname;
     raise notice ''Hospital city= %'',h1.city;
   end;
   'language 'plpgsql';  

