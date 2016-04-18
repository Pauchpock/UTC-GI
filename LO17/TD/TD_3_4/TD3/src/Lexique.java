import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Lexique {
	private HashMap<String, String> lexique;
	private HashSet<String> stoplist;
	
	public final static int SEUIL_MIN = 3; // minimum 3 lettres par mot
	public final static int SEUIL_MAX = 7; // differences entre 2 longueurs de mota
	
	public Lexique(ArrayList<String> lex) throws Exception {
		
		this.lexique = new HashMap<String, String>(); // mot, lemme
		this.stoplist = new HashSet<String>();
		
		for (String s : lex) {
			String[] tokens = s.split("\\s+");
			String tm = lexique.put(tokens[0], tokens[1]);
				if (tm != null) {
					throw new Exception("Word already existing: ".concat(tm));
				}
			
		}
	}
	
	/**
	 * Returns the lemme associated to the given word
	 * @param s The word we want the lemme for
	 * @return The lemme or null if we don't have one
	 */
	public String getLemme(String s) {
		return lexique.get(s);
	}
	
	/**
	 * Calcule la distance entre 2 mots (+ c'est grand mieux c'est)
	 * @param mot1
	 * @param mot2
	 * @return Distance
	 */
	public double prox(String mot1,String mot2) {
		int l1 = mot1.length(), l2 = mot2.length();
		
		if (l1 < SEUIL_MIN || l2 < SEUIL_MIN) {
			return 0;
		}
		else if (Math.abs(l1 - l2) > SEUIL_MAX) {
			return 0;
		}
		else {
			int i = 0;
			while ((i < Math.min(l1, l2))&& mot1.charAt(i) == mot2.charAt(i)) {
				i++;
			}
			return (i * 100)/ (Math.max(l1, l2)); 
		}
	}
	
	public HashSet<String> findBestLemmes(String mot) {
		HashSet<String> res = new HashSet<String>(); // liste de lemmes candidats
		double highestscore = 0.0;
		
		for (String s : lexique.keySet()) {
			double tmp = prox(mot, s);
			if (tmp >= highestscore) {
				if (tmp > highestscore) {
					res.clear();
				}
				highestscore = tmp;
				res.add(this.getLemme(s));
			}
 		}
		
		return res;
	}
}
