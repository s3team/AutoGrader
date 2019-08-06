AutoGrader is developed based on BAP and PathGrind.

BAP: The Binary Analysis Platform. For more information see the project
webpage at http://bap.ece.cmu.edu

BAP is released under MIT license and the GPL license; see the appropriate 
LICENSE.{MIT,GPL}.

PathGrind is released under the GPL liscence.

How to use:

1. AutoGrader starts with inquiry PathGrind an input based on white-box 
analysis.
2. When an input is inquiried, AutoGrader compares the results by running the 
reference and submission with this input. 
3. If the results are different, exit the grading process. If results are
same,then run PathAnalysis.
4. If true deviation is found, exit the grading process. If no deviation is 
found, goto 1.

Before you run the code, please follow ``ag_pathgrind/README.txt`` and
``ag_pathanalysis/INSTALL`` to configure the environment.

To run AutoGrader, you simply start by going to ``ag_pathgrind``,
```
cd ag_pathgrind
```
And run from the fuzzer,
```
./fuzz/fuzz.py ag_c1 w1
```
It will call the path analysis as long as new inputs are generated.
Here ``ag_c1`` is a reference implementation and ``w1`` is a submission.

To crawl dataset as the paper describes, please run ``crawler.py``.