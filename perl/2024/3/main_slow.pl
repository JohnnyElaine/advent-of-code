#!/usr/bin/perl
use v5.42.2;

use FindBin;
use lib $FindBin::Bin;

use Path::Tiny qw(path);
use Pattern;

sub compute_mul_instrution {
    my ($s) = @_;
    my ($x, $y) = $s =~ /(\d+),(\d+)/;
    return $x * $y
}

sub part1 {
    my ($str, $pattern) = @_;
    $pattern->reset();
    my $sum = 0;
    my $instruction_start = 0;
    my @chars = split //, $str;
    for my $i (0 .. $#chars) {
        my $c = $chars[$i];

        if($pattern->completed()) {
            my $instruction_str = substr $str, $instruction_start, $i - $instruction_start;
            $sum += compute_mul_instrution($instruction_str);
            $instruction_start = $i;
            $pattern->reset();
        }

        my $match_type = $pattern->handle_char($c);
        $instruction_start = $i + 1 if (!$match_type);
    }

    return $sum;
}

sub part2 {
    my ($str, $mul_pattern, $do_pattern, $dont_pattern) = @_;
    $mul_pattern->reset();
    $do_pattern->reset();
    $dont_pattern->reset();

    # active patterns: 1 = mul,do. 0 = don't
    my $is_mul_pattern_active = 1;
    my $mul_instruction_start = 0;
    my $do_instruction_start = 0;
    my $dont_instruction_start = 0;
    my $sum = 0;
    my $start = 0;
    my @chars = split //, $str;
    for my $i (0 .. $#chars) {
        my $c = $chars[$i];

        if (!$is_mul_pattern_active) {
            if ($do_pattern->completed()) {
                $is_mul_pattern_active = 1;
                $mul_instruction_start = $i;
                $dont_instruction_start = $i;
                $mul_pattern->reset();
                $dont_pattern->reset();
            } else {
                my $do_match_type = $do_pattern->handle_char($c);
                $do_instruction_start = $i + 1 if (!$do_match_type);
            }
        }

        next if (!$is_mul_pattern_active);

        if ($dont_pattern->completed()) {
            $is_mul_pattern_active = 0;
            $dont_instruction_start = $i;
            $do_pattern->reset();
        } else {
            my $dont_match_type = $dont_pattern->handle_char($c);
            $dont_instruction_start = $i + 1 if (!$dont_match_type);
        }

        if($mul_pattern->completed()) {
            my $instruction_str = substr $str, $mul_instruction_start, $i - $mul_instruction_start;
            $sum += compute_mul_instrution($instruction_str);
            $mul_instruction_start = $i;
            $mul_pattern->reset();
        }

        my $mul_match_type = $mul_pattern->handle_char($c);
        $mul_instruction_start = $i + 1 if (!$mul_match_type);
    }

    return $sum;
}

my $filename = shift or die "Usage: $0 FILENAME";

my $input_str = path($filename)->slurp_utf8;

my $mul_pattern = Pattern->new({
    pattern  => [('mul(', '1', '23', ',', '1', '23', ')')],
    type     => [('s', 'd', 'd', 's', 'd', 'd', 's')], # s=text, d=number
    optional => [(0, 0, 1, 0, 0, 1, 0)]
});

my $do_pattern = Pattern->new({
    pattern  => [('do()')],
    type     => [('s')],
    optional => [(0)]
});

my $dont_pattern = Pattern->new({
    pattern  => [('don\'t()')],
    type     => [('s')],
    optional => [(0)]
});

my $part1 = part1($input_str, $mul_pattern);
my $part2 = part2($input_str, $mul_pattern, $do_pattern, $dont_pattern);

say "part1: $part1";
say "part2: $part2";
