DROP TABLE student;
CREATE TABLE student (
    student_id INT AUTO_INCREMENT,
    name_ VARCHAR(20),
    major VARCHAR(20) DEFAULT "UNDECIDED",
    PRIMARY KEY (student_id)
);

SELECT * FROM student;

INSERT INTO student(name_, major) VALUES ('JACK', 'BIOLOGY');
INSERT INTO student(name_, major) VALUES ('KATE', 'SOCIOLOGY');
INSERT INTO student(name_, major) VALUES ('CLAIRE', 'COMPUTER SCIENCE');
INSERT INTO student(name_, major) VALUES ("JACK", 'BIOLOGY');
INSERT INTO student(name_, major) VALUES ("MIKE", 'COMPUTER SCIENCE');

UPDATE student
SET major = 'bio'
WHERE major = 'biology';

UPDATE student 
SET major = "comp sci"
WHERE major = 'COMPUTER SCIENCE';

UPDATE student
set major = "CHEMISTRY"
WHERE student_id= 4;

UPDATE student 
SET name_ = 'TOM' and major = 'undecided'
WHERE student_id = 1;

/*
updates each and every one of the row i wont do it,
it will cause problems for me now if i do it.
UPDATE student
SET major = 'undecided';
*/

DELETE FROM student
WHERE student_id = 5;

DELETE FROM student
WHERE name_ = 'JACK' AND major = 'Biochemistry';

/* this is illustration of how we can
   select any specific column and do stuff
   with it
   and also you can order them there is the command for it
   just like that doing order by will give you
   the alphabetical order and you can pretty much reverse it
   by adding 'DESC'
*/ 
SELECT name_, major
FROM student
ORDER BY name_ DESC; 

SELECT *
FROM student
ORDER BY major, student_id;

SELECT *
FROM student
LIMIT 2;

-- more on the basic query

SELECT name_, major
FROM student
WHERE student_id <= 3;

SELECT name_, major
FROM student
WHERE name_ IN ('CLAIRE', 'KATE');

-- and basically you can use all kinds of the
-- logic stuff and do stuff ez

-- so now the above thingy is dropped, aint gonna remove the code
-- moving towards the complex thingies

CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    first_name VARCHAR(40), 
    last_name VARCHAR(40),
    birth_day DATE,
    sex VARCHAR(1),
    salary INT,
    super_id INT,
    branch_id INT
);

CREATE TABLE branch (
    branch_id INT PRIMARY KEY,
    branch_name VARCHAR(40), 
    mgr_id INT,
    mgr_start_date DATE,
    FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL
);

ALTER TABLE employee
ADD FOREIGN KEY (branch_id)
REFERENCES branch(branch_id)
ON DELETE SET NULL;

ALTER TABLE employee
ADD FOREIGN KEY (super_id)
REFERENCES employee(emp_id)
ON DELETE SET NULL;

CREATE TABLE client (
    client_id INT PRIMARY KEY,
    client_name VARCHAR(40),
    branch_id INT,
    FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE SET NULL
);

CREATE TABLE works_with (
    emp_id INT, 
    client_id INT,
    total_sales INT,
    PRIMARY KEY (emp_id, client_id),
    FOREIGN KEY (emp_id) REFERENCES employee(emp_id) ON DELETE CASCADE,
    FOREIGN KEY (client_id) REFERENCES client(client_id) ON DELETE CASCADE
);

CREATE TABLE branch_supplier (
    branch_id INT,
    supplier_name VARCHAR(40),
    supply_type VARCHAR(40),
    PRIMARY KEY(branch_id, supplier_name),
    FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE CASCADE
); 

-- -----------------------------------------------------------------------------

-- Corporate
INSERT INTO employee VALUES(100, 'David', 'Wallace', '1967-11-17', 'M', 250000, NULL, NULL);

INSERT INTO branch VALUES(1, 'Corporate', 100, '2006-02-09');

UPDATE employee
SET branch_id = 1
WHERE emp_id = 100;

INSERT INTO employee VALUES(101, 'Jan', 'Levinson', '1961-05-11', 'F', 110000, 100, 1);

-- Scranton
INSERT INTO employee VALUES(102, 'Michael', 'Scott', '1964-03-15', 'M', 75000, 100, NULL);

INSERT INTO branch VALUES(2, 'Scranton', 102, '1992-04-06');

UPDATE employee
SET branch_id = 2
WHERE emp_id = 102;

INSERT INTO employee VALUES(103, 'Angela', 'Martin', '1971-06-25', 'F', 63000, 102, 2);
INSERT INTO employee VALUES(104, 'Kelly', 'Kapoor', '1980-02-05', 'F', 55000, 102, 2);
INSERT INTO employee VALUES(105, 'Stanley', 'Hudson', '1958-02-19', 'M', 69000, 102, 2);

-- Stamford
INSERT INTO employee VALUES(106, 'Josh', 'Porter', '1969-09-05', 'M', 78000, 100, NULL);

INSERT INTO branch VALUES(3, 'Stamford', 106, '1998-02-13');

UPDATE employee
SET branch_id = 3
WHERE emp_id = 106;

INSERT INTO employee VALUES(107, 'Andy', 'Bernard', '1973-07-22', 'M', 65000, 106, 3);
INSERT INTO employee VALUES(108, 'Jim', 'Halpert', '1978-10-01', 'M', 71000, 106, 3);


-- BRANCH SUPPLIER
INSERT INTO branch_supplier VALUES(2, 'Hammer Mill', 'Paper');
INSERT INTO branch_supplier VALUES(2, 'Uni-ball', 'Writing Utensils');
INSERT INTO branch_supplier VALUES(3, 'Patriot Paper', 'Paper');
INSERT INTO branch_supplier VALUES(2, 'J.T. Forms & Labels', 'Custom Forms');
INSERT INTO branch_supplier VALUES(3, 'Uni-ball', 'Writing Utensils');
INSERT INTO branch_supplier VALUES(3, 'Hammer Mill', 'Paper');
INSERT INTO branch_supplier VALUES(3, 'Stamford Lables', 'Custom Forms');

-- CLIENT
INSERT INTO client VALUES(400, 'Dunmore Highschool', 2);
INSERT INTO client VALUES(401, 'Lackawana Country', 2);
INSERT INTO client VALUES(402, 'FedEx', 3);
INSERT INTO client VALUES(403, 'John Daly Law, LLC', 3);
INSERT INTO client VALUES(404, 'Scranton Whitepages', 2);
INSERT INTO client VALUES(405, 'Times Newspaper', 3);
INSERT INTO client VALUES(406, 'FedEx', 2);

-- WORKS_WITH
INSERT INTO works_with VALUES(105, 400, 55000);
INSERT INTO works_with VALUES(102, 401, 267000);
INSERT INTO works_with VALUES(108, 402, 22500);
INSERT INTO works_with VALUES(107, 403, 5000);
INSERT INTO works_with VALUES(108, 403, 12000);
INSERT INTO works_with VALUES(105, 404, 33000);
INSERT INTO works_with VALUES(107, 405, 26000);
INSERT INTO works_with VALUES(102, 406, 15000);
INSERT INTO works_with VALUES(105, 406, 130000);

SELECT * FROM employee;
SELECT * FROM works_with;

-- find all employees
SELECT *
FROM employee;

-- find all clients
SELECT *
FROM client;

-- find all employee ordered by salary
SELECT *
FROM employee
ORDER BY salary DESC;

-- find all employee ordered by sex and then name
SELECT *
FROM employee
ORDER BY sex, first_name, last_name;

-- find the first 5 employee in the table
SELECT *
FROM employee
LIMIT 5;

-- find the first name and the last name
SELECT first_name, last_name
FROM employee;

-- find the forename and surnames of all employee
SELECT first_name AS forename, last_name AS surname
FROM employee;

-- find out all the different genders(distinctly returns the stuff)
SELECT DISTINCT sex
FROM employee;

-- finding out the distinct branc_ids in the employee table
SELECT DISTINCT branch_id
FROM employee; 

-- FUNCTIONS
-- find the number of employees

SELECT COUNT(emp_id)
FROM employee;

-- find the number of the supervisors
SELECT COUNT(super_id)
FROM employee;

-- find the number of female employees born after 1970
SELECT COUNT(emp_id)
FROM employee
WHERE sex = 'F' AND birth_day > '1970 - 01 - 01';

-- find the average of all employees' salaries
SELECT AVG(salary)
FROM employee
WHERE sex = 'M';

-- find the sum of all employees' salaries
SELECT SUM(salary)
FROM employee;

-- find out how many males and females there are
SELECT COUNT(sex), sex
FROM employee
GROUP BY sex;

-- find the total sales of each salesman
SELECT SUM(total_sales), emp_id
FROM works_with
GROUP BY emp_id;

-- find the total sales of each client
SELECT SUM(total_sales), client_id
FROM works_with
GROUP BY client_id;


-- WILDCARDS
-- % = any characters, _ = one character   

-- find any clients who are an LLC

SELECT *
FROM client
WHERE client_name LIKE '%LLC';

-- find any branch suppliers who are in the label business
SELECT *
FROM branch_supplier
WHERE supplier_name LIKE '% Label%';

-- find any employee born in october
SELECT *
FROM employee
WHERE birth_day LIKE '____-10%'

-- find any clients who are schools
SELECT *
FROM CLIENT
WHERE client_name LIKE '%school%';

-- UNIONS
