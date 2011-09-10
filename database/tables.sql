
BEGIN;

CREATE TABLE passports (
  id SERIAL PRIMARY KEY,
/*  owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  first_name TEXT,
  second_name TEXT,
  middle_name TEXT,
  serial_number VARCHAR(10),
  issue_date DATE,
  birth_date DATE,
  birth_place TEXT,
  is_man BOOLEAN,
  given_by_unit_name TEXT,
  given_by_unit_code TEXT,
  is_valid BOOLEAN,
  photo BYTEA
);
/*
CREATE TABLE passports (
  id SERIAL PRIMARY KEY,
/*  owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  first_name TEXT NOT NULL,
  second_name TEXT NOT NULL,
  middle_name TEXT NOT NULL,
  serial_number VARCHAR(10) NOT NULL,
  issue_date DATE NOT NULL,
  birth_date DATE NOT NULL,
  birth_place TEXT NOT NULL,
  is_man BOOLEAN NOT NULL,
  given_by_unit_name TEXT NOT NULL,
  given_by_unit_code TEXT NOT NULL,
  is_valid BOOLEAN NOT NULL DEFAULT(false),
  photo BYTEA
);
*/

CREATE TABLE licenses (
  id SERIAL PRIMARY KEY,
/*   owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  serial_number TEXT NOT NULL,
  is_valid BOOLEAN NOT NULL DEFAULT(false),
  photo BYTEA
);

CREATE TABLE customers (
  id SERIAL PRIMARY KEY,
  passport_id INTEGER REFERENCES passports(id),
  license_id INTEGER /* REFERENCES licenses(id) */
);

CREATE TABLE cars (
  id SERIAL PRIMARY KEY,
/*  owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  brand TEXT NOT NULL, 
  serial_number TEXT NOT NULL,
  photo BYTEA,
  number_photo BYTEA
);

COMMIT;