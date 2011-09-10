BEGIN;

INSERT INTO passports(
  first_name, 
  second_name, 
  middle_name, 
  serial_number, 
  issue_date, 
  birth_date, 
  birth_place, 
  is_man, 
  given_by_unit_name, 
  given_by_unit_code, 
  is_valid, 
  photo
) VALUES (
  'Иван',
  'Сидоров',
  'Иванов',
  '1122345433',
  '01-01-1980',
  '01-01-1960',
  'Иваново',
  TRUE,
  'УВД Иваново',
  '077',
  TRUE,
  E'\\x
5089 474e 0a0d 0a1a 0000 0d00 4849 5244
0000 0700 0000 0800 0608 0000 3500 e504
0006 0000 7419 5845 5374 666f 7774 7261
0065 6441 626f 2065 6d49 6761 5265 6165
7964 c971 3c65 0000 8800 4449 5441 da78
fc62 ffff 033f b808 932e 5105 810f 0f58
3f88 8eee cc7a c4c0 0780 97e0 3eac f710
9b1f 4804 e99c f7cd 0c97 6b21 fe0d dbd7
02ce aa2b 9cb0 c1f8 ca4c 3ff1 9c48 ef71
f5fd fbff 964e b032 b332 c031 271c 23ce
10cb 99ae c0c9 a4e4 c010 aee8 ce1c eff0
3fff af86 3fbf fc33 f867 9607 8900 5583
f083 3bb6 ffcb 2cbb f995 a50f 62c1 0100
0006 85d1 be41 df54 ff28 0000 0000 4549
444e 42ae 8260'
);


INSERT INTO passports(
  first_name, 
  second_name, 
  middle_name, 
  serial_number, 
  issue_date, 
  birth_date, 
  birth_place, 
  is_man, 
  given_by_unit_name, 
  given_by_unit_code, 
  is_valid, 
  photo
) VALUES(
  'Анжелина',
  'Миклушевич',
  'Ивановна',
  '0505333432',
  '11-11-2011',
  '11-01-1990',
  'Иваново',
  FALSE,
  'Село Иваново',
  '0778',
  TRUE,
  E'\\x
5089 474e 0a0d 0a1a 0000 0d00 4849 5244
0000 0500 0000 0700 0208 0000 4f00 10c5
00b9 0000 4943 4144 0854 63d7 daa8 9b1f
cdb6 ef6d f5fd c1ff 0180 9188 4085 c3fc
b68f ac05 f2d6 a55b edb1 72ce 8806 79b2
3a17 965d 00ca 3611 e0f9 fa35 2bde 2654
ae9d e906 3347 001f e73d 7649 f71f fc2d
0000 0000 4549 444e 42ae 8260'
);


/*

INSERT INTO passports(first_name, second_name, middle_name, serial_number, issue_date, birth_place, is_man, given_by_unit_name, given_by_unit_code, is_valid, photo) VALUES(
  '',
  '',
  '',
  '',
  '',
  '',
  '',
  '',
  '',
  '',
  E'\\x'
);
*/

END;
