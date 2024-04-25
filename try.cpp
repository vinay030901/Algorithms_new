#include <bits/stdc++.h>
using namespace std;
cv::Mat outputLabels, stats, img_color, centroids;
int main()
{

    int numberofComponents = cv::connectedComponentsWithStats(bwImage, outputLabels,
                                                              stats, centroids, connectivity);

    std::vector<cv::Vec3b> colors(numberofComponents + 1);
    colors[i] = cv::Vec3b(rand() % 256, rand() % 256, rand() % 256);

    // do not count the original background-> label = 0:
    colors[0] = cv::Vec3b(0, 0, 0);

    // Area threshold:
    int minArea = 10; // 10 px

    for (int i = 1; i <= numberofComponents; i++)
    {

        // get the area of the current blob:
        auto blobArea = stats.at<int>(i - 1, cv::CC_STAT_AREA);

        // apply the area filter:
        if (blobArea < minArea)
        {
            // filter blob below minimum area:
            // small regions are painted with (ridiculous) pink color
            colors[i - 1] = cv::Vec3b(248, 48, 213);
        }
    }
}
