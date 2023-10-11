#include <opencv2/opencv.hpp>

using namespace cv;
/*All of the functions utilized in detecting the signs are similar to the functions employed in detecting the
lines, with the exception of the Houghcircle function which is utilized for detecting circles.*/

int main(int argc, char** argv)
{

    Mat image = imread("C:/Users/sina tavakoli/source/repos/homework/homework/road8.jpg");

    /*In this particular section of the code, the cvtColor function was utilized with the objective of facilitating the computing
    process. Given that the input images were in RGB format, the detection procedure would have been more complex. By converting
    the RGB color model to grayscale, the detection process was simplified, thus enabling a more efficient and accurate analysis.*/
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    Mat edges;
    Canny(gray, edges, 250, 300);

    /*In the pursuit of achieving optimal results, I endeavored to fine-tune the parameters for both the Canny function and Houghcircle.
    It is important to note that finding the right balance between these parameters is crucial to obtaining the best possible outcome.*/

    std::vector<Vec3f> circles;
    HoughCircles(edges, circles, HOUGH_GRADIENT, 1, edges.rows / 10, 100, 40, 35, 100);

    /*In the following code snippet, circles that were detected in the original image are drawn and filled in green.*/
    Mat output = image.clone();
    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(output, center, radius, Scalar(0, 255, 0), 2, LINE_AA);
    }

    /*In this section of the code, we present the ultimate output of our algorithm which detects the road
    signs in the image and highlights them in red color.*/
    namedWindow("Output Image", WINDOW_NORMAL);
    imshow("Output Image", output);
    waitKey(0);

    return 0;
}
/*--------------------------REPORT-------------------------------------REPORT------------------------------------------REPORT----------------------------------*/
/*Overview Report:

Introduction:
The purpose of this project was to develop an algorithm that could detect road signs in images. The algorithm utilized various image processing techniques,
including the Canny edge detection algorithm and the Hough Circle Transform. The overall goal was to create a program that could accurately and efficiently
detect road signs in images, which would have important applications in fields such as autonomous driving.

Image Preprocessing:
In the initial stage of the program, the input images were read using OpenCV's imread function. The images were in RGB format, which made the detection
process more complex. To simplify the detection process, the RGB color model was converted to grayscale using the cvtColor function. This enabled a more
efficient and accurate analysis of the images.

Edge Detection:
The Canny edge detection algorithm was used to detect the edges of the objects in the image. The edges were detected using the grayscale image that was
generated in the previous step. In order to achieve optimal results, the parameters for the Canny function were fine-tuned. The parameters were adjusted to
find the right balance between sensitivity and noise reduction.

Circle Detection:
The Hough Circle Transform was used to detect circles in the image. The circles that were detected in the image were drawn and filled in green. The parameters
for the Hough Circle Transform were also fine-tuned to achieve the best possible results.

Road Sign Detection:
The road signs that were detected were highlighted in GREEN color in the final output image.

Conclusion:
In conclusion, the algorithm developed in this project is capable of detecting road signs in images. The algorithm utilizes various image processing techniques,
including the Canny edge detection algorithm and the Hough Circle Transform. The parameters for the different functions were fine-tuned to achieve the best possible
results.*/
