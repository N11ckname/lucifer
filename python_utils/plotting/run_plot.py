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

import pandas as pd
import matplotlib.pyplot as plt

def main(args_input):

    # ##########################################################
    # # Parse Arguments
    # ##########################################################
    argparser = argparse.ArgumentParser(
        description='Plotting tool')

    argparser.add_argument(
        '-f',
        type=str,
        dest='file_path',
        default = "",
        help='Output file path')


    args = argparser.parse_args(args_input)

    print("Opening: {}".format(args.file_path))
    csv_data = pd.read_csv(args.file_path)
    # csv_data.drop(columns=csv_data.columns[0], axis=1, inplace=True)

    print("{}".format(csv_data.head()))
    
    csv_data.plot(x=' run_time', y=[' temp', ' temp_consigne'])
    plt.title("Temp vs Temp Consigne (Celsius)\n({})".format(os.path.basename(args.file_path)))

    csv_data.plot(y=[' output', ' Kp', ' Ki', ' Kd'])
    plt.title("Controller\n({})".format(os.path.basename(args.file_path)))

    plt.show()

if __name__ == '__main__':
    try:
        main(sys.argv[1:])
    except KeyboardInterrupt:
        print('\nCancelled by user. Bye!')
