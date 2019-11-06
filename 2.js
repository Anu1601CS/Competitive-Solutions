// class Stack {
//   constructor() {
//     this.stack = [];
//   }
//   print() {
//     return this.stack;
//   }
//   top() {
//     return this.stack[this.stack.length - 1];
//   }
//   pop() {
//     this.stack.pop();
//     return this;
//   }
//   push(val) {
//     this.stack.push(val);
//     return this;
//   }
//   isEmpty() {
//     return this.stack.length > 0 ? false : true;
//   }
// }

// class Queue {
//   constructor() {
//     this.queue = [];
//   }
//   print() {
//     return this.queue;
//   }
//   front() {
//     return this.queue[0];
//   }
//   pop() {
//     this.queue.shift();
//     return this;
//   }
//   push(val) {
//     this.queue.push(val);
//     return this;
//   }
//   isEmpty() {
//     return this.queue.length > 0 ? false : true;
//   }
// }

// class Pair {
//   constructor() {}
// }

// function helper() {
//   let num = 10;

//   switch (new Date().getDay()) {
//     case 0:
//       day = 'Sunday';
//       break;
//     case 1:
//       day = 'Monday';
//       break;
//     case 2:
//       day = 'Tuesday';
//       break;
//     case 3:
//       day = 'Wednesday';
//       break;
//     case 4:
//       day = 'Thursday';
//       break;
//     case 5:
//       num = num - 4;
//     case 6:
//       num = num / 3;
//     case 7:
//       num = num * 10;
//   }

//   // Stack
//   var stack = [];
//   stack.push(2); // stack is now [2]
//   stack.push(5); // stack is now [2, 5]
//   var i = stack.pop(); // stack is now [2]
//   // console.log(stack[stack.length - 1]);
//   // alert(i); // displays 5

//   // Queue
//   var queue = [];
//   queue.push(2); // queue is now [2]
//   queue.push(5); // queue is now [2, 5]
//   var i = queue.shift(); // queue is now [5]
//   // alert(i); // displays 2

//   // Map
//   var myMap = new Map();

//   // setting the values
//   myMap.set('1', 'value1');
//   myMap.set('2', 'value2');
//   myMap.set('3', 'value3');

//   myMap.size; // 3

//   // myMap.forEach((val, key) => {
//   //   console.log(val, key);
//   // });

//   // getting the values
//   //myMap.get('1'); // "value associated with "value1"
//   //myMap.get('2'); // "value associated with "value1"
//   //myMap.get('3'); // "value associated with "value3"

//   // Sort with object and Array
//   let list = [];

//   list.push({ first: 6, second: 7 });
//   list.push({ first: 1, second: 2 });
//   list.push({ first: 4, second: 5 });
//   list.push({ first: 5, second: 6 });
//   list.push({ first: 2, second: 3 });
//   list.push({ first: 3, second: 4 });

//   // console.log(list);

//   // Sort Map

//   var map = new Map();
//   map.set('3', 'baz');
//   map.set('1', 'foo');
//   map.set('2', 'bar');

//   console.log(Array.from(map));
//   map.forEach((val, key) => {
//     console.log(val, key);
//   });
//   var mapAsc = new Map([...map].sort());
//   console.log(Array.from(mapAsc));

//   // Set

//   let set = new Set();
//   set.add(1);
//   set.add(2);
//   set.add(1);
//   set.add(2);
//   set.add(4);
//   set.add(1);
//   set.add(3);
//   set.add(2);

//   console.log(Array.from(set));
//   set.forEach(val => {
//     console.log(val);
//   });
//   var setAsc = new Set([...set].sort());
//   console.log(Array.from(setAsc));

//   setAsc.forEach(val => {
//     console.log(val);
//   });

//   var fruits = ['Banana', 'Orange', 'Apple', 'Mango'];
//   var f = fruits.entries();

//   for (x of f) {
//     console.log(x);
//   }
// }

// helper();

// let c = function() {
//   console.log(s);
//   var s = 1;

//   if (s) {
//     let t = 2;
//     console.log(s, t);
//   }

  // console.log(t);
// };

// c();

// let debounce = function(func, time) {
//   let set;
//   return function() {
//     const context = this;
//     const args = arguments;

//     clearTimeout(set);
//     set = setTimeout(() => {
//       func.apply(context, args);
//     }, time);
//   };
// };

// const throttle = (func, limit) => {
//   let inThrottle;

//   return function() {
//     const args = arguments;
//     const context = this;
  
//     if (!inThrottle) {
//       func.apply(context, args);
//       inThrottle = true;
//       setTimeout(() => (inThrottle = false), limit);
//     }
  
//   };
// };
