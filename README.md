# Lucifer - Arduino based over controller

## Lucifer

Setup:
- Open project `lucifer.ino` with  Arduino IDE
- Select board: `Arduino UNO`
- Click `upload`

## Python utility

Utility to connect to the arduino via USB and write log as csv.

### Setup virtual environment:

This is only required once to setup the environment

```
python3 -m virtualenv -p python3 ve
source ve/bin/activate
pip install -e .
```

### Run the code:

Activate the virtual environment:
```
cd python_utils
source ve/bin/activate
```

Run the code:
```
python run_serial.py -s XXXXXX -f log_XXXX.csv
```

## Notes:

To check the serial port available:
```
ls /dev/*
```

If permission issues to open serial port:
```
sudo chmod a+rw /dev/XXXXX
```

For some reason looging form `display.cpp` makes the code crash.
Maybe it interferes with display serial communication logic.
