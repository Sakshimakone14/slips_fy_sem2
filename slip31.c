Q 1)
A Write a menu driven program to perform the following operations on strings using user defined functions:
i)Length
ii)Copy
#include<stdio.h>
#include<string.h>
 int length(char s1[10])
  {
     int i;
     for(i=0;s1[i]!='\0';i++);
     return i;     
  }
  void copy(char s1[10],char s2[10])
  {
     int i;
    for(i=0;s2[i]!='\0';i++)
    {  
      s1[i]=s2[i];
    }
    s1[i]='\0';
    printf("string= %s",s1);   
  }
  int main()
{
   char s1[10],s2[10];
   int ch;
      printf("Enter 1 string= ");
        gets(s1);
      printf("Enter 2 string= ");
        gets(s2); 
  do
    {
       printf("\n1-length\n 2-copy\n Enter chioce= ");
          scanf("%d",&ch);
       switch(ch)
        {
        case 1:printf("\nLength of 1 string= %d",length(s1));
                printf("\nLength of 2 string= %d",length(s2));
          break;
        case 2:copy(s1,s2);
          break;
        default:printf("Invalid chioce.....");               
        }    
    }while(ch<3);        
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
i Write a function to accept department name and return the number of employees of that department.
create or replace function dep(dname1 text) returns int as'  
   declare
      count1 int;
   begin
     select count(*) into count1 from Employee,Department where Department.dno=Employee.dno and dname=dname1; 
   return count1;    
   end;
   'language 'plpgsql'; 
ii Write a trigger after insert on an employee record. Display appropriate message when the record is inserted.
 create or replace function emp1234() returns trigger as'
    begin
      raise exception ''Record are inserted'';
   end;
  'language 'plpgsql'; 
 create trigger t9 after insert  on Employee for each row execute procedure emp1234();   
 
 
 
 
 
 
 
   
