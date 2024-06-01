import java.util.Scanner;

class class_code {
    public static void main() {
        System.out.println("Press 1 to print alphabate ");
        System.out.println("Press 2 to print odd numbers ");
        System.out.println("Enter your choice");

        Scanner scan = new Scanner(System.in);
        int ch = scan.nextInt();

        switch (ch) {
            case 1: {
                System.out.println("Enter 1 to print Upper case alphabates");
                System.out.println("Enter 2 to print lower case alphabates");
                System.out.println("Enter your choice : ");
                int ch1 = scan.nextInt();
                switch (ch1) {
                    case 1: {
                        char c;

                        for (c = 'A'; c <= 'Z'; c++) {
                            System.out.print(c + " ");
                        }

                        break;
                    }
                    case 2: {
                        char c;
                        for (c = 'a'; c <= 'z'; c++) {
                            System.out.print(c + " ");
                        }

                        break;
                    }
                }
                break;
            }
            case 2: {
                System.out.print("Printing all the odd numbers between 0 and 20 :");
                for (int i = 0; i < 20; i++) {
                    if (i % 2 != 0)
                        System.out.print(i + " ");
                }

                break;
            }
        }

        scan.close();
    }
}