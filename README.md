# lock-free-queue
Implementation of a lock-free queue with a single producer and a single consumer

## 一致性
目前服务器CPU的一致性做的较好，变量声明为volatile后可以保证多线程情况下变量值的可见性。