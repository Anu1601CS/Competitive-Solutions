// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

// function lovely(A) {
//   let s = A.toString();

//   let myMap = new Map();

//   for (let i = 0; i < s.length; i++) {
//     myMap.set(s[i], 0);
//   }

//   for (let i = 0; i < s.length; i++) {
//     let p = myMap.get(s[i]);
//     myMap.set(s[i], p + 1);

//     if (myMap.get(s[i]) >= 3) {
//       return false;
//     }
//   }

//   return true;
// }

// function solution(A, B) {
//   let ans = 0;
//   for (let i = A; i <= B; i++) {
//     if (lovely(i)) {
//       ++ans;
//     } else {
//       console.log(i);
//     }
//   }

//   return ans;
// }


// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');


// function solution(message, K) {
//     if (message.length <= K) {
//       return message;
//     }
  
//     let res = " ";
  
//     let newStr = message.slice(0, K);
  
//     if (newStr[newStr.length - 1] == " ") {
//       let m = newStr.length - 1;
//       res = newStr.slice(0, m);
//     } else if (
//       newStr[newStr.length - 1] != " " &&
//       message[newStr.length] != " "
//     ) {
//       let n = newStr.length - 1;
  
//       while (newStr[n] != " ") {
//         --n;
//         if (n <= 0) {
//           break;
//         }
//       }
      
//       res = newStr.slice(0, n);
//     } else {
//         res = newStr;
//     }

//     console.log(res.length);
  
//     return res;
//   }
  

let minNum = 0;

function cal(N, K){
    
    while(N>1) {
        
        if(N % 2 == 0 && K>0){
           ++minNum;
           --K;
           N = N / 2;
        } else {
            N = N - 1;
            ++minNum;
        }
    }
    
}

function solution(N, K) {
  
  if(K == 0){
      return N-1;
  }
  
  cal(N,K);
  
  return minNum;
 
}






