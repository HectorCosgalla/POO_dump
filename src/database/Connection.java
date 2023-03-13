package database;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class Connection {
    
    public static java.sql.Connection getConnection(String data) throws SQLException {
        String[] stringOfData = data.split(",");
        String userName = stringOfData[0], password= stringOfData[1], dbms= stringOfData[2], serverName= stringOfData[3], portNumber= stringOfData[4], dbName= stringOfData[5];
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
