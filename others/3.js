// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

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
