-- PL/SQL Lab Assignment 10
-- 1. Write a stored procedure to calculate addition, subtraction, multiplication and
-- division of two numbers. Call this procedure from a block. Write a local
-- procedure for the same.
-- 2. Write functions and procedures to perform Insert, Update, Delete and Retrieve
-- operations on emp.
-- 3. Write a trigger to implement primary key constraint and foreign key constraint.
-- 4. Write a trigger such that no updation on emp can takes place on Sunday.
-- 5. Write a trigger such that commission cannot be greater than sal.
-- (eno, ename, job, sal, comm., dno)


-- 1. Write a stored procedure to calculate addition, subtraction, multiplication and
-- division of two numbers. Call this procedure from a block. Write a local
-- procedure for the same.

create or replace procedure addition (
   x number,
   y number,
   z out number
) is
begin
   z := x + y;
end;
/

create or replace procedure subtract (
   x number,
   y number,
   z out number
) is
begin
   z := x - y;
end;
/

create or replace procedure multiply (
   x number,
   y number,
   z out number
) is
begin
   z := x * y;
end;
/

create or replace procedure divide (
   x number,
   y number,
   z out number
) is
begin
   z := x / y;
end;
/

declare
   addition_res       number;
   subtraction_res    number;
   multiplication_res number;
   division_res       number;
   x                  number := &x;
   y                  number := &y;
   procedure computestats is
   begin
      addition(
         x,
         y,
         addition_res
      );
      dbms_output.put_line('Addition: ' || addition_res);
      subtract(
         x,
         y,
         subtraction_res
      );
      dbms_output.put_line('Subtraction: ' || subtraction_res);
      multiply(
         x,
         y,
         multiplication_res
      );
      dbms_output.put_line('Multiplication: ' || multiplication_res);
      divide(
         x,
         y,
         division_res
      );
      dbms_output.put_line('Division: ' || division_res);
   end;
begin
   computestats();
end;

-- 2. Write functions and procedures to perform Insert, Update, Delete and Retrieve
-- operations on emp.
begin
   for rec in (
      select *
        from employees
   ) loop
      dbms_output.put_line(rec.ename);
   end loop;
end;
/
create table employees (
   empno        int primary key,
   ename        varchar(100) not null,
   basicpay     int,
   da           int,
   hra          int,
   total_salary int
);
select *
  from emp;

create or replace procedure insertintoemployees (
   ename    varchar,
   basicpay number,
   da       number default 0,
   hra      number default 0
) is
   total_salary number;
   last_id      number;
   last_rec     number;
begin
   total_salary := basicpay + da + hra;
   select empno
     into last_id
     from employees
    order by empno desc
    fetch first 1 row only;

   insert into employees (
      empno,
      ename,
      basicpay,
      da,
      hra,
      total_salary
   ) values ( last_id + 1,
              ename,
              basicpay,
              da,
              hra,
              total_salary );
end;

create or replace procedure updateemployee (
   empno    number,
   ename    varchar,
   basicpay int,
   da       int default 0,
   hra      int default 0
) is
   total_salary number;
begin
   total_salary := basicpay + da + hra;
   update employees
      set ename = ename,
          basicpay = basicpay,
          da = da,
          hra = hra,
          total_salary = total_salary
    where empno = empno;
end;
/

create or replace procedure viewemployees is
begin
   for rec in (
      select *
        from employees
   ) loop
      dbms_output.put_line(rec.ename
                           || ', Total Salary' || rec.total_salary);
   end loop;
end;
/

create or replace procedure deleteemployee (
   empno number
) is
begin
   delete from employees
    where empno = empno;
end;
/

-- 3. Write a trigger to implement primary key constraint and foreign key constraint.
create or replace trigger trg_pk_employees before
   insert on employees
   for each row
declare
   v_count number;
begin
   select count(*)
     into v_count
     from employees
    where empno = :new.empno;

   if v_count > 0 then
      raise_application_error(
         -20001,
         'Duplicate EMPNO not allowed'
      );
   end if;
end;
/

create or replace trigger trg_fk_employees before
   insert or update on employees
   for each row
declare
   v_count number;
begin
   select count(*)
     into v_count
     from departments
    where dept_id = :new.dept_id;

   if v_count = 0 then
      raise_application_error(
         -20002,
         'Invalid DEPT_ID'
      );
   end if;
end;
/

-- 4. Write a trigger such that no updation on emp can takes place on Sunday.
create or replace trigger sunday_update_prevention_trg before
   update on employees
   for each row
declare
   current_day number;
   invalid_update exception;
begin
   select to_char(
      sysdate,
      'D'
   )
     into current_day
     from dual;

   if current_day = 7 then
      raise invalid_update;
   end if;
exception
   when invalid_update then
      dbms_output.put_line('No employee updates on Sunday.');
end;
/

-- 5. Write a trigger such that commission cannot be greater than sal.
-- (eno, ename, job, sal, comm., dno)
create or replace trigger salary_prevent_update_tgr before
   update or insert on employees
   for each row
begin
   if :new.commision > :new.total_salary then
      raise_application_error(
         -20001,
         'Commission cannot be greater than salary'
      );
   end if;
end;
/