# Python utility

This is a python utility to create a log from Lucifer system.
It:
- open the serial port
- write in a csv the string received

## Setup virtual environment:

This is only required once to setup the environment

```
python3 -m virtualenv -p python3 ve
source ve/bin/activate 
pip install -e .
```

## Run the code:

Activate the virtual environment:
```
cd python_utils
source ve/bin/activate
```

Run the code:
```
python run_serial.py -s XXXXXX -f log_XXXX.csv
```

**Note:**: To check the serial port available:
```
ls /dev/*
```
