String receivedCommand = "";  // Variable to store the received command
boolean newData = false;

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Enactive Torch Ready");
}

void loop() {
  receiveCommand();

  if (newData) {
    Serial.print("Received command: ");
    Serial.println(receivedCommand);

    // Handle various commands received from Processing
    if (receivedCommand.startsWith("off")) {
      Serial.println("Torch turned OFF");
    } 
    else if (receivedCommand.startsWith("laser_on")) {
      Serial.println("Laser turned ON");
    } 
    else if (receivedCommand.startsWith("laser_off")) {
      Serial.println("Laser turned OFF");
    } 
    else if (receivedCommand.startsWith("auto")) {
      Serial.println("Torch set to AUTO mode");
    } 
    else if (receivedCommand.startsWith("no_data")) {
      Serial.println("No Data mode activated");
    } 
    else if (receivedCommand.startsWith("binary")) {
      String binaryValue = receivedCommand.substring(6);
      Serial.print("Binary mode activated with distance: ");
      Serial.println(binaryValue);
    } 
    else if (receivedCommand.startsWith("manual")) {
      String manualValue = receivedCommand.substring(6);
      Serial.print("Manual mode activated with distance: ");
      Serial.println(manualValue);
    } 
    else if (receivedCommand.startsWith("sensor")) {
      String sensorValue = receivedCommand.substring(6);
      Serial.print("Sensor mode activated with distance: ");
      Serial.println(sensorValue);
    } 
    else if (receivedCommand.startsWith("energy")) {
      String energyValue = receivedCommand.substring(6);
      Serial.print("Energy level set to: ");
      Serial.println(energyValue);
    } 
    else if (receivedCommand.startsWith("data")) {
      String dataValue = receivedCommand.substring(4);
      Serial.print("Data mode activated with file name: ");
      Serial.println(dataValue);
    } 
    else if (receivedCommand.startsWith("dump")) {
      String dumpValue = receivedCommand.substring(4);
      Serial.print("Dump mode activated with file name: ");
      Serial.println(dumpValue);
    } 
    else {
      Serial.println("Unknown command");
    }

    // Clear received command
    receivedCommand = "";
    newData = false;
  }
}

// Function to receive and store commands from the serial port
void receiveCommand() {
  while (Serial.available() > 0 && newData == false) {
    char receivedChar = Serial.read();
    if (receivedChar == '\n') {
      newData = true;
    } else {
      receivedCommand += receivedChar;
    }
  }
}
