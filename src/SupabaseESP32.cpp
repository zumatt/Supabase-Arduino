#include "SupabaseESP32.h"

// #if ESP32
HTTPClient http;
// #endif

String supabase_url;
String supabase_key;
String supabase_bearer;
String supabase_table;

SUPABASE::SUPABASE(String url, String key, String tableName)
{
    supabase_table = tableName;
    supabase_url = url + "/" + supabase_table + "/rest/v1";
    supabase_key = key;
    supabase_bearer = "Bearer " + key;
}

SUPABASE::~SUPABASE() {}

void SUPABASE::begin()
{
    Serial.println(supabase_url);
    http.begin(supabase_url.c_str());
    http.addHeader("apikey", supabase_key);
    http.addHeader("Authorization", supabase_bearer);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Prefer", "return=representation");
}

int SUPABASE::update(int rowId, String column, double value)
{
    String url = supabase_url + "?id=eq." + String(rowId);
    http.begin(url.c_str());
    http.addHeader("apikey", supabase_key);
    http.addHeader("Authorization", supabase_bearer);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Prefer", "return=minimal");
    String supabase_data = "{\"" + column + "\":" + String(value) + "}";
    int httpResponseCode = http.PATCH(supabase_data);
    http.end();
    return httpResponseCode;
}

int SUPABASE::insert(String column, double value)
{
    http.begin(supabase_url.c_str());
    http.addHeader("apikey", supabase_key);
    http.addHeader("Authorization", supabase_bearer);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Prefer", "return=minimal");
    String supabase_data = "{\"" + column + "\":" + String(value) + "}";
    int httpResponseCode = http.POST(supabase_data);
    http.end();
    return httpResponseCode;
}


String SUPABASE::read()
{
    String url = supabase_url + "?select=*";
    http.begin(url.c_str());
    http.addHeader("apikey", supabase_key);
    int httpResponseCode = http.GET();
    String payload = http.getString();
    
    Serial.println("DATA READ!");
    Serial.print("HTTP GET: ");
    Serial.println(httpResponseCode);
    Serial.print("HTTP Payload: ");
    Serial.println(payload);
    
    http.end();
    return payload;
}
