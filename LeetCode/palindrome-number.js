/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    
    if(x<0) {
        return false;
    }
    
    var a = x.toString();
        
    for(let i =0; i<a.length/2; i++){
    
        if(a[i] != a[a.length -i -1]){
            return false;
        }
    }
    
    return true;
    
};