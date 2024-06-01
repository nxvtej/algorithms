
import java.io.*;
import java.util.*;

class mst {
    public int digitSum(int input1) {
        int neg = input1;
        if (input1 < 0) {
            input1 *= -1;
        }
        int len = Integer.toString(input1).length();
        if (len == 1) {
            if (neg < 0)
                return input1 * -1;
            else
                return input1;
        } else {
            int sum = 0;
            while (input1 != 0) {
                int rem = input1 % 10;
                sum += rem;
                input1 /= 10;
            }
            if (neg < 0)
                return digitSum(sum * -1);
            else
                return digitSum(sum);
        }
    }

    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        mst object = new mst();
        int number = 0;
        System.out.println("Enter number :");
        number = obj.nextInt();

        int digit = object.digitSum(number);
        System.out.println(digit);
    }

}
