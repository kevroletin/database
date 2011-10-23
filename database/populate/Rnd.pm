package Rnd;
use warnings;
use strict;

use Const;
use POSIX q(ceil);

#use utf8;

sub passport_number {
    join '', map { int rand(10) } 1 .. 10;
}

sub license_number {
    # TODO:
    join '', map { int rand(10) } 1 .. 10;
}

sub car_brand {
    # TODO:
    "Жигуль"
}

sub car_serial_number {
    # TODO:
    join '', map { int rand(10) } 1 .. 8;
}

sub name {
   join ' ', map { $_->[int rand(int @$_)] }
       \@Const::families,
       \@Const::names,
       \@Const::second_name
}

sub date {
    '10-10-2010'
}

sub adress {
    'Мыс чуркина Ул Фадеева дю 76, кв. 20'
}

sub unit {
    'Увд Первореченского района'
}

sub unit_code {
    '777'
}


1;
