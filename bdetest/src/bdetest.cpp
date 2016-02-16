#include <iostream>
#include <bslmt_threadgroup.h>

using namespace BloombergLP;
using namespace std;

class MyJob {
private:
	int m_i;
public:
	MyJob(int i): m_i(i) { }
	void operator()() {
		cout << "I am here with " << m_i << endl;
	}
};

int main(void) {
    bslmt::ThreadGroup group;
    for(int i = 0; i < 5; ++i) {
    	group.addThread(MyJob(i));
    }
    group.joinAll();
	return 0;
}
