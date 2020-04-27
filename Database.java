package com.database.connection;

import java.sql.*;
import java.util.Scanner;
import com.database.util.*;

public class Database {
	
	// database access variables
	private String url;
	private String username;
	private String password;
	private Connection connection;
	private Scanner scan;
	private Statement statement;
	private ResultSet resultSet;
	
	//constructor
	public Database(String url, String username, String password) throws Exception {
		this.url = url;
		this.username = username;
		this.password = password;
		scan = new Scanner(System.in);
		
		//driver register
		Class.forName("com.mysql.jdbc.Driver");
		connection = DriverManager.getConnection(url, username, password);
	}
	/*method asks for user ID, enters the database
	 * retrieves email and password for that user
	 * exceptions that are programmed asure the 
	 * program doesn't crash if the user inputs an
	 * an id that doesn't exist and then asks 
	 * if they would like to try again
	 */
	public void getUserAndPass() throws Exception {
		
		//variables that catch the database output
		String user = null;
		String pass = null;
		
		while(true) {
			System.out.print("Type user ID: ");
			//variable for user input
			int num = scan.nextInt();
			
			//query executer and information getter 
			String query = "SELECT * FROM javagaurdians.users WHERE idUsers = " + num;
			connection = DriverManager.getConnection(url, username, password);
			statement = connection.createStatement();
			resultSet = statement.executeQuery(query);
			resultSet.next();
			
			//exception handler
			try {
				user = resultSet.getString("UserEmail");
				pass = resultSet.getString("Password");
			} catch(Exception e) {
				System.out.println("A user with that ID does not exist");
				System.out.println("Try again? Y/N");
				if(scan.next().equalsIgnoreCase("y")) {
					getUserAndPass();
				}
				System.out.println("Exiting...");
				break;
			}
			//information print statements
			System.out.println("Here are the account details for the user with ID: " + num);
			System.out.println("Username: " + user);
			System.out.println("Password: " + pass);
			break;
		}
		//closers
		scan.close();
		connection.close();
		statement.close();
	}
}
