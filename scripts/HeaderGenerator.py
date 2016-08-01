'''
Script to generate header file to init hal instance.
Author: VictorLi
'''

import argparse

def add_header_include(platformlist):
    xlist = list()
    xlist.append('#include"HalBase.h"')
    for item in platformlist:
        hname = 'Hal'+item+'.h'
        xlist.append('#include"'+hname+'"')
    return xlist


'''
    Generate code for each platform

    case GEN9:
        phal = new HalGen9;
        break;
'''
def add_instance(platform):
    xlist = list()
    xlist.append('case '+platform.upper()+':')
    xlist.append('phal = new ' + 'Hal'+platform + ';')
    xlist.append('break;')
    xlist.append('')
    return xlist

def add_init_function(platformlist):
    xlist = list()
    xlist.append('void init(HalBase * &phal, GEN_PLATFORM running_platfrom)')
    xlist.append('{')
    xlist.append('switch(running_platfrom)')
    xlist.append('{')
    for platform in platformlist:
        xlist.extend(add_instance(platform))
    xlist.append('}')
    xlist.append('return;')
    xlist.append('}')
    return xlist


def generate_code(platformlist, outputfile):
    #generate code
    codelist =  add_header_include(platformlist)
    codelist.extend(add_init_function(platformlist))
    #write into file
    with open(outputfile, 'w') as xfile:
        for line in codelist:
            xfile.write(line + '\n')


if __name__ == "__main__":
    # Parser input arguments
    parser = argparse.ArgumentParser(description='Generate header for Hal instances')

    parser.add_argument('--platform', required=True, help='Gen9 Gen10 Gen11')
    parser.add_argument('--outputfile', required=True, help='../HalInit.h')

    args = parser.parse_args()
    print args

    plist = args.platform.split(' ')
    plist = [x.strip() for x in plist]
    print plist

    generate_code(plist, args.outputfile)