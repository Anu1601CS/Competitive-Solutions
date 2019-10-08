// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function calculate(A, B) {
  // write your code in JavaScript (Node.js 8.9.4)
  let list = [];

  for (let j = 0; j < A.length; j++) list.push({ front: A[j], back: B[j] });

  list.sort(function(a, b) {
    return a.front < b.front ? -1 : a.front == b.front ? 0 : 1;
  });

  for (let k = 0; k < list.length; k++) {
    A[k] = list[k].front;
    B[k] = list[k].back;
  }

  let max = 1;

  if (A[0] != 1) {
    if (B[0] == 1) A[0] = 1;
    else {
      max = 1;
      return max;
    }
  }

  let flag = 0;
  let i;
  for (i = 0; i < A.length - 1; i++) {
    if (A[i] + 1 == A[i + 1]) continue;
    if (A[i] + 1 != A[i + 1]) {
      if (A[i] + 1 != B[i + 1]) {
        flag = 1;
        max = Math.max(A[i] + 1, max);
        break;
      } else {
        A[i + 1] = B[i + 1];
      }
    }
  }

  if (flag == 0) max = Math.max(A[i] + 1, max);

  return max;
}

function solution(A, B) {
  let max1 = calculate(A, B);
  let max2 = calculate(B, A);

  return Math.max(max1, max2);
}
