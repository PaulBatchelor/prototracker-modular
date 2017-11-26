#include "Color.h"
#include "EffectParam.h"

Color::Color(int _r, int _g, int _b, int _a)
	: r(_r), g(_g), b(_b), a(_a)
{
}


Color Color::getColor(ColorType type)
{
	switch (type)
	{
		case ColorType::EditCursor:
			return Color(255, 0, 0);

		case ColorType::NonEditCursor:
			return Color(0, 0, 255);

		case ColorType::RowCounter:
			return Color(128, 128, 255);

		default:
			return Color();
	}
}


Color Color::getEffectColor(const EffectParam& effect)
{
	if (effect.isEmpty())
		return Color(128, 128, 128);

	switch (effect.effect)
	{
		default:
			return Color(192, 192, 192);

		case 'n':
			return Color(128, 255, 128);

		case 'b':
		case 'd':
		case 'j':
			return Color(255, 128, 128);

		case 'a':
		case 'c':
		case 'k':
			return Color(192, 192, 255);

		case 'm':
			return Color(255, 255, 255);

		case 'f':
		case 's':
			return Color(192, 255, 128);
	}
}
