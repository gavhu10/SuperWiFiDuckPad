# Super WiFi Duck Pad

This is the firmware for [my keypad](https://github.com/gavhu10/keypad).

It is called SuperWifiDuckPad because it is a fork of [wasdwasd0105/SuperWiFiDuck](https://github.com/wasdwasd0105/SuperWiFiDuck).
The SuperWifiDuck project is in turn is a fork of [SpacehuhnTech/WiFiDuck](https://github.com/SpacehuhnTech/WiFiDuck).

## Uses

Here are some things that you can automate with the DuckPad:

### Open a webpage

```
WINDOWS r
DELAY 500
STRINGLN https://youtu.be/dQw4w9WgXcQ
```

### Open task manager

```
CTRL SHIFT ESCAPE
```

### Pause music and mute speakers

```
MEDIA_PLAY_PAUSE
MEDIA_MUTE
```

A complete reference of the duckyscript functions available can be found in [DUCKYSCRIPT.md](DUCKYSCRIPT.md).

Other examples can be found in the [examples](./examples) folder. You can also use the penetration testing related scripts in the hak5 repo [here](https://github.com/hak5/usbrubberducky-payloads/tree/master/payloads/library), although some of them will need adaptation before they work properly.
