-- Assignment–5
-- Create table and insert appropriate records.
-- S (Salesperson table) (Sno, Sname, City)
-- P (Part table) (Pno, Pname, Color)
-- SP(Sno, Pno, Qty)
-- 1. Identify primary and foreign keys in each of these tables and create all the tables.
-- 2. Violate the foreign key constraint and identify the oracle errors.
-- 3. Delete record of supplier S1 from S table and write a note on the output of query.
-- 4. Get Qty supplied for Red parts and get Sname supplying Red part.
-- 5. For each part supplied get part number and names of all cities supplying the part.
-- 6. Get all pairs of suppliers numbers such that the two suppliers are located in the same city.
-- 7. Drop table SP and create another table SP1 with delete cascade foreign key option
-- 8. Delete record of supplier S1 from S table and write a note on the output of query.
-- 9. Drop table SP1 and create another table SP2 with delete set null option of foreign key.
-- 10. Delete record of supplier S1 from S table and write a note on the output of query.
-- 11. Alter table SP2 and drop existing foreign key constraint.
-- 12. Add foreign key constraint with alter table option with on delete set default option.

-- Create table and insert appropriate records.
-- S (Salesperson table) (Sno, Sname, City)
-- P (Part table) (Pno, Pname, Color)
-- SP(Sno, Pno, Qty)

-- 1. Identify primary and foreign keys in each of these tables and create all the tables.
DROP TABLE IF EXISTS supplier_by_parts2;
DROP TABLE IF EXISTS supplier_by_parts1;
DROP TABLE IF EXISTS supplier_by_parts;
DROP TABLE IF EXISTS suppliers;
DROP TABLE IF EXISTS parts;

CREATE TABLE suppliers (
	s_no VARCHAR(100) PRIMARY KEY,
	s_name VARCHAR(100) NOT NULL,
	city VARCHAR(100) NOT NULL
);

CREATE TABLE parts (
	p_no VARCHAR(100) PRIMARY KEY,
	p_name VARCHAR(100) NOT NULL,
	color VARCHAR(100) NOT NULL
);

CREATE TABLE supplier_by_parts (
	s_no VARCHAR(100) NOT NULL,
	p_no VARCHAR(100) NOT NULL,
	qty INT UNSIGNED DEFAULT 1,
	CONSTRAINT s_no_fk
	FOREIGN KEY (s_no) REFERENCES suppliers(s_no),
-- 	ON DELETE CASCADE,
	CONSTRAINT p_no_fk
	FOREIGN KEY (p_no) REFERENCES parts(p_no)
);

-- 2. Violate the foreign key constraint and identify the oracle errors.
INSERT INTO suppliers VALUES ('S1', 'Ramesh', 'Mumbai');
INSERT INTO suppliers VALUES ('S2', 'Suresh', 'Delhi');
INSERT INTO suppliers VALUES ('S3', 'Mahesh', 'Mumbai');
INSERT INTO suppliers VALUES ('S4', 'Naresh', 'Chennai');
INSERT INTO suppliers VALUES ('S5', 'Ashok', 'Mumbai');

INSERT INTO parts VALUES ('P1', 'Bolt', 'Red');
INSERT INTO parts VALUES ('P2', 'Nut', 'Green');
INSERT INTO parts VALUES ('P3', 'Screw', 'Red');
INSERT INTO parts VALUES ('P4', 'Washer', 'Blue');

INSERT INTO supplier_by_parts VALUES ('S1', 'P1', 100);
INSERT INTO supplier_by_parts VALUES ('S5', 'P1', 100);
INSERT INTO supplier_by_parts VALUES ('S2', 'P1', 100);
INSERT INTO supplier_by_parts VALUES ('S1', 'P99', 200); -- SQL Error [1452] [23000]: Cannot add or update a child row: a foreign key constraint fails (`college`.`supplier_by_parts`, CONSTRAINT `p_no_fk` FOREIGN KEY (`p_no`) REFERENCES `parts` (`p_no`))
INSERT INTO supplier_by_parts VALUES ('S2', 'P2', 150);
INSERT INTO supplier_by_parts VALUES ('S3', 'P1', 300);
INSERT INTO supplier_by_parts VALUES ('S4', 'P4', 250);


-- 3. Delete record of supplier S1 from S table and write a note on the output of query.
DELETE FROM suppliers WHERE s_no = "S1"; -- SQL Error [1451] [23000]: Cannot delete or update a parent row: a foreign key constraint fails (`college`.`supplier_by_parts`, CONSTRAINT `s_no_fk` FOREIGN KEY (`s_no`) REFERENCES `suppliers` (`s_no`))s

-- 4. Get Qty supplied for Red parts and get Sname supplying Red part.
SELECT s.s_name, sp.qty
FROM supplier_by_parts sp
INNER JOIN parts p ON p.p_no = sp.p_no AND lower(p.color) = "red"
INNER JOIN suppliers s ON s.s_no = sp.s_no;

-- 5. For each part supplied get part number and names of all cities supplying the part.
SELECT p.p_no  as "Part Number", p.p_name as "Part Name", GROUP_CONCAT(DISTINCT s.city SEPARATOR ",") as "City Supplying"
FROM supplier_by_parts sbp
INNER JOIN parts p ON p.p_no = sbp.p_no
INNER JOIN suppliers s ON s.s_no = sbp.s_no
GROUP BY sbp.p_no;

-- 6. Get all pairs of suppliers numbers such that the two suppliers are located in the same city.
SELECT s1.s_no AS Supplier1,
       s2.s_no AS Supplier2,
       s1.city
FROM suppliers s1
INNER JOIN suppliers s2 
     ON s1.city = s2.city
     AND s1.s_no < s2.s_no;

-- 7. Drop table SP and create another table SP1 with delete cascade foreign key option
DROP table supplier_by_parts;

CREATE TABLE supplier_by_parts1 (
	s_no VARCHAR(100) NOT NULL,
	p_no VARCHAR(100) NOT NULL,
	qty INT UNSIGNED DEFAULT 1,
	CONSTRAINT s_no_fk
	FOREIGN KEY (s_no) REFERENCES suppliers(s_no)
	ON DELETE CASCADE,
	CONSTRAINT p_no_fk
	FOREIGN KEY (p_no) REFERENCES parts(p_no)
	ON DELETE CASCADE
);

-- 8. Delete record of supplier S1 from S table and write a note on the output of query.
DELETE FROM suppliers WHERE s_no = "S1"; -- Updated rows: 1

-- 9. Drop table SP1 and create another table SP2 with delete set null option of foreign key.
DROP table supplier_by_parts1;

CREATE TABLE supplier_by_parts2 (
	s_no VARCHAR(100),
	p_no VARCHAR(100),
	qty INT UNSIGNED DEFAULT 1,
	CONSTRAINT s_no_fk
	FOREIGN KEY (s_no) REFERENCES suppliers(s_no)
	ON DELETE SET NULL,
	CONSTRAINT p_no_fk
	FOREIGN KEY (p_no) REFERENCES parts(p_no)
	ON DELETE SET NULL
);

-- 10. Delete record of supplier S1 from S table and write a note on the output of query.
INSERT INTO suppliers VALUES ('S1', 'Ramesh', 'Mumbai');
INSERT INTO supplier_by_parts2 VALUES ('S1', 'P1', 100);
DELETE FROM suppliers WHERE s_no = "S1"; -- Updated rows: 1

-- 11. Alter table SP2 and drop existing foreign key constraint.
ALTER TABLE supplier_by_parts2
DROP CONSTRAINT s_no_fk;

ALTER TABLE supplier_by_parts2
DROP CONSTRAINT p_no_fk;

-- 12. Add foreign key constraint with alter table option with on delete set default option.
ALTER TABLE supplier_by_parts2
ADD CONSTRAINT s_no_fk
FOREIGN KEY (s_no) REFERENCES suppliers(s_no)
ON DELETE RESTRICT;

ALTER TABLE supplier_by_parts2
ADD CONSTRAINT p_no_fk
FOREIGN KEY (p_no) REFERENCES parts(p_no)
ON DELETE RESTRICT;
