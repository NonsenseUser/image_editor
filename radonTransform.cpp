#include "radonTransform.h"


void radon(QImage& img) {
    int width = img.width();
    int height = img.height();
    int diagonal = static_cast<int>(std::sqrt(width * width + height * height));
    int maxRho = 2 * diagonal;

    // Инициализация матрицы для хранения результатов преобразования Радона
    std::vector<int> transformedPixels(180 * maxRho, 0);
    int maxPixel = 0;

    for (int theta = 0; theta < 180; theta++) {
        double angle = theta * M_PI / 180.0;
        double cosTheta = std::cos(angle);
        double sinTheta = std::sin(angle);
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                int pixelValue = qGray(img.pixel(x, y));
                int rho = static_cast<int>(x * cosTheta + y * sinTheta) + diagonal;
                if (rho >= 0 && rho < maxRho) {
                    transformedPixels[theta * maxRho + rho] += pixelValue;
                }
            }
        }

        // Обновляем максимальное значение пикселя
        maxPixel = std::max(maxPixel, *std::max_element(transformedPixels.begin() + theta * maxRho, transformedPixels.begin() + (theta + 1) * maxRho));
    }

    // Нормализация и создание нового изображения
    QImage radonImage(180, maxRho, QImage::Format_Grayscale8);
    for (int theta = 0; theta < 180; ++theta) {
        for (int rho = 0; rho < maxRho; ++rho) {
            int pixelValue = static_cast<int>(255.0 * transformedPixels[theta * maxRho + rho] / maxPixel);
            radonImage.setPixel(theta, rho, qRgb(pixelValue, pixelValue, pixelValue));
        }
    }

    img = radonImage;
}
