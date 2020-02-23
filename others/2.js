// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function deb(s){
    console.log('Debug--->' , s);    
}

function solution(message, K) {
  if (message.length <= K) {
    return message;
  }

  let res = " ";

  let newStr = message.slice(0, K);

  deb(newStr);

  if (newStr[newStr.length - 1] == " ") {
    let m = newStr.length - 1;
    res = newStr.slice(0, m);
  } else if (
    newStr[newStr.length - 1] != " " &&
    message[newStr.length] != " "
  ) {
    let n = newStr.length - 1;

    while (newStr[n] != " ") {
      --n;
      if (n <= 0) {
        break;
      }
    }

    res = newStr.slice(0, n);
  } else {
      res = newStr;
  }

  return res;
}
