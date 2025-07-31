// // // #single inheritence
// // #include<iostream>
// // using namespace std;
// // class Animal{
// //     public:
// //     void eat(){
// //         cout<<"animal is eating"<<endl;
// //     }
// // };
// // class Dog:public Animal{
// //     public:
// //     void bark(){
// //         cout<<"dog is barking"<<endl;
// //     }
// // };
// // int main(){
// //     Dog d;
// //     d.bark();
// //     d.eat();
// // }
// // 
// // // multiple inheritence
// // #include<iostream>
// // using namespace std;
// // class Animal{
// //     public:
// //     void eat(){
// //         cout<<"animal is eating"<<endl;
// //     }
// // };
// // class Animal1{
// //     public:
// //     void bark(){
// //         cout<<"animal1 id barking"<<endl;
// //     }
// // };
// // class Frog:public Animal,public Animal1{
// //     public:void jump(){
// //         cout<<"frog is jumping"<<endl;
// //     }
// // };
// // int main(){
// //     Frog f;
// //     f.jump();
// //     f.eat();
// //     f.bark();
// // }
// // mutilevel inheritence
// #include<iostream>
// using namespace std;
// class Animal{
//     public:
//     void eat(){
//         cout<<"animal is eating"<<endl;
//     }
// };
// class Dog:public Animal{
//     public:
//     void bark(){
//         cout<<"dog is barking"<<endl;
//     }
// };
// class Frog:public Dog{
//     public:
//     void jump(){
//         cout<<"frog is jumping"<<endl;
//     }
// };
// int main(){
//     Frog f;
//     Dog d;
//     f.jump();
//     f.eat();
//     f.bark();
// }