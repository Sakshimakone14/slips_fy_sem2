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
ii. Write a C program to count the number of characters and lines in a text file.
  #include<stdio.h>
       int main()
{
       FILE *f1;
       char ch;
       int c=0,l=0;
  f1=fopen("abc.txt","r");
    if(f1==NULL)
       {
            printf("File does not exit....");
       } 
while(!feof(f1))
   {
             ch=fgetc(f1);
                 c++;
             if(ch=='\n')
                l++;    
   } 
printf("\n No of character= %d",c);
printf("\n No of lines= %d",l);             
} 
         
Section II : Relational Database Management Systems
Consider the following Item-Supplier database
Item(itemno integer, itemname varchar(20))
Supplier(supplier_no integer, supplier_name varchar(20), city varchar(20))
Item-Supplier: M-M relationship with rate(money) and quantity (integer) as descriptive attributes.
Q 2) A Create the above database in PostGreSQL and insert sufficient records.   
*  create table Item(itemno int primary key, itemname varchar(20));   
         insert into Item values(101,'abc');
         insert into Item values(102,'xyz');
         insert into Item values(103,'pqr');
         insert into Item values(104,'acd');
         insert into Item values(105,'xyz');
* create table Supplier(supplier_no int primary key, supplier_name varchar(20), city varchar(20));    
        insert into Supplier values(1,'om','pune');  
        insert into Supplier values(2,'sai','mumbai');  
        insert into Supplier values(3,'ram','nashik');  
        insert into Supplier values(4,'ramesh','newasa');  
        insert into Supplier values(5,'sham','shrirampur'); 
*  create table i_s(itemno int references Item(itemno),supplier_no int references Supplier(supplier_no),rate money,quantity int);
           insert into i_s values(101,1,'34000',6);  
           insert into i_s values(102,2,'84000',7);  
           insert into i_s values(103,3,'14000',21);  
           insert into i_s values(104,4,'324000',8);  
           insert into i_s values(105,5,'78000',2);  
 i.Write a cursor to display the names of items whose rate is more than 500.          
create or replace function ratedet() returns void as'
  declare
      Iteamname1 item.iname%type; 
     c1 cursor for select Item.itemname from Item,Supllier,si where Item.iteamno=i_s.iteamno and 
     Supllier.supplier_no =i_s.supplier_no  and rate>''500'';
  begin
     open c1;
        loop    
         fetch c1 into Iteamname;
         exit when not found;
       raise notice ''Iteam name= %'', Iteamname1;  
     end loop;
    close c1;
  end;
 'language 'plpgsql';       
ii Write a trigger before insert or update on rate field. If the rate is less than 50 then raise the appropriate exception.
create or replace function rateupd() returns trigger as'
   begin
     if new.rate<''50'' then
       raise exception ''Rate less than 50 is not allowed'';
     end if;  
     return new;
   end;
  'language 'plpgsql';   
create trigger t2 before insert or update on i_s for each row execute procedure rateupd();










           
