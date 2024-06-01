abstract class end_sem_paper {
    abstract void oops_exam();

    abstract void ds_exam();

    abstract void dbms_exam();
}

public class samplepaper extends end_sem_paper {

    public static void introduce() {
        System.out.println("Hi, my name is John.");
    }

    char color = 'white';

    class inner {
        void display()
        {
            System.out.println("inside the inner class display fucntion");
            char color = 'black';
            System.out.println(color);
            System.out.println(super.color);
        }

    }

    void oops_exam() {
        System.out.println("Studying for oops for end sem paper...");
    }

    public static void main(string ars[]) {
        int a = 9;
        Integer integerobj = new Integer(a);

    }
}
