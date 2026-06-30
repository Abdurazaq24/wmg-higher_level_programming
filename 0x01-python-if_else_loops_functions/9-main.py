#!/usr/bin/python3

print_last_digit = __import__('9-print_last_digit').print_last_digit

print("Last digit of 98 is {}".format(print_last_digit(98)))
print("Last digit of 0 is {}".format(print_last_digit(0)))
print("Last digit of -1024 is {}".format(print_last_digit(-1024)))
print("Last digit of 123456789 is {}".format(print_last_digit(123456789)))
