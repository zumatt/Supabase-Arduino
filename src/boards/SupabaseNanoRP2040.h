/**
 **************************************************
 *
 * @file        SupabaseNanoRP2040.h
 * @brief       Basic funtions for connecting supabase with Arduino
 *
 *              https://github.com/zumatt/Supabase-Arduino
 * 
 *              Created based on the library https://github.com/clock27-lab/unofficial-esp32-supabase
 *
 * MIT License
 * 
 * Copyright (c) 2024 Matteo Subet
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @authors     Matteo Subet https://github.com/zumatt/
 ***************************************************/

#ifndef SupabaseNanoRP2040_h
#define SupabaseNanoRP2040_h

#include <SPI.h>
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>

class Supabase {
public:
    Supabase(const char* ssid, const char* pass, const char* serverAddress, const char* apiKey, const char* bearerToken);
    void begin();
    void read();
    //int update(int rowId, const String& column, double value);

private:
    const char* _ssid;
    const char* _pass;
    const char* _serverAddress;
    const char* _apiKey;
    const char* _bearerToken;

    WiFiSSLClient _wifiClient;
    HttpClient _client;
};

#endif