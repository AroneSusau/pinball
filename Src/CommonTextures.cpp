#include "CommonTextures.h"

TexturedMaterial* CommonTextures::Asphalt;
TexturedMaterial* CommonTextures::Bricks1;
TexturedMaterial* CommonTextures::Dark_Marble;
TexturedMaterial* CommonTextures::Marble;
TexturedMaterial* CommonTextures::Metal;
TexturedMaterial* CommonTextures::Wood;

TexturedMaterial* CommonTextures::Empty;

void CommonTextures::Init(std::string root) {

	CommonTextures::Asphalt     = TexturedMaterial::Make(root, "asphalt",     25.0f,  GL_RGB, false, 0.0);
	CommonTextures::Bricks1     = TexturedMaterial::Make(root, "bricks1",     75.0f,  GL_RGB, true,  0.6);
	CommonTextures::Dark_Marble = TexturedMaterial::Make(root, "dark_marble", 100.0f, GL_RGB, true,  0.7);
	CommonTextures::Marble      = TexturedMaterial::Make(root, "marble",      90.0f,  GL_RGB, true,  0.9);
	CommonTextures::Metal       = TexturedMaterial::Make(root, "metal",       100.0f, GL_RGB, true,  0.1);
	CommonTextures::Wood        = TexturedMaterial::Make(root, "wood",        20.0f,  GL_RGB, false, 0.0);

	CommonTextures::Empty       = new TexturedMaterial(new Texture("", "", "", 0), new Texture("", "", "", 0), 0.0, false, 0.0);
}