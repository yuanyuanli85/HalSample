import os
import argparse

def scan_empty_lines(filename):
    with open(filename) as mfile:
        xlist = list()
        for line_num, line in enumerate(mfile.readlines()):
            if line.strip() == '':
                xlist.append(line_num)

        xstack = list()
        empty_line_list = list()
        for xline in xlist:
            if len(xstack) == 0 : #empty
                xstack.append(xline)
            if xstack[-1] == (xline -1):
                xstack.append(xline)
            else:
                #print and clean all of elements in xstack
                xlen = len(xstack)
                if xlen >=2:
                    #recode the empty lines to delete
                    empty_line_list.extend(xstack[1:])
                    print "extra empty line detected ~~~~"
                    for i in range(xlen):
                        mline = xstack.pop()
                        print filename, mline
                    xstack.append(xline)
                else:
                    xstack.pop()
                    #add new one into xstack
                    xstack.append(xline)
        return empty_line_list

def remove_empty_lines(filename):
    empty_lines = scan_empty_lines(filename)
    xlines = open(filename).readlines()
    newlines = list()
    for line_num, xline in enumerate(xlines):
        if line_num in empty_lines:
            continue
        newlines.append(xline)

    with open(filename, 'w') as outfile:
        outfile.writelines(newlines)

def replace_tabs_with_4spaces(filename):
    newlines = list()
    with open(filename) as mfile:
        for linenum, line in enumerate(mfile.readlines()):
            newlines.append(line.replace('\t', '    '))

    with open(filename, 'w') as outfile:
        outfile.writelines(newlines)

def scan_tabs(filename):
    xlist = list()
    with open(filename) as mfile:
        for linenum, line in enumerate(mfile.readlines()):
            if '\t' in line:
                xlist.append(linenum)
    return xlist

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="tool to scan/remove tabs and extra empty lines")
    parser.add_argument('--file',   dest='xfile', help='file to scan', default=None)
    parser.add_argument('--path',   dest='xpath', help='path to scan', default=None)
    parser.add_argument('--action', dest='xact',  choices=['scan_empty_lines', 'scan_tabs', 'remove_empty_lines', 'replace_tabs_with_4spaces'])

    args = parser.parse_args()

    if args.xfile:
        if args.xact == 'remove_empty_lines':
            remove_empty_lines(args.file)
        elif args.xact == 'replace_tabs_with_4spaces':
            replace_tabs_with_4spaces(args.file)

    if args.xpath:
       for root, dirs, files in os.walk(args.xpath):
            for xfile in files:
                if args.xact == 'remove_empty_lines':
                    remove_empty_lines(os.path.join(root, xfile))
                elif args.xact == 'replace_tabs_with_4spaces':
                    replace_tabs_with_4spaces(os.path.join(root, xfile))
