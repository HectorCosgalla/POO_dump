package database;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class Cypher {
  private int code;

  public Cypher(){
  }

  public void encrypt(String path) throws FileNotFoundException{
    File fileToEncrypt = new File(path);
    Scanner scanFile = new Scanner(fileToEncrypt);
    String textToWrite = new String();
    while (scanFile.hasNext()) {
      String[] data = scanFile.nextLine().split(" ");
      String encryptedString = new String();
      for (int i = 0; i < data[1].length(); i++) {
        char tempChar = (char) (data[1].charAt(i)+code);
        encryptedString += tempChar;
      }
      data[1] = encryptedString;
      textToWrite += data[0] + " " + data[1] + "\n";
    }

    Path fileName = Path.of(path);
    try {
      Files.writeString(fileName, textToWrite);
    } catch (IOException e) {
      e.printStackTrace();
    }
    scanFile.close();
  }

  public String decrypt(String path, int code) throws FileNotFoundException{
    File fileToDecrypt = new File(path);
    Scanner scanFile = new Scanner(fileToDecrypt);
    String textToWrite = new String();
    while (scanFile.hasNext()) {
      String[] data = scanFile.nextLine().split(" ");
      String decryptedString = new String();
      for (int i = 0; i < data[1].length(); i++) {
        char tempChar = (char) (data[1].charAt(i)-code);
        decryptedString += tempChar;
      }
      data[1] = decryptedString;
      textToWrite += data[1] + ",";
    }
    scanFile.close();
    return textToWrite;
  }

  public void setCode(int code) {
      this.code = code;
  }
}