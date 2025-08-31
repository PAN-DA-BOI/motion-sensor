import socket
import pygame
import time

# pygame for sound (theres prob a better way)
pygame.mixer.init()
alert_sound = pygame.mixer.Sound("alert.wav")  # Replace actual sound file

# UDP socket
udp_ip = "1.1.1.1"
udp_port = 4210

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((udp_ip, udp_port))

print(f"Listening for UDP packets on {udp_ip}:{udp_port}...")

while True:
    data, addr = sock.recvfrom(1024) #buffer sizing
    message = data.decode('utf-8').strip()
    if message == "MOTION_DETECTED":
        print(f"Motion detected from {addr}! Playing alert sound...")
        alert_sound.play()
        time.sleep(2)  # Debounce delay prob needs to be shortened
"""
things that still need to be added
-TTS saying which motion detector went off
-connection lost
-.96in oled I2C connection
-obviusly the background crypto mining scheme
"""