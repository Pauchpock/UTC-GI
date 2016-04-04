import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
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
		
		String prompt = Lexique.toLowerCase(s.getChaine());
		String tokens[] = prompt.split("\\s+");
		
		for (String str : tokens) {
			String lemme = lex.getLemme(str);
			if (lemme != null) {
				System.out.println("Lemme trouvé pour le mot "+str+" : "+lemme);
			}
			else {
				System.out.println("No lemme found for the word: "+str);
			}
		}
	}

}
