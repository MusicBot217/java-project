
package com.database.connection;

import java.sql.*;
import java.util.Scanner;

public class Main {

	// registration for a MySQL connection
	public static void main(String[] args) throws Exception {
		String url = "jdbc:mysql://localhost:3306/javagaurdians";
		String uname = "root";
		String pass = "JavaGaurds11*";
		
		//initialized database
		Database database = new Database(url, uname, pass);
		database.getUserAndPass();
	}
}
