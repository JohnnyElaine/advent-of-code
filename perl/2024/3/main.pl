#!/usr/bin/perl
use v5.42.2;

use Path::Tiny qw(path);

my $filename = shift or die "Usage: $0 FILENAME\n";
my $input = path($filename)->slurp_utf8;

# Part 1: sum all valid mul instructions (ignore do/don't)
my $part1 = 0;
while ($input =~ /mul\((\d{1,3}),(\d{1,3})\)/g) {
    $part1 += $1 * $2;
}

# Part 2: only enabled mul instructions
my $part2 = 0;
my $enabled = 1;          # mul is enabled at start
while ($input =~ /(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))/g) {
    if ($1 eq "do()") {
        $enabled = 1;
    } elsif ($1 eq "don't()") {
        $enabled = 0;
    } elsif ($enabled) {
        $part2 += $2 * $3;
    }
}

say "part1: $part1";
say "part2: $part2";
