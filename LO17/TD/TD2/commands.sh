# Create tf.txt and remove leading spaces and remove lines containing at least one number
rm -f tf.txt idf.txt; cat ../TD1/output.xml| ./segmente_TT.pl -f | sort | uniq -c | sed 's/^\s*//' | sed -r '/.*?\s.*?[0-9].*?\s.*/d' > tf.txt

# Create df.txt
cat tf.txt | cut -d' ' -f2 | cut -f1 | sort | uniq -c | sed -e 's/^\s*//' > df.txt

# Create idf.txt
rm -f idf.txt; ./idf.pl df.txt > idf.txt

# Create tfidf.txt
rm -f tfidf.txt; ./tfidf.pl idf.txt tf.txt | sort -k 3,3 > tfidf.txt

# Show
#less tfidf.txt

# Create stop list
rm -f stoplist.txt; ./extractWordsBelowSpecificTFIDF.pl tfidf.txt > stoplist.txt

# Create script to remove words
rm -f removeWordsFromXML.pl; ./newcreeFiltre.pl stoplist.txt > removeWordsFromXML.pl && chmod +x removeWordsFromXML.pl

# Create new XML without the words from the stop list
rm -f newOutput.xml; ./removeWordsFromXML.pl ./../TD1/output.xml > newOutput.xml

# Create the successors and remove lines containing at least one number
rm -f successeurs.txt; cat newOutput.xml| ./segmente_TT.pl | sort -u | sed '/[0-9]/d' | ./successeurs_P16.pl > successeurs.txt

# Create the lemmes
rm -f successeurs.filtered.txt; ./filtronc_P16.pl -v successeurs.txt successeurs.filtered.txt

# Create the script to replace the words with their lemmes in the XML
rm -f replaceLemmesInXML.pl; ./newcreeFiltre.pl successeurs.filtered.txt > replaceLemmesInXML.pl && chmod +x replaceLemmesInXML.pl

# Run the script
rm -f lemmes.xml; ./replaceLemmesInXML.pl ./newOutput.xml > lemmes.xml
