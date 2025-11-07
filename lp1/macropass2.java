import java.util.*;

public class MacroPass2 {
    public static void main(String[] argsss) {

        // Simulated MNT (Macro Name Table)
        Map<String, Integer> MNT = new HashMap<>();
        MNT.put("MYMACRO", 1);

        // Simulated MDT (Macro Definition Table)
        String MDT[] = {
            "MOV AREG,#1",
            "ADD AREG,#2",
            "MEND"
        };

        // Source code after PASS-1 (macro removed)
        String prog[] = {
            "START",
            "MYMACRO 5,10",
            "END"
        };

        System.out.println("\n--- PASS-II OUTPUT ---\n");

        for (String line : prog) {
            String parts[] = line.split("\\s+");

            // If first word is a macro name
            if (MNT.containsKey(parts[0])) {
                String args[] = parts[1].split(",");

                // Expand macro using MDT
                for (String m : MDT) {
                    if (m.equals("MEND")) break;

                    String exp = m.replace("#1", args[0])
                                  .replace("#2", args[1]);

                    System.out.println(exp);
                }
            } else {
                System.out.println(line);
            }
        }
    }
}
