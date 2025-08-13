#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <DNSServer.h>

// Replace with your network credentials
const char* ssid = "VENOM";
const char* password = "eacx4221";

ESP8266WebServer webServer(80);
DNSServer dnsServer;

// Structure to hold network information
struct Network {
  String ssid;
  byte bssid[6];
  int ch;
};

Network _networks[16];
Network _selectedNetwork;
String _correct = "";
bool deauthing_active = false;
bool hotspot_active = false;

String bytesToStr(const byte* bytes, int len) {
  String result = "";
  for (int i = 0; i < len; ++i) {
    char hex[3];
    sprintf(hex, "%02X", bytes[i]);
    result += hex;
    if (i < len - 1) {
      result += ":";
    }
  }
  return result;
}

String _tempHTML = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Venom</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            background-color: #fff;
            border-radius: 5px;
            padding: 20px;
            box-shadow: 0 2px 5px rgba(0,0,0,0.1);
        }
        h1 {
            color: #2c3e50;
            text-align: center;
        }
        .controls {
            display: flex;
            justify-content: space-between;
            margin-bottom: 20px;
        }
        .btn {
            padding: 10px 15px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s;
        }
        .btn-primary {
            background-color: #3498db;
            color: #fff;
        }
        .btn-danger {
            background-color: #e74c3c;
            color: #fff;
        }
        .btn:hover {
            opacity: 0.9;
        }
        .btn:disabled {
            background-color: #bdc3c7;
            cursor: not-allowed;
        }
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            padding: 12px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }
        th {
            background-color: #f2f2f2;
            font-weight: bold;
        }
        tr:hover {
            background-color: #f5f5f5;
        }
        .selected {
            background-color: #e8f0fe;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>WiFi Tool Interface</h1>
        <div class="controls">
            <form style='display:inline-block;' method='post' action='/?deauth={deauth}'>
                <button id="deauthBtn" class="btn btn-danger"{disabled}>{deauth_button}</button>
            </form>
            <form style='display:inline-block;' method='post' action='/?hotspot={hotspot}'>
                <button id="evilTwinBtn" class="btn btn-primary"{disabled}>{hotspot_button}</button>
            </form>
        </div>
        <table id="networkTable">
            <thead>
                <tr>
                    <th>SSID</th>
                    <th>BSSID</th>
                    <th>Channel</th>
                    <th>Select</th>
                </tr>
            </thead>
            <tbody>
                {network_rows}
            </tbody>
        </table>
        {correct_message}
    </div>
    <script>
        // JavaScript for dynamic updates can be added here if needed
    </script>
</body>
</html>
)=====";


void handleIndex() {
  String _html = _tempHTML;
  String networkRows = "";

  for (int i = 0; i < 16; ++i) {
    if (_networks[i].ssid == "") {
      break;
    }
    networkRows += "<tr><td>" + _networks[i].ssid + "</td><td>" + bytesToStr(_networks[i].bssid, 6) + "</td><td>" + String(_networks[i].ch) + "</td><td><form method='post' action='/?ap=" + bytesToStr(_networks[i].bssid, 6) + "'>";

    if (bytesToStr(_selectedNetwork.bssid, 6) == bytesToStr(_networks[i].bssid, 6)) {
      networkRows += "<button class='btn btn-primary'>Selected</button></form></td></tr>";
    } else {
      networkRows += "<button class='btn'>Select</button></form></td></tr>";
    }
  }

  _html.replace("{network_rows}", networkRows);

  if (deauthing_active) {
    _html.replace("{deauth_button}", "Stop deauthing");
    _html.replace("{deauth}", "stop");
  } else {
    _html.replace("{deauth_button}", "Start deauthing");
    _html.replace("{deauth}", "start");
  }

  if (hotspot_active) {
    _html.replace("{hotspot_button}", "Stop EvilTwin");
    _html.replace("{hotspot}", "stop");
  } else {
    _html.replace("{hotspot_button}", "Start EvilTwin");
    _html.replace("{hotspot}", "start");
  }

  if (_selectedNetwork.ssid == "") {
    _html.replace("{disabled}", " disabled");
  } else {
    _html.replace("{disabled}", "");
  }

  if (_correct != "") {
    _html.replace("{correct_message}", "<h3>" + _correct + "</h3>");
  } else {
    _html.replace("{correct_message}", "");
  }

  webServer.send(200, "text/html", _html);
}


void handleAdmin() {
  String _html = _tempHTML;
  String networkRows = "";

  for (int i = 0; i < 16; ++i) {
    if (_networks[i].ssid == "") {
      break;
    }
    networkRows += "<tr><td>" + _networks[i].ssid + "</td><td>" + bytesToStr(_networks[i].bssid, 6) + "</td><td>" + String(_networks[i].ch) + "</td><td><form method='post' action='/?ap=" + bytesToStr(_networks[i].bssid, 6) + "'>";

    if (bytesToStr(_selectedNetwork.bssid, 6) == bytesToStr(_networks[i].bssid, 6)) {
      networkRows += "<button class='btn btn-primary'>Selected</button></form></td></tr>";
    } else {
      networkRows += "<button class='btn'>Select</button></form></td></tr>";
    }
  }

  _html.replace("{network_rows}", networkRows);

  if (deauthing_active) {
    _html.replace("{deauth_button}", "Stop deauthing");
    _html.replace("{deauth}", "stop");
  } else {
    _html.replace("{deauth_button}", "Start deauthing");
    _html.replace("{deauth}", "start");
  }

  if (hotspot_active) {
    _html.replace("{hotspot_button}", "Stop EvilTwin");
    _html.replace("{hotspot}", "stop");
  } else {
    _html.replace("{hotspot_button}", "Start EvilTwin");
    _html.replace("{hotspot}", "start");
  }

  if (_selectedNetwork.ssid == "") {
    _html.replace("{disabled}", " disabled");
  } else {
    _html.replace("{disabled}", "");
  }

  if (_correct != "") {
    _html.replace("{correct_message}", "<h3>" + _correct + "<h3>");
  } else {
    _html.replace("{correct_message}", "");
  }

  webServer.send(200, "text/html", _html);
}


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  webServer.on("/", handleIndex);
  webServer.on("/admin", handleAdmin);
  webServer.begin();
  Serial.println("HTTP server started");
}

void loop() {
  webServer.handleClient();
}

