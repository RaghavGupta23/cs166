import static java.lang.System.out;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;


/*
 * Lab 16 Instructions
 * 1. Add one extra coin to the miner's account in the ledger
 * 2. Convert the new ledger to a String (`ledgeStr`)
 * 3. Search for a "proof" where the result of `hash(ledgerStr + proof)` has `NUM_ZEROES` leading zeroes, similar to the hashcash protocol used for spam reduction in Chapter 5 of your textbook.
 */


public class Miner {

    public static int NUM_ZEROES = 22;

    private String name;

    public Miner(String name) {
        this.name = name;
    }

    public String findProof(Map<String,Integer> ledger) throws Exception {
        // init values
        Map<String, Integer> paid = ledger;
        paid.put(this.name, paid.get(this.name) + 1);  // pay yourself
        String ledgerStr = paid.toString();
        String hashed;
        int proof = 0;
        boolean notFound = true;

        // don't hard code the zero string
        String zeroes = "";
        for (int i = 0; i < NUM_ZEROES; i++)
            zeroes += "0";

        // GOOOOOOOO
        while (notFound) {
            // unobtrusive progress
            if (proof % 100000 == 0)
                System.out.print(".");
            // hash and check
            hashed = hash(ledgerStr + proof);
            if (hashed.substring(0, NUM_ZEROES).equals(zeroes)) {
                System.out.println("\nproof: " + proof);
                System.out.println("hash:  " + hashed);
                notFound = false;
            } else {
                // keep mining
                proof++;
            }
        }

        return proof + "";
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

