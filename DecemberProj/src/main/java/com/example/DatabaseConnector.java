package com.example;

import java.sql.*;
import java.util.Scanner;

public class DatabaseConnector {

    // Function for clearing screen cuz its easier
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static Connection connect() {
        // blank for safety
        String url = "";
        String user = "";
        
        String password = "";
        
        Connection connection = null;

        try {
            connection = DriverManager.getConnection(url, user, password);
            System.out.println("Connection Successgul");
            return connection;
        } catch (SQLException e) {
            System.err.println("Connection failed");
            e.printStackTrace();
            return null;
        }
    }
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        try (Connection conn = connect()) {
            if (conn != null) {
                Statement statement = conn.createStatement();

            boolean keepLoop = true;
            while (keepLoop) {
                String tableName = "employees";
                System.out.println("What action would you like to do? \n 1. Clear table\n 2. Add a new entry\n 3. Display all entries\n 4. Quit");
                int choice = input.nextInt();
                
                switch (choice) {
                    // Case for clearing table
                    case 1:
                        input.nextLine();
                        System.out.println("Are you sure? This is not reversible (y/N)");
                        String response = input.nextLine();
                        if (response.equalsIgnoreCase("y")) {
                            statement.executeUpdate("TRUNCATE TABLE " + tableName +";");
                            clearScreen();
                            System.out.println("Table Cleared");
                        }
                        else{
                            // clearScreen();
                            System.out.println("Canceled");
                        }
                        break;
                    // Case for adding new entry
                    case 2:
                        clearScreen();
                        input.nextLine();
                        System.out.println("What is this employee's first name?");
                        String newFirstName = input.nextLine();
                        System.out.println("What is this employee's last name?");
                        String newLastName = input.nextLine();
                        System.out.println("What is this employee's role?");
                        String newRole = input.nextLine();
                        statement.executeUpdate("INSERT INTO " + tableName + "(firstName, lastName, role) VALUES ('" + newFirstName + "', '" + newLastName + "', '" + newRole + "');");
                        clearScreen();
                        System.out.println("Added New Entry");
                        break;
                    // Case for printing the table
                    case 3:
                        clearScreen();
                        System.out.format("|%10s|%19s|%20s|%20s|\n", "Employee ID", "Role", "Last Name", "First name");
                        System.out.println("---------------------------------------------------------------------------");
                        ResultSet resultSet = statement.executeQuery("SELECT * FROM " +  tableName + ";");
                        // Print the results 1 line at a time
                        while (resultSet.next()) {
                            int id = resultSet.getInt("employeeId");
                            String role = resultSet.getString("role").trim();
                            String firstName = resultSet.getString("firstName").trim();
                            String lastName = resultSet.getString("lastName").trim();
                            System.out.format("|%10d|%20s|%20s|%20s|\n", id, role, lastName, firstName);
                        }
                        break;
                    // Case for quitting
                    case 4:
                        keepLoop = false;
                        break;
                }
            }
            // Close resources
            
            statement.close();
            conn.close();
            }
        } catch (SQLException e) {
            System.err.println("Error closing connection: " + e.getMessage());
        }
    }
}