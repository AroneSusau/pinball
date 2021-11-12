#pragma once

#include "Material.h"
#include "Common.h"

class CommonTextures
{
public:
	static TexturedMaterial* Asphalt;
	static TexturedMaterial* Bricks1;
	static TexturedMaterial* Dark_Marble;
	static TexturedMaterial* Marble;
	static TexturedMaterial* Metal;
	static TexturedMaterial* Wood;

	static TexturedMaterial* Empty;

	static void Init(std::string root);
};
