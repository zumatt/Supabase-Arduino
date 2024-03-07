#include <SupabaseArduino.h>

#define SSID      "FabulousNet"
#define PASSWORD  "25jan2022"

#define URL       "https://mwezguicqnnqaoolfnjr.supabase.co"
#define APIKEY    "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im13ZXpndWljcW5ucWFvb2xmbmpyIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDk2MzA1MDUsImV4cCI6MjAyNTIwNjUwNX0.B9QVLOD3uP9MUPRqf64_VqSFmRV78FTRa89kdk3mGps"
#define TABLE     "Speed"

void setup() {
  // put your setup code here, to run once:
  Supabase supabase(SSID, PASSWORD, URL, APIKEY, TABLE);

  supabase.begin();
  supabase.read();

  delay(500);
  supabase.update(1, "velocity", 234.57);
  supabase.update(1, "distance", 12.48);

  delay(500);
  supabase.read();
}

void loop() {
  // put your main code here, to run repeatedly:

}
