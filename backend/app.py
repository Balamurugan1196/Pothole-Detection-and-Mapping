from flask import Flask, render_template, jsonify, request
from pymongo import MongoClient
import urllib.parse
import certifi  # Ensures secure connection to MongoDB Atlas

app = Flask(__name__)

# 🔹 MongoDB Connection
db_username = "admin"  # Change to your actual username
db_password = urllib.parse.quote_plus("Bala@9952")  # URL encode special characters
mongo_uri = f"mongodb+srv://{db_username}:{db_password}@hackathondb.hwg5w.mongodb.net/PotholeDB?retryWrites=true&w=majority&appName=hackathondb"

client = MongoClient(mongo_uri, tlsCAFile=certifi.where())  # Use `certifi` for SSL verification
db = client["PotholeDB"]  # Ensure the database name is correct
collection = db["potholecollection"]  # Ensure collection name is correct

# 🔹 TomTom API Key
TOMTOM_API_KEY = "bPOvrz1JAgbzJf6miYPGHa1gbAAHhwDn"

@app.route("/")
def index():
    locations = list(collection.find({}, {"_id": 0, "latitude": 1, "longitude": 1}))  # Fetch lat/lng only
    return render_template("map.html", locations=locations, tomtom_api_key=TOMTOM_API_KEY)

@app.route("/api/store_pothole", methods=["POST"])
def store_pothole():
    """Store a new pothole location."""
    data = request.get_json()
    
    if not data or "latitude" not in data or "longitude" not in data:
        return jsonify({"error": "Latitude and Longitude are required"}), 400

    # Insert into MongoDB
    collection.insert_one({"latitude": data["latitude"], "longitude": data["longitude"]})

    return jsonify({"message": "Pothole location stored successfully"}), 201

@app.route("/api/locations")
def get_locations():
    locations = list(collection.find({}, {"_id": 0, "latitude": 1, "longitude": 1}))
    return jsonify(locations)

if __name__ == "__main__":
    app.run(debug=True)
