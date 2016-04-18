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
	private double prox(String mot1,String mot2) {
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
			double ret = (double)((i * 100)/ (Math.max(l1, l2)));
			if (ret > 65.0)
				return ret;
			else return 0.0;
		}
	}
	
	public HashSet<String> findBestLemmes(String mot) {
		HashSet<String> res = new HashSet<String>(); // liste de lemmes candidats
		double highestscore = 0.0;
		
		for (String s : lexique.keySet()) {
			double tmp = prox(mot, s);
			if (tmp >= highestscore && tmp != 0.0) {
				if (tmp > highestscore) {
					res.clear();
				}
				highestscore = tmp;
				res.add(this.getLemme(s));
			}
 		}
		
		return res;
	}
	
	private int cout(Character a, Character b) {
		if (a == null || b == null) {
			return 1;
		}
		if (a.equals(b)) return 0;
		return 1;
	}
	 
	private int levenshteinDistance(String motA, String motB) {
		int i, j,
			dist[][] = new int[motA.length() + 1][motB.length() + 1];
		
		// Initialisation
		dist[0][0] = 0;
		for (i = 0; i < motA.length(); i++) {
			dist[i][0] = i;
		}
		for (i = 0; i < motB.length(); i++) {
			dist[0][i] = i;
		}
		
		for (i = 1; i <= motA.length(); i++) {
			for (j = 1; j <= motB.length(); j++) {
				int d1 = dist[i - 1][j - 1] + cout(motA.charAt(i-1), motB.charAt(j-1));
				int d2 = dist[i - 1][j] + cout(motA.charAt(i-1), null);
				int d3 = dist[i][j - 1] + cout(null, motB.charAt(j-1));
				dist[i][j] = Math.min(d3, Math.min(d1, d2));
			}
		}
		return dist[motA.length()][motB.length()];
	}
	
	public HashSet<String> findLemmesLevenshtein(String mot) {
		HashSet<String> res = new HashSet<String>(); // liste de lemmes candidats
		
		int lowestscore = 1000;
		
		for (String s : lexique.keySet()) {
			int tmp = this.levenshteinDistance(mot, s);
			if (tmp <= lowestscore) {
				if (tmp < lowestscore) {
					res.clear();
				}
				lowestscore = tmp;
				res.add(this.getLemme(s).concat(" (cout: "+String.valueOf(tmp))+")");
			}
 		}
		
		return res;
	}
}
