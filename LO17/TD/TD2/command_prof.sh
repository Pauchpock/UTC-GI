rm -f tf_prof.txt idf_prof.txt ; cat corpusp15_28_03_2015_ssChiffres.xml| ./segmente_TT.pl -f | sort | uniq -c | sed -e 's/^\s*//' > tf_prof.txt ; cat tf_prof.txt | cut -d' ' -f2 | cut -f1 | sort | uniq -c | sed -e 's/^\s*//' > idf_prof.txt ; less tf_prof.txt && less idf_prof.txt