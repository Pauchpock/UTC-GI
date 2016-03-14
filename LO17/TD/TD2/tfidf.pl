#!/usr/bin/perl
#

use utf8;

#binmode(STDIN, ":utf8");
#binmode(STDOUT, ":utf8");

# Usage: perl % idf.txt tf.txt

sub log10 {
    my $n = shift;
    return log($n)/log(10);
}

@mots;
while (<>) {
    if ($ARGV eq 'idf.txt') {
        /(\d+) (.*)/;
        $mots{$2} = log10(326/$1);
    }
    elsif ($ARGV eq 'tf.txt') {
        /(\d+)\s+(.*?)\s+(.*)/;
        $nb = $1;
        $mot = $2;
        $file = $3;
        $tfidf = $nb * ($mots{$mot});
        print $file."\t".$mot."\t".$tfidf."\n";
    }
}
