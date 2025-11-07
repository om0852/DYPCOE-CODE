import java.util.*;

// Class to store symbol information
class Symbol {
    String name;
    int address;

    Symbol(String name, int address) {
        this.name = name;
        this.address = address;
    }

    @Override
    public String toString() {
        return name + "\t" + address;
    }
}

// Main Assembler Pass-I
public class PassOneAssembler {
    static Map<String, Integer> MOT = new HashMap<>(); // Machine Op Table
    static Map<String, Integer> POT = new HashMap<>(); // Pseudo Op Table
    static List<Symbol> symbolTable = new ArrayList<>();

    public static void main(String[] args) {
        // Initialize instruction tables
        initTables();

        // Example assembly program (you can modify)
        String program[] = {
            "START 100",
            "LOOP MOV AREG, NUM",
            "ADD AREG, ONE",
            "SUB AREG, TWO",
            "MOV RESULT, AREG",
            "NUM DS 1",
            "ONE DC 1",
            "TWO DC 2",
            "RESULT DS 1",
            "END"
        };

        passOne(program);
    }

    static void initTables() {
        // Machine Op Table (MOT)
        MOT.put("MOV", 1);
        MOT.put("ADD", 2);
        MOT.put("SUB", 3);

        // Pseudo Op Table (POT)
        POT.put("START", 1);
        POT.put("END", 2);
        POT.put("DS", 3);
        POT.put("DC", 4);
    }

    static void passOne(String[] program) {
        int LC = 0;

        System.out.println("----- PASS-I OUTPUT -----");
        for (String line : program) {
            String[] parts = line.trim().split("\\s+");
            String label = "", opcode = "", operand = "";

            if (parts.length == 3) { // Label + Opcode + Operand
                label = parts[0];
                opcode = parts[1];
                operand = parts[2];
            } else if (parts.length == 2) { // Opcode + Operand
                opcode = parts[0];
                operand = parts[1];
            } else if (parts.length == 1) { // Single word (e.g., END)
                opcode = parts[0];
            }

            // START directive
            if (opcode.equals("START")) {
                LC = Integer.parseInt(operand);
                System.out.println("Program starts at address: " + LC);
                continue;
            }

            // If line has a label, add to symbol table
            if (!label.isEmpty()) {
                symbolTable.add(new Symbol(label, LC));
            }

            // Process pseudo-ops
            if (POT.containsKey(opcode)) {
                if (opcode.equals("DS")) {
                    LC += Integer.parseInt(operand);
                } else if (opcode.equals("DC")) {
                    LC += 1;
                } else if (opcode.equals("END")) {
                    break;
                }
            } 
            // Process machine instructions
            else if (MOT.containsKey(opcode)) {
                LC += 1;
            } else {
                System.out.println("Error: Invalid opcode " + opcode);
            }
        }

        // Print symbol table
        System.out.println("\n----- SYMBOL TABLE -----");
        System.out.println("Symbol\tAddress");
        for (Symbol s : symbolTable) {
            System.out.println(s);
        }
    }
}
