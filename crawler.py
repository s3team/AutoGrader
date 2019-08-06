import os

# result = "ac"
# result = "wa"
# result = "tle"
# result = "rte"
result = "cle"

def code_handler(p, id):
    c_url = "https://www.codechef.com/viewplaintext/" + id
    os.system("wget " + c_url)
    os.system("mv " + id + " " + p + "/code/" + id + "_" + result)

import urllib2, re

def get_num_of_pages(p):
    url_base = "https://www.codechef.com/status/%s?sort_by=All&sorting_order=asc&language=11&status=11&handle=&Submit=GO"
    urlt = url_base % p
    try:
        response = urllib2.urlopen(urlt)
    except:
        print "503" + urlt
	return "0"
    html = response.read()
    reg = r'''1 of ([0-9]+)'''
    m = re.findall(reg, html)
    if (len(m) == 1):
        return m[0]
    elif (len(m) == 0):
        return "1"
    else:
	assert(0 == 1)


def process_one_problem(p):
    url_base = "https://www.codechef.com/status/%s?page=%s&sort_by=All&sorting_order=asc&language=11&status=11&handle=&Submit=GO"
    n = get_num_of_pages(p)
    # return
    for i in range(0, int(n)):
        urlt = url_base % (p, str(i))
	try:
            response = urllib2.urlopen(urlt)
        except:
	    print "503" + urlt
	    continue
        html = response.read()
        reg = r'''href='/viewsolution/([0-9]+)'''
        m = re.findall(reg, html)
        for mid in m:
            code_handler(p, mid)

def process(problem):
    os.system("mkdir " + problem)
    os.system("mkdir " + problem + "/code")
    process_one_problem(problem)

plist = ["TRISQ"]
for p in plist:
    problem = p
    process(p)