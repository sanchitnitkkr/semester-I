-- PL/SQL Lab Assignment 9
-- 1. WAP to print name of employees belonging to deptno 10.
-- 2. WAP to find top 5 highest paid employees
-- 3. Perform Q1 & 2 with cursor for loop.
-- 4. Write a PL/SQL block that calculate simple interest for principal 1000, time 2
-- years and rate of interest varies from 5 to 15. Store the computed information in
-- following table:
-- Principal | time | rate | interest
-- 5.Write a PL/SQL block to print name of employees belonging of a particular
-- department, the user will supply the value of deptno during run time.

-- 1. WAP to print name of employees belonging to deptno 10.
drop table employees cascade constraints;
drop table departments cascade constraints;

create table departments (
   id              int primary key,
   department_name varchar(50)
);

insert into departments (
   id,
   department_name
) values ( 10,
           'HR' );

create table employees (
   empno        int primary key,
   ename        varchar(100) not null,
   basicpay     int,
   da           int,
   hra          int,
   total_salary int,
   dept_id      int,
   constraint fk_dept foreign key ( dept_id )
      references departments ( id )
);

insert into employees (
   empno,
   ename,
   basicpay,
   da,
   hra,
   total_salary,
   dept_id
) values ( 1,
           'Rahul',
           12000,
           2000,
           3000,
           15000,
           10 );
insert into employees (
   empno,
   ename,
   basicpay,
   da,
   hra,
   total_salary,
   dept_id
) values ( 2,
           'Ajay',
           12000,
           2000,
           3000,
           15000,
           10 );

declare
   v_ename varchar2(100);
begin
   dbms_output.put_line('Employee names in dept 10:');
   for emp_rec in (
      select ename
        from employees
       where dept_id = &v_dept_id
   ) loop
      dbms_output.put_line(emp_rec.ename);
   end loop;
end;
/

-- 2. WAP to find top 5 highest paid employees
begin
   dbms_output.put_line('Top 5 highest paid employees are:');
   for emp_rec in (
      select ename,
             total_salary
        from (
         select ename,
                total_salary
           from employees
          order by total_salary desc
      )
       where rownum <= 5
   ) loop
      dbms_output.put_line(emp_rec.ename
                           || ' - ' || emp_rec.total_salary);
   end loop;
end;
/

-- -- 3. Perform Q1 & 2 with cursor for loop.
-- Cursor for Q1: employees in dept 10
declare
   cursor c_dept10 is
   select ename
     from employees
    where dept_id = 10;
begin
   dbms_output.put_line('Employee names in dept 10 (using explicit cursor):');
   for emp_rec in c_dept10 loop
      dbms_output.put_line(emp_rec.ename);
   end loop;
end;
/

-- Cursor for Q2: top 5 highest paid employees
declare
   cursor c_top5 is
   select ename,
          total_salary
     from (
      select ename,
             total_salary
        from employees
       order by total_salary desc
   )
    where rownum <= 5;
begin
   dbms_output.put_line('Top 5 highest paid employees (using explicit cursor):');
   for emp_rec in c_top5 loop
      dbms_output.put_line(emp_rec.ename
                           || ' - ' || emp_rec.total_salary);
   end loop;
end;
/