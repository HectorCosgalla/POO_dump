import database.Connection;

public class App {
    public static void main(String[] args) throws Exception {
        Connection database = new Connection();

        database.getConnection();
    }
}
