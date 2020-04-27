package classproject;

public class PasswordGenerater {
// Java program generate a random AlphaNumeric String 
// using Regular Expressions method 
	
	public static void main(String[] args) {
		
		String result = makePassword(10);
		System.out.println(result);
	}
	//Generate password length of parameter
	public static String makePassword(int length) {
		
		//variable holding possible characters
		String Characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                + "abcdefghijklmnopqrstuvxyz";
		String numbers = "0123456789";
		String password = "";
		
		/*loop that adds into the password string
		 * wit the methods below
		 */
		for (int i = 0; i < length; i++) {
			password = password + randomCharacter(Characters);
		}
		String randomDigit = randomCharacter(numbers);
		password = insertAtRandom(password, randomDigit);
		return password;
	}
	//get random character from string
	public static String randomCharacter(String characters) {
			int n = characters.length();
			int r = (int) (n * Math.random());
			return characters.substring(r, r + 1);
		}
	//insert one string into another at a random position
	public static String insertAtRandom(String str, String toInsert) {
		int n = str.length();
		int r = (int)((n+1) * Math.random());
		return str.substring(0, r) + toInsert + str.substring(r);
}
}