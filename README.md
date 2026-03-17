
<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/raw/main/covers/cover-minitalk-bonus.png" alt="MiniTalk cover" width="100%">
</p>

<h1 align="center">
  <br>
  <a href="https://github.com/SEU_USUARIO/minitalk">
    <img src="https://github.com/ayogun/42-project-badges/raw/main/badges/minitalkm.png" alt="MiniTalk badge" width="200">
  </a>
  <br>
  MiniTalk
  <br>
</h1>

<h4 align="center">
  A small client-server communication system built with Unix signals in <a href="https://www.c-language.org/" target="_blank">C</a>.
</h4>

<p align="center">
  <img src="https://img.shields.io/badge/Final%20Score-125%2F125-00C853?style=for-the-badge" alt="Final Score 125/125">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c" alt="Language C">
  <img src="https://img.shields.io/badge/Communication-Unix%20Signals-blueviolet?style=for-the-badge" alt="Unix Signals">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status Completed">
</p>

<p align="center">
  <a href="#about-the-project">About</a> •
  <a href="#core-idea">Core Idea</a> •
  <a href="#signals-and-binary-communication">Signals & Binary Communication</a> •
  <a href="#the-handshake-problem">The Handshake Problem</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#bonus">Bonus</a> •
  <a href="#team">Team</a>
</p>

---

<!-- You can replace this with a GIF later -->
<!-- ![demo](./imgs/minitalk_demo.gif) -->

## About the Project

**MiniTalk** is a project focused on **inter-process communication**.

Its goal is to build two separate programs:

- a **server**
- a **client**

The **client** sends a message to the **server**, and the **server** reconstructs that message, stores it, and prints it to the standard output once the transmission is complete.

At first glance, this sounds simple.

But there is an important detail:  
the message is **not** sent all at once.

Instead, each character is transmitted **bit by bit**, using Unix signals, and the server must rebuild each byte correctly before displaying the final message.

This project was one of my first deeper contacts with:

- signals
- process communication
- synchronization
- binary reasoning
- low-level message transmission

---

## Core Idea

A good way to understand **MiniTalk** is this:

The client does not send text directly.  
It sends the **binary representation** of each character, one bit at a time.

For example, if I want to send:

```text
Oi
````

I am not sending just two visible characters.

I need to send:

* the bits for `'O'`
* the bits for `'i'`
* and finally the bits for `'\0'`

Why `'\0'`?

Because the server needs a way to know that the message has ended.

So even a short message like `"Oi"` actually needs:

* 8 bits for `'O'`
* 8 bits for `'i'`
* 8 bits for `'\0'`

Which gives a total of:

```text
24 bits
```

That is when the project stops looking simple and starts becoming really interesting.

---

## Signals and Binary Communication

To make this communication possible, the project uses **Unix signals**.

Some signals in Linux already have predefined purposes, such as:

* `SIGTERM`
* `SIGINT`
* `SIGKILL`

But for this project, the most useful ones are:

* `SIGUSR1`
* `SIGUSR2`

These are user-defined signals, which means the programmer can decide how to interpret them.

In **MiniTalk**, they work as the binary language between client and server.

For example, one signal can represent:

* `1`

and the other can represent:

* `0`

This gives us a way to transmit each character in pure binary form.

So if a character in ASCII is represented by 8 bits, the client sends those 8 bits one by one through signals, and the server receives them, organizes them, rebuilds the byte, and discovers which character was sent.

That is the heart of the project.

---

## The Handshake Problem

At first, it may seem that sending bits one after another is enough.

But during implementation, I discovered an important problem:

> The client may send bits faster than the server can correctly receive and process them.

And if the timing is wrong, the message may become corrupted.

I tested pauses and timing adjustments to improve stability, but that alone was not enough for a truly reliable communication system.

So the real solution was to create a **handshake** between the two programs.

### What does that mean?

It means the **server** must tell the **client** when it is ready to receive the next bit.

So the communication becomes:

1. The client sends one bit
2. The client waits
3. The server processes that bit
4. The server sends a confirmation signal
5. The client sends the next bit

This creates a synchronized exchange.

Because of this handshake, the message arrives correctly and the communication becomes much more stable and trustworthy.

At the very end, once the full message has been received and the null terminator is detected, the server can also send a final confirmation to stop the client's transmission loop.

This part was one of the most important lessons of the project, because it showed that communication is not just about sending data — it is also about **timing, coordination, and confirmation**.

---

## Message Reconstruction

On the server side, the logic is essentially:

1. Receive one signal
2. Interpret it as `0` or `1`
3. Shift/store that bit in the correct position
4. Rebuild the full byte after 8 received bits
5. Convert that byte into a character
6. Store the character
7. If the character is `'\0'`, print the complete message

This makes the project feel like a tiny communication protocol built from scratch.

That is exactly why **MiniTalk** is so interesting:
it transforms a simple message into a low-level system of binary transmission between processes.

---

## How To Use

To compile the project, run:

```bash
make
```

This will generate both executables:

* `server`
* `client`

### 1. Compile the programs

<p align="center">
  <img src="./imgs/MiniTalk_1.png" alt="Compiling MiniTalk" width="85%">
</p>

Run:

```bash
make
```

During my implementation, I chose **not to use Libft** in this project, because I wanted to rebuild the necessary logic from scratch again, both to strengthen my understanding and to prepare myself better for the École 42 exams that were approaching.

### 2. Open two terminals

To execute the project properly, open **two terminals**.

In the first one, run the server:

```bash
./server
```

The server will print its **PID**, which is the process identifier used by the client to know where the message must be sent.

In the second terminal, run the client with:

```bash
./client <server_pid> "Your message here"
```

Example:

```bash
./client 4242 "Hello from MiniTalk"
```

### 3. Observe the communication

<p align="center">
  <img src="./imgs/MiniTalk_2.png" alt="Using MiniTalk" width="85%">
</p>

With that, the client starts sending the message bit by bit to the server, and the server reconstructs it and prints the final result.

---

## Bonus

This version of **MiniTalk** was completed with **bonus**, and the project received:

```text
125 / 125
```

The bonus part was especially meaningful because it pushed the project beyond a minimal proof of concept and toward a more complete and reliable communication flow.

For me, the biggest gain in this project was not only making processes talk, but understanding that even a tiny communication system needs:

* structure
* synchronization
* confirmation
* integrity of transmission

---

## Team

**MiniTalk** is an individual project at **École 42**.

So this project was entirely developed by me.

---

## Final Note

MiniTalk may look like a small project, but it carries a powerful lesson.

It teaches that communication between processes is not magic.

It is built step by step:

* one signal at a time
* one bit at a time
* one character at a time

And from that, a real message emerges.

For me, **MiniTalk** was a project about much more than sending strings.
It was about understanding how machines can communicate through extremely small building blocks and how reliability depends on careful coordination between both sides.
