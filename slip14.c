Q 1)A
i Accept details of n students (roll no, name, percentage) using structure.Write a menu driven program for the following:
a. Display all students
b. Display all students having percentage > ___
#include<stdio.h>
  int main()
{
   struct  student
  {
    int Roll_no;
    char name[10];
    float per;    
  }s1[10];
 int n,i,ch;
   printf("Enter limit= ");
     scanf("%d",&n);   
  for(i=0;i<n;i++)
   {
     printf("Enter Roll_no name percentage= ");
       scanf("%d%s%f",&s1[i].Roll_no,&s1[i].name,&s1[i].per);
   }
  do
   {
     printf("\n1-Display all student\n2-disp stud having per>77.45");
         printf("\nenter choice= ");
           scanf("%d",&ch);
         switch(ch)
          {
            case 1:for(i=0;i<n;i++)
                {
                   printf("\nRoll no= %d",s1[i].Roll_no);
                   printf("\nName= %s",s1[i].name);
                   printf("\nRoll no= %f",s1[i].per);
                }  
            case 2: for(i=0;i<n;i++)
                 {
                    if(s1[i].per>77.45) 
                  {
                  printf("\nRoll no= %d",s1[i].Roll_no);
                  printf("\nName= %s",s1[i].name);
                  printf("\nRoll no= %f",s1[i].per);
                  }
                 } 
           default:printf("Invalid choice");            
          }  
   }
  while(ch<3);   
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
   
 i Write a cursor to display account details of all customers of “Pune” city.  
create or replace function cus_det() returns void as'
   declare
     cus customer%rowtype;
     c1 cursor for select Customer.* from customer,account where Customer.cno=Account.cno and city=''pune'';
   begin
     open c1;
       loop
         fetch c1 into cus;
         exit when not found;
       raise notice ''Customer no= %'',cus.cno;   
       raise notice ''Customer name= %'',cus.cname;         
     raise notice ''Customer city= %'',cus.city;
    end loop;
   close c1;
 end;
 'language 'plpgsql';       
ii Write a trigger before inserting an account record in Account table and raise exception if balance is <500.
create or replace function account() returns trigger as'
   begin
     if new.balance <''500'' then
   raise exception ''balance less than 500 not allowed'';
     end if;
    end;
   'language 'plpgsql';    
create trigger t13 before insert on Account for each row execute procedure account();










  
