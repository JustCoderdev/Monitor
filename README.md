# Monitor

> Monitor is a simple program to keep track of server statistics
> It updates the screen every second if the lid is open

## Todo
- [ ] Major refactor and recompacting
- [ ] Implement macOS fields
- [ ] Support SIGSTOP clearing stuff
- [ ] Implement alpine fields


## Implemented Fields

*Operating System*
- [x] OS Name   ("macOS Monterey")
- [ ] OS Uptime (time)

*Network*
- [ ] Net SSID    (“Webpocket”)
- [ ] Net address (address, “Disconnected”)

*CPU*
- [ ] CPU Usage (%)
- [ ] CPU Temp  (*C)

*RAM*
- [ ] RAM Usage (%)
- [ ] RAM Used  (Gb)
- [ ] RAM Total (Gb)

*Memory*
- [ ] Mem Usage (%)
- [ ] Mem Used  (Gb)
- [ ] Mem Total (Gb)

*Battery*
- [ ] Batt Stored      (%)
- [ ] Batt Status      (“charging”, “discharging”)
- [ ] Batt Time until: (time)
    - depleted
    - full

*Power*
- [ ] Pow Source (“socket”, “battery”)
- [ ] Pow Draw   (W)

