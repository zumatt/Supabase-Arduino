/*
   Supabase Library for ESP32

       Created by Matteo Subet - Last version 05 March 2024
    
    Created based on the library https://github.com/clock27-lab/unofficial-esp32-supabase
*/

#include <SupabaseESP32.h>

// Replace with your Supabase URL, table name and API key
#define supabaseUrl  "INSERT YOUR URL HERE"
#define tableRealtime  "INSERT YOUR TABLE NAME HERE"
#define supabaseApiKey  "INSERT YOUR API KEY HERE"

// Setup the Supabase client
SUPABASE supabaseClient(supabaseUrl, supabaseApiKey, tableRealtime);

// Replace with your network credentials
const char *ssid = "INSERT YOUR SSID HERE";  
const char *password = "INSERT YOUR PASSWORD HERE";

void setup()
{
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED){delay(500); Serial.print(".");}

    //Begin the connection to the database
    supabaseClient.begin();

    delay(2000);
    //Read the data from the table
    supabaseClient.read();

    delay(2000);
    //Update a specific row with a new value
        int rowId = 1;
        String column = "column_name";
        double value = 100.0;
    supabaseClient.update(rowId, column, value);

    delay(2000);
    //Insert a new row with a new value
        column = "column_name";
        value = 100.0;
    supabaseClient.insert(column, value);

    delay(2000);
    //Read the data again to see the changes
    supabaseClient.read();
}

void loop(){
    //Do nothing
}