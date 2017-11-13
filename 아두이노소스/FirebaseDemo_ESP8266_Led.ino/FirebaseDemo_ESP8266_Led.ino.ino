//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "maker-ab6f2.firebaseio.com"
#define FIREBASE_AUTH "lQCOnHGm1tcU4Ay14I4X5x5bl2ToG9X0r6CVtuix"
#define WIFI_SSID "silla2g"
#define WIFI_PASSWORD "min12345"

int led = 13 ;
int speakerpin = 12; //스피커가 연결된 디지털핀 설정 

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

void loop() {
  // set value
  String n = Firebase.getString("led") ;
  Serial.println(n);
  // handle error
  if (Firebase.failed()) {
      Serial.print("read /led failed:");
      Serial.println(Firebase.error());  
      return;
  }

  if ( n == "0" ) {
      digitalWrite(led, LOW);
  }
  else {
     digitalWrite(led, HIGH);
     tone(speakerpin,500,500); 
  }
  delay(1000);
  
}
