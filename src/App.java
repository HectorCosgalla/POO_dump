
import database.Connection;
import database.Cypher;
import database.Queries;

public class App {
    public static void main(String[] args) throws Exception {
        Cypher fileToDecrypt = new Cypher();

        java.sql.Connection database;

        database = Connection.getConnection(fileToDecrypt.decrypt("src\\files\\configuration.txt", 1));
        String query = "SELECT * FROM student";
        Queries.aQuery(query, database);
        database.close();
    }
}
