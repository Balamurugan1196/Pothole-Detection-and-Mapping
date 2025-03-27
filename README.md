📌 Pothole Detection and Mapping System
🚀 An IoT & AI-powered approach to real-time pothole detection and visualization
📖 Overview
This project focuses on detecting potholes using an ESP32-CAM with an Edge Impulse ML model and mapping their locations using GPS and MongoDB.

The ESP32-CAM captures pothole images and processes them using a deployed ML model.

A NodeMCU ESP8266 fetches the latitude and longitude from a GPS module.

The ESP32-CAM sends the pothole image and GPS coordinates to a Flask backend via a POST request.

The backend stores the data in MongoDB and visualizes the pothole locations using the TomTom API on a web interface.

🛠 Tech Stack
Hardware: ESP32-CAM, NodeMCU ESP8266, GPS Module

Machine Learning: Edge Impulse (Deployed ML Model)

Backend: Flask, MongoDB (Atlas)

Frontend: HTML, CSS, JavaScript (for map visualization)

API Integration: TomTom API (for mapping potholes)

🔗 System Architecture

🎯 Working Process
Pothole Detection:

The ESP32-CAM captures an image and processes it using an Edge Impulse ML model to identify potholes.

GPS Coordinates Retrieval:

The NodeMCU ESP8266 fetches the GPS location of the pothole using a connected GPS module.

Data Transmission:

The ESP32-CAM sends the image & GPS coordinates to the Flask backend via a POST request.

Backend Processing:

The Flask server stores the data in MongoDB Atlas.

Visualization:

The TomTom API plots the pothole locations on an interactive map.

📷 Project Implementation

🎥 Live Demonstration

📌 Click on the image above to watch the demo video

🛠 Setup Instructions
1️⃣ Clone the Repository
bash
Copy
Edit
git clone https://github.com/Balamurugan1196/Pothole-Detection-and-Mapping.git
cd Pothole-Detection-and-Mapping
2️⃣ Install Dependencies
bash
Copy
Edit
pip install -r requirements.txt
3️⃣ Run the Flask Server
bash
Copy
Edit
python app.py
4️⃣ Access the Web Interface
Open http://127.0.0.1:5000/ in your browser.

🗺 Future Enhancements
✔️ Integrate real-time notifications for authorities
✔️ Improve ML model accuracy with a larger dataset
✔️ Develop a mobile app for better accessibility

💡 Contributors
Balamurugan - Developer & Researcher

Open for Contributions! Feel free to fork this repo & raise a PR. 🚀

