import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

# Read data from file
# file_path = "data/patrik_i_payriks.csv"
file_path = "data/josie_i_patriks.csv"
data = []
with open(file_path, 'r') as file:
    # Skip the header line
    next(file)
    for line in file:
        values = line.strip().split(';')
        time = float(values[0].replace(',', '.'))
        ax = float(values[1].replace(',', '.').replace('−', '-'))
        ay = float(values[2].replace(',', '.').replace('−', '-'))
        az = float(values[3].replace(',', '.').replace('−', '-'))
        aT = float(values[4].replace(',', '.').replace('−', '-'))
        data.append((time, ax, ay, az, aT))

# Extract values for plotting
time_values = [entry[0] for entry in data]
ax_values = [entry[1] for entry in data]
ay_values = [entry[2] for entry in data]
az_values = [entry[3] for entry in data]

# Create subplots
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(100, 50))

# Plot ax
ax1.plot(time_values, ax_values)
ax1.set_ylabel('ax (m/s^2)')
ax1.set_title('Acceleration vs. Time')
ax1.xaxis.set_major_locator(ticker.MultipleLocator(1))
ax1.grid(True)
# Plot ay
ax2.plot(time_values, ay_values)
ax2.set_ylabel('ay (m/s^2)')
ax2.xaxis.set_major_locator(ticker.MultipleLocator(1))
ax2.grid(True)

# Plot az
ax3.plot(time_values, az_values)
ax3.set_xlabel('Time (s)')
ax3.set_ylabel('az (m/s^2)')
ax3.xaxis.set_major_locator(ticker.MultipleLocator(1))
ax3.grid(True)

# Adjust spacing between subplots
plt.tight_layout()
plt.grid(True)

# Save the plot as a PNG image
plt.savefig('acceleration_plot.png')

print("Plot saved as acceleration_plot.png")
