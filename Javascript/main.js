// window.addEventListener("DOMContentLoaded", () => {
//   console.log("Loaded..");

//   class Fetcher {
//     constructor() {
//       this.XMLHttp = new XMLHttpRequest();
//     }

//     fetch() {
//       return new Promise((resolve, reject) => {
//         this.XMLHttp.onreadystatechange = function() {
//           if (this.readyState == 4 && this.status == 200) {
//             resolve(this.responseText);
//           }

//           if (this.status == 500) {
//             reject(
//               new Error({
//                 message: "Error"
//               })
//             );
//           }
//         };

//         this.XMLHttp.onerror = function() {};

//         this.XMLHttp.open(
//           "GET",
//           "https://jsonplaceholder.typicode.com/todos/1"
//         );
//         this.XMLHttp.send();
//       });
//     }
//   }

//   const func = async () => {
//     const f = new Fetcher();
//     f.fetch()
//       .then(Val => {})
//       .catch(err => {});
//     const data = await f.fetch();
//     console.log(data);
//   };

//   func();

// //   Promise.all()

// //   Promise.race()

//   document.getElementById("btn").addEventListener("click", event => {
//     console.log(event);
//   });
// });
