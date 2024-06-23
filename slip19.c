Q 1)A
i.Write a C program to store the information of one person as his pancard number or Aadhar card number using union.  
    #include<stdio.h>
         int main()
            {
                 union pan
                     {
                          long int adharcard;
                          char pancard[10];
                     }p;
                printf("Enter adhar card no or pancard no=  ");
                     scanf("%s",p.pancard);  
               printf("\nEnter adharcard no or pancard no=  %s",p.pancard);                         
            }
 ii Write a C program to count the number of characters and lines in a text file.           
#include<stdio.h>
  int main()
{
   FILE *f1,*f2;
   char ch;
 f1=fopen("abc.txt","r");  
 f2=fopen("a.txt","w");
   if(f1==NULL)
    {
      printf("File does not exist");
    }   
   while(!feof(f1))
    {
      ch=fgetc(f1);
      putc(ch,f2);
    } 
    printf("File copied successfullyyyyyyyyyyy........."); 
}  
Section II : Relational Database Management Systems
Consider the following Project-Employee database
Project (pno integer, pname varchar (30), ptype varchar (20), duration integer)
Employee (eno integer, ename varchar(20), qualification varchar(15), salary float, joining_date date)
Relationship between Project and Employee is many to many with descriptive attribute start_date,no_of_hours_worked.
Q 2) A Create the above database in PostGreSQL and insert sufficient records.
* create table  Project (pno int primary key, pname varchar (30), ptype varchar (20), duration int);
       insert into Project values(101,'robotic','abc',5);
       insert into Project values(102,'C++','xyz',4);
       insert into Project values(103,'robotic','abc',3);
       insert into Project values(104,'db','ssm',9);
       insert into Project values(105,'rd','km',6);
 * create table Employee (eno int primary key, ename varchar(20), qualification varchar(15), salary int, joining_date date);
           insert into Employee values(1,'om','mcs',3400,'13-2-2024');
           insert into Employee values(2,'sai','mba',9400,'11-2-2023');
            insert into Employee values(3,'ram','bca',8400,'14-5-2022');
            insert into Employee values(4,'sham','mcs',9400,'19-4-2024');
            insert into Employee values(5,'ramesh','bcs',6400,'13-2-2023');
*  create table e_p(pno int references Project(pno),eno int references Employee(eno),start_date date);
         insert into e_p values(101,1,'22-4-2024');  
         insert into e_p values(102,2,'21-6-2023');  
         insert into e_p values(103,3,'20-6-2021');  
         insert into e_p values(104,4,'27-12-2024');  
         insert into e_p values(105,5,'1-4-2023');
i. Write a cursor to accept the employee name as an input parameter and displays the names of projects of that employee.
    create or replace function f1(ename1 text) returns void as'
         declare
              pname1 text;
              c1 cursor for select Project.pname from Project,Employee,e_p where Project.pno=e_p.pno and Employee.eno=e_p.eno and 
              ename=ename1;
        begin
             open c1;
                loop 
                    fetch c1 into pname1;
                    exit when not found;
                  raise notice''Project name= %'',pname1; 
              end loop;
          close c1;
       end;
   'language 'plpgsql';
 ii Write a trigger which ensures that if an employee's salary entered less than zero, the trigger gets fired.      
     create or replace function trigger1() returns trigger as'
   begin
     if salary<0 then    
       raise exception ''Salary caanot be less than 0 ..................'';
     end if;
     return new;
  end;
'language 'plpgsql';        
create trigger t4 before insert or update on e_p for each row execute procedure trigger1();
                  
