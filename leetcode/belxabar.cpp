#include <iostream>
#include <cmath>
#include <unordered_set>

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num < 2)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to find the count of Belzabar numbers up to limit
int countBelzabarNumbers(int limit)
{
    std::unordered_set<int> belzabarNumbers;

    // Iterate over all possible primes
    for (int n = 2;; ++n)
    {
        if (n * (n + 20) > limit && n * (n - 20) > limit)
        {
            break; // Both expressions exceed the limit, so stop
        }

        if (isPrime(n))
        {
            int belzabar1 = n * (n + 20);
            int belzabar2 = n * (n - 20);

            if (belzabar1 <= limit)
            {
                belzabarNumbers.insert(belzabar1);
            }
            if (belzabar2 > 0 && belzabar2 <= limit)
            {
                belzabarNumbers.insert(belzabar2);
            }
        }
    }

    return belzabarNumbers.size();
}

int main()
{
    int n;

    std::cout << "Enter the value of n: ";
    n = 500000;

    int result = countBelzabarNumbers(n);
    std::cout << "Count of Belzabar numbers up to " << n << " is: " << result << std::endl;
    n = 1000000;

    result = countBelzabarNumbers(n);
    std::cout << "Count of Belzabar numbers up to " << n << " is: " << result << std::endl;

    return 0;
}
