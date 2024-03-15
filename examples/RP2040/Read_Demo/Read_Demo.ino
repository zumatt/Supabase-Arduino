#include <SupabaseArduino.h>

const char* SSID      = "YOURSSID";
const char* PASSWORD  = "YOURPASSWORD";

const char* URL       = "databaseurl.supabase.co";
const char* APIKEY    = "APIKEY";
const char* BEARER    = "Bearer APIKEY";

void setup() {
  // put your setup code here, to run once:
  Supabase supabase(SSID, PASSWORD, URL, APIKEY, BEARER);

  supabase.begin();
  supabase.read();
}

void loop() {
  // put your main code here, to run repeatedly:

}
