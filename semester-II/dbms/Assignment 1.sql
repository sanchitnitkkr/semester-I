/*Assignment-1
1. Create table Student (Rno, Name, DOB, Gender, Class, College, City, Marks). Insert
five records in student table.
2. Display the detail structure of student table and Display the information of all the
students.
3. Display information in ascending order of marks. Display Rno, Name and Class
information of ‘Patiala’ students.
4. Change the marks of Rno 5 to 89 and Change the name and city of Rno 9.
5. Delete the information of ‘Amritsar’ city records and also Delete the records of student
where marks<30.
*/
-- Create table Student(Rno, Name, DOB, Gender, Class, College, City, Marks).
CREATE table students (
 rollNo INTEGER PRIMARY KEY AUTO_INCREMENT,
 name VARCHAR(100) NOT NULL,
 dob DATE NOT NULL,
 gender TEXT NOT NULL CHECK (gender IN ('male','female')),
 class varchar(20),
 college varchar(20),
 city varchar(30),
 marks INTEGER NOT NULL
);
-- Insert five records in student table
INSERT INTO students (name, dob, gender, class, college, city, marks)
VALUES
('Sanchit Tewari', '2004-05-12', 'male', NULL, 'NIT KKR', 'Patiala', 450),
('Riya Sharma', '2005-08-23', 'female', NULL, 'DAV', 'Chandigarh', 420),
('Aarav Singh', '2005-01-17', 'male', NULL, 'St. Xaviers', 'Amritsar', 380),
('Priya Patel', '2004-11-05', 'female', '12th', NULL, 'Bengaluru', 430),
('Rahul Kumar', '2006-03-28', 'male', '10th', NULL, 'Lucknow', 400),
('Ananya Mehta', '2005-06-14', 'female', '11th', 'Modern School', 'Amritsar', 410),
('Aditya Verma', '2004-12-02', 'male', '12th', 'Delhi Public School', 'Delhi', 445),
('Ishita Gupta', '2006-09-21', 'female', '10th', 'St. Thomas School', 'Kolkata', 395),
('Kabir Singh', '2004-07-30', 'male', '12th', 'Ryan International', 'Noida', 430),
('Tanya Reddy', '2005-04-18', 'female', '11th', 'Bishop Cotton', 'Bengaluru', 425);

-- Display detail structure of student table
DESCRIBE students;

-- Display the information of all the students
SELECT * FROM students;

-- Display information in ascending order of marks.
SELECT * FROM students ORDER BY marks asc;

SET SQL_SAFE_UPDATES = 0;

-- Display Rno, Name and Class information of 'Patiala' students
SELECT rollNo, name, class FROM students WHERE city = "Patiala";

-- Change the marks of Rno 5 to 89
UPDATE students set rollNo = 89 WHERE rollNo = 5;

-- Change name and city of Rno 9
UPDATE students SET city = 'Punjab', name = 'Aditi' WHERE rollNo = 9;

-- Delete the information of 'Amritsar' city records
DELETE FROM students WHERE city = "Amritsar";

-- Delete the records of student where marks < 30
DELETE FROM students WHERE marks < 30;
-- ROLLBACK;  -- cancels the insert

