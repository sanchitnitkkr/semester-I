-- Assignment–4
-- 
-- 1. Create table emp which has the following attributes(empno, ename, job,sal, deptno) Where
-- empno is primary key, ename is unique, job in (Prof, AP, and Lect), sal is not NULL, and
-- deptno default is 10.
-- a) Insert appropriate records, check error messages in case of violation and list all the
-- constraint names for given table.
-- b) Check the constraint name for applied constraints?
-- c) Drop the unique constraint on ename and Change Data type of ename.
-- 2. Create table S (Salesperson table) which has the following attributes (sno, sname, city)
-- Where sno is primary key.
-- Create table P (Part table) which has the following attributes (pno, pname, color) Where
-- pno is primary key
-- Create table SP which has the following attributes (sno, pno qty) Where combination of
-- (sno, pno) is primary key, also sno and pno are foreign keys.
-- a)Insert appropriate records and violate the foreign key constraint and identify the errors
-- messages.
-- b) Drop the Foreign Key constraint on sno and pno.
-- c) Alter table SP and drop existing foreign key constraint.

-- 1. Create table emp which has the following attributes(empno, ename, job,sal, deptno) Where
-- empno is primary key, ename is unique, job in (Prof, AP, and Lect), sal is not NULL, and
-- deptno default is 10.
CREATE TABLE emp (
	empno BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	ename VARCHAR(50) UNIQUE NOT NULL,
	job ENUM('professor', 'ap', 'lecturer') NOT NULL,
	salary BIGINT UNSIGNED NOT NULL,
	dept_id BIGINT UNSIGNED NOT NULL DEFAULT 10,
	CONSTRAINT fk_department 
	FOREIGN KEY (dept_id) REFERENCES departments(id)
);

-- a) Insert appropriate records, check error messages in case of violation and list all the
-- constraint names for given table.
INSERT INTO emp (ename, job, salary, dept_id)
VALUES
('Alice', 'professor', 120000, 10),
('Bob', 'ap', 85000, 40),
('Charlie', 'lecturer', 60000, 20),
('Diana', 'ap', 90000, 30),
('Ethan', 'lecturer', 65000, 50);

INSERT INTO emp (ename, job, salary)
VALUES ('Frank', 'professor', 130000);

-- Check the constraint name for applied constraints
SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS WHERE TABLE_NAME = "emp";

-- Drop the unique constraint on ename and Change Data type of ename.
ALTER TABLE emp
DROP INDEX ename;

ALTER TABLE emp
MODIFY ename VARCHAR(100) NOT NULL;

-- 2. Create table S (Salesperson table) which has the following attributes (sno, sname, city) Where sno is primary key.
CREATE TABLE sales_persons (
	s_no BIGINT PRIMARY KEY AUTO_INCREMENT,
    s_name VARCHAR(100) NOT NULL,
    city VARCHAR(100) NOT NULL
);

-- Create table P (Part table) which has the following attributes (pno, pname, color) Where pno is primary key
CREATE TABLE parts (
	p_no BIGINT PRIMARY KEY AUTO_INCREMENT,
    p_name VARCHAR(100) NOT NULL,
    color VARCHAR(100) NOT NULL
);
-- Create table SP which has the following attributes (sno, pno qty) Where combination of (sno, pno) is primary key, also sno and pno are foreign keys.
CREATE TABLE sp (
	s_no BIGINT,
    p_no BIGINT,
    CONSTRAINT s_no_fk 
    FOREIGN KEY (s_no) REFERENCES sales_persons(s_no),
    CONSTRAINT p_no_fk
    FOREIGN KEY (p_no) REFERENCES parts(p_no),
    qty INT UNSIGNED
);

-- a)Insert appropriate records and violate the foreign key constraint and identify the errors messages.
INSERT INTO sp VALUES (2, 4, 10); 
-- Error Code: 1452. Cannot add or update a child row: a foreign key constraint fails (`college`.`sp`, CONSTRAINT `s_no_fk` FOREIGN KEY (`s_no`) REFERENCES `sales_persons` (`s_no`))

-- b) Drop the Foreign Key constraint on sno and pno.
ALTER TABLE sp
DROP CONSTRAINT s_no_fk;

ALTER TABLE sp
DROP CONSTRAINT p_no_fk;
-- c) Alter table SP and drop existing foreign key constraint.
INSERT INTO sp VALUES (2, 4, 10); 