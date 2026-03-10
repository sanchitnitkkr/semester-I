-- Assignment–6
-- Create table and Insert appropriate records.
-- S(Sno, Sname, City, Status)
-- P(Pno, Pname, Color, Weight)
-- SP( Sno, Pno, Qty)
-- a) Apply Column level constraints on City such that it may be only “Amritsar”, “Delhi”,
-- “Batala” and “Qadian”.
-- b) Apply Column level constraints such that Qty should be between 100 to1000, Weight
-- is NOT NULL, Sname is NOT NULL and Pname is UNIQUE.
-- c) Get supplier name who supply at least one red part.
-- d) Get supplier number who supplies maximum quantity.
-- e)Get supplier number who supply quantity greater than average quantity.
-- f) Increase the Quantity of part P1 by 10%..
-- g)Get total number of parts supplied by supplier S1.
-- h) Count the parts having red color.
-- i) Count red parts supplied by Ajay.
-- j) Get the total quantity supplied by S1.
-- k) Change the color of Red parts supplied by Ajay to Green.
-- l) Delete all the entries of part P1.

-- Create table and Insert appropriate records.
-- S(Sno, Sname, City, Status)
-- P(Pno, Pname, Color, Weight)
-- SP( Sno, Pno, Qty)
DROP TABLE IF EXISTS sp;
DROP TABLE IF EXISTS P;
DROP TABLE IF EXISTS S;

CREATE TABLE S (
	s_no varchar(100) PRIMARY KEY,
	s_name varchar(150),
	city varchar(100) NOT NULL,
	status varchar(100)
);

CREATE TABLE P (
	p_no varchar(100) PRIMARY KEY, 
	p_name varchar(150) NOT NULL,
	color varchar(100),
	weight decimal(8,2)
);

CREATE TABLE sp (
	s_no varchar(100) NOT NULL,
	CONSTRAINT s_no_fk_1
	FOREIGN KEY (s_no) REFERENCES S(s_no),
	p_no varchar(100) NOT NULL,
	CONSTRAINT p_no_fk_1
	FOREIGN KEY (p_no) REFERENCES P(p_no),
	qty INT NOT NULL
);

INSERT INTO S VALUES ('S1', 'Ramesh', 'Amritsar', NULL);
INSERT INTO S VALUES ('S2', 'Suresh', 'Delhi', NULL);
INSERT INTO S VALUES ('S3', 'Mahesh', 'Batala', NULL);
INSERT INTO S VALUES ('S4', 'Naresh', 'Qadian', NULL);
INSERT INTO S VALUES ('S5', 'Ashok', 'Amritsar', NULL);

INSERT INTO P VALUES ('P1', 'Bolt', 'Red', 100);
INSERT INTO P VALUES ('P2', 'Nut', 'Green', 200);
INSERT INTO P VALUES ('P3', 'Screw', 'Red', 300);
INSERT INTO P VALUES ('P4', 'Washer', 'Blue', 400);

INSERT INTO sp VALUES ('S1', 'P1', 100);
INSERT INTO sp VALUES ('S5', 'P1', 100);
INSERT INTO sp VALUES ('S2', 'P1', 100);
INSERT INTO sp VALUES ('S2', 'P2', 150);
INSERT INTO sp VALUES ('S3', 'P1', 300);
INSERT INTO sp VALUES ('S4', 'P4', 250);

-- a) Apply Column level constraints on City such that it may be only “Amritsar”, “Delhi”, “Batala” and “Qadian”.
ALTER TABLE S
MODIFY city ENUM("Amritsar","Delhi","Batala","Qadian");

-- b) Apply Column level constraints such that Qty should be between 100 to 1000, Weight is NOT NULL, Sname is NOT NULL and Pname is UNIQUE.
ALTER TABLE P
ADD CONSTRAINT qty_range_check
CHECK(weight BETWEEN 100 AND 1000); 

ALTER TABLE P
MODIFY weight DECIMAL(8,2) NOT NULL;

ALTER TABLE S
MODIFY s_name VARCHAR(150) NOT NULL;

ALTER TABLE P
ADD CONSTRAINT p_name_unique
UNIQUE (p_name);

-- c) Get supplier name who supply at least one red part.
SELECT sp.*
FROM sp 
INNER JOIN parts p ON p.p_no  = sp.p_no AND lower(p.color) = "red"
INNER JOIN S on sp.s_no = S.s_no

-- d) Get supplier number who supplies maximum quantity.
SELECT s_no as "supplier_number", MAX(total_qty) as "qty"
FROM (
	SELECT sp.s_no, SUM(qty) as "total_qty"
	FROM sp 
	GROUP BY sp.s_no 
) a;


SELECT * FROM sp;

-- e)Get supplier number who supply quantity greater than average quantity.
SELECT *
FROM (
    SELECT s_no, SUM(qty) AS total_qty
    FROM sp 
    GROUP BY s_no
) b
WHERE total_qty >= (
    SELECT AVG(sum_qty)
    FROM (
        SELECT s_no, SUM(qty) AS sum_qty
        FROM sp 
        GROUP BY s_no 
    ) a
);

-- f) Increase the Quantity of part P1 by 10%..
UPDATE sp 
SET qty = qty * 1.1
WHERE p_no = "P1";

-- g) Get total number of parts supplied by supplier S1.
SELECT sp.s_no as "Supplier no", COUNT(*) as "No of parts supplied" 
FROM sp 
WHERE s_no = "S1";

-- h) Count the parts having red color.
SELECT COUNT(*) as "Total parts having red color"
FROM parts 
WHERE lower(color) = "red";

-- i) Count red parts supplied by Ajay.
SELECT COUNT(*) as "Red parts supplied by Ajay"
FROM sp 
INNER JOIN P p ON p.p_no = sp.p_no AND lower(p.color) = "red"
INNER JOIN S s ON s.s_no = sp.s_no AND s.s_name = "Ajay";

-- j) Get the total quantity supplied by S1.
SELECT SUM(qty) as "Total Quantity"
FROM sp 
WHERE sp.s_no = "S1"


-- k) Change the color of Red parts supplied by Ajay to Green.
UPDATE P 
INNER JOIN sp ON sp.p_no  = P.p_no 
INNER JOIN S ON S.s_no  = sp.s_no   
SET P.color = "Green"
WHERE S.s_name = "Ajay" and lower(P.color) = "red";


-- l) Delete all the entries of part P1.
DELETE FROM sp
WHERE p_no = "P1";

