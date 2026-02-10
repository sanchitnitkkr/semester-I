/*Assignment 2
Create Emp table: Columns are EmpNo, Ename, Job, Salary, date of joining,
Commission, DeptNO
Insert 5 records by storing Null value in some records for commission column.
1. Get employee no and employee name who work in dept no 10, 20 and 30?
2. Display the employee names of those clerks whose salary > 2000 and also get all details
of employees whose salary between 2000 and 3000 ?
3. Display name of those employees whose commission is NULL ?
4. Display name of employees having two ‘a’ or ‘A’ chars in the name and also display the
name of the employees whose second char is ‘b’ or ‘B’ ?
5. Display maximum, minimum, average salary of deptno 10 employees and also display
total number of employees working in deptno 20.
 */
DROP TABLE IF EXISTS employees;
DROP TABLE IF EXISTS departments;

CREATE TABLE departments (
	id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(100) NOT NULL
);

INSERT INTO departments (id, name) VALUES (10, "HR");
INSERT INTO departments (id, name) VALUES (20, "Marketing");
INSERT INTO departments (id, name) VALUES (30, "Engineering");
INSERT INTO departments (id, name) VALUES (40, "Sales");
INSERT INTO departments (id, name) VALUES (50, "Client Relations");
INSERT INTO departments (id, name) VALUES (60, "Accounting");


-- Create Emp table: Columns are EmpNo, Ename, Job, Salary, date of joining, Commission, DeptNO

CREATE TABLE employees (
	id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(100) NOT NULL,
	job VARCHAR(100) NOT NULL,
	salary INT UNSIGNED,-- 
	date_of_joining DATE NOT NULL,
	commission INT UNSIGNED,
	department_id BIGINT UNSIGNED NOT NULL,
	CONSTRAINT fk_department_id
	FOREIGN KEY (department_id) REFERENCES departments(id)
);

-- Insert 5 records by storing Null value in some records for commission column.
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Sanchit Tewari", "SDE-1", 50000, "2023-01-01", NULL, 30);
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Rahul Gupta", "Clerk", 25000, "2024-01-01", NULL, 10);
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Amit Mishra", "Accounting Head", 75000, "2024-01-01", NULL, 60);
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Prem Rai", "Marketing Head", 65000, "2024-01-01", 20000, 20);
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Aditi Pandey", "HR", 50000, "2022-01-01", NULL, 50);
INSERT INTO employees (name, job, salary, date_of_joining, commission, department_id) VALUES ("Vaishak Banshiwal", "Sales Head", 25000, "2024-01-01", 10000, 40);

-- Get employee no and employee name who work in dept no 10, 20 and 30?
SELECT * FROM employees 
WHERE department_id IN (10,20,30);

-- Display the employee names of those clerks whose salary > 2000 and also get all details
-- of employees whose salary between 2000 and 3000
SELECT name FROM employees WHERE job = "clerk" AND salary > 2000;
SELECT * FROM employees WHERE SALARY BETWEEN 2000 AND 3000;

--  Display name of those employees whose commission is NULL ?
SELECT * FROM employees WHERE commission IS NULL;

-- Display name of employees having two ‘a’ or ‘A’ chars in the name and also display the
-- name of the employees whose second char is ‘b’ or ‘B’
SELECT * FROM employees  
WHERE (lower(name) LIKE "%a%a%") OR (lower(name) LIKE "_b%");

-- Display maximum, minimum, average salary of deptno 10 employees and also display
-- total number of employees working in deptno 20.
SELECT max(salary) as "Max Salary", min(salary) as "Min Salary", avg(salary) AS "Avg Salary"
FROM employees 
WHERE department_id = 10;

SELECT COUNT(*) as "Total Number of Employees"
FROM employees WHERE department_id = 20;

