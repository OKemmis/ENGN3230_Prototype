# ENGN3230_Prototype
_SeatMap product prototype for ENGN3230_

<img src=Circuit_Diagram.png width=400 height=400 />

The aim of this prototype is to provide a proof-of-concept for a system which can sense and record the number of passengers who use a particular seat on a public transit vehicle (e.g. bus or train carriage). This is a potentially useful product for controlling passenger dispersion within public transport vehicles and thus limiting the spread of infectious diseases, such as COVID-19 (which is contractible through contact with infected surfaces). The physical prototype makes use of a force sensitive resistor (FSR), an arduino UNO board, cathode LED, and piezo buzzer. 

Initially, the cathode is set to green, indicating that passengers are permitted to use the seat. The FSR sensor unit, mounted on the seat cushion, senses and records the number of times an occupant uses the seat. Passengers sitting and standing are recognised events. When a threshold for the number of discrete seat occupants is met, the cathode is set to red and further attempts to sit will elicit an audible alarm to sound (via the piezo buzzer). This threshold for seat occupants can be set in software. Further attempts to sit will also increment the seat counter variable, enabling the public transport service provider access to this potentially useful metric. 

[link to video of working prototype (YouTube)](https://youtu.be/z3oedwZhUuU)
