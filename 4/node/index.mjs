// setTimeout(()=>console.log("first") , 0);
// Promise.resolve().then(()=>console.log("Second"))
// console.log("Third");
 

// 7 premitive data types in javascript
// 1- string
// 2- object
// 3- bigint
// 4- boolean
// 5- undefined
// 6- null
// 7- Symbol

// Closures
// function C(){
//     let np = 10;
//     return function(n=1){
//         return np+=n;
//     }
// }
// const B = C();

// console.log(B());
// console.log(B(45));


// function  N(){
//     console.log(this==global);
// }

// const obj  = {
//     hello: "Hello" ,
//     fun : ()=>{
//         this.name  = "Awais";
//         console.log(this);
//     } , 
//     fun1 : function (){
//         console.log(this);
//     } , 
//     fun2(){
//         console.log(this);
//     }
// }
// obj.fun();
// obj.fun1();
// obj.fun2();

// object is passed by reference only


// class ABC{
//     constructor(){
//     }
//     fun(){
//         console.log(this.nam);
//     }
//     get name(){
//         return this.nam;
//     }
//     set name(h){
//         this.nam =h;
//     }
//     get age(){
//         return this.age;
//     }
//     set age(h){
//         this.age =h;
//     }
//     static Love(){
//         console.log("Love You");
//     }
// };
// const obj = new ABC();
// obj.name("Awais");
// console.log(obj.name());
// obj.fun();


// import Fast , {y , z , a,b} from './2nd.mjs';
// console.log(y , z,a,b);

let log = console.log;
// Functions
// function hoisted (){}
// let not_Hoisted  = function (){}

//IIFE
// (()=>{})();

// arguments
// function ABC(){
//     log(arguments);
// }
// ABC(4,5,3,45,34,534,53,4534)

// (HOF) higher order fuctions
// functions who return another functions or accept function
  
// nullish colaising
// let s = null;
// let v = s ?? "default";
// log(v);

// Closures
// - function inside a function
// - impure function inside a pure function

// Array Tricks

// const arr = [1,2,3,4,5,234,5,324,234,2,34];
// const arr2 = Array(100).fill(0).map((o,i)=>i+1);
// const arr3  = [...Array(50).keys()];
// // log(...arr.keys());
// for(let i of arr.keys()){
//     log(arr[i]);
// }
// log(" ")

// for(let val of arr){
//     log(val);
// }
// log(" ")

// for(let index in arr){
//     log(index);
// }
// log(" ")
// for(let [index,val] of arr.entries()){
//     log(index, val);
// }
// log(" ")
// arr.forEach((val,index)=>log(index, val));


// Algorithms

//Comulative Sum
// let sum=arr=>arr.reduce((a,b)=>a+b);
// log(sum([5,3,2,1]));

//Objects

// const x=1,y=1,z = 0
// const animal = {x,y,z};
// log(animal.x , animal.y , animal.z);
// const animal = {x:0,y:1,z:0};
// const {x,y,z:c} = animal
// log(x);
// const dog = Object.create(animal);
// log(Object.getPrototypeOf(dog));
// log(Object.getPrototypeOf(Object.getPrototypeOf(animal)));
//

// in this function toString Method convert number into base 36 first and then convert into string and slice method grab only last 5 entries in that string
// const rand = ()=>Math.random().toString(36).slice(-5);
// dynamic key name
// const obj = {
//     [rand()] : "wow",
//     [rand()] : "grapes",
//     [rand()] : "asd",
//     [rand()] : "sadf",
//     [rand()] : "asd",
// }
// log(obj)

// method chaining
// const obj = {
//     count : 10, 
//     inc(n=1){
//         this.count+=n;
//         return this
//     },
//     dec(n=1){
//         this.count-=n;
//         return this;
//     }
// }
// log(obj.inc().dec().inc(4).dec());

// copy object , loop on object
// const r={x:0,z:0,y:0}
// const t = {...r}; 
// for(let key in t){
//     log(key)
// }
// for(let value of Object.values(t)){
//     log(value)
// }
// for(let key of Object.keys(t)){
//     log(key)
// }
// for(const [key ,value] of Object.entries(t)){
//     log(key , value)
// }




// Pending Concepts To Learn
// how to use get and set in class in js
// call back hell
// promises

