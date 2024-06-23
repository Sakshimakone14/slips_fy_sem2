Q 1)A
i Write a C program to copy the contents of one text file to another such that uppercase alphabets are converted to lowercase, lowercase to uppercase and digits are converted to *.
#include<stdio.h>
#include<ctype.h>
  int main()
{
   FILE *f1,*f2;
     char ch;
   f1=fopen("sm.txt","r");
   f2=fopen("xyz.txt","w");
    if(f1==NULL)
     {
       printf("File does not found= ");
        exit(0);
     }   
  while(!feof(f1))
   {
     ch=fgetc(f1);
       if(islower(ch))
        {
          fputc(toupper(ch),f2);          
        }
      else if(isupper(ch))
        {
           fputc(tolower(ch),f2);
         
        }
      else if(ch>='0' && ch<='9')
        {
          fputc(ch='*',f2);
        }   
   }
  fcloseall();
     printf("Copy successfully..................."); 
} 
Section II : Relational Database Management Systems
Consider the following Department-employee database.
Department (dno integer, dname varchar(20),city varchar(20))
Employee (eno integer, ename varchar(20), salary money)
Department and Employee are related with a one to many relationship
Q 2)
A Create the above database in PostGreSQL and insert sufficient records.
* create table  Department (dno int primary key, dname varchar(20),city varchar(20));
      insert into Department values(101,'BCS','pune');
      insert into Department values(102,'BSC','mumbai');
      insert into Department values(103,'MCS','nashik');
      insert into Department values(104,'MSC','pune');
      insert into Department values(105,'BIO','shrirampur');
* create table Employee (eno int primary key, ename varchar(20), salary money,dno int references Department(dno));
      insert into Employee values(1,'om','34000',101); 
      insert into Employee values(2,'sai','50000',102); 
      insert into Employee values(3,'ram','35000',103); 
      insert into Employee values(4,'ramesh','90000',104);
      insert into Employee values(5,'sham','54000',105); 
i Write a cursor to display the names of employees who works in “HR” department.        
create or replace function emp() returns void as'
   declare
     ename1 Employee.ename%type; 
     c1 cursor for select ename from Employee,Department where Employee.dno=Department.dno and dname=''HR'';
   begin
     open c1;
       loop
         fetch c1 into ename1;
         exit when not found;
        raise notice ''Emp name= %'',ename1;   
      end loop;
    close c1;
  end;
 'language 'plpgsql';     
ii  Write a trigger before updating an employee record in the Employee table. Raise a notice and display the message “Employee record 
is being updated”.
create or replace function t17() returns trigger as'
   begin
      raise notice ''“Employee record is being updated”.'';
       return new;
  end;
  'language 'plpgsql';      
create trigger t1 before update on Employee for each row execute procedure t17();












 
