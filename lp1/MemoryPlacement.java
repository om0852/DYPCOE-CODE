import java.util.*;

public class MemoryPlacement {

    static void firstFit(int blockSize[], int m, int processSize[], int n) {
        int allocation[] = new int[n];
        Arrays.fill(allocation, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }

        System.out.println("\n--- FIRST FIT ---");
        printResult(allocation, processSize);
    }

    static void bestFit(int blockSize[], int m, int processSize[], int n) {
        int allocation[] = new int[n];
        Arrays.fill(allocation, -1);

        for (int i = 0; i < n; i++) {
            int bestIdx = -1;
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                        bestIdx = j;
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                blockSize[bestIdx] -= processSize[i];
            }
        }

        System.out.println("\n--- BEST FIT ---");
        printResult(allocation, processSize);
    }

    static void worstFit(int blockSize[], int m, int processSize[], int n) {
        int allocation[] = new int[n];
        Arrays.fill(allocation, -1);

        for (int i = 0; i < n; i++) {
            int worstIdx = -1;
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                        worstIdx = j;
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                blockSize[worstIdx] -= processSize[i];
            }
        }

        System.out.println("\n--- WORST FIT ---");
        printResult(allocation, processSize);
    }

    static void printResult(int allocation[], int processSize[]) {
        System.out.println("Process\tSize\tBlock");
        for (int i = 0; i < processSize.length; i++) {
            System.out.print("P" + (i + 1) + "\t" + processSize[i] + "\t");
            if (allocation[i] != -1)
                System.out.println("Block " + (allocation[i] + 1));
            else
                System.out.println("Not Allocated");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of blocks: ");
        int m = sc.nextInt();
        int block[] = new int[m];
        System.out.println("Enter block sizes:");
        for (int i = 0; i < m; i++) block[i] = sc.nextInt();

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        int process[] = new int[n];
        System.out.println("Enter process sizes:");
        for (int i = 0; i < n; i++) process[i] = sc.nextInt();

        int[] b1 = block.clone(), b2 = block.clone(), b3 = block.clone();

        firstFit(b1, m, process, n);
        bestFit(b2, m, process, n);
        worstFit(b3, m, process, n);
    }
}
