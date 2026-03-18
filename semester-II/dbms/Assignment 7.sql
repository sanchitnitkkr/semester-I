-- PL/SQL Lab Assignment-7
-- 1) Write a PL/SQL block to find the sum of two numbers.
-- 2) Write a PL/SQL block to compare two employee salaries and display which employee earns more. 
-- If both are equal, display an appropriate message
-- 3) Write a PL/SQL block to find the larger of two numbers
-- 4) Write a PL/SQL block to find the geatest of three numbers
-- 5) Write a PL/SQL block to calculate fine for rno 100
-- Rno, bookno, doi, dor, fine
-- Fine is Rs 1 if days<7
-- Fine is Rs 2 if days<14 and >7
-- Fine is Rs 3 if days>14
-- Amount mentioned is for each day.
-- 4. Write a PL/SQL block to calculate fine for all students
-- Rno, bookno, doi, dor, fine
-- Fine is Rs 1 if days7 Fine is Rs 3 if days>14 Amount mentioned is for
-- each day.
-- 6) Write a PL/SQL block to generate multiplication table for 3 to n.


-- 1) Write a PL/SQL block to find the sum of two numbers.
SET SERVEROUTPUT ON;

DECLARE
    invoice1      NUMBER;
    invoice2      NUMBER;
    total_amount  NUMBER;
BEGIN
    invoice1 := &invoice1;
    invoice2 := &invoice2;
    
    total_amount := invoice1 + invoice2;
    
    DBMS_OUTPUT.PUT_LINE('Total Payable Amount = ' || total_amount);
END;
/

-- 2) Write a PL/SQL block to compare two employee salaries and display which employee earns more. 
-- If both are equal, display an appropriate message
DECLARE
    sal1  NUMBER := &sal_emp1;
    sal2  NUMBER := &sal_emp2;
BEGIN
    IF sal1 > sal2 THEN
        DBMS_OUTPUT.PUT_LINE('Employee 1 earns more (' || sal1 || ' > ' || sal2 || ')');
    ELSIF sal2 > sal1 THEN
        DBMS_OUTPUT.PUT_LINE('Employee 2 earns more (' || sal2 || ' > ' || sal1 || ')');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Both employees earn the same salary (' || sal1 || ')');
    END IF;
END;
/

-- 3) Write a PL/SQL block to find the larger of two numbers
SET SERVEROUTPUT ON;

DECLARE
    sal1    NUMBER := &salary1;
    sal2    NUMBER := &salary2;
    sal3    NUMBER := &salary3;
    highest NUMBER;
BEGIN
    highest := sal1;
    
    IF sal2 > highest THEN highest := sal2; END IF;
    IF sal3 > highest THEN highest := sal3; END IF;
    
    DBMS_OUTPUT.PUT_LINE('The highest salary is: ' || highest);
END;
/

-- 4) Write a PL/SQL block to find the geatest of three numbers
CREATE TABLE library (
   rno int primary key,
   bookNo int,
   dateOfReturn date,
   dateOfIssue date
);
INSERT INTO library (rno, bookNo, dateOfReturn, dateOfIssue)
VALUES (
 100,
 1,
 TO_DATE('2026-03-11','YYYY-MM-DD'),
 TO_DATE('2026-02-25','YYYY-MM-DD')
);
DECLARE
   v_doi    DATE;
   v_dor    DATE;
   v_days   NUMBER;
   v_fine   NUMBER := 0;
BEGIN
   SELECT dateOfIssue, dateOfReturn
     INTO v_doi, v_dor
     FROM library
    WHERE rno = 100;
   v_days := v_dor - v_doi;
   IF v_days <= 7 THEN
       v_fine := v_days * 1;
   ELSIF v_days <= 14 THEN
       v_fine := v_days * 2;
   ELSE
       v_fine := v_days * 3;
   END IF;
   DBMS_OUTPUT.PUT_LINE('Days delayed : ' || v_days);
   DBMS_OUTPUT.PUT_LINE('Total fine   : Rs. ' || v_fine);
  
EXCEPTION
   WHEN NO_DATA_FOUND THEN
       DBMS_OUTPUT.PUT_LINE('No record found for rno = 100');
   WHEN TOO_MANY_ROWS THEN
       DBMS_OUTPUT.PUT_LINE('Error: Multiple records found for rno = 100');
   WHEN OTHERS THEN
       DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/

-- 5) Write a PL/SQL block to calculate fine for rno 100
-- Rno, bookno, doi, dor, fine
-- Fine is Rs 1 if days<7
-- Fine is Rs 2 if days<14 and >7
-- Fine is Rs 3 if days>14
-- Amount mentioned is for each day.
DROP TABLE IF EXISTS library;
CREATE TABLE library (
   rno int primary key,
   bookNo int,
   dateOfReturn date,
   dateOfIssue date,
   fine_amt int default 0
);
INSERT INTO library (rno, bookNo, dateOfReturn, dateOfIssue)
VALUES (
 100,
 1,
 TO_DATE('2026-03-11','YYYY-MM-DD'),
 TO_DATE('2026-02-25','YYYY-MM-DD')
);

-- 4. Write a PL/SQL block to calculate fine for all students
-- Rno, bookno, doi, dor, fine
-- Fine is Rs 1 if days7 Fine is Rs 3 if days>14 Amount mentioned is for
-- each day.
DECLARE
   v_doi    DATE;
   v_dor    DATE;
   v_days   NUMBER;
   v_fine   NUMBER := 0;
BEGIN
   SELECT dateOfIssue, dateOfReturn
     INTO v_doi, v_dor
     FROM library;
   v_days := v_dor - v_doi;
   IF v_days <= 7 THEN
       v_fine := v_days * 1;
   ELSIF v_days <= 14 THEN
       v_fine := v_days * 2;
   ELSE
       v_fine := v_days * 3;
   END IF;
   UPDATE library
      SET fine_amt = v_fine;
   DBMS_OUTPUT.PUT_LINE('Days delayed : ' || v_days);
   DBMS_OUTPUT.PUT_LINE('Total fine   : Rs. ' || v_fine);
  
EXCEPTION
   WHEN NO_DATA_FOUND THEN
       DBMS_OUTPUT.PUT_LINE('No record found for rno = 100');
   WHEN TOO_MANY_ROWS THEN
       DBMS_OUTPUT.PUT_LINE('Error: Multiple records found for rno = 100');
   WHEN OTHERS THEN
       DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/



-- 6) Write a PL/SQL block to generate multiplication table for 3 to n.
DECLARE
    n  NUMBER := &n;
BEGIN
    FOR i IN 3 .. n LOOP
        DBMS_OUTPUT.PUT_LINE('────────────────────────────');
        DBMS_OUTPUT.PUT_LINE('     Table of ' || i);
        DBMS_OUTPUT.PUT_LINE('────────────────────────────');

        FOR j IN 1 .. 10 LOOP
            DBMS_OUTPUT.PUT_LINE('  ' || i || ' x ' || LPAD(j,2) || ' = ' || (i*j));
        END LOOP;
        
        DBMS_OUTPUT.NEW_LINE;
    END LOOP;
END;
/
