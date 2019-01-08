#######################
# Create admin table
########################
CREATE TABLE admin
(
  admin_id       char(30)  NOT NULL ,
  admin_password char(30)  NOT NULL ,
  PRIMARY KEY   (admin_id)
) ENGINE=InnoDB;
