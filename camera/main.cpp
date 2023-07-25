#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	cv::VideoCapture cap(0); // ������ͷ��0����Ĭ������ͷ �� C++ �� OpenCV ���У�cv::VideoCapture ���� Windows ƽ̨��ʹ�� DirectShow ��������Ƶ�����豸

	if (!cap.isOpened()) {
		std::cerr << "Error: Could not open the camera." << std::endl;
		return -1;
	}

	//��������ͷ�ֱ���
	int desired_width = 4656;
	int desired_height = 3496;
	cap.set(cv::CAP_PROP_FRAME_WIDTH, desired_width);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, desired_height);

	//���ñ��Ͷ�
	//double target_saturation = 0.5; // ����Ŀ�걥�Ͷ�ֵ
	//cap.set(cv::CAP_PROP_SATURATION, target_saturation);

	//�����ع�
	//double exposureValue = -8;
	//cap.set(cv::CAP_PROP_EXPOSURE, exposureValue);

	//��������
	//int brightness = 20;
	//cap.set(cv::CAP_PROP_BRIGHTNESS, brightness);//���� 1

	//���öԱȶ�
	//int contrast = 60;
	//cap.set(cv::CAP_PROP_CONTRAST, contrast);//�Աȶ� 40

	//����������ʾ����ͷ֡
	cv::namedWindow("Camera", cv::WINDOW_NORMAL);

	while (true){
		cv::Mat frame;
		cap >> frame; // ������ͷ����һ֡ͼ��
		if (frame.empty()) {
			std::cerr << "Error: Could not capture a frame." << std::endl;
			return -1;
		}

		// ��ʾ֡
		cv::imshow("Camera", frame);

		if (cv::waitKey(1) == 'c'){
			cv::imwrite("captured_image.jpg", frame); // ��ͼ�񱣴�Ϊ�ļ�
			std::cout << "Image captured successfully." << std::endl;
		}

		if (cv::waitKey(1) == 'q'){
			break;
		}

	}

	cap.release(); // �ͷ�����ͷ
	cv::destroyAllWindows();//�رմ���

	return 0;
}
