Q 1)A
i. Write a program to find the length of a string using standard library function.
#include<stdio.h>
#include<string.h>
  int main()
 {
    int n,i,count=0;
      char s1[10];
    printf("Enter string= ");
      scanf("%s",&s1);
    printf("Length of string= ");
       for(i=0;s1[i]!='\0';i++)
      {
        count++;
      }    
  printf("%d",count);
 } 
ii. Write a program to read a text file and display all the characters such that the case is reversed (upper to lower and lower to upper case).
#include<stdio.h>
  int main()
 {
    FILE *f1,*f2;    
     char ch;  
  f1=fopen("sm.txt","r");
  f2=fopen("abc.txt","w"); 
   if(f1==NULL) 
    {
       printf("File not found");
        exit(0);
    }
  while(!feof(f1))
   {
     ch=fgetc(f1);
      if(islower(ch))
      { 
        fputc(toupper(ch),f2);
     } 
     if(isupper(ch))
      { 
        fputc(tolower(ch),f2);
     }      
   }
  fcloseall();
  printf("File copy successfullyyyyyyy");      
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
i  Write a trigger before insert the record of the student in the Student table. If the Roll_No is less than or equal to zero then the 
 trigger gets fired and displays the message “Invalid Roll Number”                   
create or replace function student() returns trigger as'
  begin
     if new.Roll_no<=0 then
       raise exception ''Stud roll no less than zero not allowed'';
     end if;
     return new;
   end;
  'language 'plpgsql';
create trigger T1 before insert on Student for each row execute procedure stud();          
ii  Write a stored function to count the number of teachers having experience > 10 years
create or replace function teach() returns int as'
  declare
    int count1;
  begin
    select count(*) into count1 from Teacher where Experience>10;  
     return count1;
  end;
 'language 'plpgsql';    







 
 
 
 
