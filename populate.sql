##########################
# Populate admin table
##########################
--  INSERT INTO admin(admin_id, admin_password) VALUES('100', 'qq');

##########################
# Populate student table
##########################
INSERT INTO student(student_id, student_password, student_name, student_age, student_classnum)
VALUES("100", "1", "caofeng", "22", "1");
INSERT INTO student(student_id, student_password, student_name, student_age, student_classnum)
VALUES("101", "1", "cf", "22", "2");

##########################
# Populate course table
##########################
INSERT INTO course(course_num, course_teacher, course_hour, course_capacity, course_classroom)
VALUES("1", "Wang", "36", "30", "16-303");
INSERT INTO course(course_num, course_teacher, course_hour, course_capacity, course_classroom)
VALUES("2", "Li", "36", "30", "3-201");

##########################
# Populate subject table
##########################
