#include "model_import.hpp"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace samplelib
{
	Mesh load_mesh(const char* relative_path)
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(relative_path, aiProcess_Triangulate | aiProcess_CalcTangentSpace | aiProcess_GenNormals);
		tz_assert(scene != nullptr, "Model import failed: %s. Please submit a bug report.", importer.GetErrorString());
		return {};
	}
}
