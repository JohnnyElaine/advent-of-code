#!/usr/bin/perl
use 5.42.2;

use List::Util qw(sum);
use Path::Tiny qw(path);

my $filename = shift or die "Usage: $0 FILENAME";

my @left;
my @right;

my $fh = path($filename)->openr_utf8;
while (my $row = <$fh>) {
    chomp $row;
    my ($left_val, $right_val) = split ' ', $row;   # split on any whitespace
    push @left,  $left_val;
    push @right, $right_val;
}
close $fh;

die "Lists have different lengths" unless @left == @right;

@left = sort { $a <=> $b } @left;
@right = sort { $a <=> $b } @right;

my $sum1 = sum map { abs($left[$_] - $right[$_]) } 0 .. @left;
say "Part 1: $sum1";

# Part 2:
# key=number in right list, value=frequency
my %right_freq;

for my $num (@right) {
    $right_freq{$num}++;
}

my $sum2 = sum map { $_ * ($right_freq{$_} // 0) } @left;
say "Part 2: $sum2";
