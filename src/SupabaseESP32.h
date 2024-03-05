/*
   Supabase Library for ESP32

       Created by Matteo Subet - Last version 05 March 2024
    
    Created based on the library https://github.com/clock27-lab/unofficial-esp32-supabase
*/

#include <WiFi.h>
#include <HTTPClient.h>
class SUPABASE
{
public:
    SUPABASE(String url, String key, String tableName);
    ~SUPABASE();
    void begin();
    int update(int rowId, String column, double value);
    int insert(String column, double value);
    String read();
};