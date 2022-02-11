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