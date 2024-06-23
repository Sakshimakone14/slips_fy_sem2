#include <stdio.h>
Q 1) A i. Write a program to calculate sum of two numbers. Pass the numbers as command line arguments.
int main(int argc, char *argv[])
{
	int a,b,sum;
	if(argc!=3)
	{
		printf("please use \"prg_name value1 value2 \"\n");
		return -1;
	}	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	sum = a+b;	
	printf("Sum of %d, %d is: %d\n",a,b,sum);	
	return 0;
}
ii. Write a program to create student structure having fields roll no,name. Accept details of one student and write a function to
display the details.
#include<stdio.h> 
   struct stud
    {
      int roll_no;
      char name[20];
    }s1;
   int main()
{
   void display(struct stud s1);     
printf("Enter roll no= ");
  scanf("%d",&s1.roll_no);
printf("\nEnter stud name= ");
   scanf("%s",s1.name);
 display(s1);
} 
 void display(struct stud s1) 
{  
printf("\nEnter ROLLNO= %d",s1.roll_no);
printf("\nEnter name= %s",s1.name);       
} 
Q.1 A Write a program to copy contents of file a.txt to b.txt by changing the case of each alphabet.
#include<stdio.h>
#include <ctype.h>
  int main()
{
   FILE *f1,*f2;
   int ch;
   f1=fopen("a.txt","r");
   f2=fopen("b.txt","w");   
  if(f1==NULL)
  {
    printf("File does not exist");
    exit(0);
  }
  while(!feof(f1))
  {
   ch=getc(f1);
   if(islower(ch))
    {
     ch=toupper(ch);
     putc(ch,f2); 
    }
  else if(isupper(ch))
    {
      ch=tolower(ch);
      putc(ch,f2);
    }  
  }
}
Section II : Relational Database Management Systems
Consider the following database
Movie (m_name varchar (25), release_year integer, budget money)
Actor (a_name varchar(30), role varchar(30), charges money, a_address varchar(30) )
Movie and Actor are related with many to many relationship.

A)  Create the above database in PostGreSQL and insert sufficient records.
* create table Movie (m_name varchar (25) primary key, release_year integer, budget money);
    insert into Movie values('Animal','2024','234000');
    insert into Movie values('RRR','2024','534000');
    insert into Movie values('12_fail','2024','734000');
    insert into Movie values('shidhaat','2022','734000');
insert into Movie values('kedarnath','2023','334000');
* create table Actor (a_name varchar(30) primary key, role varchar(30), charges money, a_address varchar(30) );
    insert into  Actor values('ranbir','hero','50000','mumbai');
    insert into  Actor values('ram','hero','70000','madras');
    insert into  Actor values('vikrant','hero','80000','mumbai');
    insert into  Actor values('sham','hero','50000','pune');
    insert into  Actor values('sushant','hero','90000','mumbai');
* create table m_a(m_name varchar(25) references Movie(m_name),a_name varchar(30) references Actor(a_name));
     insert into m_a values('Animal','ranbir');
     insert into m_a values('RRR','ram');
     insert into m_a values('12_fail','vikrant');
     insert into m_a values('shidhaat','sham');
     insert into m_a values('kedarnath','sushant');
i.Write a function using cursor, which will accept the actor name and print the names of all movies in which that actor has acted.
  create or replace function movie_name(aname1 Actor.a_name%type) returns void as'
       declare
       mname1 Movie.m_name%type;
        c1 cursor for select Movie.m_name from Actor,Movie,m_a where Actor.a_name=m_a.a_name and Movie.m_name=m_a.m_name and  a_name=aname1;     
      begin
          open c1;
             loop
                fetch c1 into mname1;
                Exit when not found;
       raise notice''Movie name= %'',mname1; 
           end loop;
         close c1;
       end;
     'language 'plpgsql';   
ii.Write a trigger which will be executed whenever an actor is deleted from the actor table, display appropriate message.
  create or replace function f1() returns trigger as'
      begin
         raise notice''The actor record is being deleted'';
      end;
     'language 'plpgsql';     
   create trigger t90 after delete on Actor  for each row execute procedure f1();
                   
