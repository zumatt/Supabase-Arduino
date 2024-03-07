#include <SupabaseArduino.h>

const char* SSID      = "FabulousNet";
const char* PASSWORD  = "25jan2022";

const char* URL       = "mwezguicqnnqaoolfnjr.supabase.co";
const char* APIKEY    = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im13ZXpndWljcW5ucWFvb2xmbmpyIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDk2MzA1MDUsImV4cCI6MjAyNTIwNjUwNX0.B9QVLOD3uP9MUPRqf64_VqSFmRV78FTRa89kdk3mGps";
const char* BEARER    = "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im13ZXpndWljcW5ucWFvb2xmbmpyIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDk2MzA1MDUsImV4cCI6MjAyNTIwNjUwNX0.B9QVLOD3uP9MUPRqf64_VqSFmRV78FTRa89kdk3mGps";

void setup() {
  // put your setup code here, to run once:
  Supabase supabase(SSID, PASSWORD, URL, APIKEY, BEARER);

  supabase.begin();
  supabase.read();
}

void loop() {
  // put your main code here, to run repeatedly:

}
