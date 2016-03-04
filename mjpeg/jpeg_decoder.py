#!/usr/bin/python
#-*- coding: utf-8 -*-

import sys

# jpeg file's header
SOI = [0xff, 0xd8]
SOI_SIZE = 2
APP0 = [0xff, 0xe0]
APP0_SIZE = 2

DATA_LENGTH = 0

ID = [0x4a, 0x46, 0x49, 0x46, 0x00] #JFIF
ID_SIZE = 5

MAJOR_VER_ID = 0
MINOR_VER_ID = 0

UNITS = 0

X_DENSITY = 0
Y_DENSITY = 0

X_THUMBNAIL = 0
Y_THUMBNAIL = 0

# DQT Marker
DQT_MARKER = [0xff, 0xdb]
DQT_MARKER_SIZE = 2

DQT_DATA_LENGTH = 0

DQT_TABLE = [[], [], [], []]

# SOF marker
SOF_SIZE = 2

SOF_DATA_LENGTH = 0

SOF_SAMPLING_PRECISION = 0

SOF_IMG_H = 0
SOF_IMG_W = 0

# header file의 magic number와 비교하는 함수
def check_header(f, magic_bytes, magic_len):
    check_bytes = f.read(magic_len)
    for idx in range(0, magic_len):
        if magic_bytes[idx] != ord(check_bytes[idx]):
            return False

    return True

def get_char_value(f):
    read_bytes = f.read(1)
    return int(ord(read_bytes[0]))

def get_short_value(f):
    read_bytes = f.read(2)
    return int(ord(read_bytes[0])) * 256 + int(ord(read_bytes[1]))


if __name__ == '__main__':
    filename = sys.argv[1]

    f = open(filename, 'rb')

    # check SOI marker
    print "check SOI marker...",
    if check_header(f, SOI, SOI_SIZE) == False:
        print "fail"
        f.close()
        sys.exit(0)

    print "success"

    # check APP0 marker
    print "check APP0 marker...",
    if check_header(f, APP0, APP0_SIZE) == False:
        print "fail"
        f.close()
        sys.exit(0)

    print "success"

    # get data length
    DATA_LENGTH = get_short_value(f)
    print "data length = ", DATA_LENGTH

    # check identifier
    print "check Identifier...",
    if check_header(f, ID, ID_SIZE) == False:
        print "fail"
        f.close()
        sys.exit(0)

    print "success"

    # get Major version
    MAJOR_VER_ID = get_char_value(f)
    print "Major version ID = ", MAJOR_VER_ID 

    # get Minor version
    MINOR_VER_ID = get_char_value(f)
    print "Minor version ID = ", MINOR_VER_ID

    # get units
    UNITS = get_char_value(f)
    print "units = ", UNITS
 
    # get Xdensity
    X_DENSITY = get_short_value(f)
    print "Xdensity = ", X_DENSITY 
    
    # get Ydensity
    Y_DENSITY = get_short_value(f)
    print "Ydensity = ", Y_DENSITY 

    # get Xthumbnail
    X_THUMBNAIL = get_char_value(f)
    print "Xthumbnail = ", X_THUMBNAIL
    
    # get Ythumbnail
    Y_THUMBNAIL = get_char_value(f)
    print "Ythumbnail = ", Y_THUMBNAIL


    for table_idx in range(0, 4):
        # check DQT marker
        print "check DQT marker...",
        if check_header(f, DQT_MARKER, DQT_MARKER_SIZE) == False:
            print "fail - file offset : ", f.tell()
            f.seek(f.tell() - DQT_MARKER_SIZE)
            print "revert to file offset : ", f.tell()
            break
        print "success"

        # get DQT Data length
        DQT_DATA_LENGTH = get_short_value(f)
        print "DQT Data length = ", DQT_DATA_LENGTH 

        # get table info
        table_info_val = get_char_value(f)
        table_size = table_info_val & 0b11110000
        table_id =  table_info_val & 0b00001111 
        print "table size : ", table_size, ", table id : ", table_id

        for idx in range(0, DQT_DATA_LENGTH - 3):
            DQT_TABLE[table_id].append(f.read(1))

        #print DQT_TABLE[table_id]

    # SOF
    print "check SOF marker...",
    sof_marker = f.read(2)
    if 0xff != ord(sof_marker[0]):
        print "fail"
        f.close()
        sys.exit(0)
    
    print "success"
    print "SOF marker : ",
    sof_marker_mode = 0
    if ord(sof_marker[1]) == 0xc0:
        print "baseline"
    elif ord(sof_marker[1]) == 0xc1:
        print "extended sequential"
    elif ord(sof_marker[1]) == 0xc2:
        print "progressive"
    else:
        print "fail"
        f.close()
        sys.exit(0)

    SOF_DATA_LENGTH = get_short_value(f)
    print "SOF Data length = ", SOF_DATA_LENGTH

    SOF_SAMPLING_PRECISION = get_char_value(f)
    print "SOF Sampling precision = ", SOF_SAMPLING_PRECISION

    SOF_IMG_H = get_short_value(f)
    SOF_IMG_W = get_short_value(f)
    print "SOF Image Size = %dx%d" % (SOF_IMG_W, SOF_IMG_H)



    f.close()
