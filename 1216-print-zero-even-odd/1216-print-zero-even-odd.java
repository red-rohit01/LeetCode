import java.util.concurrent.Semaphore;

class ZeroEvenOdd {
    private int n;
    
    Semaphore semaZero;
    Semaphore semaEven;
    Semaphore semaOdd;

    public ZeroEvenOdd(int n) {
        this.n = n;
        semaZero = new Semaphore(1); // Initially "0" can be printed, so start with 1 permit
        semaEven = new Semaphore(0); // 
        semaOdd = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        boolean printOdd=true;

        for(int i=0;i<n;++i)
        {
            semaZero.acquire();    // acquiring (decreasing count) to print "0"
            printNumber.accept(0);

            if(printOdd) semaOdd.release();   // odd Semaphore released (count increased)
            else semaEven.release();

            printOdd=!printOdd;
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2;i<=n;i+=2)
        {
            semaEven.acquire();    // acquiring even Semaphore to print even value
            printNumber.accept(i);
            semaZero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i+=2)
        {
            semaOdd.acquire();      // acquiring odd Semaphore to print odd value
            printNumber.accept(i);
            semaZero.release();
        }
    }
}