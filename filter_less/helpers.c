#include "helpers.h"
#include <math.h>
#include<stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int blue = 0;
    int green = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            red = image[h][w].rgbtRed;
            blue = image[h][w].rgbtBlue;
            green = image[h][w].rgbtGreen;
            float theAverageAdded = red + blue + green;
            float theAverage = theAverageAdded / 3;
            image[h][w].rgbtRed = round(theAverage);
            image[h][w].rgbtBlue = round(theAverage);
            image[h][w].rgbtGreen = round(theAverage);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int blue = 0;
    int green = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            red = image[h][w].rgbtRed;
            blue = image[h][w].rgbtBlue;
            green = image[h][w].rgbtGreen;
            float sepiaRedR = 0.393 * red;
            float sepiaRedB = 0.189 * blue;
            float sepiaRedG = 0.769 * green;
            float sepiaRed = sepiaRedR + sepiaRedB + sepiaRedG;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[h][w].rgbtRed = round(sepiaRed);
            float sepiaGreenR = 0.349 * red;
            float sepiaGreenG = 0.686 * green;
            float sepiaGreenB = 0.168 * blue;
            float sepiaGreen = sepiaGreenR + sepiaGreenG + sepiaGreenB;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[h][w].rgbtGreen = round(sepiaGreen);
            float sepiaBlueR = 0.272 * red;
            float sepiaBlueG = 0.534 * green;
            float sepiaBlueB = 0.131 * blue;
            float sepiaBlue = sepiaBlueR + sepiaBlueG + sepiaBlueB;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[h][w].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int blue = 0;
    int green = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            red = image[h][w].rgbtRed;
            green = image[h][w].rgbtGreen;
            blue = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            image[h][width - w - 1].rgbtRed = red;
            image[h][width - w - 1].rgbtGreen = green;
            image[h][width - w - 1].rgbtBlue = blue;
        }
    }
    return;
}
float cap(int num, int cap)
{
    int result = num;
    if (num > cap)
    {
        result = cap;
    }
    return result;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imgCopy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float avgRed = 0;
            float avgGreen = 0;
            float avgBlue = 0;
            int counter = 0;
            //top pixel
            if (h - 1 >= 0)
            {
                avgRed += image[h - 1][w].rgbtRed;
                avgGreen += image[h - 1][w].rgbtGreen;
                avgBlue += image[h - 1][w].rgbtBlue;
                counter++;
            }
            //bottom pixel
            if (h + 1 < height)
            {
                avgRed += image[h + 1][w].rgbtRed;
                avgGreen += image[h + 1][w].rgbtGreen;
                avgBlue += image[h + 1][w].rgbtBlue;
                counter++;
            }
            //left pixel
            if (w - 1 >= 0)
            {
                avgRed += image[h][w - 1].rgbtRed;
                avgGreen += image[h][w - 1].rgbtGreen;
                avgBlue += image[h][w - 1].rgbtBlue;
                counter++;
            }
            //left pixel
            if (w + 1 < width)
            {
                avgRed += image[h][w + 1].rgbtRed;
                avgGreen += image[h][w + 1].rgbtGreen;
                avgBlue += image[h][w + 1].rgbtBlue;
                counter++;
            }
            //top left
            if (h - 1 >= 0 && w - 1 >= 0)
            {
                avgRed += image[h - 1][w - 1].rgbtRed;
                avgGreen += image[h - 1][w - 1].rgbtGreen;
                avgBlue += image[h - 1][w - 1].rgbtBlue;
                counter++;
            }
            //top right
            if (h - 1 >= 0 && w + 1 < width)
            {
                avgRed += image[h - 1][w + 1].rgbtRed;
                avgGreen += image[h - 1][w + 1].rgbtGreen;
                avgBlue += image[h - 1][w + 1].rgbtBlue;
                counter++;
            }
            //bottom left
            if (h + 1 < height && w - 1 >= 0)
            {
                avgRed += image[h + 1][w - 1].rgbtRed;
                avgGreen += image[h + 1][w - 1].rgbtGreen;
                avgBlue += image[h + 1][w - 1].rgbtBlue;
                counter++;
            }
            //bottom right
            if (h + 1 < height && w + 1 < width)
            {
                avgRed += image[h + 1][w + 1].rgbtRed;
                avgGreen += image[h + 1][w + 1].rgbtGreen;
                avgBlue += image[h + 1][w + 1].rgbtBlue;
                counter++;
            }
            avgRed += image[h][w].rgbtRed;
            avgGreen += image[h][w].rgbtGreen;
            avgBlue += image[h][w].rgbtBlue;
            counter++;

            imgCopy[h][w].rgbtRed = cap(round(avgRed / counter), 255);
            imgCopy[h][w].rgbtGreen = cap(round(avgGreen / counter), 255);
            imgCopy[h][w].rgbtBlue = cap(round(avgBlue / counter), 255);
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = imgCopy[h][w].rgbtRed;
            image[h][w].rgbtGreen = imgCopy[h][w].rgbtGreen;
            image[h][w].rgbtBlue = imgCopy[h][w].rgbtBlue;
        }
    }
    return;
}
