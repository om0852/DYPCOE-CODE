import java.util.*;

class Process {
    int pid, at, bt, pri, wt, tat, rt;
    
    Process(int pid, int at, int bt, int pri) {
        this.pid = pid;
        this.at = at;
        this.bt = bt;
        this.pri = pri;
        this.rt = bt;
    }
}

 class CPUScheduling {

    static void fcfs(ArrayList<Process> p) {
        int time = 0;
        for (Process pr : p) {
            if (time < pr.at) time = pr.at;
            pr.wt = time - pr.at;
            time += pr.bt;
            pr.tat = pr.wt + pr.bt;
        }
        System.out.println("\nFCFS Scheduling:");
        print(p);
    }

    static void sjf(ArrayList<Process> p) {
        int completed = 0, time = 0;
        
        while (completed != p.size()) {
            Process shortest = null;
            for (Process pr : p)
                if (pr.at <= time && pr.rt > 0 && (shortest == null || pr.rt < shortest.rt))
                    shortest = pr;

            if (shortest == null) { time++; continue; }

            shortest.rt--;
            if (shortest.rt == 0) {
                completed++;
                int finish = time + 1;
                shortest.tat = finish - shortest.at;
                shortest.wt = shortest.tat - shortest.bt;
            }
            time++;
        }

        System.out.println("\nSJF (Preemptive):");
        print(p);
    }

    static void priority(ArrayList<Process> p) {
        int completed = 0, time = 0;

        while (completed != p.size()) {
            Process highest = null;
            for (Process pr : p)
                if (pr.at <= time && pr.rt > 0 && (highest == null || pr.pri < highest.pri))
                    highest = pr;

            if (highest == null) { time++; continue; }

            time += highest.bt;
            highest.rt = 0;
            highest.tat = time - highest.at;
            highest.wt = highest.tat - highest.bt;
            completed++;
        }

        System.out.println("\nPriority (Non-Preemptive):");
        print(p);
    }

    static void roundRobin(ArrayList<Process> p, int q) {
        int time = 0, completed = 0;
        Queue<Process> qList = new LinkedList<>(p);

        while (completed != p.size()) {
            Process pr = qList.poll();
            if (pr.rt > 0 && pr.at <= time) {
                if (pr.rt > q) {
                    time += q;
                    pr.rt -= q;
                } else {
                    time += pr.rt;
                    pr.rt = 0;
                    completed++;
                    pr.tat = time - pr.at;
                    pr.wt = pr.tat - pr.bt;
                }
            }
            qList.offer(pr);
            time++;
        }

        System.out.println("\nRound Robin (q=" + q + "):");
        print(p);
    }

    static void print(ArrayList<Process> p) {
        System.out.println("PID\tAT\tBT\tPri\tWT\tTAT");
        for (Process pr : p)
            System.out.println(pr.pid + "\t" + pr.at + "\t" + pr.bt + "\t" + pr.pri + "\t" + pr.wt + "\t" + pr.tat);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Process> p = new ArrayList<>();

        System.out.print("Enter no. of processes: ");
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            System.out.print("Enter AT, BT, Priority for P" + i + ": ");
            p.add(new Process(i, sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }

        System.out.println("\n1.FCFS\n2.SJF (Preemptive)\n3.Priority\n4.Round Robin\nEnter choice: ");
        int ch = sc.nextInt();

        ArrayList<Process> copy = new ArrayList<>();
        for (Process pr : p) copy.add(new Process(pr.pid, pr.at, pr.bt, pr.pri));

        switch (ch) {
            case 1 -> fcfs(copy);
            case 2 -> sjf(copy);
            case 3 -> priority(copy);
            case 4 -> {
                System.out.print("Enter Time Quantum: ");
                int q = sc.nextInt();
                roundRobin(copy, q);
            }
            default -> System.out.println("Invalid choice");
        }
    }
}
