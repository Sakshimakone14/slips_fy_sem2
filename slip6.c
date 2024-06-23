Q 1)A
i.Write a C program to compare two strings using standard library function.
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
  int main() 
{
    char s1[5],s2[5];
      printf("Enter 1 string= ");
         scanf("%s",s1);
      printf("Enter 2 string= ");
         scanf("%s",s2);     
     if(strcmp(s1,s2)==0)
      {
        printf("String are same");
      }
     else if(strcmp(s1,s2)<0)
      {
        printf("String s2 is greater");
      }
     else 
      {
        printf("String s1 is greater");
      }

} 
ii.Write a C program to copy contents of one file to another file. 
 #include<stdio.h>
   int main()
{
 FILE *f1,*f2;
 int ch;
   f1=fopen("a.txt","r");
   f2=fopen("abc.txt","w");
 if(f1==NULL)
  {
     printf("File does not found");
  }
 while(!feof(f1))
  {
     ch=fgetc(f1);
     fputc(ch,f2);
  }
  fcloseall();
  printf("copies sucessfully..............");
} 
Q 2 A
 Write a C program to create structure employee (id, name, salary). Accept details of n employees and perform the following operations:
a. Display all employees.
b. Display details of all employees having salary > ____.
 #include<stdio.h>   
    int main()
  {
     struct emp
       {
              int id,salary;
              char name[10];
       }e1[10];
 int i,n,ch;
 printf("Enter limit: ");
    scanf("%d",&n);
 for(i=0;i<n;i++)         
{  
 printf("Enter emp_id emp_name emp_salary= ");
   scanf("%d%s%d",&e1[i].id,e1[i].name,&e1[i].salary);
} 
 do
 {
    
        printf("\n1-display all \n2-salary>1200");
        printf("Enter choice= ");
          scanf("%d",&ch);
      switch(ch) 
        {    
        case 1: for(i=0;i<n;i++)
          {
             printf("\nEnter emp id= %d",e1[i].id);
             printf("\n Enter emp name= %s",e1[i].name);
             printf("\nEnter emp salary =%d",e1[i].salary);
          } 
          break;
        case 2:for(i=0;i<n;i++)
         {
            if(e1[i].salary>=1200)
             {
              printf("\nEnter emp id= %d",e1[i].id);
              printf("\n Enter emp name= %s",e1[i].name);
              printf("\nEnter emp salary =%d",e1[i].salary); 
             }
         }
         break;
        }
       }  
     while(ch<3);                
 }
 Section II : Relational Database Management Systems
Consider the following database
Movie (m_name varchar (25), release_year integer, budget money)
Producer (p_id integer, pname vachar(30), p_address varchar (30))
Movie and Producer are related with many to many relationship.
  A Create the above database in PostGreSQL and insert sufficient records.
* create table Movie (m_name varchar (25) primary key, release_year integer, budget money);
    insert into Movie values('Animal','2024','234000');
    insert into Movie values('RRR','2024','534000');
    insert into Movie values('12_fail','2024','734000');
    insert into Movie values('shidhaat','2022','734000');
   insert into Movie values('kedarnath','2023','334000');   
* create table Producer (p_id integer primary key, pname varchar(30), p_address varchar (30));
    insert into producer values(101,'om','pune'); 
    insert into producer values(102,'sai','mumbai');
    insert into producer values(103,'ram','nasik');
    insert into producer values(104,'sham','shrirampur');
    insert into producer values(105,'ramesh','newasa');            
* create table m_p(m_name varchar(25) references Movie(m_name),p_id int references Producer(p_id)); 
     insert into m_p values('Animal',101);
     insert into m_p values('RRR',102);
     insert into m_p values('12_fail',103);
     insert into m_p values('shidhaat',104);
     insert into m_p values('kedarnath',105);

i. Write a stored function which accepts the producer name and prints the number of movies produced by him. 
 create or replace function no_of_movies(pname1 text) returns int as'
      declare 
          cnt int;
      begin
          select count(*) into cnt from Movie,Producer,m_p where Movie.m_name=m_p.m_name and Producer.p_no=m_p.p_no
            and pname=pname1;
      return  cnt;
   end;
'language 'plpgsql';             
ii. Write a trigger which will be executed whenever insertion is made to the movie table. If the budget is less than 1,00,000 do
not allow the insertion. Give appropriate message. 
   create or replace function f1() returns trigger as'
         begin
              if(new.budget<''1000'') then
                raise exception''Budget cannot be less than 1000'';
             end if;
           return new;
         end;
         'language 'plpgsql';       
create trigger t1 before insert on Movie for each row execute procedure f1();  
 
 
 
 
 
 
 
