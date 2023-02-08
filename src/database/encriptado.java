package database;

import java.security.Key;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class encriptado {
  private static final String AESModel = "AES";
  private static final byte[] keyValue = 
    new byte[] { 'T', 'h', 'e', 'B', 'e', 's', 't',
'S', 'e', 'c', 'r','e', 't', 'K', 'e', 'y' };

  public static String encrypt(String data) throws Exception {
    Key key = generateKey();
    Cipher c = Cipher.getInstance(AESModel);
    c.init(Cipher.ENCRYPT_MODE, key);
    byte[] encVal = c.doFinal(data.getBytes());
    return Base64.getEncoder().encodeToString(encVal);
  }

  public static String decrypt(String encryptedData) throws Exception {
    Key key = generateKey();
    Cipher c = Cipher.getInstance(AESModel);
    c.init(Cipher.DECRYPT_MODE, key);
    byte[] decodedValue = Base64.getDecoder().decode(encryptedData);
    byte[] decValue = c.doFinal(decodedValue);
    return new String(decValue);
  }

  private static Key generateKey() throws Exception {
    return new SecretKeySpec(keyValue, AESModel);
  }

  public static void main(String[] args) {
    try {
      String plainText = "Hola";
      String encryptedText = encrypt(plainText);
      String decryptedText = decrypt(encryptedText);
      System.out.println("Plain Text : " + plainText);
      System.out.println("Encrypted Text : " + encryptedText);
      System.out.println("Encrypted Text : " + decryptedText);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}