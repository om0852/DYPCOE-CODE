
import java.util.concurrent.*;

 class ReaderWriter {

    static Semaphore mutex = new Semaphore(1);
    static Semaphore wrt = new Semaphore(1);
    static int readCount = 0;

    static class Reader extends Thread {
        public void run() {
            try {
                mutex.acquire();
                readCount++;
                if (readCount == 1) {
                    wrt.acquire();
                }
                mutex.release();
                System.out.println("Reading " + getName() + "Started");
                Thread.sleep(500);
                System.out.println("Reading " + getName() + "Finished");
                wrt.release();
                mutex.acquire();
                readCount--;
                if (readCount == 0) {
                    wrt.release();
                }
                mutex.release();

            } catch (Exception e) {
                // TODO: handle exception
            }
        }

    }
    static class Writer extends Thread{
        public void run(){
            try {
                wrt.acquire();
                System.out.println(getName()+"IS STARTED");
                Thread.sleep(500);
                System.out.println(getName()+"FINISHED");
                wrt.release();
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
    public static void main(String arg[]){
             
        Reader r1 = new Reader();
        Reader r2 = new Reader();
        Reader r3 = new Reader();
        Writer w1 = new Writer();
        Writer w2 = new Writer();
        // Writer w3 = new Writer();
        r1.start();
        r2.start();
        w1.start();
        r3.start();
        w2.start();


    }

}