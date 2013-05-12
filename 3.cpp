std::cout << (cRectangle2)a << std::endl;
std::cout << *(cRectangle2*)ptr << std::endl;

The second method is preferred, because when we cast pointers, the compiler does not create a new object meaning that is saves memory. As we can can see from the output of the two statements over, the first one calls Rectangles copy constructor, outputs 2 1 and then calls the destructor on the very same Rectangle object. As for the pointer, it just prints out 2 1 directly without allocating memory for a new object.