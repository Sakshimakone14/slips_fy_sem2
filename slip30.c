Q A
i. Write a program to calculate length of string using predefined function
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  int main()
{
    char s1[10];
     int a;
    printf("Enter string= ");
      scanf("%s",&s1);  
   a=strlen(s1);
    printf("Length of string= %d",a);
}  
ii  Write a program in C to display the contents of an array in the reverse order using pointer         
#include<stdio.h>
#include<stdlib.h> 
  int main()
{
    int *a[10],i,n;
      printf("Enter limit= ");
        scanf("%d",&n); 
     printf("Numbers= ");
       for(i=0;i<n;i++)
        {
          scanf("%d",a+i);
        }
    printf("Reverse Numbers= ");
       for(i=n-1;i>0;i--) 
      {
        printf("%d",*(a+i));
      }     
}  
Section II : Relational Database Management Systems
Consider the following Customer- Account database.
Customer (cno integer, cname varchar(20), city varchar(20))
Account (accno integer, acc_type varchar(10), opening_date date, balance money)
Customer and Account are related with a one to many relationship
A  create the above database in PostGreSQL and insert sufficient records.
    * create table Customer (cno int primary key, cname varchar(20), city varchar(20));
    insert into Customer values(101,'om','pune');
    insert into Customer values(102,'sai','mumbai');
    insert into Customer values(103,'ram','nashik');
    insert into Customer values(104,'sham','shrirampur');
    insert into Customer values(105,'ramesh','pune');
* create table Account (a_no int primary key, a_type varchar(10), opening_date date, balance money,cno int references Customer(cno));
    insert into Account values(1,'rural','12-5-2022','5000',101);
    insert into Account values(2,'rural','12-6-2023','42000',102);
    insert into Account values(3,'rural','15-10-2024','8000',103);
    insert into Account values(4,'urban','11-9-2012','50900',104);
    insert into Account values(5,'urban','12-5-2024','56000',105);
i  Write a function using cursor which accepts city name as input and prints the details of all customers in that city
create or replace function customer17(city1 text) returns void as'
   declare
     cus Customer%rowtype;
     c1 cursor for select * from Customer where city=city1;
   begin
     open c1;
        loop
          fetch c1 into cus;
          exit when not found;
         raise notice''customer no= %'',cus.cno;       
         raise notice''customer name= %'',cus.cname;       
         raise notice''customer city= %'',cus.city;       
      end loop;
    close c1;
   end;
 'language 'plpgsql';     
ii Write a trigger which does not allow deletion of accounts of ____type 
create or replace function acc() returns trigger as'
   begin
       if(old.a_type=''urban'') then
     raise exception ''Deletion of record not allowed'';
        end if;
     return old; 
  end;
  'language 'plpgsql';
create trigger t6 before delete on Account for each row execute procedure acc();







