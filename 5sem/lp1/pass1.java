import java.io.*;

import java.util.*;

public class pass1 {

    static Map<String, Integer> OPTAB = new HashMap<>();

    static Map<String, String> SYMTAB = new LinkedHashMap<>();

    static List<String> intermediate = new ArrayList<>();

    static int LOCCTR;

    static String startAddress = "0000";

    public static void main(String[] args) {

        initializeOPTAB();

        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {

            String line = reader.readLine();

            String[] parts = parseLine(line);

            if (parts[1].equals("START")) {

                startAddress = parts[2];

                LOCCTR = Integer.parseInt(startAddress, 16);

                intermediate.add(line + "\t" + Integer.toHexString(LOCCTR).toUpperCase());

                line = reader.readLine();

            } else {

                LOCCTR = 0;

            }

            while (line != null) {

                parts = parseLine(line);

                String label = parts[0], opcode = parts[1], operand = parts[2];

                String locHex = Integer.toHexString(LOCCTR).toUpperCase();

                // Add to SYMTAB

                if (!label.equals("")) {

                    if (SYMTAB.containsKey(label)) {

                        System.err.println("Error: Duplicate symbol " + label);

                    } else {

                        SYMTAB.put(label, locHex);

                    }

                }

                intermediate.add(line + "\t" + locHex);

                // Increase LOCCTR

                if (OPTAB.containsKey(opcode)) {

                    LOCCTR += 3;

                } else if (opcode.equals("WORD")) {

                    LOCCTR += 3;

                } else if (opcode.equals("RESW")) {

                    LOCCTR += 3 * Integer.parseInt(operand);

                } else if (opcode.equals("RESB")) {

                    LOCCTR += Integer.parseInt(operand);

                } else if (opcode.equals("BYTE")) {

                    int inc = calculateByteLength(operand);

                    LOCCTR += inc;

                } else if (opcode.equals("END")) {

                    break;

                } else {

                    System.err.println("Error: Invalid opcode " + opcode);

                }

                line = reader.readLine();

            }

            // Output intermediate file

            System.out.println("Intermediate File:");

            for (String l : intermediate) {

                System.out.println(l);

            }

            // Output symbol table

            System.out.println("\nSymbol Table:");

            for (Map.Entry<String, String> entry : SYMTAB.entrySet()) {

                System.out.println(entry.getKey() + " -> " + entry.getValue());

            }

        } catch (IOException e) {

            e.printStackTrace();

        }

    }

    static void initializeOPTAB() {

        OPTAB.put("LDA", 3);

        OPTAB.put("STA", 3);

        OPTAB.put("LDCH", 3);

        OPTAB.put("STCH", 3);

        // Add more as needed

    }

    static String[] parseLine(String line) {

        String[] parts = new String[3];

        parts[0] = "";
        parts[1] = "";
        parts[2] = "";

        String[] tokens = line.trim().split("\\s+");

        if (tokens.length == 3) {

            parts[0] = tokens[0];

            parts[1] = tokens[1];

            parts[2] = tokens[2];

        } else if (tokens.length == 2) {

            parts[1] = tokens[0];

            parts[2] = tokens[1];

        } else if (tokens.length == 1) {

            parts[1] = tokens[0];

        }

        return parts;

    }

    static int calculateByteLength(String operand) {

        if (operand.startsWith("C'")) {

            return operand.length() - 3; // e.g., C'Z' -> length 1

        } else if (operand.startsWith("X'")) {

            return (operand.length() - 3) / 2; // e.g., X'F1' -> length 1 byte

        }

        return 1;

    }

}
