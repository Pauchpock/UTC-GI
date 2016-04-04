import java.io.*;
import java.util.StringTokenizer;

class Saisie{
	private String chaine;
	private String tokens[];
	private InputStream in;
	
	public Saisie(InputStream in) {
		this.in = in;
	}
	
	public void prompt() {
		BufferedReader br = null;
		try {
			try {
				br = new BufferedReader(new InputStreamReader(this.in));
		        System.out.print("Request: ");
		        chaine=br.readLine();
		    } 
		    catch(EOFException e) {
		        br.close();
		    }
		} 
		catch(IOException e) {
		    System.out.println("IO Exception");
		}
	}

	public String getChaine() {
		return chaine;
	}
}