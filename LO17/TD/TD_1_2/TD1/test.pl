$html = "";
while (<>){
    $html .= $_;
    print "lu: ".$_;
    print $ARGV;
}

while($html =~ /\b(salut\d)\b/g) {
    print "yolo";
    print $1."\n";;;
}


while($html =~ /\b(salut\d)\b/g) {
    print "yololol";
    print $1."\n";;;
}
