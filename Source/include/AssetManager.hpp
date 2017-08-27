#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
	public:
		AssetManager();
		
		static sf::Texture& GetTexture(std::string const& filename);
		
	private:
		std::map<std::string, sf::Texture> m_Textures;
		
		static AssetManager* sInstance;
};

#endif //ASSETMANAGER_HPP
