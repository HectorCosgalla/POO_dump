package database;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Queries {
    public static void aQuery(String query, java.sql.Connection database) {
        try (Statement statement = database.createStatement()){
            ResultSet resultSet = statement.executeQuery(query);
            while(resultSet.next()){
                int studentId = resultSet.getInt("ID");
                String name = resultSet.getString("name");
                String department_name = resultSet.getString("dept_name");
                int credits = resultSet.getInt("tot_cred");
                System.out.println(studentId+"\t|\t"+name+"\t|\t"+department_name+"\t|\t"+credits);
            }
        } catch (SQLException e) {
            System.out.println(e);
        }
    }
}
