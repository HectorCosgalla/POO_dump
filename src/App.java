import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import database.Connection;

public class App {
    public static void main(String[] args) throws Exception {
        java.sql.Connection database;

        database = Connection.getConnection("u387570956_valcos98_Test","Zg=aTgwks[71","mysql","45.132.157.154","3306","u387570956_Test_connect");
        String query = "SELECT * FROM student";
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
            // TODO: handle exception
            System.out.println(e);
        }
        database.close();
    }
}
