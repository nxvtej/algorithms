def newton_raphson(x):
    def func(x):
        return x * x * x - x * x + 2

    def deriv_func(x):
        return 3 * x * x - 2 * x

    h = func(x) / deriv_func(x)
    while abs(h) >= 0.0001:
        h = func(x) / deriv_func(x)
        x = x - h
    print("The value of the root using Newton-Raphson is: %.4f" % x)


def bisection(a, b):
    def func(x):
        return x * x * x - x * x + 2

    if func(a) * func(b) >= 0:
        print("You have not assumed the right values for a and b")
        return

    c = a
    while (b - a) >= 0.01:
        c = (a + b) / 2
        if func(c) == 0.0:
            break
        if func(c) * func(a) < 0:
            b = c
        else:
            a = c
    print("The value of the root using Bisection is: %.4f" % c)


def main():
    operations = {
        '1': newton_raphson,
        '2': bisection
    }

    while True:
        print("\nChoose a method:")
        print("1. Newton-Raphson Method")
        print("2. Bisection Method")
        print("3. Exit")
        choice = input("Enter your choice: ")

        if choice in operations:
            if choice == '1':
                x0 = float(input("Enter initial guess for Newton-Raphson: "))
                operations[choice](x0)
            elif choice == '2':
                a = float(input("Enter the value of a: "))
                b = float(input("Enter the value of b: "))
                operations[choice](a, b)
        elif choice == '3':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
