import java.util.Scanner;

class helloworld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Scanner scan = new Scanner(System.in);
        /*
         * System.out.print("Enter your first name: ");
         * String name = scan.nextLine();
         * 
         * System.out.print("Enter your last name: ");
         * String last_name = scan.nextLine();
         * 
         * System.out.println();
         * System.out.println("Hi " + name + " " + last_name);
         */

        /*
         * System.out.println("Enter two number to get their sum");
         * int x = 0, y = 0;
         * 
         * x = scan.nextInt();
         * y = scan.nextInt();
         * 
         * System.out.println("SUM = " + (x + y));
         * 
         * System.out.println("Now enter float values :");
         * float xx, yy;
         * xx = scan.nextFloat();
         * yy = scan.nextFloat();
         * 
         * System.out.println("Float variable sum is :- " + (xx + yy));
         */

        // Widening Type Casting
        /*
         * System.out.println("Enter two integer to get them converted into float");
         * 
         * int x = scan.nextInt();
         * int y = scan.nextInt();
         * 
         * float sum = x + y;
         * System.out.println("SUM = " + sum);
         */

        // Narrowing Type Casting
        System.out.println("Enter two float to get them converted into double");

        float x = scan.nextFloat();
        float y = scan.nextFloat();

        double sum = (double) x + (double) y;
        System.out.println("SUM = " + sum);

        System.out.println("First code done.");
        scan.close();
    }
}