#pragma once
#include <wx/wx.h>
#include <iostream>

enum ImageType
{
	CIRCLE, CROSS, EMPTY, IMAGES_COUNT
};

class Files
{
private:
	wxImage images[IMAGES_COUNT];
	wxBitmap bitmaps[IMAGES_COUNT];
	const std::string filePath[IMAGES_COUNT] = { "Resources/Circle.png", "Resources/Cross.png", "Resources/Empty.png"};
	const std::string backgroundFilePath = "Resources/Background.jpg";

public:
Files()
{
	LoadImages();
}

private:
	void LoadImages();

public:
	wxBitmap GetBitmap(const int imageIndex);
	std::string GetBackgroundPath();
};

