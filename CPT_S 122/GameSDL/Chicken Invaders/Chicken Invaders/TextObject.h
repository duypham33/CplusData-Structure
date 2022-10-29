
/*

  This is the header file that stores standard library includes, #defined and function prototypes of TextObject class

*/

#ifndef TEXT_OBJECT_H_   //Guard code
#define TEXT_OBJECT_H_

#include "BaseObject.h"

using std::string;

static TTF_Font* g_font_text = NULL;     //The global font
static TTF_Font* menu_font_text = NULL;  //The menu font


//This class is for text object, display text during the game.

//TextObject Class(An inheritant class from BaseOject class)
class TextObject : public BaseObject
{
public:
	enum TextColor
	{
		WHITE = 0, RED, GREEN,
	};
	//Constructor
	TextObject(const int& posX = 0, const int& posY = 0, const string& newText = "");

	//Destructor
	~TextObject();

	//Setters
	void setText(const string& newText);
	void setColor(const int& colorType);

	//Override Show() function of the parent class(BaseObject)
	void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1);

private:
	string mText;      //The content of the text
	SDL_Color mColor;  //The text color
}; 



#endif