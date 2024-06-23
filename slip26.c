Q A
i. Write a C program to compare one string to another using standard library function.
         #include<stdio.h>
         #include<string.h>
               int main()
         {
                  char s1[10],s2[10];
                  printf("Enter first string= ");
                      scanf("%s",s1);  
                 printf("Enter second string= ");
                      scanf("%s",s2);
                 if(strcmp(s1,s2)==0)
                     {
                         printf("String are same");
                     }            
                else if(strcmp(s1,s2)>0)
                     {
                        printf("String 1 is greater");
                     }     
              else
                   {
                         printf("String 2 is greater");
                   }       
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
Consider the following database:
Car (c_no int, owner varchar(20), model varchar(10), color varchar(10)
Driver (driver_no int, driver_name varchar(20), license_no int, d_age int, salary float)
Car and Driver are related with many to many relationship   
A Create the above database in PostGreSQL and insert sufficient records.  
* create table  car(cno int primary key, owner varchar(20), model varchar(10), color varchar(10));
        insert into car values(101,'om','swift','white');
        insert into car values(102,'sai','amaze','white');
        insert into car values(103,'ram','indica','black');
        insert into car values(104,'sham','mahindra','blue');
        insert into car values(1051,'ramesh','swift','red'); 
* create table driver (dno int primary key, dname varchar(20), license_no int, d_age int, salary float);
         insert into driver values(1,'ram','1234','20',234.67);
         insert into driver values(2,'ramesh','934','40',5674.67);
         insert into driver values(3,'sakshi','9034','29',2904.7);
         insert into driver values(4,'kanchan','1235','30',1234.67);
         insert into driver values(5,'sakshi','9874','28',98550.7);
*  create table c_d(cno int references car(cno),dno int references driver(dno));
         insert into c_d values(101,1);
         insert into c_d values(102,2);
         insert into c_d values(103,3);
         insert into c_d values(104,4);
         insert into c_d values(105,5);                             
create or replace function cardet(color1 text) returns void as'
   declare
     owner1 text;
     c1 cursor for select owner from car where color=color1;
   begin
     open c1;
       loop
      fetch c1 into owner1;
      exit when not found;
     raise notice ''Owner name= %'',owner1;
       end loop;
     close c1;
   end;
  'language 'plpgsql';
   
 create or replace function driver1() returns trigger as'
    begin
      if new.salary<=0 then
    raise exception ''SALAY negative or zero not allowed......'';
      end if;
     return new;
    end;
  'language 'plpgsql';          
 create trigger t9 before insert or update on driver for each row execute procedure driver1();  
  
   
   
   
   
     
          
