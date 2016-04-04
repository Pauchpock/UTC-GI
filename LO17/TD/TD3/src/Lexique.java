import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Lexique {
	private HashMap<String, String> lexique;
	private HashSet<String> stoplist;
	
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
	
	
}
