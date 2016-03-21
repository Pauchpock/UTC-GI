# Create tf.txt
rm -f tf.txt idf.txt; cat ../TD1/output.xml| ./segmente_TT.pl -f | sort | uniq -c | sed -e 's/^\s*//' > tf.txt.tmp ;

# Remove numbers
./removeNumbers.pl tf.txt.tmp > tf.txt && rm -f tf.txt.tmp

# Create df.txt
cat tf.txt | cut -d' ' -f2 | cut -f1 | sort | uniq -c | sed -e 's/^\s*//' > df.txt

# Create idf.txt
rm -f idf.txt; ./idf.pl df.txt > idf.txt

# Create tfidf.txt
rm -f tfidf.txt; ./tfidf.pl idf.txt tf.txt | sort -k 3,3 > tfidf.txt

# Show
less tfidf.txt
