use warnings;
use strict;

use DBI;
use Data::Dumper::Concise;
use List::Util q(shuffle);
use Const;
use Rnd;
#use utf8;
#binmode(STDOUT, 'utf8');

my $count = shift;
my $db_name = shift;
my $username = shift;
my $host = shift;
my $password = shift;

$username = "postgres" unless $username;
$password = "" unless $password;
$db_name = "postgres" unless $db_name;
$count = 100 unless $count;

my $dbh = DBI->connect("dbi:Pg:dbname=$db_name;host=$host",
                       $username, $password)
              or die $DBI::errstr;

sub gen_many_passports {
    my ($count) = @_;
    my $q = <<SQL
INSERT INTO passports (name, serial_number, issue_date,
  birth_date, birth_place, is_man,
  given_by_unit_name, given_by_unit_code )
VALUES (?, ?, ?, ?, ?, ?, ?, ?)
SQL
;
    my $sth = $dbh->prepare($q);
    for (0 .. $count) {
        $sth->execute(Rnd::name(),
                      Rnd::passport_number(),
                      Rnd::date(),
                      Rnd::date(),
                      Rnd::adress(),
                      'true',
                      Rnd::unit(),
                      Rnd::unit_code());
    }
}

sub gen_one_passport {
    my $q = <<SQL
INSERT INTO passports (name, serial_number, issue_date,
  birth_date, birth_place, is_man,
  given_by_unit_name, given_by_unit_code )
VALUES (?, ?, ?, ?, ?, ?, ?, ?) RETURNING id, name
SQL
;
    my $sth = $dbh->prepare($q);
    $sth->execute(Rnd::name(),
                  Rnd::passport_number(),
                  Rnd::date(),
                  Rnd::date(),
                  Rnd::adress(),
                  'true',
                  Rnd::unit(),
                  Rnd::unit_code());
    $sth->fetchrow_array();
}

sub gen_manu_companies {
    my ($count) = @_;
    my $sth = $dbh->prepare('INSERT INTO companies(name, adress)' .
                            'VALUES (?, ?)');
    my $comp_cnt = @Constants::companies;
    $count = $comp_cnt unless defined $count;
    for my $i (0 .. $count) {
        $sth->execute($Constants::companies[$i % $comp_cnt],
                      Rnd::adress());
    }
}

{
    my $last_company = 0;
sub gen_one_company {
    my $sth = $dbh->prepare('INSERT INTO companies (name, adress)' .
                            'VALUES (?, ?) RETURNING id');
    $sth->execute($last_company,
                  Rnd::adress());
    $last_company = ($last_company + 1) % @Const::companies;
    $sth->fetchrow_array();
}
}

sub gen_one_car {
    my ($cus_id) = @_;
    my $q = 'INSERT INTO cars (owner_id, brand, serial_number) ' .
            'VALUES (?, ?, ?)';
    my $sth = $dbh->prepare($q);
    $sth->execute($cus_id, Rnd::car_brand(), Rnd::car_serial_number());
}

sub gen_customers {
    my ($count) = @_;

    my $q = 'INSERT INTO licenses (owner_name, serial_number)' .
            'VALUES (?, ?) RETURNING id';
    my $ins_lic = $dbh->prepare($q);
    $q = 'INSERT INTO customers (passport_id, ' .
         '  license_id, company_id)' .
         'VALUES(?, ?, ?) RETURNING id';
    my $ins_cus = $dbh->prepare($q);

    for (1 .. $count) {
        my ($passp_id, $passp_name) = gen_one_passport();
        my ($company_id) = gen_one_company();
        my ($lic_id) = $ins_lic->execute($passp_name,
                                         Rnd::license_number());
        $ins_cus->execute($passp_id, $lic_id, $company_id);
        my $cus_id = $ins_cus->fetchrow_array();
        gen_one_car($cus_id);
    }
}

gen_customers($count);
