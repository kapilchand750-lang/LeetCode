class FooBar {
private:
    int n;
    atomic<bool>avail;

public:
    FooBar(int n) {
        this->n = n;
        avail = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(!avail);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            avail = false;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(avail);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            avail = true;
        }
    }
};