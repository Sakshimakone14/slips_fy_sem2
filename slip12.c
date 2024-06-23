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
ii. Write a C program to count the vowels and consonants in a string
     #include<stdio.h>
         int main()
    {
             char s1[100];
             int i,c=0,v=0;
                printf("Enter string: ");
                   scanf("%s",s1);
                for(i=0;s1[i]!='\0';i++)
                  {
                         if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u' || s1[i]=='A' || s1[i]=='E' || s1[i]=='U' || s1[i]=='I' || s1[i]=='O')
                                 {
                                         v++;
                                 }
                         else
                               {
                                     c++; 
                               }        
                  }
           printf("\nVowels count = %d",v);
            printf("\nConsonents count = %d",c);   
                     
    }     
Section II : Relational Database Management Systems
Consider the followingr Department-employee database.
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
        
 i Write a trigger before inserting an employee record in the Employee table. Raise an exception if salary < 0        
  create or replace function fun() returns trigger as'
     begin
       if new.salary<''0'' then
     raise exception ''Salary  less than 0 not allowed'';
       end if;
       return new;
     end;
     'language 'plpgsql';    
 create trigger t2 before insert on Employee for each row execute procedure fun(); 
ii Write a cursor to display the department-wise names of employees whose salary is between 50000 and 70000.
 create or replace function details() returns void as'
     declare
       ename1 Employee.ename%type;
        c1 cursor for select ename from Employee, Department where Employee.dno= Department.dno and sal between 
        ''5000'' and ''100000'';
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
