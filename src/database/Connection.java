package database;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class Connection {
    
    public static java.sql.Connection getConnection(String userName, String password, String dbms, String serverName, String portNumber, String dbName) throws SQLException {
        java.sql.Connection conn = null;
        Properties connectionProps = new Properties();
        connectionProps.put("user", userName);
        connectionProps.put("password", password);
    
        if (dbms.equals("mysql")) {
            conn =  DriverManager.getConnection("jdbc:" + dbms + "://" + serverName +":" + portNumber + "/"+dbName,connectionProps);
        }
        System.out.println("Connected to database");
        return conn;
    }
}
