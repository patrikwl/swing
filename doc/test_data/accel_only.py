import numpy as np
from scipy.linalg import block_diag
import matplotlib.pyplot as plt

# Read accelerometer measurements from file
accel_file = "data/josie_i_josies.csv"
accel_data = np.genfromtxt(accel_file, delimiter=";", skip_header=1)

# Combine time and acceleration measurements
accel_time = accel_data[:, 0]
accel_values = accel_data[:, 1:]

# Define the system matrices
def create_system_matrices(dt):
    # State transition matrix
    A = np.array([[1, dt], [0, 1]])

    # Control input matrix
    B = np.array([[0], [0]])

    # Observation matrix
    H = np.array([[1, 0]])

    # Process noise covariance matrix
    q = 0.01  # Process noise magnitude
    Q = np.array([[dt**3/3, dt**2/2], [dt**2/2, dt]]) * q

    # Measurement noise covariance matrix
    R = np.array([[0.01]])

    return A, B, H, Q, R

# Kalman filter initialization
def initialize_kalman_filter(x0, P0):
    x_hat = x0  # Initial state estimate
    P = P0  # Initial error covariance matrix
    return x_hat, P

# Kalman filter prediction step
def kalman_filter_prediction(x_hat, P, A, B, u, Q):
    x_hat_minus = A @ x_hat + B @ u  # State prediction
    P_minus = A @ P @ A.T + Q  # Error covariance prediction
    return x_hat_minus, P_minus

# Kalman filter update step
def kalman_filter_update(x_hat_minus, P_minus, z, H, R):
    y = z - H @ x_hat_minus  # Innovation or measurement residual
    S = H @ P_minus @ H.T + R  # Innovation covariance
    K = P_minus @ H.T / S  # Kalman gain
    x_hat = x_hat_minus + K @ y  # Updated state estimate
    P = (np.eye(len(x_hat)) - K @ H) @ P_minus  # Updated error covariance
    return x_hat, P

# Main script
def run_kalman_filter(accel_data, dt):
    accel_time = accel_data[:, 0]
    accel_values = accel_data[:, 1:]

    # Create system matrices
    A, B, H, Q, R = create_system_matrices(dt)

    # Initial state estimate and error covariance matrix
    x0 = np.zeros((2, 1))  # Initial displacement and velocity estimate
    P0 = np.eye(2)

    x_hat, P = initialize_kalman_filter(x0, P0)

    # Store filtered displacement estimates
    filtered_displacement = []

    # Run the Kalman filter
    for i in range(len(accel_time)):
        accel_measurement = accel_values[i].reshape(1, 1)  # Accelerometer measurement

        # Control input using accelerometer measurement
        u = np.array([[accel_measurement]])

        # Prediction step
        x_hat_minus, P_minus = kalman_filter_prediction(x_hat, P, A, B, u, Q)

        # Update step using accelerometer measurement
        x_hat, P = kalman_filter_update(x_hat_minus, P_minus, accel_measurement, H, R)

        # Store the filtered displacement estimate
        filtered_displacement.append(x_hat[0, 0])

    return np.array(filtered_displacement)

# Calculate time step
dt = np.mean(np.diff(accel_time))

# Run the Kalman filter with accelerometer measurements
filtered_displacement = run_kalman_filter(accel_data, dt)

# Plot the filtered displacement
plt.figure(figsize=(20, 10))
plt.plot(accel_time, accel_values, label='Measured Displacement')
plt.plot(accel_time, filtered_displacement, label='Filtered Displacement')
plt.xlabel('Time')
plt.ylabel('Displacement')
plt.legend()
plt.title('Kalman Filter: Filtered Displacement')
plt.grid(True)
plt.savefig('accelerometer_plot_KALMAN_accel_only.png')

print("Plot saved as accelerometer_plot_KALMAN_accel_only.png")
