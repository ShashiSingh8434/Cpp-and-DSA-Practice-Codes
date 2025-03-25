#include <iostream>
using namespace std;
/*
---------------------------------------------------
BASE      |               DERIVED                  |
---------------------------------------------------
          |  public     | protected    |  private  |
---------------------------------------------------|
public    |  public    |  protected    |  private  |
protected |  protected |  protected    |  private  |
private   |  NaN       |  NaN          |  NaN      |
---------------------------------------------------

*/

class Animal{
    public:
    int a=1;

    protected:
    int b=2;

    private:
    int c=3;
};

class One: public Animal{
    // can use all three attributes inside
    // can use public of animal variable outside
};
class Two: protected Animal{
    // can use all three attributes inside
    // cannot use anything outside
};
class Three: private Animal{
    // cannot use inside also
    // cannot use outside also
};

int main(){
    One one ;
    Two two ;
    Three three;

    cout << one.a <<endl;
    // cout << two.a <<endl;
    // cout << three.a <<endl;

    
    return 0;
}