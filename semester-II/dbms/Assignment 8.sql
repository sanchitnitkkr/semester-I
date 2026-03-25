-- PL/SQL Lab Assignment–8
-- 1. Write a PL/SQL block to update total sal for empno 100.
-- Eno,ename, bp,da,hra,total.
-- 2. Write a PL/SQL block to update total sal for all employees.
-- Eno,ename, bp,da,hra,total.
-- 3. Add exception handlers in PL/SQL block created earlier to update total sal for
-- empno 100. (Eno,ename, bp,da,hra,total.)
-- 4. Add exception handlers in a block which contain an insert statement for the
-- following errors:
--   violation of check constraint,
--   violation of primary key,
--   violation of foreign key,
--   violation of supplied value larger than the specified width of the column.
-- 5. Write a PL/SQL in which user defined exception is trapped when date of issue is
-- greater than date of return. (rno, bookno, doi, dor)


-- 1) Calculate and update total_salary for empno = 100
CREATE TABLE employees (
   empNo int primary key,
   ename varchar(100) not null,
   basicPay int,
   da int,
   hra int,
   total_salary int
);
INSERT INTO employees (empNo, ename, basicPay, da, hra) VALUES(100, 'Jasda', 10000, 2000, 3000);
BEGIN
   UPDATE employees
      SET total_salary = basicPay + NVL(da,0) + NVL(hra,0)
    WHERE empNo = 100;
   IF SQL%ROWCOUNT = 0 THEN
       DBMS_OUTPUT.PUT_LINE('No employee found with EmpNo = 100');
   ELSE
       COMMIT;
       DBMS_OUTPUT.PUT_LINE('Total_Salary updated for EmpNo 100');
   END IF;
END;
/


-- 2) Update total salary for ALL employees
SET SERVEROUTPUT ON;
DROP TABLE IF EXISTS employees;
CREATE TABLE employees (
   empNo int primary key,
   ename varchar(100) not null,
   basicPay int,
   da int,
   hra int,
   total_salary int
);
INSERT INTO employees (empNo, ename, basicPay, da, hra) VALUES(100, 'Jasda', 10000, 2000, 3000);
BEGIN
   UPDATE employees
      SET total_salary = basicPay + NVL(da,0) + NVL(hra,0);
   IF SQL%ROWCOUNT = 0 THEN
       DBMS_OUTPUT.PUT_LINE('No employee founds');
   ELSE
       COMMIT;
       DBMS_OUTPUT.PUT_LINE('Total Salary updated');
   END IF;
END;
/

-- 3) Question 1 with exception handling
DROP TABLE IF EXISTS employees;
CREATE TABLE employees (
   empNo int primary key,
   ename varchar(100) not null,
   basicPay int,
   da int,
   hra int,
   total_salary int
);
BEGIN
  UPDATE employees
     SET total_salary = basicPay + NVL(da,0) + NVL(hra,0)
   WHERE empNo = 100;
   IF SQL%ROWCOUNT = 0 THEN
           RAISE NO_DATA_FOUND;
       END IF;
   COMMIT;
   DBMS_OUTPUT.PUT_LINE('Total_Salary updated successfully for EmpNo 100');
 EXCEPTION
   WHEN NO_DATA_FOUND THEN
       DBMS_OUTPUT.PUT_LINE('Error: Employee with EmpNo 100 not found.');
   WHEN TOO_MANY_ROWS THEN
       DBMS_OUTPUT.PUT_LINE('Error: Multiple rows matched EmpNo 100 (data issue).');
   WHEN OTHERS THEN
       DBMS_OUTPUT.PUT_LINE('Unexpected error occured!');
       ROLLBACK;
END;
/


-- 4) INSERT with multiple exception handling (example)
DROP TABLE IF EXISTS employees
CREATE TABLE departments (
    id int primary key,
    name varchar(50)
);
CREATE TABLE employees (
   empNo int primary key,
   ename varchar(100) not null,
   basicPay int,
   da int,
   hra int,
   total_salary int,
   dept_id INT,
   CONSTRAINT fk_dept
       FOREIGN KEY (dept_id)
       REFERENCES departments(id)
);
DECLARE
    e_pk_violation    EXCEPTION;
    e_fk_violation    EXCEPTION;
    e_check_violation EXCEPTION;
    e_value_large     EXCEPTION;

    PRAGMA EXCEPTION_INIT(e_pk_violation, -00001);
    PRAGMA EXCEPTION_INIT(e_fk_violation, -02291);
    PRAGMA EXCEPTION_INIT(e_check_violation, -02290);
    PRAGMA EXCEPTION_INIT(e_value_large, -01401);

BEGIN
    INSERT INTO employees (empNo, ename, basicPay, dept_id)
    VALUES (9999, 'TESTUSER', 25000, 55);

    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Employee inserted successfully.');

EXCEPTION
    WHEN e_pk_violation THEN
        DBMS_OUTPUT.PUT_LINE('Error: Primary key violation.');

    WHEN e_fk_violation THEN
        DBMS_OUTPUT.PUT_LINE('Error: Foreign key violation.');

    WHEN e_check_violation THEN
        DBMS_OUTPUT.PUT_LINE('Error: Check constraint violated.');

    WHEN e_value_large THEN
        DBMS_OUTPUT.PUT_LINE('Error: Value too large for column.');

    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An unexpected error occured');
END;
/

-- 5) User-defined exception – DateOfIssue > DateOfReturn
DECLARE
    e_invalid_date  EXCEPTION;
    v_doi  DATE;
    v_dor  DATE;
BEGIN
    SELECT DateOfIssue, DateOfReturn
      INTO v_doi, v_dor
      FROM library;

    IF v_doi > v_dor THEN
        RAISE e_invalid_date;
    END IF;

    DBMS_OUTPUT.PUT_LINE('DateOfIssue <= DateOfReturn → Valid');

EXCEPTION
    WHEN e_invalid_date THEN
        DBMS_OUTPUT.PUT_LINE('Error: DateOfIssue cannot be later than DateOfReturn!');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No records found in library table.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/




