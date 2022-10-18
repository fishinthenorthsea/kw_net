import xlrd
import csv
import codecs
import argparse
import os
import time
 
dirs = "../bin/res/database/game_system/"

def args_parse():
    # construct the argument parse and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-f", "--file", 
                    required=True,
                    help="excel file name")
    args = vars(ap.parse_args()) 
    return args
 
def xlsx_to_csv_pd(filepath):
    (filedir, filename) = os.path.split(filepath)
    (fn, ext) = os.path.splitext(filename)
    workbook = xlrd.open_workbook(filepath)
    sheets = workbook.sheet_names()
    for i in range(len(sheets)):
        table = workbook.sheet_by_index(i)
        sht = dirs + sheets[i] + '.csv'
        with codecs.open(sht, 'w', encoding='UTF-8') as f:
            write = csv.writer(f)
            for row_num in range(table.nrows):
                row_value = table.row_values(row_num)
                write.writerow(row_value)
        print(sht," created!")
        


if __name__=='__main__':
    args = args_parse()
    filepath = args['file']
    if not os.path.exists(dirs):
        os.makedirs(dirs)        
    xlsx_to_csv_pd(filepath)        #解析
   # print("Completed to convert ",filepath," to csv files!")
