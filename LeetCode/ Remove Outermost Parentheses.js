/**
 * @param {string} S
 * @return {string}
 */
const removeOuterParentheses = function(S) {
  let stack = [];
  let temp = '';
  let result = '';

  // Primitive decomposition
  for (let i = 0; i < S.length; i++) {
    if (S[i] === '(') {
      if (stack.length > 0) {
        temp += S[i];
      }
      stack.push(S[i]);
    } else if (S[i] === ')') {
      stack.pop();
      if (stack.length === 0) {
        result += temp;
        temp = '';
      } else {
        temp += S[i];
      }
    }
  }

  return result;
};
