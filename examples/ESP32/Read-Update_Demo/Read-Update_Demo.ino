#include <SupabaseArduino.h>

#define SSID      "YOURSSID"
#define PASSWORD  "YOURPASSWORD"

#define URL       "https://databaseurl.supabase.co"
#define APIKEY    "APIKEY"
#define TABLE     "TABLENAME"

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
