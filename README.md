# 🎮 Joystick Stepper Motor Controller

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Project Views](https://img.shields.io/badge/Views-3K%2B-orange?style=for-the-badge)

*A fun and interactive Arduino project that brings motor control to your fingertips!*

[🎥 Watch the TikTok Demo](https://vm.tiktok.com/ZMDdMSGhC/) • [🖥️ View Code](stepper_motor_and_joystick.ino)

---

## ✨ What's This Project About?

Ever wanted to control a motor with the precision of a joystick? This project does exactly that! Using a simple analog joystick, you can:

- **🔄 Rotate** a stepper motor left or right
- **⚡ Adjust speed** dynamically
- **🎯 Experience smooth control** with a built-in dead zone
- **💡 Get visual feedback** from LED indicators

Perfect for beginners learning Arduino, robotics enthusiasts, or anyone who loves hands-on electronics!

---

## 🛠️ What You'll Need

### Hardware Components
| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno/Nano | 1 | Any Arduino-compatible board works |
| 28BYJ-48 Stepper Motor | 1 | Comes with ULN2003 driver board |
| Analog Joystick Module | 1 | With X, Y, and push-button (SW) |
| Green LED | 1 | Shows "Motor ENABLED" |
| Red LED | 1 | Shows "Motor DISABLED" |
| 220Ω Resistors | 2 | For current limiting on LEDs |
| Breadboard | 1 | For easy prototyping |
| Jumper Wires | ~15 | Male-to-male recommended |

### Software
- [Arduino IDE](https://www.arduino.cc/en/software) (1.8.x or 2.0)
- Basic understanding of uploading sketches

---

## 🔌 Connection Guide

Here's how to wire everything up:

| Arduino Pin | Connects To | Purpose |
|-------------|-------------|---------|
| **A0** | Joystick X Pin | Horizontal position reading |
| **A1** | Joystick Y Pin | Vertical position reading |
| **2** | Joystick SW Pin | Push-button input |
| **3** | ULN2003 IN1 | Stepper motor control |
| **4** | ULN2003 IN2 | Stepper motor control |
| **5** | ULN2003 IN3 | Stepper motor control |
| **6** | ULN2003 IN4 | Stepper motor control |
| **7** | Green LED (+) | Motor status: ON |
| **8** | Red LED (+) | Motor status: OFF |
| **GND** | LEDs (-), Joystick GND | Common ground |
| **5V** | Joystick VCC, ULN2003 VCC | Power supply |

> 💡 **Tip**: Use different colored wires for power (red), ground (black), and signals (other colors) to avoid confusion!

---

## 🚀 Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/VickyAshford/joystick-stepper-controller.git
cd joystick-stepper-controller
```

### 2. Open in Arduino IDE
- Open `stepper_motor_and_joystick.ino` in Arduino IDE
- Select your board (Tools → Board → Arduino Uno)
- Select the correct port (Tools → Port)

### 3. Upload & Play!
- Click the upload button (→)
- Wait for "Done uploading"
- Watch the LEDs light up!
- Press the joystick button to enable motor control

### 🎮 Controls Explained
| Action | Result |
|--------|---------|
| **Press Joystick Button** | Toggles motor control ON/OFF |
| **Move Joystick Left/Right** | Rotates motor clockwise/counter-clockwise |
| **Move Joystick Up/Down** | Increases/decreases motor speed |
| **Center Joystick** | Motor stops (dead zone prevents jitter) |

---

## 📁 Project Structure

```
joystick-stepper-controller/
├── stepper_motor_and_joystick.ino  # Main Arduino sketch
├── README.md                        # This documentation
└── LICENSE                          # MIT License file
```

---

## 🔧 How It Works (Technical Bits)

### 🎯 Core Logic
- **Joystick X-axis** → Determines direction and rotation amount
- **Joystick Y-axis** → Maps to motor speed (1-20 RPM)
- **Dead Zone** (±50 units) → Prevents unintended movement at center
- **Button Debouncing** → Reliable toggle functionality

### 💾 Code Highlights
```cpp
// Speed control via Y axis
int speed = map(posY, 0, 1023, 1, 20);
myStepper.setSpeed(speed);

// Direction control via X axis (with dead zone)
if (abs(deltaX) > 50) {
  int steps = map(deltaX, -512, 512, -50, 50); 
  myStepper.step(steps);
}
```

---

## 🚀 Next Steps & Ideas

Want to take this further? Try these modifications:

- **Add LCD Display** → Show speed and direction values
- **Implement Acceleration** → Smoother speed transitions
- **Add Serial Monitoring** → Debug values on computer
- **Create Presets** → Save favorite speed/direction combos
- **Build an Enclosure** → Make it a permanent desktop gadget!

---

## 📞 Let's Connect!

Have questions, suggestions, or just want to chat about electronics? Reach out!

📧 **Email**: [victoria.ashford54@gmail.com](mailto:victoria.ashford54@gmail.com)  
📱 **WhatsApp**: [+380-99-792-43-19](https://wa.me/380997924319)  
💬 **Telegram**: [@Victory_Overflow](https://t.me/Victory_Overflow)  
🐙 **GitHub**: [VickyAshford](https://github.com/VickyAshford)

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for full details.

---

## 🙌 Acknowledgments

- Thanks to the amazing Arduino community for endless inspiration
- Special thanks to everyone who watched, liked, and shared the TikTok video!
- Shoutout to all open-source contributors who make learning fun

---

### ⭐ **If you like this project, please give it a star!** ⭐

*It helps others discover it and motivates me to create more cool stuff!*

[⭐ Star This Repository](https://github.com/VickyAshford/joystick-stepper-controller)
