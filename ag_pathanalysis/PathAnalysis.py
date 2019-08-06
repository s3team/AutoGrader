import os
import re
import subprocess
import glob
import pdb


def getExe(ref, sub):
	print ('------------------Compile Source File--------------------')
	cmd = ['gcc', '-m32', './autograder-example/' + ref + '.c', '-o', './autograder-example/' + ref]
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()	
	cmd = ['gcc', '-m32', './autograder-example/' + sub + '.c', '-o', './autograder-example/' + sub]
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()	
	print ('Executables:')
	print ('./autograder-example/' + ref)
	print ('./autograder-example/' + sub)
	return 

def getTrace(exe, args):
	print ('------------------Log           Trace--------------------')
	os.system('rm *.bpt')
	cmd = './pin/pin ' + '-t ' + './pintraces/obj-ia32/gentrace.so ' + '-taint_args ' + '-- ' + './autograder-example/' + exe + ' ' + args
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()
	for root, dirs, files in os.walk('.'):
		for f in files:
			if f.endswith('.bpt'):
				cmd = ['mv', f, 'trace/'+ exe + '.bpt']
				p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
				stdout, stderr = p.communicate()
				break	
	print ('Trace:')
	print ('trace/'+ exe + '.bpt')
	return 

def getFormula(trace):
	print ('------------------Generate    Formula--------------------')
	cmd = 'utils/iltrans' + ' -trace' + ' trace/'+trace+'.bpt' + ' -trace-formula' + ' formula/' + trace + '.stp'
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()
	print ('Formula:')
	print ('formula/' + trace + '.stp')
	return

def getSymbol(f1, f2):
	symbols_f1 = []
	symbols_f2 = []
	header = ''
	line = f1.readline()
	line = f2.readline()
	while True:
		line = f1.readline()
		header = header + line
		if ('end free variables' in line):
			break
		symbols_f1.append(line.split(' : ')[0])
	while True:
		line = f2.readline()
		if ('end free variables' in line):
			break
		symbols_f2.append(line.split(' : ')[0])
	return zip(symbols_f1, symbols_f2), header

def replaceSymbol(f1, f2, symbols):
	formula1 = f1.read()
	formula2 = f2.read()
	for s1, s2 in symbols:
		formula2 = re.sub(s2, s1, formula2)
	return formula1, formula2

def combineFormula(file1, file2):
	print ('------------------Combine     Formula--------------------')
	f1 = open(file1, 'r')
	f2 = open(file2, 'r')
	(symbols), header = getSymbol(f1, f2)
	formula1, formula2 = replaceSymbol(f1, f2, symbols)
	formula1 = re.sub(r'[.\n\r]*ASSERT', '', formula1)
	formula1 = re.sub(r';\nQUERY\(FALSE\);\nCOUNTEREXAMPLE;\n', '', formula1)
	formula2 = re.sub(r'[.\n\r]*ASSERT', '', formula2)	
	formula2 = re.sub(r';\nQUERY\(FALSE\);\nCOUNTEREXAMPLE;\n', '', formula2)
	f1_not_f2_t = open('formula/f1notf2', 'r').read()
	f1_not_f2_t = re.sub(r'HEADER', header, f1_not_f2_t)
	f1_not_f2_t = re.sub(r'FORMULA1', formula1, f1_not_f2_t)
	f1_not_f2_t = re.sub(r'FORMULA2', formula2, f1_not_f2_t)
	f1_not_f2 = open('formula/f1notf2_temp'+'.stp', 'w')
	f1_not_f2.write(f1_not_f2_t)
	f1_not_f2.close()
	f2_not_f1_t = open('formula/f2notf1', 'r').read()
	f2_not_f1_t = re.sub(r'HEADER', header, f2_not_f1_t)
	f2_not_f1_t = re.sub(r'FORMULA1', formula1, f2_not_f1_t)
	f2_not_f1_t = re.sub(r'FORMULA2', formula2, f2_not_f1_t)
	f2_not_f1 = open('formula/f2notf1_temp'+'.stp', 'w')
	f2_not_f1.write(f2_not_f1_t)
	f2_not_f1.close()
	print ('F1 Not F2:')
	print ('formula/f1notf2_temp.stp')
	print ('F1 Not F2:')
	print ('formula/f1notf2_temp.stp')
	return 

def findDeviation(ref, sub):
	print ('------------------Find      Deviation--------------------')
	cmd = ['stp', '--CVC', 'formula/f1notf2_temp.stp']
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()
	res1 = str(stdout)
	cmd = ['stp', '--CVC', 'formula/f2notf1_temp.stp']
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate()
	res2 = str(stdout)
	deviation_input = dict()
	if 'Invalid' in res1:
		print('Find Deviation:')
		for item in res1.split('\n'):
			if ('Invalid' in item):
				break
			sym_val = re.match('ASSERT\( symb_([0-9])_[0-9]+ = (0x[0-9]+) \);', item)
			deviation_input[sym_val.group(1)] = sym_val.group(2)
			deviation = True
		for key, val in deviation_input.iteritems():
			print (key + ' : ' + val)
		equiv = detectEquiv(deviation_input, ref, sub)
	elif 'Invalid' in res2:
		print('Find Deviation:')
		for item in res1.split('\n'):
			if ('Invalid' in item):
				break
			sym_val = re.match('ASSERT\( symb_([0-9])_[0-9]+ = (0x[0-9]+) \);', item)
			deviation_input[sym_val.group(1)] = sym_val.group(2)
			deviation = True
		for key, val in deviation_input.iteritems():
			print (key + ' : ' + val)
		equiv = detectEquiv(deviation_input, ref, sub)
	else:
		print('No Deviation!')
		deviation = False
		equiv = False
	if deviation and not equiv:
		print ('True Deviation!')
	if deviation and equiv:
		print ('False Deviation!')
	return deviation and (not equiv)

def detectEquiv(deviation_input, ref, sub):
	print ('------------------Detect  Equivalence--------------------')
	args = ''
	for i in range(len(deviation_input)):
		key = str(i+1)
		val = int(deviation_input[key], 16)
		args = args + str(val) + ' '
	cmd = './autograder-example/'+ref + ' ' + args	
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate() 
	output1 = str(stdout)
	cmd = './autograder-example/'+sub + ' ' + args
	p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
	stdout, stderr = p.communicate() 
	output2 = str(stdout)
	pdb.set_trace()
	if (output1 == output2):
		return True
	else:
		return False

def pathDeviation(ref, sub, args):
	getExe(ref, sub)
	getTrace(ref, args)
	getTrace(sub, args)
	getFormula(ref)
	getFormula(sub)
	combineFormula('formula/'+ref+'.stp', 'formula/'+sub+'.stp')
	deviation = findDeviation(ref, sub)
	return deviation

if __name__ == '__main__':
	pathDeviation('c1', 'w2', '1 2 3')
