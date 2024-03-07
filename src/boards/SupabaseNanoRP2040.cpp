#ifdef ARDUINO_NANO_RP2040_CONNECT

#include "SupabaseNanoRP2040.h"

Supabase::Supabase(const char* ssid, const char* pass, const char* serverAddress, const char* apiKey, const char* bearerToken)
: _ssid(ssid), _pass(pass), _serverAddress(serverAddress), _apiKey(apiKey), _bearerToken(bearerToken), _client(_wifiClient, serverAddress, 443) {
}

void Supabase::begin() {
    Serial.begin(9600);
    while (!Serial);

    WiFi.begin(_ssid, _pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected to WiFi");
}

void Supabase::read() {
    _client.beginRequest();
    _client.get("/rest/v1/Speed?select=*");

    _client.sendHeader("apikey", _apiKey);
    _client.sendHeader("Authorization", _bearerToken);
    _client.sendHeader("Content-Type", "application/json");
    _client.sendHeader("Prefer", "return=representation");
    _client.endRequest();

    int statusCode = _client.responseStatusCode();
    String response = _client.responseBody();

    Serial.print("Status code: ");
    Serial.println(statusCode);
    Serial.print("Response: ");
    Serial.println(response);
}

/*int Supabase::update(int rowId, const String& column, double value) {
    String path = "/rest/v1/Speed?id=eq." + String(rowId);
    String jsonData = "{\"" + column + "\":" + String(value) + "}";

    _client.beginRequest();
    
    _client.patch(path);

    _client.sendHeader("apikey", _apiKey);
    _client.sendHeader("Authorization", _bearerToken);
    _client.sendHeader("Content-Type", "application/json");
    _client.sendHeader("Prefer", "return=minimal");

    _client.beginBody();
    _client.print(jsonData);
    
    _client.endRequest();

    int statusCode = _client.responseStatusCode();
    _client.responseBody(); // Read the response body to clear the response (even if not used)

    return statusCode;
}*/
#endif