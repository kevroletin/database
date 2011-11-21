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
  name TEXT DEFAULT 'Частное лицо',
  INN TEXT,
  KPP TEXT,
  legal_adress TEXT,
  actual_adress TEXT,
  settlement_account TEXT,
  bank TEXT,
  correspondent_account TEXT,
  phone TEXT,
  BIK TEXT
/*
Название (по-умолчанию Частное Лицо)
ИНН
КПП
Юридический адрес
Фактический адрес
Расчетный счет
Банк
Корреспондентский счет
БИК
Телефон */
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

CREATE TABLE metal_deals (
  id SERIAL PRIMARY KEY,
  customer_id INTEGER REFERENCES customers(id),
  time TIMESTAMP,
/*  data DATE DEFAULT(current_date),
  time TIME DEFAULT(current_time), */
  given_money FLOAT
);

CREATE TABLE metal_costs (
  id SERIAL PRIMARY KEY,
  value NUMERIC(16, 4),
  creation_date DATE DEFAULT(current_date)
);

CREATE TABLE metal_marks (
  id SERIAL PRIMARY KEY,
  name TEXT,
  coast_id INTEGER REFERENCES metal_costs(id),
  is_color BOOLEAN
);

CREATE TABLE metal_items (
  id SERIAL PRIMARY KEY,
  deal_id INTEGER REFERENCES metal_deals(id),
  coast_id INTEGER REFERENCES metal_costs(id),
  mark_id INTEGER REFERENCES metal_marks(id),
  weight FLOAT,
  radioactivity FLOAT 
);

CREATE VIEW customer_passports AS 
  SELECT c.id, p.name FROM customers c 
    JOIN passports p ON c.passport_id = p.id;

COMMIT;
