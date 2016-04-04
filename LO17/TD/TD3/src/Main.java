import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		System.out.println("Reading the lexique file...");
		Cat c = new Cat(args[0]);
		ArrayList<String> read = c.read();
		System.out.println("Done.");
		
		System.out.println("Instantiating the lexique...");
		try {
			Lexique lex = new Lexique(read);
		}
		catch(Exception e) {
			System.err.println("Error while instantiation the lexique.");
			System.err.println(e.toString());
			System.exit(1);
		}
		System.out.println("Done.");
		
		//Saisie s = new Saisie(System.in);
		//s.read();
	}

}
