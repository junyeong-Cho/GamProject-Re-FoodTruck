#pragma once
enum class RecipeName
{
	LemonSalad, //1
	SaltSalad, //2
	LeafSalad, //3
	AntSalad, //4
	DragonFruitSalad, //5
	MermaidScalesSalad, //6
	WaterSoup, //7
	AntSoup, //8
	StrongSoup //9
};

inline RecipeName& operator+=(RecipeName& name, int value)
{
	if (value > 0)
	{
		name = (name == RecipeName::StrongSoup) ? RecipeName::StrongSoup : RecipeName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == RecipeName::LemonSalad) ? RecipeName::LemonSalad : RecipeName(static_cast<int>(name) + value);
	}
	return name;
}