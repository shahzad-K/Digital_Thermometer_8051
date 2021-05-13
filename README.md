# Digital_Thermometer_8051

This project is designed to overcome the drawbacks of a traditional laboratory thermometer which has a limited measuring range and creates inconvenience to people to read analog readings. This is a Centigrade Temperature Device operating over a full −55°C to 150°C range.

It is implemented using an 8051 microcontroller & a LM35 temperature sensor which is calibrated directly in Celsius unlike other sensors calibrated in Kelvin which requires subtracting a large constant voltage from the output to obtain convenient Centigrade scaling.
This LM35 converts surrounding temperature into analog voltage which is linearly proportional to the centigrade temperature and is provided to the MCP3204 ADC for digital conversion and is then displayed on LCD along with current date & time.

Here are the devices and sensors used viz., 
1. 8051 Microcontroller (AT89c52)
2. RTC (DS1307)
3. Temperature sensor (LM35)
4. ADC (MCP3204)
5. LCD (20*4)
