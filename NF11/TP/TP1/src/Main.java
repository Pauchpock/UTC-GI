import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	public static void main(String[] args) {
		//test1();
		int[] groups = new int[0];
		
		// q1
		String[] ex = new String[]{"0", "0002", "01", "-5", "5.5"};
		question("^((-?)[^0]\\d+|0)$", ex, groups);
		
		// q2
		System.out.println("\n\nQUESTION 2");
		String[] ex2 = new String[]{"-245.08", "45.302", "45", "45.", "45.0", "45.00"};
		question("^(-?)\\d+\\.\\d*[1-9]+\\d*$", ex2, groups);
		
		// q3
		System.out.println("\n\nQUESTION 3");
		String[] ex3 = new String[]{"dsfsdf", "parlement", "le", "un lelefant lel"};
		question("\\p{Alpha}*le\\p{Alpha}*", ex3, groups);
		
		// q4
		System.out.println("\n\nQUESTION 4");
		String[] ex4 = new String[]{"Ax25By"};
		question("\\b\\p{Alpha}+\\d+\\p{Alpha}+\\b", ex4, groups);
		
		// q5
		System.out.println("\n\nQUESTION 5");
		String[] ex5 = new String[]{"{ \"args\" : [10,20]}"};
		question("\\{ ?\"args\" ?: ?\\[((\\d+)(, ?(\\d+))*)?\\]\\}", ex5, new int[]{2,4});
		
		// q6
		System.out.println("\n\nQUESTION 5");
		String[] ex6 = new String[]{"{ \"args\" : [10,20]}"};
		question("\\{ ?\"args\" ?: ?\\[((\\d+)(, ?(\\d+))*)?\\]\\}", ex6, new int[]{2,4});
	}
	
	public static void question(String regex, String[] examples, int[] groups, String... contresExamples) {
		Pattern p = Pattern.compile(regex);
		for (String text: examples) {
			Matcher m = p.matcher(text);
			System.out.println("Testing..."+regex+"\twith "+text);
			while (m.find()) {
				System.out.println("Result found: "+m.group());
				for (int group: groups) {
					System.out.println("Groupe "+group+": " + m.group(group));
				}
//				System.out.println("   Avant : " + text.substring(0,m.start()));
//				System.out.println("   Position début : " + m.start());
//				System.out.println("   Position fin : " + m.end());
//				System.out.println("   Après : " + text.substring(m.end()));
			}
		}
	}
	
	public static void test1() {
		String patternString = "\\d+";
		String text = "rge5r43";
		Pattern p = Pattern.compile(patternString);
		Matcher m = p.matcher(text);
		System.out.println("R.E.: " + patternString);
		System.out.println("Test: " + text);
		boolean found = m.find();
		if (found) {
		System.out.println( " Position début : " + m.start());
		System.out.println( "Avant : " + text.substring(0,m.start()));
		System.out.println("Sélection : " + m.group());
		// System.out.println("Groupe : " + m.group(1));
		System.out.println( " Position fin : " + m.end());
		System.out.println( "Après : " + text.substring(m.end()));
		}
	}

}
