import java.util.HashSet;
import java.util.Set;
import java.io.File;
import java.io.FileNotFoundException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import static java.lang.System.out;
import static java.lang.System.err;

public class CrackerSalt {

  /**
   * Reads in a list of passwords from a Scanner, returning the results
   * in a List.
   */
  private static Set<String> loadPasswords(String filename)
          throws FileNotFoundException {
    Scanner scan = new Scanner(new File(filename));
    Set<String> pwds = new HashSet<String>();
    while (scan.hasNextLine()) {
      String line = scan.nextLine();
      pwds.add(line);
    }
    scan.close();
    return pwds;
  }

  /**
   * Reads in a whitespace-delimited file of usernames and hashes,
   * returning a map of hashes to usernames.
   */
  private static Map<String,ArrayList<String>> loadHash2Username(String filename)
          throws FileNotFoundException {
    Scanner scan = new Scanner(new File(filename));
    Map<String,ArrayList<String>> hashes = new HashMap<String,ArrayList<String>>();
    while (scan.hasNext()) {
      String username = scan.next();
      String salt = scan.next();
      String hash = scan.next();
      ArrayList<String> pair = new ArrayList<String>();
      pair.add(salt);
      pair.add(username);
      hashes.put(hash, pair);
    }
    scan.close();
    return hashes;
  }

  /**
   * Calculates out the md5 hash value of the specified String,
   * returning the hash as a 32 char hex string.
   */
  private static String md5hash(String s) throws NoSuchAlgorithmException {
    MessageDigest md5 = MessageDigest.getInstance("md5");
    md5.update(s.getBytes());
    byte[] md5Bytes = md5.digest();
    StringBuilder sb = new StringBuilder();
    for (int i=0; i<md5Bytes.length; i++) {
      String hex = Integer.toHexString(0xff & md5Bytes[i]);
      if (hex.length() == 1) { sb.append('0'); }
      sb.append(hex);
    }
    return sb.toString();
  }

  public static void main (String[] args) throws FileNotFoundException,
                                                 NoSuchAlgorithmException {
    if (args.length != 2) {
      err.println("Usage: java edu.sjsu.crypto.Cracker <common passwords> <hashed passwords>");
    }

    out.println("Loading passwords");
    Set<String> commonPwds = loadPasswords(args[0]);

    out.println("Loading hashes");
    Map<String,ArrayList<String>> hash2unames = loadHash2Username(args[1]);

    String hash, salt;
    for (Map.Entry<String, ArrayList<String>> pair : hash2unames.entrySet()) {
      ArrayList<String> stuff = pair.getValue();
      salt = stuff.get(0);
      for (String p : commonPwds) {
        hash = md5hash(salt + p);
        if (hash2unames.containsKey(hash)) {
          String user = hash2unames.get(hash).get(1);
          out.println("The password for " + user + " is " + p);
        }
      }
    }

  }
}
