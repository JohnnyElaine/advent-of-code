#!/usr/bin/perl
use 5.42.2;

use Path::Tiny qw(path);

#sub same_sign {
#    my ($a, $b) = @_;
#    return ($a * $b) >= 0;  # Product is positive if same sign
#}

sub same_sign { ($_[0] <=> 0) == ($_[1] <=> 0) }

=item get_invalid_level_index($report)
Checks if a report (array of integers) follows safety rules.
If the report is unsafe it returns the index of the bad level.
The returned index and the adjacent indicies can be the cause of the invalid report.
In other words: the bad level can be at (i-1, i, i+1)
If the report is valid -1 is returned.
Parameters:
  $report - Array reference of integers. Report conisting of multiple levels
Returns: the index of the level that causes the report to be invalid. -1 otherwise.

=cut
sub get_invalid_level_index {
    my ($report) = @_; # report => refernce to array of integers

    my $prev_diff = 0;
    for my $i (0 .. $#$report - 1) {
        my $diff = $report->[$i + 1] - $report->[$i];

        return $i if (abs($diff) > 3 or $diff == 0);

        # check if serires is increasing/decreasing (skip sign check for the very first pair)
        return $i if $prev_diff && !same_sign($diff, $prev_diff);

        $prev_diff = $diff;
    }
    return -1;
}

sub is_report_valid_removed_index {
    my ($report, $removed_idx) = @_; # report => refernce to array of integers

    my $prev_diff = 0;
    for my $i (0 .. $#$report - 1) {
        my $left = $i;
        my $right = $i + 1;
        # "remove" level by ignoring it. avoids unnecessary array manipulation
        next if $left == $removed_idx;
        # if last element in the array is "removed"
        next if $right == $#$report and $right == $removed_idx;

        $right = $right == $removed_idx ? $right + 1 : $right;

        my $diff = $report->[$right] - $report->[$left];
        return 0 if (abs($diff) > 3 or $diff == 0);

        # check if serires is increasing/decreasing
        return 0 if $prev_diff && !same_sign($diff, $prev_diff);

        $prev_diff = $diff;
    }
    return 1;
}

sub is_report_valid_with_problem_dampener {
my ($report, $bad_lvl_idx) = @_; # report => refernce to array of integers
    # only consider bad level index and adjacent indicies, i.e., (i-1, i, i+1) as removal candidates
    # Explanation:
    # 1. find a violation
    # 2. try removing tuple (i-1, i, i+1) that causes the violation
    # Why this works:
    # Reason: removing any element that is not one of (i-1, i, i+1) cannot fix the violation.
    # Explanation
    # We can at most remove 1 level in order to remove a violation.
    # A violation can be resolved by removing 1 level. So from the index where the bad level was detected, we check:
    # - the index of the bad level (i)
    # - right of the bad level (i + 1)
    # - left of the bad level (i - 1)
    # If we encounter a violatin and fix it, but the report is still invalid --> there must be at least 2 violations, meaning it is impossible to fix
    return 1 if (is_report_valid_removed_index($report, $bad_lvl_idx));
    return 1 if (is_report_valid_removed_index($report, $bad_lvl_idx+1));
    return 1 if $bad_lvl_idx > 0 && (is_report_valid_removed_index($report, $bad_lvl_idx-1));

    return 0;
}

my $filename = shift or die "Usage: $0 FILENAME";

my $sum1 = 0;
my $sum2 = 0;
my $fh = path($filename)->openr_utf8;
while (my $row = <$fh>) {
    chomp $row;
    my @report = split ' ', $row;   # split on any whitespace
    my $bad_lvl_index = get_invalid_level_index(\@report);

    if ($bad_lvl_index < 0) {
        ++$sum1;
        ++$sum2;
        next;
    }

    ++$sum2 if is_report_valid_with_problem_dampener(\@report, $bad_lvl_index);
}
close $fh;

say "Part 1: $sum1";
say "Part 2: $sum2";
