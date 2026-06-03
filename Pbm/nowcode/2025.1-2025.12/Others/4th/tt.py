
file = "D:/dev/code/ALGORITHM/Pbm/niuke/7_24_train/B.cpp"
with open(file, mode="r") as f:
    for line in f:
        line = line[:-1]
        print("			\"", line, "\",", sep='')