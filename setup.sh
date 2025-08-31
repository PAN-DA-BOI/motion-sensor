#!/bin/bash
rm -rf "motion sensor"
mkdir -p /opt/motion_sensor
mv "raspberry pi/code/main.py" /opt/motion_sensor/

# make and start the service
sudo bash -c 'cat > /etc/systemd/system/motion_sensor.service' << 'EOF'
[Unit]
Description=Motion Sensor Service
After=network.target

[Service]
User=pi
WorkingDirectory=/opt/motion_sensor
ExecStart=/usr/bin/python3 /opt/motion_sensor/main.py
Restart=always
RestartSec=10

[Install]
WantedBy=multi-user.target
EOF

sudo systemctl daemon-reload
sudo systemctl enable motion_sensor.service
#enable so it starts up and connects
sudo systemctl start motion_sensor.service