#ifdef ARDUINO_NANO_ESP32

#include "SupabaseESP32.h"

Supabase::Supabase(String ssid, String pass, String serverAddress, String apiKey, String tableName)
: _ssid(ssid), _pass(pass), _serverAddress(serverAddress + "/rest/v1/" + tableName), _apiKey(apiKey), _bearer("Bearer " + apiKey){
}

void Supabase::begin()
{
    Serial.begin(9600);
    while (!Serial);

    WiFi.begin(_ssid, _pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected to WiFi");
}

int Supabase::update(int rowId, String column, double value)
{
    String url = _serverAddress + "?id=eq." + String(rowId);
    _http.begin(url.c_str());
    _http.addHeader("apikey", _apiKey);
    _http.addHeader("Authorization", _bearer);
    _http.addHeader("Content-Type", "application/json");
    _http.addHeader("Prefer", "return=minimal");
    String supabase_data = "{\"" + column + "\":" + String(value) + "}";
    int httpResponseCode = _http.PATCH(supabase_data);
    _http.end();
    return httpResponseCode;
}

int Supabase::insert(String column, double value)
{
    _http.begin(_serverAddress.c_str());
    _http.addHeader("apikey", _apiKey);
    _http.addHeader("Authorization", _bearer);
    _http.addHeader("Content-Type", "application/json");
    _http.addHeader("Prefer", "return=minimal");
    String supabase_data = "{\"" + column + "\":" + String(value) + "}";
    int httpResponseCode = _http.POST(supabase_data);
    _http.end();
    return httpResponseCode;
}


String Supabase::read()
{
    String url = _serverAddress + "?select=*";
    _http.begin(url.c_str());
    _http.addHeader("apikey", _apiKey);
    int httpResponseCode = _http.GET();
    String payload = _http.getString();
    
    Serial.print("HTTP GET: ");
    Serial.println(httpResponseCode);
    Serial.print("HTTP Payload: ");
    Serial.println(payload);
    
    _http.end();
    return payload;
}

#endif