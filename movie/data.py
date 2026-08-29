import cv2
import serial
import time
import numpy as np

# Adjust COM port for your system (e.g., 'COM3' on Windows, '/dev/ttyUSB0' or '/dev/ttyACM0' on Linux/Mac)
SERIAL_PORT = 'COM12'
BAUD_RATE = 115200
VIDEO_PATH = 'vid1.mp4'

# ASCII density ramp: Darkest to Brightest
ASCII_CHARS = " .:-=+*#%@"
NUM_LEVELS = len(ASCII_CHARS)

# Initialize Serial Connection
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2)
time.sleep(2)  # Allow Arduino to reset after establishing connection

cap = cv2.VideoCapture(VIDEO_PATH)

if not cap.isOpened():
    print(f"Error: Could not open {VIDEO_PATH}")
    exit()

print("Streaming started! Press 'q' in the preview window to exit.")

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # 1. Convert to grayscale and downscale to 16 cols x 2 rows
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    small = cv2.resize(gray, (16, 2), interpolation=cv2.INTER_AREA)

    # 2. Map pixel brightness (0-255) to character indices (0-9)
    indices = (small / 256.0 * NUM_LEVELS).astype(int)
    ascii_frame = "".join(ASCII_CHARS[idx] for idx in indices.flatten())

    # 3. Send the 32 characters over USB
    ser.write(ascii_frame.encode('ascii'))

    # 4. Wait for Arduino confirmation byte ('K') to prevent buffer lag
    ser.read(1)

    # Optional local preview window on your laptop
    preview = cv2.resize(small, (320, 40), interpolation=cv2.INTER_NEAREST)
    cv2.imshow("LCD Preview", preview)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
ser.close()
print("Streaming ended.")