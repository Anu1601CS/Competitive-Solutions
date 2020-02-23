// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function lovely(A){

let s = A.toString();



let myMap = new Map();

for(let i=0; i<s.length; i++){
    myMap.set(s[i], 0);
}

for(let i=0; i<s.length; i++){
    let p = myMap.get(s[i]);
    myMap.set(s[i], p+1);
    
    if(myMap.get(s[i]) >=3){
        return false;    
    }
    
    // console.log(myMap.get(s[i]));
}

return true;
}

function solution(A, B) {
    
    let ans = 0;
    for(let i=A; i<=B; i++){
    
        if(lovely(i)){
            ++ans;        
        }
    }
    
    return ans;
   
}
