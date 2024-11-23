#include <iostream>


class mathop{
    private:
        int val;
    public:
        mathop() = default; // Add a default constructor
        mathop(int value)
        :val{value}
        {
        }
        void add(int value){
            this->val += value;
        }
        void sub(int value){
            this->val -= value;
        }
        
        void mul(int value){
            this->val *= value;
        }
        
        void print(){
            std::cout<<"this->val = "<<this->val<<"\n";
        }

        mathop& add1(int value){ this->val+= value; return *this; }
        mathop& sub1(int value){ this->val-= value; return *this; }
        mathop& mul1(int value){ this->val*= value; return *this; }
        mathop& print1(){std::cout<<"this->val = "<<this->val<<"\n"; return *this;}
        void reset() { *this = {}; } // inorder this to work need to add default constructor
        void reset_without_default() { this->val = {}; } // it works without default constructor
};

int main()
{
    mathop v{10};
    v.add(12);
    v.sub(9);
    v.mul(10);
    v.print();

    // method chaining
    mathop m{10};
    m.add1(12).sub1(8).mul1(10).print1();
    m.reset();
    m.print();

    return 0;
}