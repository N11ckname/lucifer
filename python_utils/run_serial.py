# -*- coding: utf-8 -*-

import sys
import os
import math
import time
import argparse
import numpy as np
import copy
import csv
import datetime
import serial
import csv

def main(args_input):

    # ##########################################################
    # # Parse Arguments
    # ##########################################################
    argparser = argparse.ArgumentParser(
        description='Read serial')

    argparser.add_argument(
        '-s',
        type=str,
        dest='serial_port',
        default = "",
        help='Serial port')

    argparser.add_argument(
        '-f',
        type=str,
        dest='file_path',
        default = "",
        help='Output file path')


    args = argparser.parse_args(args_input)

    serialPort = serial.Serial(port = args.serial_port, baudrate=115200,
                               bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

    writer = open(args.file_path, 'w')
    print("Opening: {} {}".format(args.serial_port, args.file_path))

    while(1):

        # Wait until there is data waiting in the serial buffer
        if(serialPort.in_waiting > 0):
            # Read data out of the buffer until a carraige return / new line is found
            serialString = serialPort.readline()
            print(serialString.decode('Ascii'))
            writer.writelines(serialString.decode('Ascii'))
            writer.flush()

    writer.close()

if __name__ == '__main__':
    try:
        main(sys.argv[1:])
    except KeyboardInterrupt:
        print('\nCancelled by user. Bye!')
