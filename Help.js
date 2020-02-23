function helper() {
  // Stack
  var stack = [];
  stack.push(2); // stack is now [2]
  stack.push(5); // stack is now [2, 5]
  var i = stack.pop(); // stack is now [2]
  alert(i); // displays 5
  

  // Queue
  var queue = [];
  queue.push(2); // queue is now [2]
  queue.push(5); // queue is now [2, 5]
  var i = queue.shift(); // queue is now [5]
  alert(i); // displays 2

  // Map
  var myMap = new Map();

  // setting the values
  myMap.set('1', 'value1');
  myMap.set('2', 'value2');
  myMap.set('3', 'value3');

  myMap.size; // 3

  // getting the values
  myMap.get('1'); // "value associated with "value1"
  myMap.get('2'); // "value associated with "value1"
  myMap.get('3'); // "value associated with "value3"

  // Sort with object and Array
  let list = [];

  for (let j = 0; j < A.length; j++) list.push({ front: A[j], back: B[j] });

  list.sort(function(a, b) {
    return a.front < b.front ? -1 : a.front == b.front ? 0 : 1;
  });

  // Sort Map

  var map = new Map();
  map.set('2-1', 'foo');
  map.set('0-1', 'bar');
  map.set('3-1', 'baz');

  var mapAsc = new Map([...map.entries()].sort());

  console.log(mapAsc);

  // Set

  let set = new Set();
  set.add('red');

  set.has('red');
  // true;
  set.delete('red');
  // true;
  set.has('red');
  // false;
  // Determining the size of a Set and clearing it:

  let set = new Set();
  set.add('red');
  set.add('green');

  set.size;

  set.clear();
  set.size;

  // sort set
  Array.from(new Set([{ a: 1, b: 2 }, { a: 4, b: 5 }, { a: 2, b: 3 }])).sort(
    (a, b) => {
      return a.a > b.a ? 1 : -1;
    }
  );
}

console.warn('YES');
