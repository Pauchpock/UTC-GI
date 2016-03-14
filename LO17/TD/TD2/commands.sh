rm -f tf.txt; cat ../TD1/output.xml| ./segmente_TT.pl -f | sort | uniq -c > tf.txt ; less tf.txt
