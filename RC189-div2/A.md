# 题解在：https://atcoder.jp/contests/arc189/editorial/11558

- 关于为什么规模是$(N - 2)!!$
 - 可以思考下面的例子：
  - 101010101 -> 111111111, 我们可以将两端去掉这样我们讨论选择0和选择1的情况。如果变0：111010101等价于1010101，少了两个1。如果边1：100010101等价于1010101，少了两个0。因此规模减去2。剩下的看代码就行。