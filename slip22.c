Q A
i Write a function which accepts a number and three flags as parameters if number is even set first flag to 1. If number is prime set 
second flag to 1 and if number is divisible by 3 or 7 set the third flag to 1(pass addresses of flags to the function.)
#include<stdio.h>
int main()
{
     int n,i,flag1=0,flag2=1,flag3=0;
     void set_flag(int n,int *f1,int *f2,int *f3)
    {
         if(n%2==0)
           *f1=1;
         for(i=2;i<n-1;i++)
        {
              if(n%i==0)
             {
                  *f2=0;
                  break;
              }
         }
     
        if(n%3==0 || n%7==0)
          *f3=1;
       }
       printf("\n Enter Number : ");
       scanf("%d",&n);
       set_flag(n,&flag1,&flag2,&flag3);
       if(flag1==1)
           printf("\n Number is even..");
       if(flag2==1)
           printf("\n Number is Prime..");
       if(flag3==1)
           printf("\n Number is divisible by 3 or 7");
    return 0;
}
  
ii. Write a program to accept details of n items (code, name, price) using structure and display the details.
#include<stdio.h>
  int main()
{
    struct item
  {
     int code,price;
     char name[10];
  }it[10];  
 int n,i;
   printf("Enter limit= ");
     scanf("%d",&n);
   for(i=0;i<n;i++)
    {
      printf("Enter Item code name price= ");
        scanf("%d%s%d",&it[i].code,it[i].name,&it[i].price);
    } 
   for(i=0;i<n;i++)
    {
       printf("\nCode of item= %d",it[i].code);
       printf("\nName of item= %s",it[i].name);
       printf("\nCode of item= %d",it[i].price);
    }     
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
i.Write a trigger before deleting a person's record from the person's table. Raise a notice and display the message “person record is 
being deleted”.
    create or replace function per() returns trigger as'
            begin
                raise notice''person record is  being deleted'';
           end;
        'language 'plpgsql'; 
 create trigger t1 before delete on Person for each row execute procedure per();            
ii Write a cursor to display the names of persons living in urban area.
      create or replace function per() returns void as'
            declare
                 pname1 text;
              c1 cursor for select pname from Area,Person where Area.ano=Person.ano and area_type=''urban'';
            begin
                      
                  
      









   
