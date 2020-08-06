
print("Accepted String is \"101*\"")


def Func(str):
    if len(str) < 3:
        return "Rejected"
    if str[0] == '1':
        if str[1] == '0':
            if str[2] == '1':
                for i in range(3, len(str)):
                    if str[i] != '1':
                        return "Rejected"
                return "Accepted"
            return "Rejected"
        return "Rejected"
    return "Rejected"


string = input('enter a string')
print(('string ' + string + ' is ' + Func(string)))
