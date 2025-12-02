def is_double_sequence(n: int) -> bool:
    s = str(n)
    if len(s) % 2 != 0:
        return False
    half = len(s) // 2
    return s[:half] == s[half:]



total_sum = 0

with open("in.txt", "r") as fin, open("out.txt", "w") as fout:
    with open("in.txt") as f:
        lines = f.readline().strip()
    lines = lines.split(",")
    for line in lines: 
        parts = line.split("-")
        if len(parts) < 2:
            continue

        a = int(parts[0])
        b = int(parts[1])

        fout.write(f"{a} {b}\n")

        for i in range(a, b + 1):
            if is_double_sequence(i):
                total_sum += i

    fout.write(f"result:{total_sum}\n")



