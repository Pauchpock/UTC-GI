import java.util.ArrayList;
import java.util.HashSet;

public class Main {

	public static void main(String[] args) {
		if (args.length < 1) {
			System.err.println("Missing argument: file (corpus XML)");
			System.exit(1);
		}
		
		System.out.println("Reading the lexique file...");
		Cat c = new Cat(args[0]);
		ArrayList<String> read = c.read();
		System.out.println("Done.");
		
		System.out.println("Instantiating the lexique...");
		Lexique lex = null;
		try {
			lex = new Lexique(read);
		}
		catch(Exception e) {
			System.err.println("Error while instantiation the lexique.");
			System.err.println(e.toString());
			System.exit(1);
		}
		System.out.println("Done.");
		
		Saisie s = new Saisie(System.in);
		s.prompt();
		
		String prompt = s.getChaine().toLowerCase();
		String tokens[] = prompt.split("\\s+");
		
		for (String str : tokens) {
			String lemme = lex.getLemme(str);
			if (lemme != null) {
				System.out.println("Lemme found for the word: "+str+" : "+lemme);
			}
			else {
				System.out.println("No lemme found for the word: "+str+", searching candidates...");
				System.err.println("Prefix...");
				HashSet<String> bestLemmes = lex.findBestLemmes(str);
				for (String ss : bestLemmes) {
					System.out.println("Found this lemme as an alternative: "+ss);
				}
				System.err.println("Levenshtein...");
				bestLemmes = lex.findLemmesLevenshtein(str);
				if (bestLemmes.size() == 0) {
					System.err.println("Giving up, nothing found.");
					return;
				}
				for (String ss : bestLemmes) {
					System.out.println("Levenshtein: "+ss);
				}
				System.out.println("Best match: "+lex.closestMacht(str, lex.getWords()));
			}
		}
	}

}
