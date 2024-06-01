import java.io.ObjectInputFilter.Status;
import java.rmi.StubNotFoundException;

// thread using thread class
/* 
class student710 extends Thread {
    public void run() {                 // job done by thread
        System.out.println("thread is excuted");
    }

}

public class threaddemo {

    public static void main(String[] args) {
        student710 s1 = new student710(); // NEW state or Burn state of thread
        s1.start(); // activate state of thread
        s1.run(); // here also run will be executed but it's not a thread ; thread always starts with start ;
    }
}
*/

// now using interface runable 

class student710 implements Runnable {
    public void run() { // job done by thread
        System.out.println("thread is excuted");
    }

}

public class threaddemo {

    public static void main(String[] args) {
        student710 s1 = new student710(); // NEW state or Burn state of thread
        // Thread t1 = new Thread(s1); // here we have to pass the object to the thread
        // class constructor ;
        Thread t1 = new Thread(s1, "First thread "); // here we have to pass the object to the thread class constructor
                                                     // ;

        t1.start(); // now activated ;
        String thread_name = t1.getName(); // to get the thread name we need to save it into some string variable;

        System.out.println(thread_name);
    }
}

// now multithreading
/*
 * class student710 extends Thread {
 * public void run() { // job done by thread
 * System.out.println("thread is excuted");
 * }
 * 
 * }
 * 
 * public class threaddemo {
 * 
 * public static void main(String[] args) {
 * student710 s1 = new student710(); // NEW state or Burn state of thread
 * student710 s2 = new student710();
 * s1.start();
 * s1.run();
 * Thread.sleep(10000);
 * s2.start();
 * s2.run();
 * }
 * }
 */