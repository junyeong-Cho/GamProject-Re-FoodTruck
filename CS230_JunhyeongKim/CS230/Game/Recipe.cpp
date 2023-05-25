#include "Recipe.h"

Recipe::Recipe()
{
	lemon = new Lemon({ 0,0 });
	boiledLemon = new Lemon({ 0,0 });
	boiledLemon->Boil();

	lettuce = new Lettuce({ 0,0 });

	ant = new Ant({ 0,0 });
	boiledAnt = new Ant({ 0,0 });
	boiledAnt->Boil();

	leaf = new Leaf({ 0,0 });
	boiledLeaf = new Leaf({ 0,0 });
	boiledLeaf->Boil();

	salt = new Salt({ 0,0 });
	boiledSalt = new Salt({ 0,0 });
	boiledSalt->Boil();

	dragonFruit = new DragonFruit({ 0,0 });
	boiledDragonFruit = new DragonFruit({ 0,0 });
	boiledDragonFruit->Boil();

	mermaidScales = new MermaidScales({ 0,0 });
	boiledMermaidScales = new MermaidScales({ 0,0 });
	boiledMermaidScales->Boil();
}

int Recipe::CheckComplete(std::vector<Ingredient*>& plating)
{
	int checkTotal = 0;
	score = 0;
	size_t size = (plating.size() > recipe.size()) ? recipe.size() : plating.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (plating[i]->GetName() == recipe[i]->GetName())
		{
			score += 100 / (totalNum-1);
			if (plating[i]->GetCutNum() == recipe[i]->GetCutNum())
			{
				score += 100 / totalNum;
				checkTotal += 1;
			}
			if (plating[i]->GetBoiled() == recipe[i]->GetBoiled())
			{
				score += 100 / totalNum;
				checkTotal += 1;
			}
		}
	}
	if (totalNum == checkTotal)
	{
		score = 100;
	}
	return score;
}

void Recipe::Update()
{
	texturePos = Math::vec2((double)Engine::GetWindow().GetSize().x / 4,
		(double)Engine::GetWindow().GetSize().y / 7);
}

void Recipe::Unload()
{
	delete lemon;
	delete boiledLemon;

	delete lettuce;

	delete ant;
	delete boiledAnt;

	delete leaf;
	delete boiledLeaf;

	delete salt;
	delete boiledSalt;

	delete dragonFruit;
	delete boiledDragonFruit;

	delete mermaidScales;
	delete boiledMermaidScales;

	recipe.clear();
}



LemonSalad::LemonSalad() : Recipe()
{
	recippeName = RecipeName::LemonSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2
	recipe.push_back(lemon); //3

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_LemonSalad.png");
}
void LemonSalad::Load()
{}
void LemonSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




SaltSalad::SaltSalad() : Recipe()
{
	recippeName = RecipeName::SaltSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(salt); //1

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_SaltSalad.png");
}
void SaltSalad::Load()
{}

void SaltSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



LeafSalad::LeafSalad() : Recipe()
{
	recippeName = RecipeName::LeafSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(leaf); //1

	recipe.push_back(salt); //1

	totalNum = recipe.size();
	
	texture = Engine::GetTextureManager().Load("Assets/Recipe_LeafSalad.png");
}
void LeafSalad::Load()
{}

void LeafSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



AntSalad::AntSalad() : Recipe()
{
	recippeName = RecipeName::AntSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(ant); //1
	recipe.push_back(ant); //2
	recipe.push_back(ant); //3
	recipe.push_back(ant); //4
	recipe.push_back(ant); //5
	recipe.push_back(ant); //6
	recipe.push_back(ant); //7

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSalad.png");
}
void AntSalad::Load()
{}

void AntSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}


DragonFruitSalad::DragonFruitSalad() : Recipe()
{
	recippeName = RecipeName::DragonFruitSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(dragonFruit); //1
	recipe.push_back(dragonFruit); //2
	recipe.push_back(dragonFruit); //3
	recipe.push_back(dragonFruit); //4

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_DragonFruitSalad.png");
}
void DragonFruitSalad::Load()
{}

void DragonFruitSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



MermaidScalesSalad::MermaidScalesSalad() : Recipe()
{
	recippeName = RecipeName::MermaidScalesSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(mermaidScales); //1
	recipe.push_back(mermaidScales); //2
	recipe.push_back(mermaidScales); //3
	recipe.push_back(mermaidScales); //4
	recipe.push_back(mermaidScales); //5

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_MermaidScalesSalad.png");
}
void MermaidScalesSalad::Load()
{}

void MermaidScalesSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




WaterSoup::WaterSoup() : Recipe()
{
	recippeName = RecipeName::WaterSoup;

	recipe.push_back(boiledSalt); //1

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_WaterSoup.png");
}
void WaterSoup::Load()
{}

void WaterSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




AntSoup::AntSoup() : Recipe()
{
	recippeName = RecipeName::AntSoup;

	recipe.push_back(boiledAnt); //1
	recipe.push_back(boiledAnt); //2
	recipe.push_back(boiledAnt); //3

	recipe.push_back(boiledSalt); //1

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSoup.png");
}
void AntSoup::Load()
{}

void AntSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



StrongSoup::StrongSoup() : Recipe()
{
	recippeName = RecipeName::StrongSoup;

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2

	recipe.push_back(boiledLeaf); //1

	recipe.push_back(boiledDragonFruit); //1

	recipe.push_back(boiledMermaidScales); //1

	recipe.push_back(boiledSalt); //1
	recipe.push_back(boiledSalt); //2

	recipe.push_back(ant); //1
	recipe.push_back(ant); //2

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_StrongSoup.png");
}
void StrongSoup::Load()
{}

void StrongSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}

