import java.util.*;
import java.io.*;

// Class to hold symbol details
class Symbol {
    String name;
    int address;
    Symbol(String name, int address) {
        this.name = name;
        this.address = address;
    }
}

// Pass-II Assembler
public class PassTwoAssembler {
    static Map<String, Integer> MOT = new HashMap<>(); // Machine Opcode Table
    static Map<String, Integer> REG = new HashMap<>(); // Register Table
    static Map<String, Integer> symbolTable = new HashMap<>(); // Symbol Table

    public static void main(String[] args) {
        initTables();

        // Step 1: Load Symbol Table
        loadSymbolTable();

        // Step 2: Simulate reading intermediate file (could read from text)
        String intermediate[] = {
            "(AD,1) (C,100)",
            "(IS,1) AREG, NUM",
            "(IS,2) AREG, ONE",
            "(IS,3) AREG, TWO",
            "(IS,1) RESULT, AREG",
            "(AD,2)"
        };

        // Step 3: Generate machine code
        generateMachineCode(intermediate);
    }

    static void initTables() {
        // Machine operation codes
        MOT.put("MOV", 1);
        MOT.put("ADD", 2);
        MOT.put("SUB", 3);

        // Register codes
        REG.put("AREG", 1);
        REG.put("BREG", 2);
        REG.put("CREG", 3);
        REG.put("DREG", 4);
    }

    static void loadSymbolTable() {
        // You can modify or load from file if needed
        symbolTable.put("NUM", 104);
        symbolTable.put("ONE", 105);
        symbolTable.put("TWO", 106);
        symbolTable.put("RESULT", 107);
        symbolTable.put("LOOP", 100);
    }

    static void generateMachineCode(String[] intermediate) {
        System.out.println("----- PASS-II OUTPUT (Machine Code) -----");

        for (String line : intermediate) {
            line = line.trim();

            if (line.contains("(AD,")) {
                // Assembler directive – skip
                continue;
            }

            if (line.contains("(IS,")) {
                // Extract opcode number
                int opCode = Integer.parseInt(line.substring(line.indexOf(",") + 1, line.indexOf(")")));

                String[] parts = line.split(" ");
                String operand1 = "";
                String operand2 = "";

                if (parts.length > 1) {
                    String[] operands = parts[1].split(",");
                    operand1 = operands[0].replace(",", "").trim();

                    if (operands.length > 1)
                        operand2 = operands[1].trim();
                }

                // Get register code
                int regCode = 0;
                if (REG.containsKey(operand1)) {
                    regCode = REG.get(operand1);
                } else if (REG.containsKey(operand2)) {
                    regCode = REG.get(operand2);
                }

                // Get symbol address
                int memAddr = 0;
                if (symbolTable.containsKey(operand1)) {
                    memAddr = symbolTable.get(operand1);
                } else if (symbolTable.containsKey(operand2)) {
                    memAddr = symbolTable.get(operand2);
                }

                // Print simulated machine code
                System.out.println(opCode + "\t" + regCode + "\t" + memAddr);
            }
        }
    }
}
