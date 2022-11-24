#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

class Circle {
public:
	//make circle
    static void createCircle(const int diameter);
    static bool validCheck(const int diameter);
    //check terminal size
	static int winSize();
};

#endif // __CIRCLE_HPP__
