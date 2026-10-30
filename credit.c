#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    long long card_number = get_long("Number: ");
    
    long  long temp = card_number;
    int sum1 = 0;
    int sum2 = 0;
    int count = 0;
    bool is_second_digit = false; 

    while (temp > 0) {
        int last_digit = temp % 10;
        
        if (is_second_digit) {
            int multiplied = last_digit * 2;
            sum1 += (multiplied / 10) + (multiplied % 10); 
        } else {
            sum2 += last_digit;
        }

        temp /= 10;
        count++;
        is_second_digit = ! is_second_digit;
    }
    int total_sum = sum1 + sum2;


    if (total_sum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }

    long long start_digits = card_number;
    while (start_digits >= 100) 
    {
        start_digits /= 10;
    }
    
    if ((count == 15) || (start_digits == 34 || start_digits == 37)) {
        printf("AMEX\n");
    }
    else if ((count == 16) && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 ||count == 16) || (start_digits / 10 == 4)) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}
