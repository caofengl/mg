#######################
# Create admin table
########################
CREATE TABLE admin
(
  admin_id       char(30)  NOT NULL ,
  admin_password char(30)  NOT NULL ,
  PRIMARY KEY   (admin_id)
) ENGINE=InnoDB;


#######################
# Create student table
########################
CREATE TABLE student
(
  student_id       char(30)  NOT NULL ,
  student_password char(30)  NOT NULL ,
  student_name     char(30)  NOT NULL ,
  student_age      char(3)   NOT NULL ,
  student_classnum char(30)  NOT NULL ,
  PRIMARY KEY     (student_id)
) ENGINE=InnoDB;


#######################
# Create course table
########################
CREATE TABLE course
(
  course_num       char(30)  NOT NULL ,
  course_teacher   char(30)  NOT NULL ,
  course_hour      char(30)  NOT NULL ,
  course_capacity  char(30)  NOT NULL ,
  course_classroom char(30)  NOT NULL ,
  PRIMARY KEY     (course_num)
) ENGINE=InnoDB;


#######################
# Create subject table
########################
CREATE TABLE subject
(
  student_id   char(30)  NOT NULL ,
  course_num   char(30)  NOT NULL ,
  course_grade char(30)  NOT NULL ,
  PRIMARY KEY (student_id, course_num)
) ENGINE=InnoDB;
