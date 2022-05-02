string_ray = []
while(1):
    try:
        string_main = (str(input()[1:-1])).replace('/', ' ')
        if (string_main in string_ray) :
            continue
        else:
            print(string_main)
            string_ray.append(string_main)

    except EOFError:
        break