import processing.serial.*;



/* Processing code for this example

 // Graphing sketch


// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 24 Nov 2015
// by Tom Igoe
// This example code is in the public domain.

import processing.serial.*;
*/

 PFont f;
 PFont F;
Serial myPort;        // The serial port
int[] xPos = {1, 1};         // horizontal position of the graph

int[] xAnt = {40, 40};         // horizontal position of the graph
int[] yAnt = {height, height};
float[] razao = {1, 1};
int shift=40;            // set trace origin

int grau = 0;
float[] inByte = {0,0};
int cor = 0;

void setup () {
  // set the window size:
   f = createFont("Arial",12,true);
   F = createFont("Arial",24,true);
   size(1000, 600);  

  // List all the available serial ports
  // if using Processing 2.1 or later, use Serial.printArray()
  //println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
    myPort = new Serial(this, Serial.list()[0], 1200, 'E', 8, 1.0); 

  // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n'); 


  strokeWeight(2);
  // set inital background:
   background(0); 
   xPos[0] = xPos[1] = 40;
   xAnt[0] = xAnt[1] = 40;         // horizontal position of the graph
   desenhaMoldura("");
}
void draw () {
     // draw the line:
     stroke(0, 255, 0);   //(127, 34, 255);//(127, 34, 255);
     strokeWeight(2);
     //if(++inByte>500)inByte=0;
     //line(xPos, height, xPos, height - inByte);
    
    
      
       xPos[0] =xPos[0] + 1;
       if (xPos[0] >= width)         //  go back to begining
       {
         xPos[0] = 40;
         background(0); 
         xAnt[0] = 40;         // horizontal position of the graph
         desenhaMoldura("");
       } else {
        // increment the horizontal position:
        xPos[0]++;
      }
      
      xPos[1] =xPos[1] + 1;
       if (xPos[1] >= width)         //  go back to begining
       {
         xPos[1] = 40;
         background(0); 
         xAnt[1] = 40;         // horizontal position of the graph
         desenhaMoldura("");
       } else {
        // increment the horizontal position:
        xPos[1]++;
      }
     
       razao[0] = (height-inByte[0]-(shift+2))-(yAnt[0]+1);
       razao[1] = (height-inByte[1]-(shift+2))-(yAnt[1]+1);
     
       if(razao[0] < 10)line(xAnt[0], yAnt[0], xPos[0], height - inByte[0] - (shift+2)); 
       if(razao[1] < 10)line(xAnt[1], yAnt[1], xPos[1], height - inByte[1] - (shift+2)); 
       //else line(xAnt, yAnt, xPos, yAnt);
       //println("x " + xPos);
       //println("y " + (height-inByte-shift));
       ///println("valor " + inByte);
       xAnt[0] = xPos[0]; 
       yAnt[0] = (int)(height-inByte[0]-(shift+2));
       
       xAnt[1] = xPos[1]; 
       yAnt[1] = (int)(height-inByte[1]-(shift+2));
   
  
}


void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
  //println(inString);
  
  boolean isA = inString.contains(" A");
  boolean isB = inString.contains(" B");
  
  if (inString != null && isA) {
    // trim off any whitespace:
    inString = trim(inString.replace(" A", ""));
    // convert to an int and map to the screen height:
    inByte[0] = float(inString);
    println(inByte);
    inByte[0] = map(inByte[0], 0, 1023, 0, height-100);
    println(inByte);    
  }
  if (inString != null && isB) {
    // trim off any whitespace:
    inString = trim(inString.replace(" B", ""));
    // convert to an int and map to the screen height:
    inByte[1] = float(inString);
    println(inByte);
    inByte[1] = map(inByte[1], 0, 1023, 0, height-100);
    println(inByte);    
  }
}



void desenhaMoldura(String inString){
        stroke(175);  
        fill(0, 102, 153);
        stroke(175);                       // temperature line

        line(40,height-40,40,0);
        
        stroke(175);                          // Time line
        line(40,height-40,width,height-40);
              
        textFont(F);       
        fill(255);
       
        textAlign(CENTER);
        text("Gráfico de Tensão - Gabriela e Vitor", width/2,40); 
      
        textAlign(LEFT);
        text("mV",2,40);                         
        
        textAlign(CENTER);
        text("t (s)",width/2,580);    
       /*
       fill(240);

        
        textAlign(RIGHT);
        text(inString,500,200);
       
        textAlign(RIGHT);
        text(" Graus Celsius",560,230);
        
        
        fill(0,0,255);
       // int j;
        stroke(255); 
        
        for(int j=500;j>430;j--)
        {
          line(j,height-398,j,height-425);
        }
      
        stroke(0,0,0);
        textAlign(RIGHT);
        text(inString,495,200); 
        */
        
       fill(240);
       textFont(f); 
       
       for (int y = 56; y < height-50; y += 50)
         for (int x = 38; x < width; x += 6) {
           stroke(-(x+y>>1 & 1));
           line(x, y, x+5, y);
           //set(x, y, -(x+y>>1 & 1));
        }

        textAlign(RIGHT);                 // 100 degree
        text("5000 -",40,60);
        
         textAlign(RIGHT);                // 90 degree
        text("4500 -",40,110);
        
         textAlign(RIGHT);                // 80 degree
        text("4000 -",40,160);
        
         textAlign(RIGHT);                 // 70 degree
        text("3500 -",40,210);
        
         textAlign(RIGHT);                // 60 degree
        text("3000 -",40,260);
        
         textAlign(RIGHT);               // 50 degree
        text("2500 -",40,310);
        
         textAlign(RIGHT);                 // 40 degree
        text("2000 -",40,360);
        
         textAlign(RIGHT);
        text("1500 -",40,410);
        
         textAlign(RIGHT);
        text("1000 -",40,460);
        
         textAlign(RIGHT);
        text("500 -",40,510);
        
        textAlign(RIGHT);
        text("0 -",40,560);
       
        
       // textAlign(RIGHT);
       // text("0 -",40,360);
 
}
