import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Lexique {
	private HashMap<String, String> lexique;
	private HashSet<String> stoplist;
	
	public final static int SEUIL_MIN = 4;
	public final static int SEUIL_MAX = 7;
	
	public Lexique(ArrayList<String> lex) throws Exception {
		
		this.lexique = new HashMap<String, String>();
		this.stoplist = new HashSet<String>();
		
		for (String s : lex) {
			String[] tokens = s.split("\\s+");
			String tm = lexique.put(tokens[0], tokens[1]);
				if (tm != null) {
					throw new Exception("Word already existing: ".concat(tm));
				}
			
		}
	}
	
	public static String toLowerCase(String s) {
		return s.toLowerCase();
	}
	
	public String getLemme(String s) {
		return lexique.get(s);
	}
	
	/**
	 * Calcule la distance entre 2 mots (+ c'est petit mieux c'est)
	 * @param mot1
	 * @param mot2
	 * @return Distance
	 */
	public int prox(String mot1,String mot2) {
		int l1 = mot1.length(), l2 = mot2.length();
		
		if (l1 < SEUIL_MIN || l2 < SEUIL_MIN) {
			return 0;
		}
		else if (Math.abs(l1 - l2) > SEUIL_MAX) {
			return 0;
		}
		else {
			int i = 1;
			while ((i < Math.min(l1, l2))&& mot1.charAt(i) == mot2.charAt(i)) {
				i++;
			}
			return (int) ((((double)i) / (Math.max(l1, l2))) * 100); 
		}
	}
	
	public ArrayList<String> findBestLemmes(String mot) {
		ArrayList<String> res = new ArrayList<String>();
		int highestscore = 1000;
		
		for (String s : lexique.keySet()) {
			int tmp = prox(mot, s);
			if (tmp <= highestscore) {
				highestscore = tmp;
				if (tmp < highestscore) {
					res.clear();
				}
				res.add(this.getLemme(s));
			}
 		}
		
		return res;
	}
}
