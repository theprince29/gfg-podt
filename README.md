# gfg-podt
# "GFG PODT  with my approch!!"

<h2><a href="https://www.geeksforgeeks.org/problems/recamans-sequence4856/1">Recamans sequence</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an integer <strong>n</strong>, return the first n elements of <a href="http://mathworld.wolfram.com/RecamansSequence.html"><span style="text-decoration: underline;"><em><strong><span style="color: #236fa1; text-decoration: underline;">Recaman’s sequence</span></strong></em></span></a>.<br>It is a function with domain and co-domain as whole numbers. It is recursively defined as below:<br>Specifically, let a(n) denote the (n+1)<sup>th</sup> term. (0 being the 1<sup>st</sup> term).<br>The rule says:<br></span><span style="font-size: 14pt;">a(0) = 0<br>a(n) = a(n-1) - n, if a(n-1) - n &gt; 0 and is not included in the sequence previously<br>&nbsp; &nbsp; &nbsp; &nbsp;=&nbsp; a(n-1) + n otherwise. </span></p>
<p><span style="font-size: 14pt;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> <br>n = 5
<strong>Output:</strong> <br>0 1 3 6 2
<strong>Explaination:</strong> <br>a(0) = 0,<br>a(1) = a(0)-1 = 0-1 = -1 and -1&lt;0, therefore a(1) = a(0)+1 = 1,<br>a(2) = a(1)-2 = 1-2 = -1 and -1&lt;0, therefore a(2) = a(1)+2 = 3,<br>a(3) = a(2)-3 = 3-3 = 0 but since 0 is already present in the sequence, a(3) = a(2)+3 = 3+3 = 6,<br>a(4) = a(3)-4 = 6-4 = 2.<br>Therefore the first 5 elements of Recaman's sequence will be 0 1 3 6 2.</span></pre>
<p><span style="font-size: 14pt;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> <br>n = 3
<strong>Output:</strong> <br>0 1 3
<strong>Explaination:</strong> <br>As seen in example 1, the first three elements will be 0 1 3.</span></pre>
<p><span style="font-size: 14pt;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>recamanSequence()</strong> which takes <strong>n</strong> as the input parameter and returns the sequence.</span></p>
<p><span style="font-size: 14pt;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong> O(n)</span></p>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Recursion</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;

