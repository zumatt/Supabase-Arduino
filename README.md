# Supabase-Arduino
### A library to connect to Supabase's Realtime Database from an Arduino with API Key authentication.

The Arduino library provides a simple and efficient way to integrate Supabase.io's Realtime Database into your ESP32 or RP2040 projects. By leveraging API Key authentication, this library enables real-time communication between your microcontroller and Supabase.io's powerful database infrastructure.

To get started, simply include the library in your Arduino IDE and follow the provided documentation to establish a connection with Supabase.io. Once connected, you can easily retrieve, update, and synchronize data between your Arduino and the Supabase.io Realtime Database.

With the Arduino Nano ESP32 library, you can unlock the full potential of Supabase.io's Realtime Database and build IoT applications that seamlessly interact with cloud-based data. Start building your next project today!
---
#### Installation
At the moment installation has to be done manually either on a global level (*libraries* folder in the main Arduino Sketch folder) or locally placed in the *libraries* folder inside your Sketch directory.
The library will be soon available also from the Arduino IDE.

For the time being when including it you'll have to go with
```#include "SupabaseArduino.h"```

#### ESP32 Usage
In order to setup the library you need to pass the following data.
Please note that those data are available from you supabase database settings under the API tab (https://supabase.com/dashboard/project/PROJECT-CODE/settings/api).
```
#define supabaseUrl  "INSERT YOUR URL HERE"
#define tableRealtime  "INSERT YOUR TABLE NAME HERE"
#define supabaseApiKey  "INSERT YOUR API KEY HERE"
```
in order to let the client begin with the right information you need to call the following function:
```SUPABASE supabaseClient(supabaseUrl, supabaseApiKey, tableRealtime);```

Before start reading, updating or inserting any data in the database, you need to begin the connection by calling:
```supabaseClient.begin();```

After that line of code, you can use three different method in order to interact with the database:
```
//Read the data from the table
    supabaseClient.read();

//Update a specific row with a new value
        int rowId = 1;
        String column = "column_name";
        double value = 100.0;
    supabaseClient.update(rowId, column, value);


//Insert a new row with a new value
        column = "column_name";
        value = 100.0;
    supabaseClient.insert(column, value);
```

#### RP2040 Usage
Coming soon...

Under the examples you can find a .ino file that includes all the mentioned functions working.

### ToDo List

- [ ] RP2040 insert and update integration
- [ ] Realtime integration from Supabase
- [ ] Other Arduino Boards supports
- [ ] Micropython Library