#!/usr/local/bin/perl
# File: recordSort
# Purpose: Sort an EPICS .db file by record name.
# Usage: recordSort <file>
# https://epics.anl.gov/tech-talk/2009/msg01757.php
#
#
$name = '!';
$block = '';
while( <>) {
  if ( /^record.*"(.*)"/) {
    $name = $1;
    $block = $_;
  }
  else {
    $block .= $_;
    if ( /\}\s*$/) {
      $block{ $name} = $block;
      undef $block;
    }
  }
}

foreach $name ( sort keys %block) { print $block{ $name};}

# EOF
