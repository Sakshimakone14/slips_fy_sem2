Q 1) A
i.
Write a C program to accept and display details of one student (roll number, name, percentage) using structure.
#include<stdio.h>
#include<stdlib.h>
  int main()
{
   struct student 
   {
      int roll_no;
      char name[20];
      float per;
   }s1;
  printf("Enter roll_no name percentage= ");
    scanf("%d%s%f",&s1.roll_no,&s1.name,&s1.per);
  printf("\nROLL_NO= %d",s1.roll_no);
  printf("\nNAME= %s",s1.name);
  printf("\nPERCENTAGE= %f",s1.per);   
} 
ii Write a program to copy contents of one text file to another.
#include<stdio.h>
   int main()
{
   char ch;
   FILE *f1,*f2;
     f1=fopen("sm.txt","r");
     f2=fopen("abc.txt","w");
       if(f1==NULL)
        {
          printf("File not found");
           exit(0);
        }
  while(!feof(f1))
   {
     ch=getc(f1);
     fputc(ch,f2);
   }
 fclose(f1);
 fclose(f2);
 printf("File copy successfullyyy...........");
}   
Section II : Relational Database Management Systems
Consider the following Project-Employee database
Project (pno integer, pname varchar (30), ptype varchar (20), duration integer)
Employee (eno integer, ename varchar(20), qualification varchar(15), salary float, joining_date date)
Relationship between Project and Employee is many to many with descriptive attribute start_date,no_of_hours_worked.
Q 2) A Create the above database in PostGreSQL and insert sufficient records.
* create table  Project (pno int primary key, pname varchar (30), ptype varchar (20), duration int);
       insert into Project values(101,'robotic','abc',5);
       insert into Project values(102,'C++','xyz',4);
       insert into Project values(103,'robotic','abc',3);
       insert into Project values(104,'db','ssm',9);
       insert into Project values(105,'rd','km',6);
 * create table Employee (eno int primary key, ename varchar(20), qualification varchar(15), salary int, joining_date date);
           insert into Employee values(1,'om','mcs',3400,'13-2-2024');
           insert into Employee values(2,'sai','mba',9400,'11-2-2023');
            insert into Employee values(3,'ram','bca',8400,'14-5-2022');
            insert into Employee values(4,'sham','mcs',9400,'19-4-2024');
            insert into Employee values(5,'ramesh','bcs',6400,'13-2-2023');
*  create table e_p(pno int references Project(pno),eno int references Employee(eno),start_date date,no_of_hours_worked int);
         insert into e_p values(101,1,'22-4-2024',9);  
         insert into e_p values(102,2,'21-6-2023',6);  
         insert into e_p values(103,3,'20-6-2021',4);  
         insert into e_p values(104,4,'27-12-2024',9);  
         insert into e_p values(105,5,'1-4-2023',9);  
 i Write a trigger before insert or update on no_of_hours field. If the no_of_hours_worked is less than zero then raise an exception and display the appropriate message.         
create or replace function trigger1() returns trigger as'
   begin
     if new.no_of_hours<0 then    
       raise exception ''no_of_hours less than 0 not allowed..................'';
     end if;
     return new;
  end;
'language 'plpgsql';        
create trigger t4 before insert or update on e_p for each row execute procedure trigger1();

ii Write a cursor to display all projects having duration > ____.
create or replace function project_det() returns void as'
   declare
      p1 Project%rowtype;
      c1 cursor for select * from Project where duration>3;    
    begin
      open c1;
        loop 
          fetch c1 into p1;
          exit when not found;
        raise notice ''Project no= %'',p1.pno;  
        raise notice ''Project name= %'',p1.pname;  
        raise notice ''Project type= %'',p1.ptype;  
        raise notice ''Project duration= %'',p1.duration;  
       end loop;
      close c1;
    end;
   'language 'plpgsql';     

