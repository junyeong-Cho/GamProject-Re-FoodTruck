#include "IngredientTextureManager.h"
#include "../Engine/Engine.h"

IngredientTextureManager::IngredientTextureManager()
{
	ingredientTexture[static_cast<int>(IngredientName::Lemon)].push_back(Engine::GetTextureManager().Load("Assets/Lemon1.png"));
	ingredientTexture[static_cast<int>(IngredientName::Lemon)].push_back(Engine::GetTextureManager().Load("Assets/Lemon2.png"));
	ingredientTexture[static_cast<int>(IngredientName::Lemon)].push_back(Engine::GetTextureManager().Load("Assets/Lemon3.png"));

	ingredientTexture[static_cast<int>(IngredientName::Lettuce)].push_back(Engine::GetTextureManager().Load("Assets/Lettuce1.png"));
	ingredientTexture[static_cast<int>(IngredientName::Lettuce)].push_back(Engine::GetTextureManager().Load("Assets/Lettuce2.png"));
	ingredientTexture[static_cast<int>(IngredientName::Lettuce)].push_back(Engine::GetTextureManager().Load("Assets/Lettuce3.png"));
	ingredientTexture[static_cast<int>(IngredientName::Lettuce)].push_back(Engine::GetTextureManager().Load("Assets/Lettuce4.png"));

	ingredientTexture[static_cast<int>(IngredientName::Ant)].push_back(Engine::GetTextureManager().Load("Assets/Ant.png"));

	ingredientTexture[static_cast<int>(IngredientName::Leaf)].push_back(Engine::GetTextureManager().Load("Assets/Leaf.png"));

	ingredientTexture[static_cast<int>(IngredientName::Salt)].push_back(Engine::GetTextureManager().Load("Assets/Salt1.png"));
	ingredientTexture[static_cast<int>(IngredientName::Salt)].push_back(Engine::GetTextureManager().Load("Assets/Salt2.png"));
	ingredientTexture[static_cast<int>(IngredientName::Salt)].push_back(Engine::GetTextureManager().Load("Assets/Salt3.png"));

	ingredientTexture[static_cast<int>(IngredientName::DragonFruit)].push_back(Engine::GetTextureManager().Load("Assets/DragonFruit1.png"));
	ingredientTexture[static_cast<int>(IngredientName::DragonFruit)].push_back(Engine::GetTextureManager().Load("Assets/DragonFruit2.png"));
	ingredientTexture[static_cast<int>(IngredientName::DragonFruit)].push_back(Engine::GetTextureManager().Load("Assets/DragonFruit3.png"));

	ingredientTexture[static_cast<int>(IngredientName::MermaidScales)].push_back(Engine::GetTextureManager().Load("Assets/MermaidScales1.png"));
	ingredientTexture[static_cast<int>(IngredientName::MermaidScales)].push_back(Engine::GetTextureManager().Load("Assets/MermaidScales2.png"));
	ingredientTexture[static_cast<int>(IngredientName::MermaidScales)].push_back(Engine::GetTextureManager().Load("Assets/MermaidScales3.png"));
}

std::vector<std::vector<CS230::Texture*>> IngredientTextureManager::GetTexture() const
{
	return ingredientTexture;
}

