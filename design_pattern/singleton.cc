

class singleton{
public:
    static singleton& getInstance()
    {
     static singleton instance;
     return instance;
    }
private:
    singleton(){}
public:
    singleton(singleton const&)=delete;
    void operator=(singleton const &)=delete;
};
int main(){
    singleton::getInstance();
}