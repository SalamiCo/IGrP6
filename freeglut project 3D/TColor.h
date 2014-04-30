#pragma once
class TColor
{
private:
	float red, green, blue;

public:
	TColor(void);
	TColor(float r, float g, float b);
	~TColor(void);

	float getRed(){ return this->red; }
	float getGreen(){ return this->green; }
	float getBlue(){ return this->blue; }

	void setRed(float r){ this->red = r; }
	void setGreen(float g){ this->green = g; }
	void setBlue(float b){ this->blue = b; }
};

