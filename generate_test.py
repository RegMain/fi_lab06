from random import randint, choice

with open("test.txt", "w") as f:
    amount = randint(10, 30);
    f.write(str(amount))
    f.write("\n\n")
    for i in range(amount):
        id = randint(1,100000000)
        # I literally don't care about 1e-8
        surname = choice(["Letov", "Lindemann", "Tsoy", "Astley", "Freeman", "Pirozhkov"])
        name = choice(["Ivan", "Andrey", "Pyotr", "Leonid", "Pavel", "Egor", "Terentiy", "Viktor"])
        patronym = choice(["Fyodorovich", "Andreevich", "Ivanovich", "Petrovich", "Leonidovich", "Pavlovich", "Egorovich", "Terentievich", "Viktorovich"])
        t_cnt = randint(1,30)
        f.write(str(id))
        f.write(f"\n{surname}\t{name}\t{patronym}\n")
        f.write(f"{t_cnt}\n")
        for j in range(t_cnt):
            date = choice(["01.01.2026", "02.01.2026", "03.01.2026", "04.01.2026"])
            time = choice(["00:00:42", "00:06:07", "12:00:00", "13:37:01", "12:34:56"])
            status = choice(["Spending", "Income"])
            rub = randint(5,6742)
            kop = randint(0,99)
            f.write(f"{date}\t{time}\t{status}\t{rub}.{kop}\n")
        f.write("\n")
