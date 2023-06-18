# Interview

## What is Node.js and how does it differ from other server-side technologies?

- Nodejs is a runtime for running JS code out of the browser
- It uses Chrome V8 engine to transpile JS
- It provides an event-driven, non-blocking I/O mode.
- **This non-blocking I/O is one of the key differentiators of Node.js compared to other server-side technologies.**
- such as PHP or Java, each incoming request typically **spawns a new thread or process, which can be resource-intensive**

- Node js uses Event looop architecture which is good at handling non block i/o operations.
- Django uses MVT model where as Node js uses MVC architecture
- A nodejs process is run only one therad and one proess and it has the ability to swarn multiple worker threads to handle async operations

## Can you explain the concept of non-blocking I/O in Node.js and its significance in building scalable applications?

- Node JS uses Chromes V\* to transplie JS to machine code.
- v8 engine and libuv and the main helpers to achieve it non blockinh i/p
- nodejs uses evenet loop architecture, nothing but a design pattern that co-ordinaties between sync and async code in nodejs
- Node js will be alive as longas there is code to executed or esle there is something in the eventloop
- Node js primary has 6 queue

1. timeout q
2. i.o q
3. proesss.nextTick
4. JS promise
5. callback q
6. closeEvents

- Js is primarly single thraded which there is only one therd to do the job thats is exuting all the code.
- So here comes in event loop where in browser JS uses webAPI and out of broswer JS uses v8 engine and lobuv
- When something is executed in ana asyncrhouniss manner the triggerd events are resiterd in side the **event q**
- event q is a loop which executed each of the task in side the q
- and the executed tasks wait until the call satck is empty once it is not emepty loop pushes the completed taks into the callback q the o.p fromthis async operteion is returned and the mianthread then continues the execution flow

## Event Registration

**When an asynchronous operation is encountered in Node.js, such as reading from a file or making a network request, it initiates the operation and registers the corresponding event in the event loop.**

**The event loop continuously checks the queues and executes tasks that are ready to run. Once an asynchronous operation is completed, its associated callback is placed in the callback queue.**

**The event loop waits until the call stack is empty, which means all synchronous code has been executed, and then it starts processing tasks in the callback queue. This ensures that asynchronous operations don't block the execution of other operations and allows Node.js to handle multiple requests concurrently.**

**Traditional server-side technologies typically spawn a new thread or process for each incoming request, which can be resource-intensive and limit scalability. Node.js, with its non-blocking I/O and event-driven architecture, can handle concurrent requests using a single thread, resulting in better resource utilization and scalability.**

**It's important to note that while the event loop is single-threaded, Node.js can leverage worker threads to handle computationally intensive tasks without blocking the main event loop, further enhancing concurrency and performance.**

## Different approaches to handle ASYNC JS

1. callbacks
2. promises
3. Async await
