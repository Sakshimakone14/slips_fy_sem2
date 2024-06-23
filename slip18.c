Q1 A
i A file “student.txt” contains rollno, name and total_marks. Write a program to read this file to display all student details on screen.
#include<stdio.h>
  int main()
{
  FILE *f1;
  int i,rno,mark,n;
  char name[10];
  f1=fopen("abc.txt","r");
 printf("Enter limit= ");
   scanf("%d",&n);
 if(f1==NULL)   
  {
    printf("File not found");
     exit(0);
  }
  for(i=0;i<n;i++)
  {
    fscanf(f1,"%d%s%d",&rno,name,&mark);
   
    printf("\nRoll no=%d",rno);
    printf("\nName=%s",name);
    printf("\nmarks=%d",mark);
  }
}
ii. Write a program to calculate area of a circle. Use macro for PI.
#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
  int main()
{
   float a,r;
    printf("Enter radius= ");
      scanf("%f",&r);
   a=PI*r*r;
    printf("The area of circle= %f",a);   
 
}  
Section II: Relational Database Management Systems
Consider the following database
Student (Roll_No int, Sname varchar (20), Sclass char (10))
Teacher (T_No int, Tname char (20), Experience int)
Student and Teacher are related with many to many relationship with the descriptive attribute Subject.
Q 2) A Create the above database in PostGreSQL and insert sufficient records.
*  create table Student (Roll_No int primary key, Sname varchar (20), Sclass varchar (10));
       insert into Student values(101,'om','fy');
       insert into Student values(102,'sai','sy');
       insert into Student values(103,'ram','ty');
       insert into Student values(104,'ramesh','fy');
       insert into Student values(105,'sham','sy');
* create table Teacher (T_no int primary key, Tname char (20), Experience int);
       insert into Teacher values(1,'ramesh',12);  
       insert into Teacher values(2,'arti',6);  
       insert into Teacher values(3,'kanchan',21);  
       insert into Teacher values(4,'sakshi',13);  
       insert into Teacher values(5,'kunal',26);
* create table t_s(Roll_no int references Student(Roll_no),T_no int references Teacher(T_no),sub varchar(30));
       insert into t_s values(101,1,'c++'); 
       insert into t_s values(102,2,'dbms'); 
       insert into t_s values(103,3,'c'); 
       insert into t_s values(104,4,'html');
        insert into t_s values(105,5,'js');   
        
i i. Write a trigger before inserting the teacher record into a teacher table. Experience should be a minimum of 4 years. If it is less 
than 4 years trigger gets fired and displays an appropriate message               
create or replace function teach() returns trigger as'
   begin
     if new.Experience>4 then
   raise exception ''Exp less than four not allowed'';
     end if;
    end;
   'language 'plpgsql';    
create trigger t1 before insert on teacher for each row execute procedure teach();
ii  Write a stored function to find the details of the maximum experienced teacher.
 create or replace function teacher1() returns void as'
   declare 
      d1 Teacher%rowtype;
   begin
     select * into d1 from Teacher where Experience=(select max(Experience) from Teacher);
     raise notice ''Teacher no= %'',d1.T_no;    
     raise notice ''Teacher tname= %'',d1.Tname;  
     raise notice ''Teacher experince= %'',d1.Experience;  
  end;
 'language 'plpgsql'; 
iii Write a cursor to accept the student name from the user as an input and give list of subjects taken by the student.
create or replace function stud_sub(name1 Student.name%type) returns void as'
   declare
     sub1 t_s.sub%type;
     c1 cursor for select t_s.sub from t_s,Student,Teacher where Student.Roll_no=t_s.Roll_no and Teacher.T_no=t_s.T_no 
     and Sname=name1;
   begin
     open c1;
       loop
         fetch c1 into sub1;
         exit when not found;
       raise notice ''Subject= %'',sub1; 
     close c1;
  end;
 'language 'plpgsql';          

