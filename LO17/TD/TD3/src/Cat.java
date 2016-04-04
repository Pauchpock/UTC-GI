import java.io.*;
import java.util.ArrayList;

class Cat{
	private String in;
	
	public Cat(String input) {
		this.in = input;
	}
	
	public ArrayList<String> read() {
		BufferedReader br=null;
		String chaine;
		ArrayList<String> res = new ArrayList();
		try {
			try {
				br = new BufferedReader(new FileReader(this.in));
                while ((chaine=br.readLine())!=null) {
                	res.add(chaine.toString());
                }
            } 
			catch(EOFException e) {
				br.close();
				return null;
            }
        } 
		catch(FileNotFoundException e) {
			System.out.println("Unknown file: " + this.in);
			return null;
        } 
		catch(IOException e) {
			System.out.println("IO Exception");
			return null;
        }
		try {
			br.close();
		} catch(IOException ioe) {/*ignore*/}
		return res;
	}
}