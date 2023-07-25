#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	cv::VideoCapture cap(0); // 打开摄像头，0代表默认摄像头 在 C++ 的 OpenCV 库中，cv::VideoCapture 类在 Windows 平台上使用 DirectShow 来操作视频捕获设备

	if (!cap.isOpened()) {
		std::cerr << "Error: Could not open the camera." << std::endl;
		return -1;
	}

	//设置摄像头分辨率
	int desired_width = 4656;
	int desired_height = 3496;
	cap.set(cv::CAP_PROP_FRAME_WIDTH, desired_width);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, desired_height);

	//设置饱和度
	//double target_saturation = 0.5; // 设置目标饱和度值
	//cap.set(cv::CAP_PROP_SATURATION, target_saturation);

	//设置曝光
	//double exposureValue = -8;
	//cap.set(cv::CAP_PROP_EXPOSURE, exposureValue);

	//设置亮度
	//int brightness = 20;
	//cap.set(cv::CAP_PROP_BRIGHTNESS, brightness);//亮度 1

	//设置对比度
	//int contrast = 60;
	//cap.set(cv::CAP_PROP_CONTRAST, contrast);//对比度 40

	//创建窗口显示摄像头帧
	cv::namedWindow("Camera", cv::WINDOW_NORMAL);

	while (true){
		cv::Mat frame;
		cap >> frame; // 从摄像头捕获一帧图像
		if (frame.empty()) {
			std::cerr << "Error: Could not capture a frame." << std::endl;
			return -1;
		}

		// 显示帧
		cv::imshow("Camera", frame);

		if (cv::waitKey(1) == 'c'){
			cv::imwrite("captured_image.jpg", frame); // 将图像保存为文件
			std::cout << "Image captured successfully." << std::endl;
		}

		if (cv::waitKey(1) == 'q'){
			break;
		}

	}

	cap.release(); // 释放摄像头
	cv::destroyAllWindows();//关闭窗口

	return 0;
}
