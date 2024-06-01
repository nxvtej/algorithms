import java.lang.*;

class ThreadDemo2 extends Thread {

    public void run() {

        System.out.println("Inside run method");
    }

    public static void main(String[] args) {

        ThreadDemo2 t1 = new ThreadDemo2();
        ThreadDemo2 t2 = new ThreadDemo2();
        ThreadDemo2 t3 = new ThreadDemo2();

        System.out.println("t1 thread priority : "
                + t1.getPriority());
        System.out.println("t2 thread priority : "
                + t2.getPriority());
        System.out.println("t3 thread priority : "
                + t3.getPriority());
    }
}