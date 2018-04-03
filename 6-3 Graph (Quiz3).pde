import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;
  float threshold=150.0;

  void setup () {
    size(400, 300);      // set the window size:

    // List all the available serial ports
    // if using Processing 2.1 or later, use Serial.printArray()
    println(Serial.list());


    myPort = new Serial(this,"COM3", 9600);

    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');
    background(0);  //set the black backgroud
  }

  void draw () {
    if(inByte >= threshold)
    {
      stroke(255, 0, 0);  //set the color of pen: red
    }
    else
    {
      stroke(127, 34, 255);  //set the color of pen: purple
    }
    line(xPos, height, xPos, height - inByte);  // draw the line
    

    // at the edge of the screen, go back to the beginning:
    if (xPos >= width)
    {
      xPos = 0;
      background(0);  //reflesh the screen
    }
    else
    {
      xPos++;
    }
  }

  void serialEvent (Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');

    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      // convert to an int and map to the screen height:
      inByte = float(inString);
      println(inByte);
      inByte = map(inByte, 0, 1023, 0, height);
    }
  }
