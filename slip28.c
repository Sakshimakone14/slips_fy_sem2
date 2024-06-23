Q A i i. Write a C program to calculate SQUARE of given number using MACRO.
#include<stdio.h>
#define SQUARE(n) n*n
  int main()  
{
   int n; 
    printf("Enter a num= ");
      scanf("%d",&n); 
    printf("\n square of num= %d",SQUARE(n));  
}  
Q 1)
A
Write a C program to accept file name and character as command line arguments and count number of occurrences of given 
character in the file.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
   int main()
{
    int ch,i;
  do
   {
      printf("Enter your chioce \n 1-lowercase string \n 2-compare string\n");
         scanf("%d",&ch);
      switch(ch)   
       {
         case 1:char s1[10];                          
                printf("Enter string= ");
                  scanf("%s",s1);
               for(i=0;s1[i]!='\0';i++)
                 {
                   s1[i]=s1[i]+32;
                 } 
               printf("String in lowercase= %s",s1);
         break;
        case 2:char s2[10],s3[10];
               printf("Enter first string= ");
                  scanf("%s",s2);
               printf("Enter second string= ");
                  scanf("%s",s3);
               if(strcmp(s2,s3)==0)
                  printf("String are same");
               else if(strcmp(s2,s3)>=0) 
                   printf("String 1 is greater"); 
               else
                  printf("String 2 is greater");
         break;                                  
       }
   }  
while(ch<3);
} 
Section II : Relational Database Management Systems
Consider the following database :
Student (rollno integer, name varchar(30),class varchar(10))
Subject(Scode varchar(10),subject name varchar(20))
Student and subject are related with M-M relationship with attributes marks_scored.
Q 2) A Create the above database in PostGreSQL and insert sufficient records
*  create table Student (Roll_No int primary key, Sname varchar (20), Sclass varchar (10));
       insert into Student values(101,'om','fy');
       insert into Student values(102,'sai','sy');
       insert into Student values(103,'ram','ty');
       insert into Student values(104,'ramesh','fy');
       insert into Student values(105,'sham','sy');    
* create table subject(Scode varchar(10) primary key,subject name varchar(20));
       insert into subject values(1,'rdbms');  
       insert into subject values(2,'dbms');        
       insert into subject values(3,'js');        
       insert into subject values(4,'vsc');        
       insert into subject values(5,'c++');
* create table sub_stud(Roll_no int references Student(Roll_no),Scode varchar(10) references subject(Scode),marks_scored 
int);  
    insert into sub_stud values(101,1,78);
    insert into sub_stud values(102,2,80);
    insert into sub_stud values(103,3,98);
    insert into sub_stud values(104,4,58);
    insert into sub_stud values(105,5,70); 
i. Write a stored function using cursors, to accept class from the user and display the details of the students of that class.
    create or replace function f1(sclass1 text) returns void as'
         declare
            d1 Student%rowtype;
            c1 cursor for select * from Student where Sclass=sclass1;
         begin
             open c1;
                  loop
                      fetch c1 into d1;
                      exit when not found;
                 raise notice''Student Rollno= %'',d1.Roll_no;  
                 raise notice''Student name= %'',d1.Sname;  
                 raise notice''Student class= %'',d1.Sclass;
              end loop;
           close c1;
         end;
      'language 'plpgsql'; 
 ii Write a trigger before insert/update the marks_scored. Raise exception if Marks are negative.    
    create or replace function f1() returns trigger as'
       begin
            if(new.marks_scored <0) then
               raise exception''Marks cannot be negative'';
           end if;
          return new;
     end;
   'language 'plpgsql'; 
create trigger t2 before insert or update on sub_stud for each row execute procedure f1();                                                      
