int redPin = 3;
int greenPin = 4;
int bluePin = 5;

int s2Pin = 7;
int s3Pin = 8;
int outPin = 9;



int redColorStrength;
int greenColorStrength;
int blueColorStrength;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(s2Pin, OUTPUT);
  pinMode(s3Pin, OUTPUT);
  pinMode(outPin, INPUT);
}

void loop() {
  //read red component
  //set S2 and S3 to low
  redColorStrength = getColorStrength(LOW,LOW);
  
  //read green component
  //set S2 and S3 to HIGH
  greenColorStrength = getColorStrength(HIGH, HIGH);

  //blue green component
  //set S2 to LOW and S3 to HIGH
  blueColorStrength = getColorStrength(LOW, HIGH);

  showDetectedColor(redColorStrength,  greenColorStrength,  blueColorStrength);

  delay(50);

}

int getColorStrength(uint8_t s2Mode, uint8_t s3Mode) {
  digitalWrite(s2Pin, s2Mode);
  digitalWrite(s3Pin, s3Mode);

  delay(20);

  // Average several measurements to reduce noise
  const int sampleCount = 5;

  unsigned long pulseSum = 0;
  int validSamples = 0;

  for (int i = 0; i < sampleCount; i++) {
    unsigned long pulseWidth = pulseIn(outPin, LOW, 100000);

    if (pulseWidth > 0) {
      pulseSum += pulseWidth;
      validSamples++;
    }
  }

  if (validSamples == 0) {
    return 0;
  }

  unsigned long averagePulse = pulseSum / validSamples;

  /*
    TCS3200:
    smaller pulse width = higher frequency = stronger color.

    Convert it so that:
    stronger color = larger number.
    
    The exact scale is unimportant because showDetectedColor()
    normalizes all three channels against each other.
  */
  unsigned long strength = 100000UL / averagePulse;

  return min(strength, 32767UL);
}


void showDetectedColor(int redRaw, int greenRaw, int blueRaw) {
  const float secondaryThreshold = 0.75; // the second-strongest component is included only when it is at least 75% as strong as the dominant component

  int redOut = 0;
  int greenOut = 0;
  int blueOut = 0;

  if (redRaw >= greenRaw && redRaw >= blueRaw) {
    redOut = 255;

    if (greenRaw >= blueRaw) {
      // RGB
      if (greenRaw >= redRaw * secondaryThreshold) {
        greenOut = map(greenRaw, 0, redRaw, 0, 180);
      }
    } else {
      // RBG
      if (blueRaw >= redRaw * secondaryThreshold) {
        blueOut = map(blueRaw, 0, redRaw, 0, 180);
      }
    }
  }
  else if (greenRaw >= redRaw && greenRaw >= blueRaw) {
    greenOut = 255;

    if (redRaw >= blueRaw) {
      // GRB
      if (redRaw >= greenRaw * secondaryThreshold) {
        redOut = map(redRaw, 0, greenRaw, 0, 180);
      }
    } else {
      // GBR
      if (blueRaw >= greenRaw * secondaryThreshold) {
        blueOut = map(blueRaw, 0, greenRaw, 0, 180);
      }
    }
  }
  else {
    blueOut = 255;

    if (redRaw >= greenRaw) {
      // BRG
      if (redRaw >= blueRaw * secondaryThreshold) {
        redOut = map(redRaw, 0, blueRaw, 0, 180);
      }
    } else {
      // BGR
      if (greenRaw >= blueRaw * secondaryThreshold) {
        greenOut = map(greenRaw, 0, blueRaw, 0, 180);
      }
    }
  }

  setRgb(redOut, greenOut, blueOut);
}


void setRgb(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
