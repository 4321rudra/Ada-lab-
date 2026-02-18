import matplotlib.pyplot as plt

# Given data
sizes = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
durations = [177030, 412660, 572950, 676980, 835140, 955470, 1226940, 1367340, 1562790, 1810680]

# Plot
plt.figure()
plt.plot(sizes, durations, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Average Duration (nanoseconds)")
plt.title("Merge Sort Time Complexity (Average Case)")
plt.grid(True)
plt.show()
