################################################################################
#
# $Project: /Tie-Hash-Indexed $
# $Author: mhx $
# $Date: 2006/01/21 10:28:25 +0100 $
# $Revision: 5 $
# $Snapshot: /Tie-Hash-Indexed/0.04 $
# $Source: /t/101_basic.t $
#
################################################################################
# 
# Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
# 
################################################################################

use Test;

BEGIN { plan tests => 29 };

use Tie::Hash::Indexed;
ok(1);

$scalar = $] < 5.008003 || $] == 5.009
        ? 'skip: no scalar context for tied hashes' : '';

tie %h, 'Tie::Hash::Indexed';
ok(1);

sub scalar_h { $scalar ? 0 : scalar %h }

$s = &scalar_h;
skip($scalar, $s, 0);

%h = (foo => 1, bar => 2, zoo => 3, baz => 4);
ok(join(',', keys %h), 'foo,bar,zoo,baz');
ok(exists $h{foo});
ok(exists $h{bar});
ok(!exists $h{xxx});
$s = &scalar_h;
skip($scalar, $s =~ /^(\d+)\/\d+$/ && $1 == scalar keys %h);

$h{xxx} = 5;
ok(join(',', keys %h), 'foo,bar,zoo,baz,xxx');
ok(exists $h{xxx});
$s = &scalar_h;
skip($scalar, $s =~ /^(\d+)\/\d+$/ && $1 == scalar keys %h);

$h{foo} = 6;
ok(join(',', keys %h), 'foo,bar,zoo,baz,xxx');
ok(exists $h{foo});
$s = &scalar_h;
skip($scalar, $s =~ /^(\d+)\/\d+$/ && $1 == scalar keys %h);

while (my($k,$v) = each %h) {
  $key .= $k;
  $val += $v;
}
ok($key, 'foobarzoobazxxx');
ok($val, 20);

$val = delete $h{bar};
ok($val, 2);
ok(join(',', keys %h), 'foo,zoo,baz,xxx');
ok(join(',', values %h), '6,3,4,5');
ok(scalar keys %h, 4);
ok(!exists $h{bar});

$val = delete $h{bar};
ok(not defined $val);

$val = delete $h{nokey};
ok(not defined $val);

%h = ();
ok(scalar keys %h, 0);
ok(!exists $h{zoo});
$s = &scalar_h;
skip($scalar, $s, 0);

%h = (foo => 1, bar => 2, zoo => 3, baz => 4);
ok(join(',', %h), "foo,1,bar,2,zoo,3,baz,4");
ok(scalar keys %h, 4);

for ($h{foo}) { $_ = 42 }
ok($h{foo}, 42);

untie %h;

# TODO: these tests fail with recent versions of blead
# ok(scalar keys %h, 0);
# ok(join(',', %h), '');

