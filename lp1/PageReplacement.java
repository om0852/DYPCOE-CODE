import java.util.*;

public class PageReplacement {

    // FIFO Page Replacement
    static void fifo(int pages[], int capacity) {
        Queue<Integer> memory = new LinkedList<>();
        int faults = 0, hits = 0;

        System.out.println("\n--- FIFO Page Replacement ---");
        
        for (int page : pages) {
            if (!memory.contains(page)) { // page fault
                if (memory.size() == capacity)
                    memory.poll(); // remove oldest
                memory.add(page);
                faults++;
            } else {
                hits++;
            }
            System.out.println("Page: " + page + " -> " + memory);
        }
        System.out.println("Hits: " + hits + ", Faults: " + faults);
    }

    // LRU Page Replacement
    static void lru(int pages[], int capacity) {
        ArrayList<Integer> memory = new ArrayList<>();
        int hits = 0, faults = 0;

        System.out.println("\n--- LRU Page Replacement ---");

        for (int page : pages) {
            if (memory.contains(page)) { // hit
                memory.remove((Integer) page);
                memory.add(page);
                hits++;
            } else { // fault
                if (memory.size() == capacity)
                    memory.remove(0); // remove least recently used
                memory.add(page);
                faults++;
            }
            System.out.println("Page: " + page + " -> " + memory);
        }
        System.out.println("Hits: " + hits + ", Faults: " + faults);
    }

    // Optimal Page Replacement
    static void optimal(int pages[], int capacity) {
        ArrayList<Integer> memory = new ArrayList<>();
        int hits = 0, faults = 0;

        System.out.println("\n--- Optimal Page Replacement ---");

        for (int i = 0; i < pages.length; i++) {
            int page = pages[i];

            if (memory.contains(page)) {
                hits++;
            } else {
                if (memory.size() < capacity) {
                    memory.add(page);
                } else {
                    int farthest = -1, indexToReplace = 0;

                    for (int j = 0; j < memory.size(); j++) {
                        int nextIndex = Integer.MAX_VALUE;

                        for (int k = i + 1; k < pages.length; k++) {
                            if (pages[k] == memory.get(j)) {
                                nextIndex = k;
                                break;
                            }
                        }

                        if (nextIndex > farthest) {
                            farthest = nextIndex;
                            indexToReplace = j;
                        }
                    }

                    memory.set(indexToReplace, page);
                }
                faults++;
            }
            System.out.println("Page: " + page + " -> " + memory);
        }
        System.out.println("Hits: " + hits + ", Faults: " + faults);
    }

    public static void main(String[] args) {
        int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
        int capacity = 3;

        fifo(pages, capacity);
        lru(pages, capacity);
        optimal(pages, capacity);
    }
}
