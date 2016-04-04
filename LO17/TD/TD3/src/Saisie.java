import java.io.*;
import java.util.StringTokenizer;

class Saisie{
	private InputStream in;
	
	public Saisie(InputStream in) {
		this.in = in;
	}
	
	public void read() {
		BufferedReader br = null;
		String chaine;
		try {
			try {
				br = new BufferedReader(new InputStreamReader(this.in));
		        System.out.print("Request: ");
		        chaine=br.readLine();
		        System.out.println("Processing \""+chaine+"\"...");
		        
		        //StringTokenizer st = new StringTokenizer(chaine); // not recommended according to official doc (Oracle)
		        String[] tokens = chaine.split("\\s");
		    } 
		    catch(EOFException e) {
		        br.close();
		    }
		} 
		catch(IOException e) {
		    System.out.println("IO Exception");
		}
	}
}