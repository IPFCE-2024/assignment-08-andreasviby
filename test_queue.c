// test_queue.c
#include <assert.h>
#include <stdio.h>
#include "exercise4.h"   // header med queue + stack-API

int main(void) {
    queue q;

    // (1) Efter init er køen tom
    init_queue(&q);
    assert(queue_empty(&q) && "Queue should be empty right after init");

    // (2) Hvis vi starter fra tom kø: enqueue(x); y = dequeue();
    //     -> køen er igen tom og y == x
    {
        init_queue(&q);
        int x = 42;
        enqueue(&q, x);
        int y = dequeue(&q);
        assert(queue_empty(&q) && "Queue should be empty after enqueue+dequeue on empty queue");
        assert(y == x && "Dequeued element must equal the enqueued element (empty pre-state)");
    }

    // (3) Hvis vi starter fra tom kø:
    //     enqueue(x1); enqueue(x2); y1=dequeue(); y2=dequeue();
    //     -> køen er igen tom, y1==x1 og y2==x2 (FIFO)
    {
        init_queue(&q);
        int x1 = 7, x2 = 9;
        enqueue(&q, x1);
        enqueue(&q, x2);
        int y1 = dequeue(&q);
        int y2 = dequeue(&q);
        assert(queue_empty(&q) && "Queue should be empty after two enqueues then two dequeues on empty queue");
        assert(y1 == x1 && "First dequeued must equal first enqueued (FIFO)");
        assert(y2 == x2 && "Second dequeued must equal second enqueued (FIFO)");
    }

    // Ekstra sanity: Hvis køen IKKE er tom i forvejen,
    // enqueue(x) efterfulgt af dequeue() returnerer DET GAMLE front-element (ikke x)
    {
        init_queue(&q);
        enqueue(&q, 1);
        enqueue(&q, 2);
        enqueue(&q, 3);
        enqueue(&q, 99);          // ny bagerst
        int y = dequeue(&q);      // skal være 1 (front), ikke 99
        assert(y == 1 && "Dequeue must return the previous front when queue was non-empty");
        // ryd op
        (void)dequeue(&q);
        (void)dequeue(&q);
        (void)dequeue(&q);
        assert(queue_empty(&q));
    }

    puts("All queue laws passed ✅");
    return 0;
}
