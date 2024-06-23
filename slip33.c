Q A 
Write a program to read the contents of a text file and count the number of characters, lines and words in the file.
#include<stdio.h>
   int main()
{
  FILE *f1;
     char ch;
  int character=0,lines=0,words=0;    
  f1=fopen("sm.txt","r");    
   if(f1==NULL)
    {
      printf("File not found");
      exit(0);
    }
   while(!feof(f1))
    {
      fgetc(f1);
        if(ch==' ')
         {
          words++;
         }
       if(ch=='\n')
         {
          lines++;
         }  
    } 
    fclose(f1);
    printf("file success");
    printf("no of words= %d",words);
    printf("no of lines= %d",lines);
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
 i Write a function which accepts the model name and prints all cars of that model.   
   create or replace function cardet(model1 text) returns void as'
          declare
               d1 car%rowtype;
          begin
            select * from car where model=model1;
              raise notice''Car no= %'',d1.cno; 
              raise notice''Car owner= %'',d1.owner; 
              raise notice''Car model= %'',d1.model; 
              raise notice''Car color= %'',d1.color;        
        end;
        'language 'plpgsql';
ii Write a trigger before insert/update on Driver. Raise exception if driver age is < 21.  
     create or replace function f1() returns trigger as'
            begin
                if(new.d_age<21) then
              raise exception''Age cannot be less then 21'';   
                 end if;
               return new;  
              end;
            'language 'plpgsql';  
create trigger t1 before insert or update on driver for each row execute procedure f1();                                   
