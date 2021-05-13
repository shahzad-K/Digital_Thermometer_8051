# Digital_Thermometer_8051

This project is designed to overcome drawbacks of a traditional laboratory thermometer which has limited measuring range and creates inconvenience to people to read analog readings. This is a Centigrade Temperature Device operating over a full −55°C to 150°C range.
It is immplemented using an 8051 microcontroller & a LM35 temperature sensor which is calibrated directly in Celsius unike other sensors calibrated in Kelvin. This LM35 converts surrounding temperature into analog voltage which is linearly proportional to the centigrade temperature and is provided to the MCP3204 ADC for digital conversion and is then displayed on LCD along with current date & time.
