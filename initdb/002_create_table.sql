CREATE TABLE student (
  student_id serial NOT NULL PRIMARY KEY,
  name text NOT NULL,
  age int NOT NULL,
  updated_at timestamptz DEFAULT CURRENT_TIMESTAMP,
  created_at timestamptz DEFAULT CURRENT_TIMESTAMP
);
