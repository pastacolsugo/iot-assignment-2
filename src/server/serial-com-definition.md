# Serial communication

Baud 115200

## Messages from Arduino

water lv    int 
valve pos   int
state       char* "normal/prealarm/alarm"
control     char* "auto/manual"
lamp        char* "off/on"

```
control_source:none
```
```
control_source:pot
```
```
control_source:serial
```

```
lamp:on
```

```
lamp:off
```

```
state:normal
```

```
state:prealarm
```

```
state:alarm
```

```
water_level:100
```

```
valve_position:100
```


## Messages to Arduino

```
set_control:auto
```

```
set_control:manual
```

```
set_valve:0
```

```
set_valve:180
```
