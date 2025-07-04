==================================================
         Spinalysis_Application_Demo (Trial Version)
==================================================

Overview:
---------
This application provides a simulated demonstration of how our sensor-based gait analysis system works. This version is designed for client preview purposes and uses *simulated data* instead of real-time sensor input. The full version will interface with actual foot pressure sensors.

Application Flow:
-----------------
1. **Doctor Login / Registration:**
   - If new, create a doctor account.
   - If already registered, simply log in.

2. **Patient Management:**
   - Once logged in, you can create and register a patient under the doctor's account.
   - The dashboard will only show the patients registered under the currently logged-in doctor.

3. **Walk Test Interface:**
   - Set a custom time limit (in seconds or minutes).
   - Conduct three types of walk tests:
     - **Heel Walk**
     - **Forefeet Walk**
     - **Normal Walk**
   - During each test, simulated sensor data is streamed and visualized in real time.

4. **Data Storage Format:**
   - All test data is saved in the following folder structure:
     DoctorName/
         └── PatientName/
               └── test_data.xlsx

5. **Analysis & Visualization:**
   - The app calculates the average pressure for three regions of the foot:
     - **Forefoot** (Sensors 1, 2, 3)
     - **Arch**     (Sensor 4)
     - **Heel**     (Sensors 5, 6)
   - A bar graph is generated with:
     - X-axis: Walk types (Heel, Normal, Forefeet)
     - Y-axis: Average pressure applied per region

6. **Doctor’s Report Generation:**
   - After the tests, a summary report is generated.
   - The report includes analyzed data and visualizations.
   - The final report can be downloaded as a **PDF file**.

Important Notes:
----------------
- This is a **TRIAL version** and only demonstrates the functionality using **simulated data**.
- The final version will integrate with live sensor hardware for real-time data acquisition.
- For feedback, collaboration, or customization inquiries, please contact us.

Thank you for previewing our application!

- [Your Name / Company Name]
- [Contact Information or Support Email]
