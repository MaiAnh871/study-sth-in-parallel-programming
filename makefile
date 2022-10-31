week1:
	g++ -fopenmp week1_wt_pragma.cpp -o week1_wt_pragma
	./week1_wt_pragma
	g++ -fopenmp week1_w_pragma.cpp -o week1_w_pragma
	./week1_w_pragma

week2:
	g++ week2_wt_pragma.cpp -o week2_wt_pragma -fopenmp -I/usr/include/opencv4 -L/path/to/my/openCV/lib -lopencv_core -lopencv_imgcodecs -lopencv_core -lopencv_imgproc -lopencv_highgui
	./week2_wt_pragma
	g++ week2_w_pragma.cpp -o week2_w_pragma -fopenmp -I/usr/include/opencv4 -L/path/to/my/openCV/lib -lopencv_core -lopencv_imgcodecs -lopencv_core -lopencv_imgproc -lopencv_highgui
	./week2_w_pragma

