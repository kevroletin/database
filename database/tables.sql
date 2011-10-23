BEGIN;

CREATE TABLE passports (
  id SERIAL PRIMARY KEY,
/* owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  name TEXT,
  serial_number VARCHAR(10) UNIQUE,
  issue_date DATE,
  birth_date DATE,
  birth_place TEXT,
  is_man BOOLEAN,
  given_by_unit_name TEXT,
  given_by_unit_code TEXT,
  /*is_valid BOOLEAN DEFAULT(TRUE),*/
  photo BYTEA/*,
  whole_photo BYTEA */
/* TODO: Should we store whole passport photo? */
);

CREATE TABLE companies (
  id SERIAL PRIMARY KEY,
  name TEXT,
  adress TEXT
);

CREATE TABLE licenses (
  id SERIAL PRIMARY KEY,
/*  owner_id INTEGER REFERENCES customers(id) NOT NULL, */
  owner_name TEXT,
  serial_number TEXT NOT NULL,
  /*is_valid BOOLEAN NOT NULL DEFAULT(TRUE),*/
  photo BYTEA/*,
  whole_photo BYTEA */
/* TODO: Should we store whole passport photo? */
);

CREATE TABLE customers (
  id SERIAL PRIMARY KEY,
  passport_id INTEGER REFERENCES passports(id),
  license_id INTEGER REFERENCES licenses(id),
  company_id INTEGER REFERENCES companies(id)
);

CREATE TABLE cars (
  id SERIAL PRIMARY KEY,
  owner_id INTEGER REFERENCES customers(id) NOT NULL,
  brand TEXT NOT NULL, 
  serial_number VARCHAR(8) NOT NULL,
  photo BYTEA,
  number_photo BYTEA
/* TODO: can car have many photos? */
);

CREATE TABLE metal_deal (
  id SERIAL PRIMARY KEY,
  time TIMESTAMP,
/*  data DATE DEFAULT(current_date),
  time TIME DEFAULT(current_time), */
  given_money FLOAT
);

CREATE TABLE metal_items (
  id SERIAL PRIMARY KEY,
  weight FLOAT,
  radioactivity FLOAT 
);

CREATE TABLE metal_mark (
  id SERIAL PRIMARY KEY,
  name TEXT,
  is_color BOOLEAN
);

CREATE TABLE metal_cost (
  id SERIAL PRIMARY KEY,
  value NUMERIC(16, 4)
);

COMMIT;
