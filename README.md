# Low-Cost Frequency-Based Lactometer for Milk Adulteration Detection

## 📌 Project Overview
This project presents a custom-built, low-cost electronic lactometer designed to detect milk adulteration (e.g., water, urea, melamine). Unlike traditional hydrometer-based lactometers that rely on density (which can be easily bypassed by chemical adulterants), this system uses a custom-fabricated capacitive sensor to measure changes in the dielectric properties and ionic conductivity of milk. 

The variation in capacitance is converted into a measurable digital frequency using a CD4093 oscillator and a **7476 JK Flip-Flop**, processed by an Arduino, and analyzed using Principal Component Analysis (PCA) in Python.

## 🛠️ Hardware & Components
* **Microcontroller:** Arduino UNO / Mega 2560
* **Sensor:** Custom-fabricated capacitive sensor (Graphite powder, Acrylic binder, Chloroform/Xylene, Copper tape)
* **Oscillator Circuit:** CD4093 (Quad NAND Schmitt Trigger)
* **Signal Conditioning:** IC 7476 (JK-Type Flip-Flop)
* **Display & Logging:** 16x2 I2C LCD Display, PLX-DAQ for real-time Excel data logging
* **Test Equipment:** Digital Storage Oscilloscope (DSO), Multimeter

## ⚙️ System Architecture
1. **Sensor Immersion:** The graphite sensor is dipped into the milk sample. Adulterants alter the ionic content and dielectric constant of the milk, changing the sensor's capacitance.
2. **Frequency Conversion:** The CD4093 NAND gate oscillator converts this variable capacitance into an analog oscillating signal.
3. **Signal Conditioning:** The IC 7476 JK Flip-Flop processes the noisy analog signal into a clean, stable digital square wave.
4. **Data Processing:** The Arduino reads the digital frequency via internal timers and outputs the data to the I2C LCD and PLX-DAQ.

## 💻 Software Stack
* **Embedded Software:** Arduino C++ (IDE)
* **Data Acquisition:** PLX-DAQ (Parallax Data Acquisition Tool) to Microsoft Excel
* **Machine Learning / Analysis:** Python (Scikit-Learn, Pandas, Matplotlib) for Principal Component Analysis (PCA)

## 📊 Results & Analysis
The system successfully discriminated between pure milk and various concentrations of adulteration (10% to 100% water, melamine, and urea). 
* **Frequency Shift:** As water concentration increases, the ionic mobility and dielectric constant decrease, leading to an increase in resistance and a measurable shift in output frequency.
* **PCA Clustering:** Principal Component Analysis applied to the sensor data confirmed that samples are chemically unique, with distinct spatial separation in the PCA component space.

## 🚀 How to Run the Project
1. **Arduino Setup:** Connect the Arduino to the custom circuit. Flash `lactometer_sensor.ino` using the Arduino IDE. 
2. **Data Logging:** Open PLX-DAQ in Excel, select the correct COM port, and connect. The Arduino will automatically stream frequency data with timestamps.
3. **PCA Analysis:** Ensure you have Python installed. Run `pip install pandas numpy scikit-learn matplotlib`. Update the CSV file path in `pca_analysis.py` and run the script to generate the discrimination plot.

## 📝 Reference
This project was developed as part of an M.Tech final thesis in Electronics and Communication Engineering.
