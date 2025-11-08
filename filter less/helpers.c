#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int blue = 0;
    int green = 0;
    for (int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            red = image[h][w].rgbtRed;
            blue = image[h][w].rgbtBlue;
            green = image[h][w].rgbtGreen;
            int theAverageAdded = red + blue + green;
            int theAverage = theAverageAdded / 3;
            image[h][w].rgbtRed = theAverage;
            image[h][w].rgbtBlue = theAverage;
            image[h][w].rgbtGreen = theAverage;
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

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;
    float counter = 0.0;
    RGBTRIPLE tempTable[height][width];
    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            for (int x = -1; x < 2; x++)
            {
                if (h + x < 0 || h + x > height - 1)
                {
                    continue;
                }
                for (int y = -1; y < 2; y++)
                {
                    if (w + y < 0 || w + y > width - 1)
                    {
                        continue;
                    }
                    red += image[h + x][w + y].rgbtRed;
                    green += image[h + x][w + y].rgbtGreen;
                    blue += image[h + x][w + y].rgbtBlue;
                    counter++;

                }
            }
            tempTable[h][w].rgbtRed = round(red / counter);
            tempTable[h][w].rgbtGreen = round(green / counter);
            tempTable[h][w].rgbtBlue = round(blue / counter);

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempTable[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempTable[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempTable[i][j].rgbtBlue;
        }
    }
    return;
}
