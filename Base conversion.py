v = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
try:
    a = int(input("Enter a base 10 integer:"))
    if a < 0:
        print("Please provide a base 10 natural number")
    else:
        try:
            b = int(input("Enter the conversion base:"))
            if b < 2 or b > 36:
                print("Please provide a base 10 natural number between 2 and 36")
            else:
                if a == 0:
                    print(0)
                else:
                    ans = ""
                    while a > 0:
                        ans = ans + v[int(a % b)]
                        a = int(a / b)
                    ans = ans[::-1]
                    print(ans)
        except ValueError:
            print("Please provide a base 10 natural number greater than 1")
except ValueError:
    print("Please provide a base 10 natural number")
