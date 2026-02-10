-- Assignment-3
-- 1. Write queries to:
-- Display the system date, current day, current month and spell out year, spell out current date,
-- round the system date on month, display the date of next Friday, truncate the system date on
-- month, find the day after three days, and also check whether it is AM or PM right now.
-- 2. Queries Based on EMP table:
-- Display day of date of joining column, display those employees who join the company on
-- Monday, display those employees who join the company this month, and display those
-- employees who join the company in last 30 days.
-- 3. Create a table train having four columns (Train Number, date of Departure,
-- time of departure, time of arrival)
-- 
-- Display all the records, display those trains which arrived on PM, and display train number
-- who are going to depart in next one hour.


-- Display the system date, current day, current month and spell out year, spell out current date,
-- round the system date on month, display the date of next Friday, truncate the system date on
-- month, find the day after three days, and also check whether it is AM or PM right now.
SELECT NOW() as "Current Timestamp",
CURDATE() as "Current Date",
MONTH(CURDATE()) as "Current Month",
DATE_FORMAT(CURDATE(), '%M') as "Current Month in Text",
DATE_FORMAT(CURDATE(), "%Y") as "Current Year in Text",
DATE_FORMAT(CURDATE(), "%M %d, %Y") as "Spelled out current date",
CASE
WHEN DAY(CURDATE()) < 15
  THEN DATE_FORMAT(CURDATE(), '%Y-%m-01')
ELSE
  DATE_FORMAT(DATE_ADD(CURDATE(), INTERVAL 1 MONTH), '%Y-%m-01')
END AS "System Date Rounded on Month",
DATE_ADD(curdate(), INTERVAL CASE WHEN WEEKDAY(CURDATE()) >= 4 THEN  7 - ( WEEKDAY(CURDATE()) - 4)
ELSE 4 - WEEKDAY(CURDATE()) END DAY)  as "Date of next friday" ,
DATE_FORMAT(CURDATE(), "%Y-%m-%01") as "Truncated on month",
DATE_ADD(CURDATE(), INTERVAL 3 DAY) as "Date after three days",
CASE WHEN time(now()) > "12:00:00" THEN "PM" else "AM" end as "AM/PM";

 
-- Display day of date of joining column, display those employees who join the company on
-- Monday, display those employees who join the company this month, and display those
-- employees who join the company in last 30 days.
SELECT name, DATE_FORMAT(date_of_joining,"%W")  as "Day joined" FROM employees;
SELECT name as "Employees joined on Monday" FROM employees WHERE WEEKDAY(date_of_joining) = 0;
SELECT name as "Employees joined this month" FROM employees WHERE DATE(date_of_joining) >= DATE_FORMAT(NOW(), "%Y-%m-01");
SELECT name as "Employees joined in the last 30 days" FROM employees WHERE date(date_of_joining) >= DATE_SUB(CURDATE(), INTERVAL 30 DAY); 

DROP TABLE IF EXISTS trains;
--  Create a table train having four columns (Train Number, date of Departure, time of departure, time of arrival)
CREATE TABLE trains (
	id BIGINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	train_number VARCHAR(20) NOT NULL,
	date_of_departure DATE,
	time_of_departure TIME,
	time_of_arrival TIME
);

INSERT INTO trains
(train_number, date_of_departure, time_of_departure, time_of_arrival)
VALUES
('12951', '2025-01-20', '06:30:00', '08:45:00'),
('12002', '2025-01-21', '12:15:00', '13:30:00'),
('22691', '2025-01-22', '21:00:00', '22:10:00'),
('19019', '2025-01-23', '05:45:00', '06:55:00'),
('11077', '2025-01-24', '17:10:00', '18:40:00');


-- Display all the records, display those trains which arrived on PM, and display train number
-- who are going to depart in next one hour.
SELECT * FROM trains WHERE time_of_arrival >= '12:00:00';
SELECT train_number FROM trains WHERE time_of_departure <= CURTIME() + INTERVAL 1 HOUR AND time_of_departure>= CURTIME();
