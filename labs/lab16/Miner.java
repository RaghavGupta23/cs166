import static java.lang.System.out;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;


public class Miner {

    public static int NUM_ZEROES = 22;

    private String name;

    public Miner(String name) {
        this.name = name;
    }

    public String findProof(Map<String,Integer> ledger) throws Exception {
        return null;
    }

    public static String hash(String s) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.update(s.getBytes());

        byte[] data = md.digest();
        StringBuffer sb = new StringBuffer();
        for (int i=0; i<data.length; i++) {
            sb.append(Integer.toString((data[i] & 0xff) + 0x100, 16).substring(1));
        }
        int i = Integer.parseInt(sb.toString().substring(0,7), 16);
        String binStr =  Integer.toBinaryString(i);
        return String.format("%28s", binStr).replace(" ", "0");
    }

    public static void main(String[] args) throws Exception {
        Map<String,Integer> ledger = new HashMap<String,Integer>();
        ledger.put("Alice", 42);
        ledger.put("Bob", 316);
        ledger.put("Charlie", 19);

        Miner alice = new Miner("Alice");
        out.println(alice.findProof(ledger));
    }
}

