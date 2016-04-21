#include <string>
#include <iostream>
using namespace std;

namespace figure{
    
    //You can add member function in this class
    class BasePoint{
        public:
            BasePoint(int px, int py):x(px),y(py){}
            virtual ~BasePoint(){}
            virtual void settype(string s){
            	type = s;
			}
            virtual void info(){
                cout<<"figure: "<<type<<endl;
                cout<<"position x:"<<x<<" y:"<<y<<endl;
            }
        
        protected:
            int x,y;
        private:
            string type;
    }; 
    //Fill your code here
    class Figure1P: public BasePoint {
        public:
            Figure1P(int px,int py, int _p1):BasePoint(px, py), p1(_p1){}
            void info(){
				BasePoint::info();
                cout<<"property 1: p1="<<p1<<endl;
            }
        protected:
            int p1;
    };
    class Square: public Figure1P {
        public:
            Square(int px,int py, int _p1):Figure1P(px, py, _p1){
            	BasePoint::settype("square");
			}
            void info(){
            	Figure1P::info();
            	cout<<"area: "<<p1 * p1<<endl;
			}
    };
    class Figure2P: public Figure1P {
        public:
            Figure2P(int px,int py, int _p1, int _p2):Figure1P(px, py, _p1), p2(_p2){}
            void info(){
            	Figure1P::info();
                cout<<"property 2: p2="<<p2<<endl;
            }
            
        protected:
            int p2;
    };
    class Rectangle: public Figure2P {
        public:
            Rectangle(int px,int py, int _p1, int _p2):Figure2P(px, py, _p1, _p2){
            	BasePoint::settype("rectangle");
			}
            void info(){
            	Figure2P::info();
            	cout<<"area: "<<p1 * p2<<endl;
			}
    };
}
