# csv_writer.py

import sys
import ast
import csv

import csv
import numpy as np



if __name__ == '__main__':
    # Check if the correct number of command-line arguments is provided
    if len(sys.argv) != 3:
        print("Usage: python3 csv_writer.py [data_list] [filename]")
        sys.exit(1)

    # Parse command-line arguments safely using ast.literal_eval
    print(sys.argv[1])
    data_list = ast.literal_eval(sys.argv[1])
    
    filename = sys.argv[2]

    save_to_csv(data_list, filename)
