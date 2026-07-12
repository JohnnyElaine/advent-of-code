package Pattern;

use v5.42.2;

sub is_char_a_digit {
    my ($c) = @_;
    $c = ord($c);
    return $c >= 48 && $c <=57;
}

sub new {
    my ($class, $args) = @_;
    my $self = bless { pattern => $args->{pattern},
                       type => $args->{type},
                       optional => $args->{optional},
                       section_idx => 0,
                       subsection_idx => 0,
                     }, $class;
    return $self;
}

sub char_at {
    my ($self, $section, $subsection) = @_;
    return substr($self->{pattern}[$section], $subsection, 1);
}

sub matches_at {
    my ($self, $c, $section, $subsection) = @_;

    if ($self->{type}[$section] eq 's') { # case: string
        return $self->char_at($section, $subsection) eq $c;
    } elsif ($self->{type}[$section] eq 'd') { # case: digit
        return is_char_a_digit($c);
    }
}

sub matches_this {
    my ($self, $c) = @_;
    return $self->matches_at($c, $self->{section_idx}, $self->{subsection_idx});
}

sub matches_beginning_of_next_section {
    my ($self, $c) = @_;
    return $self->matches_at($c, $self->{section_idx} + 1, 0);
}

sub matches {
    my ($self, $c) = @_;
    return 1 if ($self->matches_this($c));
    return 2 if $self->{optional}[$self->{section_idx}] && ($self->matches_beginning_of_next_section($c));

    return 0;
}

sub completed {
    my $self = shift;
    my $pattern_last_idx = $#{$self->{pattern}};;
    return $self->{section_idx} > $pattern_last_idx;
}

sub get_next_ids {
    my $self = shift;

    if ($self->{subsection_idx} == length($self->{pattern}[$self->{section_idx}]) - 1) {
        # continue to the next section
        return $self->{section_idx} + 1, 0;
    } else {
        # move furhter along the current subsection
        return $self->{section_idx}, $self->{subsection_idx} + 1;
    }
}

sub increment {
    my $self = shift;
    ($self->{section_idx}, $self->{subsection_idx}) = $self->get_next_ids();
}

sub skip_section {
    my $self = shift;
    ++$self->{section_idx};
    $self->{subsection_idx} = 0;
    $self->increment();
}

sub reset {
    my $self = shift;

    ($self->{section_idx}, $self->{subsection_idx}) = (0, 0);
}

sub handle_char {
    my ($self, $c) = @_;

    my $match_type = $self->matches($c);

    # no match
    $self->reset() if ($match_type == 0);

    # matches this current char
    $self->increment() if ($match_type == 1);

    # current section is optional and matches next section
    $self->skip_section() if ($match_type == 2);
    return $match_type;
}

1;
