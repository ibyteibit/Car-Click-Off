# Car Click-Off - *Personal Project (created for High School Computer Club)*
![car_game_labeled_pic](https://github.com/ibyteibit/Car-Click-Off/blob/main/pics/CarGame.png)


## Description
- A two-player rapid-fire clicking game featuring a car that rides along a wooden track
- The car is equipped with two opposing fans, each controlled by a button; the faster the button is clicked, the faster the fan spins
- When the car reaches one end of the track, the game stops and plays a victory fanfare with a flashing LED
- The game was displayed at our high school’s club fair and later donated to our Computer Club

## Materials & Tools
### Mechanical:
- Wood planks
- Kebab skewers
- Screws/nails
- Pinewood Derby car
- Gorilla glue
- Masking tape
### Electrical:
- Arduino
- Breadboard
- L298 Motor driver
- Wire (jumper & spool)
- Resistors
- Pushbuttons
- IR LEDs & phototransistors
- LEDs & Buzzers
- Heat-shrink tubing
- Batteries & battery holders
### Tools:
- Arduino IDE
- Miter saw
- Drill
- Soldering iron
- Wire strippers

## Methodology
- Cut, drilled, and assembled an elevated 2ft wooden track and car with openings for the fan motor wires
- Linked button click rate and fan speed using millis() to determine click rate, and PWM and an L298 motor driver to control motor speed
- Engineered IR tripwires at both ends of the track to trigger the winner’s LED and buzzer
- Taught myself to use a miter saw for the woodwork, and coordinated two friends who wrote the C++ code

![soldering](https://github.com/ibyteibit/Car-Click-Off/blob/main/pics/Soldering.jpg)
