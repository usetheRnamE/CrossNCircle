#include "Files.h"


void Files::LoadImages()
{
	#define ImageSize 50, 50

	int length = sizeof(images) / sizeof(wxBitmap);

	for (int i = 0; i < length; i++)
	{
	    try
		{
			images[i].LoadFile(filePath[i], wxBITMAP_TYPE_PNG);

		    if (!images[i].IsOk()) printf("Error: image is nullptr\n");			
		}
		catch (std::exception e)
		{
			printf("Exception: [%s]\n", e.what());
		}

		images[i].Rescale(ImageSize);

		bitmaps[i] = images[i];
	}
}

wxBitmap Files::GetBitmap(const int bitmapIndex)
{
    return bitmaps[bitmapIndex];
}

std::string Files::GetBackgroundPath()
{
	return backgroundFilePath;
}
