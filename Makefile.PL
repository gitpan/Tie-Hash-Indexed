################################################################################
#
# $Project: /Tie-Hash-Indexed $
# $Author: mhx $
# $Date: 2006/01/21 12:06:59 +0100 $
# $Revision: 6 $
# $Source: /Makefile.PL $
#
################################################################################
# 
# Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
# 
################################################################################

use ExtUtils::MakeMaker;
use Config;

$MODULE = 'Tie::Hash::Indexed';

%FEATURES = (
  debug => {
             enabled => $Config{ccflags} =~ /-DDEBUGGING\b/ ? 1 : 0,
             e_flags => [qw( THI_DEBUGGING )],
             d_flags => [qw( NDEBUG )],
           },
);

@ARGV = map {
  my $myopt = 0;
  if( my($what, $feat) = /^(en|dis)able-(\S+)$/ ) {
    exists $FEATURES{$feat} or $feat = '$'.$feat;
    exists $FEATURES{$feat}
      or die "Invalid feature '$2'. Use one of [ @{[keys %FEATURES]} ].\n";
    $FEATURES{$feat}{enabled} = $what eq 'en';
    $myopt = 1;
  }
  elsif( /^help$/ ) {
    die <<ENDUSAGE;

USAGE: $^X Makefile.PL enable-feature disable-feature

  Available Features: @{[sort grep !/^\$/, keys %FEATURES]}

ENDUSAGE
  }
  $myopt ? () : $_
} @ARGV;

if (eval $ExtUtils::MakeMaker::VERSION >= 6) {
  push @moreopts, AUTHOR => 'Marcus Holland-Moritz <mhx@cpan.org>',
                  ABSTRACT_FROM => 'lib/Tie/Hash/Indexed.pm';
}

if (eval $ExtUtils::MakeMaker::VERSION >= 6.30_01) {
  print "Setting license tag...\n";
  push @moreopts, LICENSE => 'perl';
}

WriteMakefile(
  NAME           => $MODULE,
  VERSION_FROM   => 'lib/Tie/Hash/Indexed.pm',
  PREREQ_PM      => { 'Test' => 0 },
  INC            => '-I.',
  CONFIGURE      => \&configure,
  @moreopts,
);

sub configure {
  for( keys %FEATURES ) {
    my $f = $FEATURES{$_};
    $f->{enabled} and print "Building with feature '$_'\n";
    push @DEFINE, @{$f->{enabled} ? $f->{e_flags} : $f->{d_flags} };
  }
  
  { 'DEFINE' => join(' ', map("-D$_", @DEFINE)) };
}

