Q A 
i. Write a program to interchange two numbers using pointers.
#include<stdio.h>
  int main()
{
    int *p,*q,a,b,c;
      printf("Enter 1 no= ");
        scanf("%d",&a);
     printf("Enter 2 no= ");
        scanf("%d",&b);    
     p=&a;
     q=&b;
   c=*p;
  *p=*q;
  *q=c;     
  printf("\nInterchange no a=%d",*p); 
  printf("\nInterchange no b=%d",*q);      
}
ii. Write a program to accept and display details of 5 students (roll no,name, percentage) using structure.
#include<stdio.h>
   int main()
{
     struct stud
  {
     int roll_no;
    char name[10];
    float per; 
  }s1[5];
 int i,n;
   printf("enter limit= ");
     scanf("%d",&n);
  for(i=0;i<n;i++)
   {
      printf("Enter student Roll_no  Name  Percentage");
        scanf("%d%s%f",&s1[i].roll_no,s1[i].name,&s1[i].per);
   }     
  for(i=0;i<n;i++)
   {
      printf("\nStudent rollno= %d",s1[i].roll_no);
      printf("\nStudent name= %s",s1[i].name);
      printf("\nStudent percentage= %f",s1[i].per);                  
   } 
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
*  create table e_p(pno int references Project(pno),eno int references Employee(eno),start_date date);
         insert into e_p values(101,1,'22-4-2024');  
         insert into e_p values(102,2,'21-6-2023');  
         insert into e_p values(103,3,'20-6-2021');  
         insert into e_p values(104,4,'27-12-2024');  
         insert into e_p values(105,5,'1-4-2023');
i Write a trigger before insert/update on project table. Raise an exception if duration is <=0.    
        create or replace function trigger1() returns trigger as'
   begin
     if duration<=0 then    
       raise exception ''duration caanot be less than 0 ..................'';
     end if;
     return new;
  end;
'language 'plpgsql';        
create trigger t4 before insert or update on Project for each row execute procedure trigger1();     
ii Write a cursor to accept the project name as an input parameter from the user and display the names of employees working on that
   project.
      create or replace function f1(pname1 text) returns void as'
         declare
              ename1 text;
              c1 cursor for select Employee.ename from Project,Employee,e_p where Project.pno=e_p.pno and Employee.eno=e_p.eno 
              and pname=pname1;
        begin
             open c1;
                loop 
                    fetch c1 into ename1;
                    exit when not found;
                  raise notice''Employee name= %'',ename1; 
              end loop;
          close c1;
       end;
   'language 'plpgsql';    
